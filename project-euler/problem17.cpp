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

"one","two","three","four","five","six","seven","eight","nine"



int one(int x) {
 
}
int ten(int x){
    
        switch(x){
        case 1: return 3; //ten  
        case 2: return 3; //eleven
        case 3: return 5; //tw
        case 4: return 4; //four
        case 5: return 3; //five
        case 6: return 3; //six
        case 7: return 5; //seven
        case 8: return 5; //eight
        case 9: return 4; //nine
    } 
}

int hundred(int x){
    
    return one(x) + 7;   
}

int main(){
    
}
