#include <iostream>
#include<string>
#include <cmath>
#include <sstream>
using namespace std;

string conv(string s, bool back = false){
    string ret = "";
    for (int i = s.size() - 1; i >= 0; i--){
        ret.push_back(back ? s[i] + '0' : s[i] - '0');
    }
    return ret;
}

string add(string a, string b) {
    string sol = "";
    int len = max(a.size(), b.size());
    char c = 0;
    
    for (int i = 0; i < len; i++) {
        char x = i >= a.size() ? 0 : a[i];
        char y = i >= b.size() ? 0 : b[i];
        char z = (x + y + c) % 10;
        c = (x + y + c) / 10;
        sol.push_back(z);
    }
    if (c) sol.push_back(c);
    return sol;
}

string mul(string a, string b) {
    string sol = "";
    
    for (int j = 0; j < b.size(); ++j) {
        char x = b[j], c = 0;
        string tmp = "";

        for (int i = 0; i < j; ++i) tmp.push_back(0);
        
        for (int i = 0; i < a.size(); ++i) {
            tmp.push_back((a[i] * x + c) % 10);
            c = (a[i] * x + c) / 10;
        }
        if (c) tmp.push_back(c);
        sol = add(sol, tmp);
    }
    return sol;
}

int main() {
    int n; cin >> n;
    while (n--){
        int x; cin >> x;
        string sol = conv("1");
        while (x) {
            stringstream ss; ss << x--;
            sol = mul(sol, conv(ss.str()));
        }
        cout << conv(sol, true) << endl;
    }
    return 0;
}