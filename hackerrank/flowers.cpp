#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int n, k; cin >> n >> k;
    vector<int> v, f(k,0);
    while(n--){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.rbegin(), v.rend());
    int j = 0, sol = 0;
    for (int i = 0; i < v.size(); ++i){
        sol += (f[j]++ + 1)*v[i];
        j = (j + 1) % k;
    }
    cout << sol;
    return 0;
}