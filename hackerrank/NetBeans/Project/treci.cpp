//#include "stdafx.h" !!! OVO ODKOMENTIRAJ !!!
#include<iostream>
#include <cstring>
#define red 10
#define znak 50
using namespace std;

int main() //!!! int zamijeni za void !!!
{
	char azili[red][znak], AZIL[znak];
	int i, j, n, najdulji=0, rijeci;
	cout<<"Upisite broj azila: ";
	cin>>n;
	cin.ignore();
	cout<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"Upisite naziv "<<i+1<<". azila: ";
		cin.getline(azili[i], znak);
	}
	
        //Trazenje azila sa najvise rijeci
        for (i=0; i < n; ++i) { //Idemo za svaki azil
            
            for (j=0; azili[i][j] != '\0'; j++) { // Petlja za svako slovo u azilu
                    rijeci = 1;
                    if(azili[i][j]==' ') //Ako je znak razmak uvecaj broj rijeci za 1
                    {
                        rijeci += 1;
                    }
            }   
            if (rijeci > najdulji) { //Ako smo nasli azil sa najvise rijeci do sad, kopiraj ga u AZIL
                najdulji = rijeci;
                strcpy(AZIL, azili[i]);
            }
        }
        
        rijeci = 1; //Pocinjemo brojati od 1. rijeci
        //Pretvaranje slova u velika
        for (i=0; AZIL[i] != '\0'; i++) { //Idemo za svaki znak
            
            if (AZIL[i] == ' ') { //Kad naidemo na razmak znaci da smo nasli pocetak iduce rijeci, pa uvecavamo brojac
                rijeci += 1;
                if(rijeci == 4) {
                    AZIL[i+2]=toupper(AZIL[i+2]); //Drugo slovo pretvaramo u veliko
                }
                if(rijeci==5) {
                    AZIL[i-2]=toupper(AZIL[i-2]); //Predzadnje slovo pretvaramo u veliko
                }
            }
        }
        
	cout << "Azil s najvise rijeci (s pretvornim slovima): " << AZIL << endl;
}