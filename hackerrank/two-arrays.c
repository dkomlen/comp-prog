#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n){
    int i = n-1, j = 0;
    for (; i >= 0; --i){
        for (j = 0; j < i; ++j){
            if (arr[j] > arr[j+1]){
                int x = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = x;
            }
        }
    }
}

int main(int argc, char** argv) {

    int t;
    scanf("%d", &t);
    while(t--) {
        int i = 0, n, k; scanf("%d%d", &n, &k);
        char ok = 1;
        
        int a[n], b[n]; 
        for (; i < n; ++i){
            scanf("%d", &a[i]);
        }
        for (i = 0; i < n; ++i){
            scanf("%d", &b[i]);
        }
        sort(a, n);
        sort(b, n);
        for (i = 0; i < n; ++i){
            int j = n - 1 - i;
            if (a[i] + b[j] < k ) {
                ok = 0;
                break;
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

