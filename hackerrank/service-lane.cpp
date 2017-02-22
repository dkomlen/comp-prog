#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int n,t; cin >> n >> t;
    vector<int> v(100000,0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v[i] = x;
    }
    
    while (t--) {
        int a,b; cin >> a >> b;
        int sol = 3;
        for (int i = a; i <= b; i++) {
            sol = min(sol, v[i]);
        }
        cout << sol << endl;
    }
    return 0;
}