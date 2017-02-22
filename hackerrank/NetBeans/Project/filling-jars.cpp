#include <iostream>
using namespace std;

#define ll unsigned long long int

int main() {
    ll n,m; cin >> n >> m;
    ll s = 0;
    while (m--) {
        ll a,b,k; cin >> a >> b >> k;
        s += (b-a+1) * k;
    }
    cout << s / n << endl;
    return 0;
}
