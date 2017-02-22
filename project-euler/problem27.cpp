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

ll fun(ll n,int a,int b){
    return n*(n+a)+b;
}

bool isp(ll x) {
    x = abs(x);
    for (ll i = 2; i*i < x; ++i){
        if (x%i == 0) return false;
    }
    return true;
}

int main(){

    int max = 0, sol;
    f(a,-999,1000) {
        f(b,-999,1000) {
           ll n = 0;
           if (b % 2 == 0 || b % 3 == 0) continue;

           while(isp(fun(n,a,b))) n++;
           if (n > max) {
                sol = a*b;
                max = n;
                cout << a << " " << b << " " << n << endl;
            }
        }
    }
    cout << sol << endl;
    getchar();
    return 0;
}
