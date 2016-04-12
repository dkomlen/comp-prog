#include <iostream>
#include <vector>
using namespace std;

#define ll long long int

int main() {
   int t; cin >> t;
   while(t--){
      ll n, s = 0; cin >> n;
      vector<ll> v, w;

      w.push_back(0);
      v.push_back(0);

      for (int i = 0; i < n; ++i) {
         ll x; cin >> x;
         v.push_back(x);
         w.push_back(x+s);
         s += x;
      }

      s = 0;
      bool done = false;
      for (int i = n; i >= 1; --i) {
         if (s == w[i - 1]) {
            cout << "YES" << endl;
            done = true;
            break;
         }
         s += v[i];
      }
      if (!done) cout << "NO" << endl;
   }
   return 0;
}