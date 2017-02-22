#include <cstdio>
#include <cctype>

char text[1000] = {'\0'};

int main(){

    int x, n = 0;
    while (scanf("%d ", &x) != EOF) {
        text[n++] = (char) x;
    }

    char i = 'e' ^ 2;
    char j = 'T' ^ 59;
    char k =  'h' ^ 12;

        int br = 0;

        char des[2000] = {'\0'};
        for (int l = 0; l < n; ++l){
            des[l] = text[l] ^ ((l+1) % 3 == 0? k : (l +2) % 3 == 0? j : i);

            if (isalpha(des[l]) || des[l] == ' ' || des[l] == '.' || des[l] == ','|| des[l] == '?'|| des[l] == '!'|| des[l] == ':'|| des[l] == ';'){
                br++;
            }


        }

        printf("%s\n", des);

unsigned long long int sum = 0;
for (int i = 0; i < n; ++i) sum += des[i];
printf("%lld\n", sum);
 return 0;
}
