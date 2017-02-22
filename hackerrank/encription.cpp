#include <iostream>
#include <string>
using namespace std;

int main(){
    string s, sol = ""; cin >> s;
    int l = s.size(), x = 1, y = 1;
    while(x*y < l){
        if (x==y) x++;
        else y++;
    }
    for (int i = 0; i < x; ++i){
        for (int j = 0; j < y; ++j){
            if (j*x+i > l-1) break;
            sol += s[j*x+i];
        }
        sol += " ";
    }
    cout << sol << endl;
    return 0;
}