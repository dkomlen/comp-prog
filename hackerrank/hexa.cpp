#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 101-march-14

string x,y;
bool okx(int a) {
    if (a < 0 || a >= x.size()) return false;
    return x[a] == '0';
}
bool oky(int a) {
    if (a < 0 || a >= y.size()) return false;
    return y[a] == '0';
}

bool dfs(int n){
    if (n == 0) return true;

    for (int i = 0; i < x.size(); ++i) {
        if (x[i] != '0') continue;
        if (okx(i+1)) {
            x[i] = '1'; x[i+1] = '1';
            if (dfs(n-2)) return true;
            x[i] = '0'; x[i+1] = '0';
        }
        if (oky(i+1)) {
            x[i] = '1'; y[i+1] = '1';
            if (dfs(n-2)) return true;
            x[i] = '0'; y[i+1] = '0';
        }
        if (oky(i)) {
            x[i] = '1'; y[i] = '1';
            if (dfs(n-2)) return true;
            x[i] = '0'; y[i] = '0';
        }
    }
    for (int i = 0; i < y.size(); ++i) {
        if (y[i] != '0') continue;
        if (oky(i+1)) {
            y[i] = '1'; y[i+1] = '1';
            if (dfs(n-2)) return true;
            y[i] = '0'; y[i+1] = '0';
        }
    }
    return false;
}

int main(){
    int n; cin >> n;
    while (n--){
        int a, k; cin >> a; k = 2*a;
        cin >> x >> y;
        for(int i = 0; i < a; ++i){
            if (x[i] == '1') k--;
        }
        for(int i = 0; i < a; ++i){
            if (y[i] == '1') k--;
        }
        x = x + "1";
        y = "1" + y;
        cout  << (dfs(k) ? "YES" : "NO") << endl;
    }

    return 0;
}