#include <iostream>
#include <set>
using namespace std;

// Qualification Round 2016, Problem A. Counting Sheep
// https://code.google.com/codejam/contest/6254486/dashboard#s=p0

int main() {
   int t; cin >> t;
   for (int i = 0; i < t; i++) {
      set<int> s;
      unsigned long int x = 0, y; cin >> y;
      if (y == 0) {
         cout << "Case #" << i + 1 << ": INSOMNIA" << endl;
         continue;
      }
      while (s.size() < 10) {
         int k = 1;
         x += y;
         while(x/k) {
            s.insert(x % (10 * k) / k);
            k *= 10;
         }
      }
      cout << "Case #" << i + 1 << ": " << x << endl;
   }
   return 0;
}