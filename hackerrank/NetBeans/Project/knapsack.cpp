#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n,k; cin >> n >> k;
        
        vector<int>  v;
        vector<int> dp;
        dp.push_back(0);
        
        for (int i = 0; i < n; ++i) {
            int a; cin >> a; v.push_back(a);
        }
        for (int i = 1; i <= k; ++i) {
            int dif = k;
            for (int j = 0; j < n; j++) {
                if (i - v[j] < 0) continue;
                dif = min(dif, k - dp[i-v[j]] - v[j]);
            }
            dp.push_back(k - dif);
        }
        cout << dp[dp.size() - 1] << endl;
    }
    return 0;
}
