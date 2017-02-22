#include <iostream>
#include <string>
using namespace std;

int main(){
    string s; cin >> s;
    int c[50] = {0}, ok = 0;

    for (unsigned int i = 0; i < s.size(); ++i) {
        c[s[i] - 'a']++;
    }
    for (int i = 0; i < 40; ++i){
        if (c[i] % 2) ok++; 
    }

    cout << (ok <= 1 ? "YES" : "NO") << endl;
    

    return 0;
}
