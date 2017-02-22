#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    vector<int> v;
    while(n--){
        int x; cin >> x;
        v.push_back(x);        
    }
    sort(v.begin(), v.end());
    int sol = -1;
    for (int i = k-1; i < v.size(); ++i){
        int d = v[i] - v[i-k+1];
        if (sol < 0 || sol > d)
            sol = d;
    }
    cout << sol << endl;
    return 0;
}
