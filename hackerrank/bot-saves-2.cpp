#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int main(){
    int n,px,py,bx,by; cin >> n;
    int a,b; cin >> a >> b;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < s.size(); ++j){
            if (s[j] == 'm') {bx = j; by = i;}
            if (s[j] == 'p') {px = j; py = i;}
        }
        
    }
    vector<string> moves;
    string mx = (bx < px) ? "RIGHT" : "LEFT", my = (by < py) ? "DOWN" : "UP";
    for (int j = 0; j < abs(bx-px); ++j){
        moves.push_back(mx);
    }
    for (int j = 0; j < abs(by-py); ++j){
        moves.push_back(my);
    }
    cout << moves[0] << endl;
    return 0;
}