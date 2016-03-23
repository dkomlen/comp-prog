#include <iostream>
#include <string>
using namespace std;

int main() {
	int n; cin >> n;
	for(int i = 0; i < n; ++i) {
		string x,y;
		while (cin >> x) {
			y = x + " " + y;
			if (cin.peek() == '\n') break;
		}
		cout << "Case #" << i + 1 << ": " << y << endl;
	}
	return 0;
}