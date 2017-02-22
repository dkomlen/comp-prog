#include <iostream>
using namespace std;
#define ll unsigned long long int

int main() {
    int n; cin >> n;
    while (n--) {
        ll i=1,x=1,a,b; cin >> a >> b;
        int sol = 0;
        while (x < b) {
            x = i*i;
            if (x >= a && x <= b) sol++;
            i++;
        }
        cout << sol << endl;
    }
    return 0;
}
