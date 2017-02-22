#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<int> v;
    while(n--){
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int s = 0, a = 0, b = 0;
    for (int i = 0; i <= k-1; ++i){
        a += i * v[i] - s;
        s += v[i];
    }
    cout << "a = " << a << endl;
    int sol = a;
    for (int i = k; i < v.size(); ++i){
        a -= s - v[i-k] * k;
        a += k*v[i] - s;
        if (a < sol) sol = a;
        s -= v[i-k];
        s += v[i];
    }
    cout << sol << endl;
    return 0;
}
