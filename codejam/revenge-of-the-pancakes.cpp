#include <iostream>
#include <string>
using namespace std;

// Qualification Round 2016, Problem B. Revenge of the Pancakes
// https://code.google.com/codejam/contest/6254486/dashboard#s=p1

int main() {
   int t; cin >> t;
   for (int i = 0; i < t; ++i) {
      int k = 0, sol = 0;
      bool s = false;
      string x; cin >> x;

      for (int j = x.size() - 1; j >= 0; --j) {
         bool ok = (x[j] == '+' && k % 2 == 0) || (x[j] == '-' && k % 2);
         cout << x[j]<< ": " << ok<< endl;

         if (ok && s) {
            sol++;
            k++;
         } else if (!ok) {
            s = true;
         } else {
            s = false;
         }
      }
      cout << "Case #" << i + 1 << ": " << sol + s << endl;
   }
   return 0;
}