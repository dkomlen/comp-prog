 #include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#define pb push_back
#define fi(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define fit(v) fi(it, v)
#define f(i,n) for(int i = 0; i < (n); ++i)

#define fs first
#define sc second
#define mp make_pair

#define all(v) (v).begin(), (v).end()
#define ll long long int
#define vi vector<int>
#define vii vector<vi >
using namespace std;

bool leap(int year){
    if (year % 400 == 0) return true;
    else if (year % 100 == 0) return false;
    else if (year % 4 == 0) return true;
    return false;    
}

int month(int mon, int year){
     int months[12] = {31,leap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
     return months[mon-1];
}

int main() {

    

    int year = 1900;
    int mon = 1;
    int day = 1;
    int weekday = 0;
    int sol = 0;
    
    while(year <= 2000){
        cout << day << " ";
        int m = month(mon, year);
        day++;
        
        weekday++; weekday %= 7;
        if (day > m) {
            day = 1;
            mon++;
            cout << endl << mon<< ": ";
            if (mon > 12){
                mon = 1;
                year++;   
                cout << "year: " << year << endl;
            }
        }
        if (year >= 1901 && weekday == 6 && day == 1) sol++;
    }
    
    cout << sol << endl;
    getchar();
    return 0;   
}
