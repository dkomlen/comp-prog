#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fs first
#define sc second
#define pii pair<int,int>
#define mp make_pair
bool cmp(pii a, pii b){
    if (a.sc != b.sc) return a.sc < b.sc;
    return a.fs < b.fs;
}
bool inside(int x, pii y){
    return y.fs <= x && y.sc >= x;
}

int main(){
    
    int n; cin >> n;
    while (n--){
        vector <pii > v;
        int k, sol = 0; cin >> k;
        while (k--){
            int a,b; cin >> a >> b;
            v.push_back(mp(a,b));
        }
        sort(v.begin(), v.end(), cmp);
        int ctr = 0;
        pii last1 = mp(0,0), last2 = mp(0,0);
        for (int i = 0; i < v.size(); ++i){
            //cout << v[i].fs << " " << v[i].sc << endl;
            if (inside(v[i].fs, last2) || v[i].fs < last2.fs){
                continue;
            }
            //cout << v[i].fs << " " << v[i].sc << endl;
            if (inside(v[i].fs, last1) || v[i].fs < last1.fs){
                    sol++;
                    last2 = mp(max(v[i].fs,last1.fs), last1.sc);
                    last1 = mp(last1.sc, v[i].sc);
            } else {
                last1 = v[i];
                sol++;
            }
        }
        cout << sol << endl;
    }

    return 0;
}