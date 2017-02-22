#include <iostream>
using namespace std;
#define ll long long int
const ll MOD = 1000000007;

int main(){
    ll n; cin >> n;
    while(n--){
        ll h,w; cin >> h >> w;
        ll dp[2001] = {0}, all[2001] = {0}, all_h[2001] = {0};

        all[1] = 1; all[2] = 2;
        all[3] = 4; all[4] = 8;
        for (int i = 5; i <= w; ++i){
            for (int j = 1; j <= 4; ++j) {
                all[i] += all[i-j];
                all[i] %= MOD;
            }
        }

        for (int i = 1; i <= w; ++i){
            all_h[i] = 1;
            for (int j = 1; j <= h; ++j){
                all_h[i] *= all[i];
                all_h[i] %= MOD;
            }
        }

        dp[1] = 1;
        for (int i = 2; i <= w; ++i){
            dp[i] = all_h[i];
            for (int j = 1; j < i; ++j){
                dp[i] -= (dp[j] * all_h[i-j]) % MOD;
                if (dp[i] < 0) dp[i] += MOD;
                //dp[i] %= MOD;
            }
        }
        cout << dp[w] % MOD << endl;
    }
    

    return 0;
}