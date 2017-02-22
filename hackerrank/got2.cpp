#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define ll long long int
const ll M = 1000000007L;

ll fact(ll n){
    ll ret = n;
    if (n <= 1) return 1;
    while (--n) {ret *= n; ret %= M; }
    return ret;
}

ll pot(ll x, ll n){
    if (n == 0) return 1L;
    if (n == 1) return x;
    if (n % 2) return (pot(x,n-1) * x) % M;
    else {
        ll k = pot(x, n/2);
        return (k*k) % M;
    }
}

int main(){
    int odd = 0, pos;
    vector<int> v(100,0);
    string s; cin >> s;
    int n = s.size();
    
    for (int i = 0; i < n; ++i){
        int k = s[i] - 'a';
        v[k]++;
        if (v[k] % 2){ odd++; }
        else odd--;
    }
    if (odd > 1){
        cout << 0 << endl;
        return 0;
    }
    ll m = 1;
    for (int i = 0; i < v.size(); ++i){
        if (v[i] % 2) v[i]--;
        m *= fact(v[i]/2);
        m %= M;
    }
    cout << (fact(n/2) * pot(m, M-2)) % M << endl;
    return 0;
}