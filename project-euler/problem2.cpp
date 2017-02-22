#include <cstdio>

using namespace std;

int main (){
    long long i = 1, j = 1, rez = 0;

while (i <= 4000000){
    if (!(i%2)) rez += i;
    i = j+i;
    j = i-j;

}
printf("%lld\n", rez);
 return 0;
}
