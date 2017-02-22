#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int a,b,sol = 0; cin >> a >> b;

    for (int i = a; i <= b; ++i) {
        for (int j = i; j <= b; ++j) {
            sol = max(sol, i ^ j);            
        }
    }
    cout << sol << endl;

    return 0;
}
