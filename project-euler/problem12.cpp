#include <cstdio>
#include <cmath>

int main(){

    unsigned long long b = 0, i = 1;
    while (true){
        b += i++;
        int num = 0;
        for (int j = 1; j < sqrt(b); ++j){
            if (b % j == 0) num+=2;
        }
        if (b % (int) sqrt(b) == 0) num++;

        if (num > 500) {
            printf("%lld\n", b);
            break;
        }
    }
    return 0;
}
