#include <string>
#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    string sol[100];
    for (int i = 0; i < n; ++i){
        int x; string s; cin >> x >> s;
        if (i < n/2) sol[x] += "- ";
        else sol[x] += s;
    }
    for (int i = 0; i < 100; ++i) cout << sol[i];
    return 0;
}