#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int n; cin >> n;
    vector <pair<int,int> > v;
    vector <int> in(n,0), out(n,0);
    for (int i = 0; i < n; ++i){
        int x; cin >> x;
        v.push_back(make_pair(x,i));
        in[i] = x;
    }
    sort(v.begin(), v.end());
    int sol = 0;
    for (int i = 0; i < v.size(); ++i){
    
        int x = v[i].second;
        int d = 0;
        if (x > 0 && in[x-1] < in[x]){
            d += out[x-1];
        }
        if (x < n-1 && in[x+1] < in[x]){
            d = max(d, out[x+1]);
        }
        d += 1;
        sol += d;
        out[x] = d;
    }
    
    cout << sol << endl;
    return 0;
}