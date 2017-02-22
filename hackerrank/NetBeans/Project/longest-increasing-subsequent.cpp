#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v;
    while (n--) {
        int x; cin >> x;
        int m, l = 0, h = v.size() - 1;
        while (l < h){
            m = (l + h) / 2;
            if (v[m] < x) l = m + 1;               
            else h = m;
        }
        if (v.size() > 0 && v[l] >= x) v[l] = x;
        else v.push_back(x);
    }
    cout << v.size() << endl;
    return 0;
}
