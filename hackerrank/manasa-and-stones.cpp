#include <iostream>
using namespace std;

int main() {

    int t; cin >> t;
    while (t--){
        int n,a,b,t; cin >> n >> a >> b; n--;
        if (b < a) {
            t = a; a = b; b = t;
        }
        for (int i = 0; i <= n; ++i) {
            cout << i * b + (n - i) * a << " ";
            if (a == b) break;
        }
        cout << endl;
    }

    return 0;
}
