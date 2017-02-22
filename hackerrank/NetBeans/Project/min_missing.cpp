#include <iostream>
using namespace std;

int main() {
    int n, m, a, b, state = 0; 
    cin >> n >> m;
    
    while (n--) {
        int x; cin >> x;
        switch (state){
            case 0: if (x > m) {
                        a = x; 
                        state = 1;
                    }
                    break;
            case 1: if (x > a) {
                        b = x; 
                        state = 2;
                    } else if (x > m) {
                        a = x;
                    }
                    break;
            case 2: if (x > m && x < a) {
                        b = a;
                        a = x;
                    } else if (x < b) {
                        b = x;
                    }
        }
    }
    cout << a << " " << b << endl;
    int sol;
    if (m < a + 1) sol = m + 1;
    else if (m >= a && m < b) sol = a + 1;
    else sol = b + 1;
    
    cout << sol << endl;
    return 0;
}
