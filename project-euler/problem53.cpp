#include <iostream>
#include <cmath>
#define ll unsigned long long int
using namespace std;

void cnt(ll n, int *a){
    
    for (ll i = 2; i <= n; ++i) {
        ll j = i;
        int x = 2;
        while (j > 1){
            while(j > 0 && j%x == 0){
                j /= x;
                a[x]++;
            }
            x++;
        }
    }
}

ll calc(ll n, ll k){
    if (k >= n) return 0;
    int a[100] = {0}, b[100] = {0}, c[100] = {0};
    cnt(n, a); cnt(k, b); cnt(n-k, c);
    ll ret = 1;
    for (int i = 2; i < 100; ++i){
        if (a[i] > 0) a[i] = max(a[i] - b[i] -c[i], 0);
        while (a[i]){
            ret *= i;
            a[i]--;
        }
    }
    cout << n << " " << k << " " << ret << endl;
    return ret;
}


int main(){
    ll sol = 0;
    for (int i = 1; i <= 100; ++i){
        for (int j = 1; j <= 100; j++){
            if (calc(i,j) > 1000000) sol++;
        }
    }
    cout << sol << endl;
    return 0;
}