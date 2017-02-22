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

int sum(int x){
 
    int ret = 0;
    for (int i = 1; i < x; ++i){
        
        if (x % i == 0) ret += i;
        
    }   
    return ret;
    
}

int main(){
    cout << sum(6) << " " << sum(496) << endl;
    int sol =0;
    for (int i = 1; i <= 10000; ++i){
           
        int x = sum(i);
        
        if (i == sum(x) && x != i) {
            cout << i << endl;
            sol+=i;
        }
        
    }
    cout << sol << endl;
    getchar();
}
