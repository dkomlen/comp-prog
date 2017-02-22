#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<int> lg, input, ord, a, b;
map<int,int> idx;
int n;

void put(int x){
    x++;
    for(;x <= n; x += x&-x) lg[x]++;
}

int get(int x) {
    int d = 0;
    for(; x > 0; x -= x & -x) d += lg[x];
    return d;
}

void print(vector<int> &v){
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){

    cin >> n;
    input = vector<int>(n+1,0);
    lg = vector<int>(n+1,0);
    ord = vector<int>(n+1,0);
    a = vector<int>(n+1,-1);
    b = vector<int>(n+1,0);

    for (int i = 1; i <= n; ++i){
        int x; cin >> x;
        input[i] = x;
        ord[i] = x;
    }

    sort(input.begin(), input.end());
    int j = 1, last = -1;
    for (int i = 1; i <= n; ++i){
        if (input[i] != last){
            idx[input[i]] = j; j++;
            last = input[i];
        }
    }

    for (int i = 1; i <= n; ++i){
        int k = idx[ord[i]];
        ord[i] = k;
        int x = get(k);
        if (a[k] < 0) {a[k] = x; put(k);}
        else b[k] = x - a[k];
    }
    
    lg = vector<int>(n+1,0);
    long long int sol = 0;
    int m = idx.size();
    for (int i = n; i > 0; --i){
        int k = ord[i];
        int g = m - ord[i] + 1;
        int x = get(g);
        if (input[k] >= 0){
            sol += (a[k] + b[k]) * x;
            b[k] = x;
            input[k] = -1;
            put(g);
        } else {
            sol += a[k] * (x - b[k]);
        }
        
    }
    cout << sol << endl;

    return 0;
}