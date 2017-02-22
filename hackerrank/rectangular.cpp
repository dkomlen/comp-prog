#include <iostream>
#include <cmath>
using namespace std;

// 101-march-14

int main(){

    long long int n, a, b, x = -1, y = -1;
    cin >> n;
    while (n--){
        cin >> a >> b;
        if (x < 0) x = a;
        if (y < 0) y = b;
        x = min(x,a);
        y = min(y,b);
    }
    cout << x*y;
    return 0;
}