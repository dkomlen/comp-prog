#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n; cin >> n;
    int x[50] = {0};
    for (int j = 0; j < n; j++) {
        string s; cin >> s;
        set<char> st;
        for (int i = 0; i < (int) s.size(); i++) {
            if (st.find(s[i]) == st.end()){
                st.insert(s[i]);
                x[s[i] - 'a']++;
            }
        }
    }
    int sol = 0;
    for (int i = 0; i < 50; i++) {
        if (x[i] == n) sol++;
    }
    cout << sol << endl;
    
    return 0;
}
