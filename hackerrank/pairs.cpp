#include <set>
#include <iostream>
using namespace std;
#define ll long long int

int main(){
    set<ll> s;
    int n, k, sol = 0; cin >> n >> k;
    while(n--){
        ll x; cin >> x;
        if (s.find(x-k) != s.end()) sol++;
        if (s.find(x+k) != s.end()) sol++;
        s.insert(x);
    }
    cout << sol << endl;
    return 0;
}