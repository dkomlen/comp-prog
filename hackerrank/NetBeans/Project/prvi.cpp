//#include "stdafx.h" !!! OVO ODKOMENTIRAJ !!!
#include<iostream>
#include<string>

#define broj_azila 50
#define broj_pasmina 50

using namespace std;

int main(){ //!!! int zamijeni za void !!!

	int AP[broj_azila][broj_pasmina];
	int n,m,i,j;
	float PR[broj_pasmina]={0};
	//upis podataka
	cout<<endl<<"Unesite broj azila: ";
	cin>>n;
	cin.ignore();

	cout<<endl<<"Unesite broj pasmina: ";
	cin>>m;
	cin.ignore();
	// Upis broja pasa po azilima za danu pasminu (i,j) i zprajanje po pasminama u PR
	for(i=0; i<n; i++)
		for(j=0; j<m; j++){
			cout<<endl<<"Broj pasa za " << j+1 <<". pasminu "<<" u "<<i+1<<". azilu? "<<endl;
			cin>>AP[i][j];
			PR[j]+=AP[i][j];
		}

        //ISPIS PROSJECNO
	for(j=0;j<m; j++){
            PR[j]=PR[j]/n;
	    cout << endl << "Od " << j+1 << ". pasmine prosjecno po svim azilima ima " << PR[j] << " pasa" << endl;
	}
	//ISPIS ATLETIKA
	
	for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                    cout<<AP[i][j]<<"\t";}
            cout<<endl;
        }
        
	cout<<endl;
}