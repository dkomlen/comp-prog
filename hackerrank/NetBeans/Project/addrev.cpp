#include <iostream>
using namespace std;

int rev(int x){
    int ret = 0;
    
    while(x){
        ret *= 10;
        ret += x % 10;
        x /= 10;
    }
    return ret;
}

int main() {
    
    int n; cin >> n;
    while (n--) {
        int x,y; cin >> x >> y;
        cout << rev(rev(x) + rev(y)) << endl;
    }
    
    return 0;
}