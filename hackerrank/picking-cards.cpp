#include <iostream>
#include <vector>
using namespace std;
#define ll unsigned long long int
int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> v(n,0);
        for(int i = 0; i < n; ++i){
            int x; cin >> x;
            v[x]++;
        }
        ll sol = 1, x = 0, k = 0;
        for(int i = 0; i < n; ++i){
            if (x==0 && v[i] == 0){
                sol = 0; break;
            }
            x += v[i];
            sol*=x;
            x--;
            sol %= 1000000007;
        }
        cout << sol << endl;
    }

    return 0;
}