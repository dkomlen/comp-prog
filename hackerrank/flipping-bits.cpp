#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--) {
        unsigned int x; cin >> x;
        cout << (x ^ ((unsigned int) -1)) << endl;
    }
    return 0;
}
