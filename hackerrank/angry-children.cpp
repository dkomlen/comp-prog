#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {

    int n,k; cin >> n >> k;
    vector<int> v;
    while(n--) {
        int x; cin >> x; v.push_back(x);
    }
    sort(v.begin(), v.end());
    int a = 0, sol = v[k-1] - v[0];
    for (unsigned int b = k-1; b < v.size(); b++){
        sol = min(sol, v[b] - v[a++]);
    }
    cout << sol << endl;
    return 0;
}
