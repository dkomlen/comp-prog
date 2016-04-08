#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cctype>
using namespace std;

// Qualification Round 2009, Problem A. Alien Language
// https://code.google.com/codejam/contest/90101/dashboard#s=p0

int filter(vector<string> &v, set<char> &s, int n) {
   int r = 0;
   for (int i = 0; i < v.size(); ++i) {
      if (n == 0) v[i][0] = tolower(v[i][0]);
      if (islower(v[i][0])) {
        if (s.find(v[i][n]) == s.end()) v[i][0] = toupper(v[i][0]);
        else r++;
      }
   }
   return r;
}

int main() {

   int l,d,n;
   vector<string> dict;
   cin >> l >> d >> n;

   for (int i = 0; i < d; ++i) {
      string x; cin >> x; dict.push_back(x);
   }

   for (int i = 0; i < n; ++i) {
      string x; cin >> x;
      set<char> s;
      bool p = false;
      int sol = 0, r = 0;

      for (int j = 0; j < x.size(); ++j) {
         if (x[j] == '(') {
            p = true;
            s = set<char>();
         } else if (x[j] == ')') {
            p = false;
            sol = filter(dict, s, r++);
         } else {
            if (!p) s = set<char>();
            s.insert(x[j]);
            if (!p) sol = filter(dict, s, r++);
         }
      }
      cout << "Case #" << i + 1 << ": " << sol << endl;
   }
   return 0;
}