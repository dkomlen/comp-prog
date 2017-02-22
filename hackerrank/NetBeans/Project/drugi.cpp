//#include "stdafx.h" !!! OVO ODKOMENTIRAJ !!!
#include<iostream>
#include <cstring>
#define red 10
#define znak 50
using namespace std;

int main() //!!! int zamijeni za void !!!
{
	char azili[red][znak], AZIL[znak];
	int i, j, n, najdulji=0, razmak, rijeci;
	cout<<"Upisite broj azila: ";
	cin>>n;
	cin.ignore();
	cout<<endl;
	for(i=0; i<n; i++)
	{
		cout<<"Upisite naziv "<<i+1<<". azila: ";
		cin.getline(azili[i], znak);
	}
	razmak=0;
        for (i=0; i < n; ++i) {
            for (j=0; azili[i][j] != '\0'; j++) {
                    rijeci = 1;
                    if(azili[i][j]==' ')
                    {
                        rijeci += 1;
                    }
            }   
            if (rijeci > najdulji) {
                najdulji = rijeci;
                strcpy(AZIL, azili[i]);
            }
        }
	cout << "Azil s najvise rijeci: " << AZIL << endl;
}