//#include "stdafx.h" !!! OVO ODKOMENTIRAJ !!!
#include<iostream>
#include <cstring>
#define red 10
#define znak 50
using namespace std;

int kdo(char AZIL[])
{
	int sum=0;
	for(int i=0; i<strlen(AZIL); i++)
		sum+=AZIL[i];
	return sum;
}
void nvb(int broj, int baza)
{
	if(broj>=baza)
		nvb(broj/baza, baza);
	if(broj%baza>=10)
		cout<<char(broj%baza+55);
	else
		cout<<broj%baza;
}

void din(int *H, int rijeci) {
        cout << endl << "Polje H je: " << endl;
        for (int i = 0; i < rijeci; i++)
                cout << *(H + i) << ' ';
}

int main() //!!! int zamijeni za void !!!
{
	char AS[red][znak], AZIL[znak];
	int i, j, n, najdulji=0, rijeci, razmak, slova, *H;
	cout<<"Upisite broj azila: ";
	cin>>n;
	cin.ignore();
	cout<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"Upisite naziv "<<i+1<<". azila: ";
		cin.getline(AS[i], znak);
	}
	
        //Trazenje azila sa najvise rijeci
        for (i=0; i < n; ++i) { //Idemo za svaki azil
            
            for (j=0; AS[i][j] != '\0'; j++) { // Petlja za svako slovo u azilu
                    rijeci = 1;
                    if(AS[i][j]==' ') //Ako je znak razmak uvecaj broj rijeci za 1
                    {
                        rijeci += 1;
                    }
            }   
            if (rijeci > najdulji) { //Ako smo nasli azil sa najvise rijeci do sad, kopiraj ga u AZIL
                najdulji = rijeci;
                strcpy(AZIL, AS[i]);
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
        
        //Dinamicko polje (zadatak 5.)
        H = new int[rijeci];
        slova = 0; //brojac slova u rijeci AZIL
        j = 0;
        
        for (i=0; AZIL[i] != '\0'; i++) {
            slova +=1;
            
            if (AZIL[i] == ' ') { //na kraju svake rijeci pohrani brojac u polje H
                *(H + j) = slova - 1; //-1 ide jer ne brojimo razmak
                j += 1;
                slova = 0; //ponisti brojac da mozemo brojati sljedecu rijec
            }
        }
        
        *(H + rijeci - 1) = slova; //pohranjivanje zadnje rijeci kad smo gotovi
        
        //Ispis svih azila
        cout << "Polje AS: " << endl;
        for (i=0; i < n; ++i) { 
            cout << AS[i] << endl;
        }
	cout << endl <<"Azil s najvise rijeci (s pretvornim slovima): " << AZIL << endl;
        cout<<endl<<"Suma ASCII kodova stringa '" << AZIL << "': " << endl << kdo(AZIL) << endl;
        
	cout<<"Ekvivalent s bazom 18: ";
        nvb(kdo(AZIL), 18);
        cout << endl;
        
        cout <<endl<< "Dinamicko polje H je ";
        din(H, rijeci);
}