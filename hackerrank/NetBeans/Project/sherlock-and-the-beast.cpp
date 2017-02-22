#include <iostream>
using namespace std;

void p(int x, int k) { while(x--) cout << k; }

int main() {
    int n; cin >> n;
    while (n--) {
        int x, y = 0; cin >> x;
        while (x >= 0 && x % 3 != 0) { x-=5; y += 5; }
        if (x < 0) { cout << -1 << endl; continue; }
        p(x, 5);
        p(y, 3);
        cout << endl;
    }
    return 0;
}
