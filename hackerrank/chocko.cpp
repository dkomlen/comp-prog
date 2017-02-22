#include <iostream>
using namespace std;

int main(){

    int t; cin >> t;
    while(t--){
        int sol=0, n,c,m; cin >> n >> c >> m;
        sol += n / c;
        n /= c;
        while (n >= m){
            sol += n / m;
            n = n / m + n % m;
        }
        cout << sol << endl;
    }
    return 0;
}
