#include <iostream>
#include <vector> 
#include <algorithm>
#include <cmath>
#define ll long long int
using namespace std;

ll dist (pair<ll,ll> a, pair<ll,ll> b){
    return max(abs(a.first-b.first),abs(a.second-b.second));
}

int main(){
    int n; cin >> n;
    double cx = 0, cy = 0;
    vector<pair<int,int> > vp;
    for (int i = 0; i < n; ++i){
        ll x,y; cin >> x >> y;
        vp.push_back(make_pair(x,y));
        cx += x/ (double)n;
        cy += y/ (double)n;
    }
    double d = -1;
    int j;
    for (int i = 0; i < n; ++i){
        ll a = vp[i].first;
        ll b = vp[i].second;
        double k = sqrt((a-cx)*(a-cx)+(b-cy)*(b-cy));
        if (d < 0 || d > k){
            d = k;
            j = i;
        }
    } 
    ll sol = 0;
    for (int i = 0; i < n; ++i){
        sol += dist(vp[i], vp[j]);
    }
    cout << sol << endl;
    return 0;
}