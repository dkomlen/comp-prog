#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        string a,b; cin >> a >> b;
        set<char> s;
        for (int i = 0; i < a.size(); i++) {
            s.insert(a[i]);
        }
        for (int i = 0; i < b.size(); i++) {
            if (s.find(b[i]) != s.end()){
                cout << "YES" << endl;
                break;
            } else if (i == b.size() - 1) {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}
