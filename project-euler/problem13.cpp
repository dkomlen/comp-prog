#include <cstdio>
#include <iostream>

#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define fit(v) for (typeof(v.begin()) it = v.begin(); it != v.end(); ++it)

using namespace std;

struct bint{
	vector<int> br;
	
	bint operator+ (bint drugi){
		int carry = 0;
		bint ret(*this);

		for (int i = 0; i < drugi.size(); ++i) {
			int x = ret.br[i] + drugi.br[i] + carry;
			carry = x/10;
			ret.br[i] = x % 10;
		}
		return ret;
	}
	void print() {
		fit (br) printf("%d", *it);
	}
}

int main() {

	int n; scanf("%d", &n);
	bint rez(0);
	for (int i = 0; i < n; ++i) {
		bint br(cin.getline());
		rez += br;
	}

	rez.print();
	return 0;
}