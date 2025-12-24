#include <stdio.h>

int main() {
    
    int mat[4][4] = {
        {0, 12, 0, 0},
        {0, 0, 0, 45},
        {7, 0, 0, 0},
        {0, 0, 91, 0}
    };

    int i, j;
    int adet = 0;

    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (mat[i][j] != 0) {
                adet++;
            }
        }
    }

    
    int sparse[adet][3];
    int sira = 0;

    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (mat[i][j] != 0) {
                sparse[sira][0] = i;         // satır 
                sparse[sira][1] = j;         // sütun 
                sparse[sira][2] = mat[i][j]; 
                sira++;
            }
        }
    }

    
    printf("--- Sparse Matrix Tablosu ---\n");
    printf("Satir\tSutun\tDeger\n");
    
    for (i = 0; i < adet; i++) {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}