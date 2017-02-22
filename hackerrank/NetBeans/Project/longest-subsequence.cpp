#include <iostream>
#include <map>
using namespace std;

int main(){
    int n, sol = 0; cin >> n;
    map<int,int> m;
    while(n--) {
        int x; cin >> x;
        map<int,int>::iterator lb = m.lower_bound(sol);
        if (lb == m.end() || lb == m.begin()){
            m[x] = 1;
        } else if (lb->first == x) {
            m[x]++;
        } else {
            lb--;
            m[lb->first]++;
        }
    }
    cout << (--m.end())->second << endl;
    
    return 0;
}
