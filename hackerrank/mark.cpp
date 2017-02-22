#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,k; cin >> n >> k;
    vector<int> v;
    while (n--){
        int x; cin >> x; v.push_back(x);
    }
    sort(v.begin(), v.end());
    int sol = 0;
    do{
        k-=v[sol++];
    } while(k > 0);
    cout << sol-1 << endl;
    return 0;
}