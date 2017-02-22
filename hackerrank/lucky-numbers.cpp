#include <iostream>
using namespace std;

#define ll unsigned long long int

const int MAX = 18;
const int MAX_S = 9*MAX;
const int MAX_SS = 9*MAX_S;
int prim[MAX_SS+1] = {0};
ll dp[MAX+1][MAX_S+1][MAX_SS+1] = {0};
ll bg[MAX+1][MAX_S+1], ed[MAX+1][MAX_S+1];
ll ch[10][MAX+1][MAX_S+1][MAX_SS+1] = {0};
bool is_prim(int x){ return prim[x] == 0; }

void erat() {
    prim[0] = 1;
    prim[1] = 1;
    for (int i = 2; i <= MAX_SS; ++i){
        if (prim[i] == 0){
            for (int j = i+i; j <= MAX_SS; j += i){
                prim[j] = 1;
            }
        }
    }
}

void gen_dp(){
    dp[0][0][0] = 1;
    for (int i = 0; i < MAX; ++i){
        for (int j = 0; j <= 9*i; ++j){
            for (int k = 0; k <= 9*9*i; ++k){
                for (int l = 0; l < 10; ++l){
                    dp[i+1][j+l][k+l*l] += dp[i][j][k];
                }
            }
        }
    }
    for (int i = 1; i <= MAX; ++i){
        for (int j = 0; j <= 9*i; ++j){
            for (int k = 0; k <= 9*9*i; ++k){
                if (dp[i][j][k]) {bg[i][j] = k; break;}
            }
            for (int k = 9*9*i; i >= 0; --k){
                if (dp[i][j][k]) {ed[i][j] = k; break;}
            }
        }
    }
}

ll lucky(ll x){
    int num[MAX], len = 0;
    while(x){
        num[len] = x%10;
        len++;
        x/=10;
    }
    ll ret = 0, s=0, ss=0;
    for (int i = len-1; i >= 0; --i){
        for (int l = 0; l < num[i]; ++l){
            ll add = 0;
            if (ch[l][i][s][ss]){
                ret += ch[l][i][s][ss];
                continue;
            }
            for (int j = 0; j <= 9*i; ++j){
                if (is_prim(j+l+s))
                for (int k = bg[i][j]; k <= ed[i][j]; ++k){
                    if (is_prim(k+l*l+ss)){
                        ret += dp[i][j][k];
                        add += dp[i][j][k];
                    }
                }
            }
            ch[l][i][s][ss] = add;
        }

        s += num[i];
        ss += num[i]*num[i];
    }
    if (is_prim(s) && is_prim(ss)) ret++;
    return ret;
}

int main(){
    erat();
    gen_dp();

    int t; cin >> t;
    while (t--){
        ll a,b; cin >> a >> b;
        cout << lucky(b) - lucky(a-1) << endl;
    }
    return 0;
}