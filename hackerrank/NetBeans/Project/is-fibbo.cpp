#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

#define ll unsigned long long int

int main() {
    int n; cin >> n;
    unordered_set<ll> s;
    
    ll a = 0, b = 1;
    s.insert(a);
    while (b <= 10000000000) {
        s.insert(b);
        ll t = a + b;
        a = b;
        b = t;
    }
    
    while(n--) {
        ll x; cin >> x;
        if (x < 0 || s.find(x) == s.end()) cout << "IsNotFibo" << endl;
        else cout << "IsFibo" << endl;
    }
    return 0;
}
