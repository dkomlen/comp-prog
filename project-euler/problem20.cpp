
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>

#include <string>
#include <iostream>
#include <sstream>
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

typedef vector<char> bint;

string conv(bint b){
   string ret;
   for(int i = b.size()-1; i >= 0; --i) ret.pb(b[i] + '0');
    return ret;
}

bint conv(string s){
    bint ret;
    for(int i = s.size()-1; i >= 0; --i) ret.pb(s[i] - '0');
    return ret;
}

char get(bint x, int i){
    if (i >= x.size()) return 0;
    else return x[i];
}


bint add(bint x, bint y){

    bint ret;
    char c = 0;
    f(i, max(x.size(),y.size())){
        char rez = c + get(x,i) + get(y,i);
        ret.pb(rez%10);
        c = rez/10;

    }
    if (c > 0) ret.pb(c);
    return ret;
}
bint mul(bint x, bint y){

    bint ret;
    for(int i = y.size()-1; i >= 0;--i) {
        bint z;
        char c = 0;
        fi(j,x){
            char rez = (*j)*y[i] + c;
            z.pb(rez%10);
            c = rez/10;
        }
        if (c > 0) z.pb(c);
        if (ret.size() == 0) ret = z;
        else {
            ret.insert(ret.begin(),0);
            ret = add(ret,z);
        }

    }
    return ret;
}

int main() {

    bint rez = conv("1");
    for (int i = 2; i <= 1000; ++i){
        string s;
        stringstream out;
        out << i; s = out.str();
        rez = mul(rez, conv(s));
    }
    cout << conv(rez) << endl;
    int ret = 0;
    fit(rez) ret+=*it;
    cout << ret << endl;

    getchar();
    getchar();
 return 0;
}
