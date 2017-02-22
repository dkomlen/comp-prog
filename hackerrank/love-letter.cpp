#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        int a = 0, b = s.size() - 1, sol = 0;
        while(a < b) {
            sol += abs(s[a]-s[b]);
            a++; b--;
        }
        cout << sol << endl;
    }

    return 0;
}
