**Topic 9 - Advanced MongoDB (page 15)**



1\. create index on city

db.order.createIndex({city})



2\. view on all index

db.orders.getIndexes()



3\. index for filter + sort together

db.orders.createIndex({ city = 1, amount = -1 })



4\. using index for range queries 

* db.orders.createIndex({ amount 1 })
* db.orders.find({ amount: { $gte: 100, $lte: 250 } })



5\. create a compound index on city and status

db.orders.createIndex({ city = 1, status = 1 })



6\. query that uses compound index

db.orders.find({ city = "KL", status = "PAID" })



7\. query only using the first field

db.orders.find({ city = "KL" })



8\. compound index with sorting

db.orders.find({ city = "KL" }).sort({ status: 1 })



9\. total sales by city, using aggregation

db.orders.aggregate(\[ { $match: { status: "PAID" } }, { $group: { \_id: "$city", totalSales: { $sum: "$amount" } } }



10\. exercise: find total spending per customer and totalSpent in descending order using aggregation

db.orders.aggregate(\[ { $group: { \_id: "$customer", totalSpent: { $sum: "$amount"} } }, { $sort: { totalSpent: -1 } } ])



11.find orders by city 

(SELECT \* FROM orders WHERE city = "KL";)

db.orders.find({ city: "KL" })



12\. filter, select specific columns, and sort 

(SELECT orderId, city, amount, status FROM orders WHERE status = "PAID" ORDER BY amount DESC;)

db.orders.find({ status: "PAID" }, { orderId: 1, city: 1, amount: 1, status: 1 }).sort({ amount: -1 })



13\. count the orders by both city \& amount

(SELECT city, amount, COUNT(\*) AS totalOrders FORM orders WHERE amount>100 GROUP BY city;)

db.orders.aggregate(\[ { $match: { amount: { $gt: 100 } } }, { $group: { \_id: "$city", totalOrders: { $sum: 1 } } } ])



14\. update one document

* db.orders.updateOne( { orderId: 1002 }, { $set: { status: "PAID" } } )
* db.orders.find( { orderId: 1002 } )



15\. update many document

* db.orders.updatemany( { status: "FAILED" }, { $set: { status: "REVIEW" } } )
* db.orders.find( { status: "REVIEW })



16\. retrieve active login sessions

a) create a collection called loginSessions that stores user login activity.

b) insert many sample login session records, as example; userId: "U001", username: "ali", ipAddress: "10.10.1.5", status: "ACTIVE", loginTime: ISODate("2026-01-07T08:30:00Z")

* db.loginSessions.insertMany(\[ { userId: "U001", username: "ali", ipAddress: "10.10.1.5", status: "ACTIVE", loginTime: ISODate("2026-01-07T08:30:00Z") }, { userId: "U002", username: "siti", ipAddress: "10.10.1.6", status: "INACTIVE", loginTime: ISODate("2026-01-07T09:00:00Z") }, { userId: "U003", username: "ahmad", ipAddress: "10.10.1.7", status: "ACTIVE", loginTime: ISODate("2026-01-07T09:15:00Z") } ])

c) verify data.

* db.loginSessions.find()

d) retrieve all active sessions.

* db.loginSessions.find({ status: "ACTIVE" })
