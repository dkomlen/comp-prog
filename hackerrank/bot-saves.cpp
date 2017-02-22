#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int main(){
    int n,px,py,bx,by; cin >> n;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); ++j){
            if (s[j] == 'm') {bx = j; by = i;}
            if (s[j] == 'p') {px = j; py = i;}
        }
        
    }
    string mx = (bx < px) ? "RIGHT" : "LEFT", my = (by < py) ? "DOWN" : "UP";
    for (int j = 0; j < abs(bx-px); ++j){
        cout << mx << endl;
    }
    for (int j = 0; j < abs(by-py); ++j){
        cout << my << endl;
    }

    return 0;
}