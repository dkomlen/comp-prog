#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        int x, y, d = -1; cin >> x >> y;
        if (x == y) d = (x % 2) ? 1 : 0;
        if (x - y == 2) d = (x % 2) ? 3 : 2;
        if (d < 0 || x < 0 || y < 0 || x > 10000 || y > 10000) cout << "No Number" << endl;
        else cout << 2 * x - d << endl;
    }  
    return 0;
}