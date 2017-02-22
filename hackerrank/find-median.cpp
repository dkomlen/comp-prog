#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int median(vector<int> v, int x, int n){
    int p = v[0];
    vector<int> a,b;
    for (int i = 1; i < v.size(); ++i){
        if (v[i] < p) a.push_back(v[i]);
        else b.push_back(v[i]);
    }
    a.push_back(p);
    if (x + a.size() == n+1) return p;
    else if (x + a.size() < n+1) return median(b,x + a.size(),n);
    return median(a,x,n);
}

int main(){
    
    int n,m; cin >> n; m = n/2;
    vector<int> v;
    while (n--){
        int x; cin >> x;
        v.push_back(x);
    }
    cout << median(v,0,m) << endl;
    
    return 0;
}