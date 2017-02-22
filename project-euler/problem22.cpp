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

int main(){

    ll res = 0;
    int n = 0;
    string s;
    vector<string> vs;

    while(s != "000"){
        cin >> s;
        n++;
        vs.pb(s);
    }
    cout << n<<endl;

    sort(all(vs));

    f(i,n){


        int x = 0;
        fit(vs[i])  x += *it -'A' + 1;
        res += x*i;
    }
    cout << res << endl;

}
