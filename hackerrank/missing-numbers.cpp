#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int n; cin >> n;
    map<int, int> mp;
    while(n--){
        int x; cin >> x;
        if (mp.find(x) == mp.end()) mp[x] = 1;
        else mp[x]++;
    }
    cin >> n;
    vector<int> sol;
    while(n--){
        int x; cin >> x;
        if (mp.find(x) != mp.end()){
            mp[x]--;
            if (mp[x] == -1) sol.push_back(x);
        } else {
            sol.push_back(x);
            mp[x] = -2;
        }
    }
    sort(sol.begin(), sol.end());
    for (int i = 0; i < sol.size(); ++i) cout << sol[i] << " ";
    cout << endl;
    return 0;
}