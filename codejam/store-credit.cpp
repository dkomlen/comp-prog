#include <iostream>
#include <map>
using namespace std;

void output(int i, int x, int y) {
	cout << "Case #" << i << ": " << (x < y ? x : y) << " " << (x > y ? x : y) << endl;
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		map<int, int> m;
		int c,k; cin >> c >> k;
		for (int j = 0; j < k; j++) {
			int x; cin >> x;
			if (m.find(c-x) != m.end()) {
				output(i + 1, j + 1, m[c-x] + 1);
				cin.ignore(10000, '\n');
				break;
			}
			m[x] = j;
		}
	}
	return 0;
}