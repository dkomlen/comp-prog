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
        int n,k,p,s,sol; cin >> n>>k; sol = n;
        vi v; vi ok(n,1);
        f(j,0,n){
            int x; cin >> x;
            f(z,0,v.size()){
                if (ok[z] && abs(v[z]-x) >= k){
                    ok[z] = 0;
                    sol--;
                    break;
                }
            }
            v.pb(x);
        }
        cout << sol << endl;
    }
    return 0;
}