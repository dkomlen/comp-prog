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

void print(vector<int> v){
    for (int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
}

vector<int> sort(vector <int>  ar) {
    if (ar.size() <= 1) {
        return ar;
    }
    vector<int> left, right;
    int pivot = ar[0];
    for (int i = 1; i < ar.size(); ++i){
        if (ar[i] <= pivot)
            left.push_back(ar[i]);
        else right.push_back(ar[i]);
    }
    left = sort(left);
    right = sort(right);
    left.push_back(pivot);
    vector<int> ret = left;
    ret.insert(ret.end(), right.begin(), right.end());

    print(ret);
    return ret;
}

void quickSort(vector <int>  ar, int ar_size) {

    sort(ar);
}
/* Tail starts here */
int main(void) {
   vector <int>  _ar;
   int _ar_size;
cin >> _ar_size;
for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
   int _ar_tmp;
   cin >> _ar_tmp;
   _ar.push_back(_ar_tmp);
}

quickSort(_ar, _ar_size);

   return 0;
}