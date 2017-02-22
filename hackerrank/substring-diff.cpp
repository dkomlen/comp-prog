#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; string a,b; cin >> n >> a >> b;
        int sol = 0;
        a = a+a;
        for (int j = 0; j < b.size(); ++j){
            vector<int> c(b.size(), 0);
            for (int i = 0; i < b.size(); ++i){
                if (a[j+i] != b[i]) c[i] = 1;
                else c[i] = 0;
            }
            int k = 0, s = 0;
            for (int i = 0; i < c.size(); ++i){
                if (i == b.size() - j) { k = i; s = 0; }
                s += c[i];
                if (s <= n){
                    sol = max(sol, i-k+1);
                }
                if (s > n) {
                    while(s > n) s -= c[k++];
                }
            }
        }
        cout << sol << endl;
    }
    
    return 0;
}