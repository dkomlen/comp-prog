#include <iostream>
#include <cmath>
using namespace std;
#define ll long long int

int main() {
    int n; cin >> n;
    while (n--){
        int k; cin >> k;
        ll sol1 = 0, sol2 = 0, max_val, sm;
        bool start = true;
        while (k--){
            ll x; cin >> x;
            if (x > 0) sol2 += x;
            if (start) {
                max_val = x;
                start = false;
                sm = x;
            } else {
                if (sm + x < 0) sm = 0;
                else sm += x;
                sol1 = max(sol1, sm);                
                max_val = max(max_val, x);               
            }
        }
        cout << (sol1 > 0 ? sol1 : max_val) << " " << (sol2 > 0 ? sol2 : max_val) << endl;
    }
    return 0;
}