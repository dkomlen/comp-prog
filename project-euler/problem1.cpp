#include <cstdio>

int main(){
    int sum = 0;
    for (int i = 3, j=5; i < 1000 || j < 1000; i+=3, j+=5){
        if (j < 1000) sum += j;
        if (i %5 != 0) sum+=i;
    }
    printf("%d", sum);
    int a;
    scanf("%d",a);
    return 0;
}
