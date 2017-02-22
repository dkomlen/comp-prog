#include <iostream>
using namespace std;

void sol(int i, bool ok){
    cout << "Case #" << i << ": " << (ok ? "GABRIEL" : "RICHARD") << endl;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x,r,c; cin >> x >> r >> c;
        if (x == 1) sol(i,true);
        if (x == 2){
            if ((r * c) % 2 != 0) sol(i, false);
            else if (r == 1 || c == 1) sol(i, false);
            else sol(i, true);
        }
        if (x == 3){
            if ((r * c) % 3 != 0) sol(i, false);
            else if (r * c == 6) sol(i, true);
            else sol(i, false);
        }
        if (x == 4){
            if ((r * c) % 4 != 0) sol(i, false);
            else if (r < 4 || c < 4) sol(i, false);
            else sol(i, true);
        }
        
    }
    return 0;
}
