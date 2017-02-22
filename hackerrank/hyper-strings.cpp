#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

#define ll long long int
const ll M = 1000000007L;

bool check(string s, set<string> vs){
    string k = "";
    for (int i = 0; i < s.size(); ++i) {
        k += s[i];
        bool ok = vs.find(k) != vs.end();
        if (ok && i == s.size()-1) return true;
        if (ok && check(s.substr(i+1), vs)) return true;
   }
   return false;
}

vector<string> filter(vector<string> vs){
    vector<string> ret;
    set<string> ss(vs.begin(), vs.end());
    for (int i = 0; i < vs.size(); ++i){
        ss.erase(vs[i]);
        if (!check(vs[i], ss)) ret.push_back(vs[i]);
        ss.insert(vs[i]);
    }
    return ret;
}

int main(){
    int n, m; cin >> n >> m;
    map<int, int> mp;
    vector<int> v;
    vector<string> vs;
    while (n--){
        string s; cin >> s; vs.push_back(s);
    }
    
    vs = filter(vs);
    for (int i = 0; i < vs.size(); ++i){
        int k = vs[i].size();
        if (mp.find(k) == mp.end()) { mp[k] = 1; v.push_back(k); }
        else mp[k]++;
    }
    
    vector<ll> dp(110, 0);
    dp[0] = 1;
    for (int i = 1; i <= m; ++i){
        for (int j = 0; j < v.size(); ++j){
            if (i - v[j] >= 0) {
                dp[i] += (dp[i-v[j]] * mp[v[j]]) % M;
                dp[i] %= M;
            }
        }        
    }
    ll sol = 0;
    for (int i = 0; i <= m; ++i){
        sol += dp[i]; 
        sol %= M;
    }
    cout << sol << endl;
    return 0;
}