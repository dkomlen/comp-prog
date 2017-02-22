#include <iostream>
#include <string>

using namespace std;

int main() {
    int n; cin >> n;
    while (n--) {
        string s; cin >> s;
        char c = s[0];
        int sol = 0;
        for (unsigned int i = 1; i < s.size(); ++i) {
            if (c == s[i]) sol++;
            else c = s[i];
        }
        cout << sol << endl;
    }


    return 0;
}
