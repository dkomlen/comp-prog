#include <iostream>
using namespace std;

int main() {
	unsigned int x, n, sum = 0; cin >> n;
	while(n--) {
	    cin >> x; sum += x;
	}
	cout << sum;
	return 0;
}