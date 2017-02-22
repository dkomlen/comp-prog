#include <cstdio>

int main(){
 
long rez = 1, broj = 1;
 for (long i = 2; i <= 1000; i+=2){
broj = 3*(i-2) + broj +i;
rez += 4*broj + 6*i;
    printf("%ld\n", rez);
 }
    printf("%ld", rez);
    scanf("%d", &rez);
    
}
