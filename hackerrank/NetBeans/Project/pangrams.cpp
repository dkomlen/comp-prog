#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s; getline(cin, s);
    int x[50] = {0}, sol = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (!isalpha(s[i])) continue;
        int c = tolower(s[i]) - 'a';
        if (x[c] == 0) sol++;
        x[c] = 1;
    }
    cout << (sol == 'z' - 'a' + 1 ? "pangram" : "not pangram") << endl;         
    return 0;
}
