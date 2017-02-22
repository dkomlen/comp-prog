#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main(){
    int n; cin >> n;
    while (n--){
        long long int t, k = 1; cin >> t;
        for (int i = 0; i < t;i++) k = (i % 2 ?  k+1 : k*2);
        cout << k << endl;
    }
    return 0;
}