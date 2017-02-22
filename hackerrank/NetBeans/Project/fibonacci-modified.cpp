#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define ll unsigned long long int

int num(string s, int i) { return (i < 0 || i >= s.size()) ? 0 : s[i] - '0'; }

string sum(string a, string b, bool with_mul = false) {
    int carry = 0;
    string ret;

    
    for (int i = 0; i < a.size() + with_mul ? 1 : 0 || i < b.size(); ++i) {
        int x = num(a, with_mul ? i - 1 : i) + num(b,i) + carry;
        carry = x / 10;
        ret.push_back(x%10 + '0');
    }
    if (carry) ret.push_back(carry + '0');
    return ret;
}

string mul(string s, int x) {
    int carry = 0;
    string ret;
    for (int i = 0; i < s.size(); ++i) {
        int k = num(s,i) * x + carry;
        ret.push_back(k % 10 + '0');
        carry = k / 10;
    }
    if (carry) ret.push_back(carry + '0');
    return ret;
}

string mul(string a, string b) {
    string ret;
    for (int i = b.size() - 1; i >= 0; --i) {
        ret = sum(ret, mul(a, num(b,i)), true);
    }
    return ret;
}

int main() {
    string a,b; int n; cin >> a >> b >> n; n-=2;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

//    string s; s = mul(a,b);
//    reverse(s.begin(), s.end());
//    cout << s << endl;
    
    while (n--) {
        string k = sum(a, mul(b,b));
        a = b;
        b = k;
    }
    reverse(b.begin(), b.end());
    cout << b << endl;
    return 0;
}
