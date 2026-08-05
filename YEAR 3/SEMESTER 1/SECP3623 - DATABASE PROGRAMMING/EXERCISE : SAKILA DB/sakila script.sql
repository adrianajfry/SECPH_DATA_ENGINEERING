# example 1
DELIMITER $$
create procedure GetCustomers()
begin
	select * from CUSTOMER where STORE_ID = 2 order by FIRST_NAME;
end$$
DELIMITER ;

call GetCustomers();

# example 2: create procedure with variables & parameter
DELIMITER $$
create procedure GetCustomerStoreID1 (in storeID int, out totCust int)
begin
	declare newTotCust int;
    select * from CUSTOMER where STORE_ID = storeID;
    
    select count(*) INTO newTotCust from customer where store_id = storeID;
    
    set totCust = newTotCust;
end$$
DELIMITER ;

call GetCustomerStoreID1 (2, @totalCust);
select @totalCust;

# example 3: IF statement
DELIMITER $$
create procedure star (in countryID int, out starPriv int)
begin 
	declare cntCity int;
    select count(city_id) into cntCity from city where country_id = countryID;
    if cntCity >= 9 then set starPriv = 5;
    elseif cntCity >= 4 and cntCity < 9 then set starPriv = 3;
    else set starPriv = 1;
    end if;
end$$
DELIMITER ;

set @country = 3;
call star(@country, @starPrivilage);
select @country, @starPrivilage;

use sakila;

# Rewrite the procedure STAR using CASE conditional statement
DELIMITER $$
create procedure star_case (in countryID int, out starpriv int)
begin 
	declare cntcity int;

# count number of cities for given country 
select count (city_id) into cntCity from city where country_id = countryID;

# CASE statement logic
	case 
		when cntCity >= 9 then set starPriv = 5;
        when cntCity >= 4 then set starPriv = 3;
        else set starPriv =1;
	end case;
end$$
delimiter ;

# this is wrong
set @country = 3;
call star_case(@country, @starPrivilage); # error
select @country, @starPrivilage;

set @country = 3;
call star(@country, @starPrivilage);
select @country, @starPrivilage;

# loop in stored procedure
delimiter $$
create procedure DemoNumbers()
begin
	declare n int default 1;
    declare str varchar(100) default '';
    
    num_loop: loop
		if n > 10 then
			leave num_loop;
		end if;
		
		set str = concat(str, n, '');
		set n = n + 1;
	end loop num_loop;
    select str as numbers;
end$$
delimiter ;

call DemoNumbers();

delimiter $$
create procedure LoopActors()
begin
	declare id int default 1;
    declare fullname varchar(500) default '';
    
    actor_loop: loop
    
    if id > 20 then
		leave actor_loop;
	end if;
    
    if (select last_name from actor where actor_id = id) like 'A%' then
		set id = id + 1;
        iterate actor_loop;
	end if;
    
    set fullname = concat(
		fullname,
        (select concat(first_name, '', last_name)
        from actor where actor_id = id)
        
	);
    
    set id = id + 1;
end loop actor_loop;
select fullname as actors_list;
end$$
delimiter ;

# while loop
create table calendars(
	id int auto_increment,
    fulldate date unique,
    day tinyint not null,
    month tinyint not null,
    quarter tinyint not null,
    year int not null,
    primary key(id)
    );
    
delimiter $$
create procedure InsertCalendar(dt date)
begin
	insert into calendars(
    fulldate, day, month, quarter, year)
    values(dt, extract(day from dt), extract(month from dt), extract(quarter from dt),
    extract(year from dt)
    );
end$$
delimiter ;

delimiter $$
create procedure LoadCalendars(
	startDate date, day int
)
begin
	declare counter int default 1;
    declare dt date default startDate;
    
    while counter <= day do
		call InsertCalendar(dt);
        set counter = counter + 1;
        set dt = date_add(dt, interval 1 day);
	end while;
    
end$$
delimiter ;

select * from calendars;

# exercise
delimiter $$
create procedure CountCustomerByStore(
in storeID int, inout customerCount int
)
begin
	declare totalCust int;
    select count(*) into totalCust from customer where store_id = storeID;
    set customerCount = totalCust;
    
end$$
delimiter ;    

set @myCount = 0;
call CountCustomerByStore(1, @myCount);
select @myCount;

# stored function
delimiter $$
create function CustomerLevel(
	credit decimal(10,2)
)
returns varchar(20)
deterministic
begin
	declare customerLevel varchar(20);
    
    if credit > 50000 then
		set customerLevel = 'PLATINUM';
	elseif (credit <= 50000 and credit >= 1000) then
		set customerLevel = 'GOLD';
    elseif credit > 1000 then
		set customerLevel = 'SILVER';
	end if;
		return (customerLevel);
end$$
delimiter ;

use classicmodels;
select customerName, CustomerLevel(creditLimit) from customers order by customerName;

delimiter $$
create function CountOrdersByCustomer(custNo int)
returns int
deterministic
begin
	declare totalOrders int;
    select count(*) into totalOrders from orders where customerNumber = custNo;
    return totalOrders;
end$$
delimiter ;

select customerNumber, customerName, CountOrdersByCustomer(customerNumber) 
as 'Total Orders' from customers order by customerNumber;
