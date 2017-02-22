#include <iostream>
using namespace std;
#define ll long long int
int main() {
    int n; cin >> n;
    while (n--){
        ll x; cin >> x;
        ll a = (x - 1) / 2;
        ll sol = a * (a + 1);
        if (x % 2 == 0) sol += x / 2;
        cout << sol << endl;  
//        1 2 3 4 5 6 
//        0 1 1 2 2 3 
    }
    return 0;
}
