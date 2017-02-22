#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int n; cin >> n;
    vector<int> v, sol;
    
    while(n--){
        int x; cin >> x; v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size()-1; ++i){
        
        bool ok = false;
        if (sol.size() == 0) ok = true;
        else {
            int a = abs(v[i] - v[i+1]), b = abs(sol[0] - sol[1]);
            if(a < b) {sol.clear(); ok = true;}
            else if (a == b) ok = true;
        }
        if (ok){
            sol.push_back(v[i]);
            sol.push_back(v[i+1]);
        }
    }
    for (int i = 0; i < sol.size(); ++i) cout << sol[i] << " ";
    cout << endl;
    return 0;
}