#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void print(vector <int>  &v, bool new_line) {

   for(int i = 0; i < v.size(); ++i){
        cout << (i ? " " : "") << v[i];
    }
    if (new_line) cout << endl;
}

void insertionSort(vector <int>  &v) {
    int x = v[v.size()-1], i = v.size()-1;

   
    while(i-1 >= 0 && x < v[i-1]) {
        v[i] = v[i-1];
        print(v, true); 
        i--;       
    }
    v[i] = x;
    print(v, false);
}

int main() {

    vector <int> v;
    int n; cin >> n;

    while(n--) {
        int x; cin >> x;
        v.push_back(x); 
    }
    insertionSort(v);
   return 0;
}