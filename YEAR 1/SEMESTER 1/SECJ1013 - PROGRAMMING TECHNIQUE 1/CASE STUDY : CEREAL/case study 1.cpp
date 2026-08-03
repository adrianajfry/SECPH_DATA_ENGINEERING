/* Group member :
1. DAMIYA AINA BINTI BASIR ABD SHAMAD (A23CS0220)
2. NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)
3. LUBNA AL HAANI BINTI RADZUAN (A23CS0107)

Date :
21 January 2024*/

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

void calconvert(float carbo[], float protein[], float fat[]);
void calDV(float carboDV[], float proteinDV[], float fatDV[]);
void category(float carboDV[], float proteinDV[], float fatDV[], string level_carbo[], string level_protein[], string level_fat[]);
string categoryAVG(float);
int main()
{
	fstream infile("inputcereal.txt", ios::in );
	fstream outfile("outputcereal.txt", ios::out);
	string cerealname[10];
	char cerealtype[10];
	float carbo[10], protein[10], fat[10];
	float carboDV[10], proteinDV[10], fatDV[10];
	int nutrientchoice,level,num = 1;
	float total_carbo = 0, total_protein = 0, total_fat = 0;
	float average_carbo, average_protein, average_fat;
	string level_carbo[10], level_protein[10], level_fat[10];
	char choice;
	string level_avgcarb, level_avgpro, level_avgfat;
	
	if(!infile)
	{
		cout<<"ERROR: Cannot open file\n";
		exit(1);
	} for(int i=0; i<10; i++) {
		infile>>cerealname[i]>>cerealtype[i]>>carbo[i]>>protein[i]>>fat[i];
	}
	
	do {
		cout<<"1.Carbohydrate\n2.Protein\n3.Fat\n";
		cout<<"Please enter your choice>> ";
		cin>>nutrientchoice;
		cout<<"\n1.Low\n2.Moderate\n3.High\n";
		cout<<"Please enter your choice>> ";
		cin>>level;
		cout<<endl;
	
		calconvert(carbo, protein, fat);
	
		for(int i=0; i<10;i++) {
		  carboDV[i]=carbo[i];
		  proteinDV[i]=protein[i];
		  fatDV[i]=fat[i];
		}
	
		calDV( carboDV, proteinDV, fatDV);
		category(carboDV, proteinDV, fatDV, level_carbo, level_protein, level_fat);
	
		for(int i=0; i<10;i++) {
			total_carbo = total_carbo + carboDV[i];
			total_protein = total_protein + proteinDV[i];
			total_fat = total_fat + fatDV[i];
		}
	
		average_carbo = total_carbo / 10;
		average_protein = total_protein / 10;
		average_fat = total_fat / 10;
	
		if(nutrientchoice==1) {
			if(level == 1)
			{
				cout<<"List of cereal with low amount of carbohydrate:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "Low") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}
			}
			if(level == 2) {
				cout<<"List of cereal with moderate amount of carbohydrate:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "Moderate") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}
			}
			if(level == 3) {
				cout<<"List of cereal with high amount of carbohydrate:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "High") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}	
				}
			}
		}
		
		if(nutrientchoice==2) {
			if(level == 1) {
				cout<<"List of cereal with low amount of protein:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "Low") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}
			}
			if(level == 2) {
				cout<<"List of cereal with moderate amount of protein:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "Moderate") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}
			}
			if(level == 3) {
				cout<<"List of cereal with high amount of protein:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "High") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}	
			}
		}
		if(nutrientchoice==3) {
			if(level == 1) {
				cout<<"List of cereal with low amount of fat:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "Low") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}
			}
			if(level == 2) {
				cout<<"List of cereal with moderate amount of fat:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "Moderate") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}
			}
			if(level == 3) {
				cout<<"List of cereal with high amount of fat:\n";
				for(int i=0 ; i<10; i++) {
					if(level_carbo[i] == "High") {
						cout<<num<<". Cereal "<<cerealtype[i]<<endl;
						num++;
					}
				}
			}
		 	level_avgcarb = categoryAVG(average_carbo);
			level_avgpro = categoryAVG(average_protein);
			level_avgfat = categoryAVG(average_fat);
		}
		cout<<"Choose again? Y/N >> ";
		cin>>choice;
	} while((choice == 'Y')||(choice == 'y'));
	
	outfile<<"Type\t\tCarbohydrate\t\t Protein\t\t   Fat\n";
	outfile<<"========\t============\t\t =======\t\t   ===\n";
	for(int i=0;i<10;i++) {
		outfile<<"Cereal "<<cerealtype[i]<<"\t";
		if (level_carbo[i] == "Moderate")
		outfile<<fixed<<setprecision(2)<<setw(5)<<carboDV[i]<<"%("<<level_carbo[i]<<left<<setw(10)<<")";
	    else if (level_carbo[i] == "Low")
		outfile<<fixed<<setprecision(2)<<setw(5)<<carboDV[i]<<"%("<<level_carbo[i]<<left<<setw(15)<<")";
		else
		outfile<<fixed<<setprecision(2)<<setw(5)<<carboDV[i]<<"%("<<level_carbo[i]<<left<<setw(14)<<")";
		
		if(level_protein[i] == "Moderate") {
			outfile<<setw(5)<<proteinDV[i]<<"%("<<level_protein[i]<<left<<setw(10)<<")";
		} else if(level_protein[i] == "Low") {
			outfile<<setw(5)<<proteinDV[i]<<"%("<<level_protein[i]<<left<<setw(15)<<")";
	    } else {
			outfile<<setw(5)<<proteinDV[i]<<"%("<<level_protein[i]<<left<<setw(14)<<")";
	    }
			outfile<<fatDV[i]<<"%("<<level_fat[i]<<")\n";
	}
	outfile<<"The ten cereal types produce an average %DV of:\n";
	outfile<<"Carbohydrate: "<<average_carbo<<"%("<<level_avgcarb<<")\n";
	outfile<<"Protein: "<<average_protein<<"%("<<level_avgpro<<")\n";
	outfile<<"Fat: "<<average_fat<<"%("<<level_avgfat<<")\n";

	infile.close();
	outfile.close();
	
	return 0;
}

void calconvert(float carbo[], float protein[], float fat[]) {
	for(int i=0; i<10; i++) {
		carbo[i] = carbo[i]*28.35;
		protein[i] = protein[i]*28.35;
		fat[i] = fat[i]*28.35;
	}
}

void calDV(float carboDV[], float proteinDV[], float fatDV[]) {
    for(int i = 0; i < 10; i++) {
        carboDV[i] = carboDV[i] / 300 * 100;
        proteinDV[i] = proteinDV[i] / 50 * 100;
        fatDV[i] = fatDV[i] / 65 * 100;
    }
}

void category(float carboDV[], float proteinDV[], float fatDV[], string level_carbo[], string level_protein[], string level_fat[]) {
    for(int i=0; i<10; i++) {
        if (carboDV[i] <= 5)
            level_carbo[i] = "Low";
        else if ((carboDV[i] > 5) && (carboDV[i] < 20))
            level_carbo[i] = "Moderate";
        else
            level_carbo[i] = "High";
    }

    for(int i=0; i<10; i++) {
        if (proteinDV[i] <= 5)
            level_protein[i] = "Low";
        else if ((proteinDV[i] > 5) && (proteinDV[i] < 20))
            level_protein[i] = "Moderate";
        else
            level_protein[i] = "High";
    }

    for(int i=0; i<10; i++) {
        if (fatDV[i] <= 5)
            level_fat[i] = "Low";
        else if ((fatDV[i] > 5) && (fatDV[i] < 20))
            level_fat[i] = "Moderate";
        else
            level_fat[i] = "High";
    }
}

string categoryAVG(float avg) {	
	string level;
	
	if (avg <= 5)
		level= "Low";
		
	else if ((avg > 5) && (avg < 20))
		level = "Moderate";
		
	else 
		level= "High";
		
	return level;
}
