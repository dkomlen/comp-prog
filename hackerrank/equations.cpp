#include <iostream>
#include <vector>
#define ll unsigned long long int
using namespace std;
const ll  M = 1000007;
int main(){
    int n; cin >> n;
    vector<int> v(n+1,0);
    for (int i = 2; i <= n; ++i){
        if (v[i] == 0){
            v[i] = 1;
            for (int j = i+i; j <= n; j+=i){
                int d = j;
                v[j] = -1;
                while(d % i == 0){
                    v[i]++;
                    d /= i;
                }
            }
        }
    }
    ll sol = 1;
    for (int i = 2; i <= n; ++i){
        if (v[i] > 0){
            sol *= 2*v[i]+1;
            sol %= M;
        }
    }
    cout << sol << endl;
    return 0;
}