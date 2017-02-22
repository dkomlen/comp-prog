#include <iostream>
#include <vector>
#include <string>
using namespace std;

int x(string a, string b){
    int ret = 0;
    for (unsigned int i = 0; i < a.size(); ++i){
        ret += (a[i] - '0' || b[i] - '0');
    }
    return ret;
}

int main() {
    int n,k,a=0,b=0; cin >> n >> k;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s; v.push_back(s);
    }
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            int t = x(v[i], v[j]);
            if (t > a) {
                a = t;
                b = 1;
            } else if (t == a) b++;
        }
    }
    cout << a << endl << b << endl;
    return 0;
}
