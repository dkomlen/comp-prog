#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int sub(string s) {
    int c = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') c++;
        else if(s[i] == ')') c--;
        if (c == 0) return i;
    }
}

string conv(string s){
    stringstream ss;
    if (s[0] != '(') {
        ss << s[0];
        if (s.size() > 2) ss << conv(s.substr(2)) << s[1];
    } else {
        int x = sub(s);
        ss << conv(s.substr(1, x-1));
        if (x < s.size() - 1) ss << conv(s.substr(x + 2)) << s[x+1];
    }
    return ss.str();
}

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        cout << conv(s) << endl;
    }
    return 0;
}