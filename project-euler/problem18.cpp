#include <cstdio>

int mat[15][15];

bool ok(int i, int j){
    if (i < 0 || j < 0 || i >= 15 || j >= 15) return false;
    return true;
}
int main(){

    for (int i = 0; i < 15; ++i){
        for (int j = 0; j <= i; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 14; i >= 0; --i){
        for (int j = i; j >= 0; --j) {

            int max = mat[i][j];

            if (ok(i, j-1) && max < mat[i][j-1]) max = mat[i][j-1];
            if (ok(i-1, j-1)) {
                mat[i-1][j-1] += max;
            }
        }
    }
    for (int i = 0; i < 15; ++i){
        for (int j = 0; j <= i; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
printf("%d\n", mat[0][0]);
    return 0;
}
