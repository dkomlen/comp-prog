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
#define f(i,a,n) for(int i = a; i < (n); ++i)

#define fs first
#define sc second
#define mp make_pair

#define all(v) (v).begin(), (v).end()
#define ll long long int
#define vi vector<int>
#define vii vector<vi >
using namespace std;

int x[28123+ 10] = {0};

int main(){
    
    ll n = 28123;
    vi ab;
    f(i,1,n){ 
        int sum = 0;
        
        for(int j = 1; j < i; ++j){
            if (i % j == 0) sum += j;
        }
        
        if (sum > i) ab.pb(i);
        
    }
    cout << ab.size() << endl;
    fi(i,ab){
        fi(j,ab){
            if (*i + *j <= n) x[*i + *j] = 1;
        }   
    }
    ll sum = 0;
    f(i,28100,28123) cout << i << ":" << x[i] << " ";
    f(i,0,n+1) if(x[i] == 0) { sum += i; }
    cout << sum << endl;
    getchar();
    return 0;   
}
