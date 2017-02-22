#include <iostream>
#define ll long long int
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        ll n,a,sol = 0; cin >> n; a = n;
        while(a) {
            int k = a % 10;
            if (k != 0 && n % k == 0) sol++;
            a /= 10;
        }
        cout << sol << endl;
    }

    return 0;
}
