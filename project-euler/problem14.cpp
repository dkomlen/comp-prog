#include <cstdio>
#include <iostream>

using namespace std;

const int MAX = 1000000;
long long res[MAX+10] = {-1};


long long calc(long long x) {

 long long ret = 1;
 while (x != 1) {
       if (x <= MAX && res[x] > 0) return ret + res[x];

       x = (x % 2)? 3*x+1 : x/2;
       ret++;
 }

 return ret;
}

int main() {
 int max = 1;
 res[1] = 1;
 for (int i = 1; i <= MAX; i++) {
     if (res[i] > 0) continue;

     res[i] = calc(i);
     if (res[i] > res[max]) max = i;

     if (i % 1000 == 0) printf("i = %d\n", res[max]);
 }

 printf("%d\n", max);

 cin.get();
 return 0;
}
