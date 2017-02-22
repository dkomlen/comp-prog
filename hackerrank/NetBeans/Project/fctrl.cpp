#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--){
        int x, y = 5; cin >> x; 
        int sol = 0;
        while (x >= y){
            sol += x / y;
            y *= 5;
        }
        cout << sol << endl;
    }
    return 0;
}
