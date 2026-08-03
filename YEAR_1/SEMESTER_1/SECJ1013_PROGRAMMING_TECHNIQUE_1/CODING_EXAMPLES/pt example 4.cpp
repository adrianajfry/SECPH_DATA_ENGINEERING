#include <iostream>
using namespace std;

struct Tenants {
		int lotNumber;
		char lotStatus;
		string tenantName;
		string phoneNum;
		double lotLength;
		double lotWidth;
		double rentalRate;
		double mthlyRent;
	};
	
	int main() {
    Tenants tenant[3];
	
	tenant[0].lotNumber = 2317;
    tenant[0].lotStatus = 'P';
    tenant[0].tenantName = "Shafie Afdal";
    tenant[0].phoneNum = "0173323477";
    tenant[0].lotLength = 12;
    tenant[0].lotWidth = 15;
    tenant[0].rentalRate = 2.5;
    tenant[0].mthlyRent = tenant[0].lotLength * tenant[0].lotWidth * tenant[0].rentalRate;	
    
    tenant[1].lotNumber = 1224;
    tenant[1].lotStatus = 'O';
    tenant[1].tenantName = "Linda Malek";
    tenant[1].phoneNum = "0113211212";
    tenant[1].lotLength = 5;
    tenant[1].lotWidth = 12;
    tenant[1].rentalRate = 3.0;
    tenant[1].mthlyRent = tenant[1].lotLength * tenant[1].lotWidth * tenant[1].rentalRate;	
    
    cout << "Enter information for Ordinary Tenant:\n";
    cout << "Lot Number: ";
    cin >> tenant[2].lotNumber;

    cout << "Tenant Name: ";
    cin.ignore(); // Ignore any newline character in the input buffer
    getline(cin, tenant[2].tenantName);

    cout << "Phone Number: ";
    cin >> tenant[2].phoneNum;

    cout << "Lot Length: ";
    cin >> tenant[2].lotLength;

    cout << "Lot Width: ";
    cin >> tenant[2].lotWidth;

    cout << "Rental Rate: ";
    cin >> tenant[2].rentalRate;

    tenant[2].mthlyRent = tenant[2].lotLength * tenant[2].lotWidth * tenant[2].rentalRate;

    // Display the information for each tenant
    for (int i = 0; i < 3; i++) {
        cout << "Tenant " << i + 1 << " Information:\n";
        cout << "Lot Number: " << tenant[i].lotNumber << endl;
        cout << "Lot Status: O " << endl;
        cout << "Tenant Name: " << tenant[i].tenantName << endl;
        cout << "Phone Number: " << tenant[i].phoneNum << endl;
        cout << "Lot Length: " << tenant[i].lotLength << " meters" << endl;
        cout << "Lot Width: " << tenant[i].lotWidth << " meters" << endl;
        cout << "Rental Rate: $" << tenant[i].rentalRate << " per square meter" << endl;
        cout << "Monthly Rent: $" << tenant[i].mthlyRent << "\n\n";
    }

    return 0;
}


