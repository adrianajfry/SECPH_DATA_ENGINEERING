/* Group member :
1. DAMIYA AINA BINTI BASIR ABD SHAMAD (A23CS0220)
2. NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)
3. LUBNA AL HAANI BINTI RADZUAN (A23CS0107)

Date :
21 January 2024*/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

//Function prototype list
int readFile(const char*, float[][12], string[], int);
int change(float[][12],int);
float grandTotalSales(float[][12], int);
float highestSale(float[][12], string[], string[], int, int&, int&);
float lowestSale(float[][12], string[], string[], int, int&, int&);
float totalMonthly(float[][12], int, int);
int totalStores(float[][12], float[], int);

int main()
{
	const int row = 5, col = 12;
	int h1 = 0, h2 = 0, l1 = 0, l2 = 0;
	float sales[row][col], storeAnn[5];
	string store[row];
	string month[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	
	const char* file = "sales2014.dat";
	const char* ofile = "Report Sales.txt";
	
	int read = readFile(file, sales, store, row); // Read input from file
	
	int changes = change(sales,row); // Change all input to real value
	
	float total = grandTotalSales(sales, row); // Calculate grand total
	float avg = total / 12.0; // Calculate average of company annual sales
	
	float highest = highestSale(sales, store, month, row, h1, h2); // Find the highest monthly sales
	
	float lowest = lowestSale(sales, store, month, row, l1, l2); // Find the lowest monthly sales
	
	int totalS = totalStores(sales, storeAnn, row); // Calculate total sales for each store
	
	
	fstream outfile(ofile, ios::out); // Opening output file
	// Check output file can be opened or not
	if (!outfile)
		cout << "Error in opening output file" << endl;
	else
		cout << "Output file is opened successfully" << endl; 
	
	// Output for grand total and average
	outfile << "Total of sales over all stores : RM ";
	outfile << right << setw(10);
	outfile << fixed << setprecision(2) << total << endl;
	outfile << "Average sale per month : RM ";
	outfile << right << setw(10);
	outfile << fixed << setprecision(2) << avg << endl;
	
	// Output for the highest monthly sales
	outfile << "\nThe highest sales :" << endl;
	outfile << "-------------------" << endl;
	outfile << "Store : " << store[h1] << endl;
	outfile << "Month : " << month[h2] << endl;
	outfile << "Sales : RM " << fixed << setprecision(2) << right << setw(10) << highest << endl;
	
	// Output for the lowest monthly sales
	outfile << "\nThe lowest sales :" << endl;
	outfile << "-------------------" << endl;
	outfile << "Store : " << store[l1] << endl;
	outfile << "Month : " << month[l2] << endl;
	outfile << "Sales : RM " << fixed << setprecision(2) << right << setw(10) << lowest << endl;
	
	// Output for total sales for each month 
	outfile << "\n\nTotal sales by month :" << endl << "Month" << setw(10) << "Sales" << endl << "-----" << setw(10) << "-----" << endl;
	outfile << right;
	for (int x = 0; x < 12; x++)
	{
		outfile << month[x] << "   RM " << fixed << setprecision(2) << setw(10) << totalMonthly(sales, x, row) << endl;
	}
	
	// Output for the total annual sales for each store 
	outfile << "\nTotal sales by store :" << endl << "Store" << setw(21) << "Total Sales" << endl << "-----" << setw(21) << "-----------" << endl;
	for (int x = 0; x < row; x++)
	{
		outfile << left;
		outfile << setw(14) << store[x] << "RM";
		outfile << right;
		outfile << setw(10) << fixed << setprecision(2) << storeAnn[x] << endl;
	}
	
	// Output for the profitable stores
	outfile << "\nProfitable stores :" << endl << "-----------------" << endl;
	for (int x = 0; x < row; x++)
	{
		if (storeAnn[x] >= 600000)
			outfile << store[x] << endl;
	}
	
	outfile.close(); // Closing the output file
	
	return 0;
}

// Function to read input from input file
int readFile(const char* file, float sales[][12],string store[],int row)
{
	fstream infile(file, ios::in);
	
	if (!infile)
		cout << "Error in opening input file" << endl;
	else
		cout << "Input file is opened successfully" << endl; 

	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y< 12; y++)
		{
			infile >> sales[x][y];
		}
		getline(infile >> ws, store[x]);
	}
	
	infile.close();
	return row;
}

// Function to change each cell to real value(multiple of 1000)
int change(float sales[][12], int row)
{
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			sales[x][y] = sales[x][y] * 1000.0;
		}
	}
	return row;
}

// Function to calculate the grand total
float grandTotalSales(float sales[][12], int row)
{
	float total = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			total += sales[x][y];
		}
	}
	return total;
}

// Function to find the highest sales 
float highestSale(float sales[][12], string store[], string month[], int row, int &n, int &c)
{	
	float high = 0;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			if (sales[x][y] >= high)
			{
				high = sales[x][y];
				n = x;
				c = y;
			}
		}
	}
	return high;
}

// Function to find the lowest sales
float lowestSale(float sales[][12], string store[], string month[], int row, int &i, int &j)
{
	float low = 9999999999;
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			if (sales[x][y] <= low)
			{
				low = sales[x][y];
				i = x;
				j = y;
			}
		}
	}
	return low;
}

// Function to calculate total monthly sales for each month
float totalMonthly (float sales[][12], int x, int row)
{
	float total = 0;
	for (int y = 0; y < row; y++)
	{
		total += sales[y][x];
	}
	return total;
}

// Function to calculate total annual sales for each store
int totalStores(float sales[][12], float storeAnn[], int row)
{
	for (int x = 0; x < row; x++)
	{
		for (int y = 0; y < 12; y++)
		{
			storeAnn[x] += sales[x][y];
		}
	}
	return row;
}

