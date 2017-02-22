#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>

#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

#define fi(it, v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define fit(v) fi(it, v)
#define f(i,s,n) for(int i = s; i < (n); ++i)
#define all(v) (v).begin(), (v).end()

#define fs first
#define sc second
#define mp make_pair
#define pb push_back

#define ll long long int
#define vi vector<int>
#define vii vector<vi >

#define trace(x) cout << #x << " = " << x << endl;
using namespace std;

int main() {
    int t; cin >> t;
    f(i,0,t){
        int k,n,c,m,sol=0; cin >> n>>c >>m;
        k = n /c;
        sol = k;
        while (k / m >= 1){
            int x = k / m;
            k %= m;
            sol += x;
            k += x;
        }
        cout << sol << endl;
    }
    
    return 0;
}