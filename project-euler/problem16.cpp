#include <cstdio>

#define fint(X,N) for (int X = 0; X < (N); ++X)

int x[500];

int main() {
    long long int res = 2;
    fint(i,500) x[i] = -1;
    x[0] = 2;
    int asd;
    scanf("%lld", &asd);

    fint(i,asd){
        int carry = 0;

        fint(j,500) {
            if (x[j] < 0) {
                x[j] = carry;
                break;
            }
            int a = (2 * x[j]) / 10;
            x[j] = (carry + 2 * x[j]) % 10;
            carry = a;
        }

    }

    res = 0;
    fint(i,500) {
        if (x[i] < 0) break;
        res += x[i];
    }

    printf("%lld", res);
    printf("\n");
    scanf("%lld", &res);
    return 0;
}
