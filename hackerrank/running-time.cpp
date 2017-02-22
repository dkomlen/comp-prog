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

int ctr = 0;

void insertionSort(vector <int>  &v, int k) {
    int x = v[k], i = k;

    while(i-1 >= 0 && x < v[i-1]) {
        v[i] = v[i-1];
        ctr++;

        i--;
    }
    v[i] = x;

}

int main() {

    vector <int> v;
    int n; cin >> n;

    while(n--) {
        int x; cin >> x;
        v.push_back(x);
    }
    for (int i = 1; i < v.size(); ++i){
        insertionSort(v, i);
	}
	cout << ctr << endl;
   return 0;
}
