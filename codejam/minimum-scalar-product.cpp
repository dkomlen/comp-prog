#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Round 1A 2008, Problem A. Minimum Scalar Product
// https://code.google.com/codejam/contest/32016/dashboard#s=p0

#define ll long long int

void read(vector<ll> &v, ll n) {
   for (int j = 0; j < n; ++j) {
      int x; cin >> x; v[j] = x;
   }
}

int main() {
   int t; cin >> t;
   for (int i = 0; i < t; ++i) {
      ll n, sol = 0; cin >> n;
      vector<ll> v(n),w(n);
      read(v,n);
      read(w,n);

      sort(v.begin(), v.end());
      sort(w.rbegin(), w.rend());

      for (int j = 0; j < n; j++) {
         sol += v[j] * w[j];
      }
      cout << "Case #" << i + 1 << ": " << sol << endl;
   }
   return 0;
}