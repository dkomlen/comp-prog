#include <cstdio>

bool ok (int i, int j){
    if (i < 0 || j < 0 || i >= 20 || j >= 20) return false;
    return true;
}
int mat[20][20];

int main(){

    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
    int sol = 0;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j){
            for (int k = 0; k < 8; ++k){
                bool o = true;
                int m = 1;
                for (int l = 0; l < 4; ++l){
                    int a, b;
                    if (k < 5) {
                        a = k < 3 ? -1 : 1;
                        b = k % 2 == 0 ? -1 : 1;
                    } else {
                        if (k < 7){
                            a = 0;
                            b = k % 2 == 0 ? -1 : 1;
                        } else {
                            b = 0;
                            a = k % 2 == 0 ? -1 : 1;
                        }
                    }
                    if (!ok(i+a*l, j+b*l)) {
                        o = false;
                        break;
                    }
                    m *= mat[i+a*l][j+b*l];
                }

                    if (o && (sol < m)){
                        sol = m;
                    }
            }
        }
    }


    printf ("%d\n", sol);
    return 0;
}
