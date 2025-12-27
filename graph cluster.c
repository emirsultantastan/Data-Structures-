#include <stdio.h>

#define MAX 5

int bakildi[MAX];

int matris[MAX][MAX] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 0, 0},
    {1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0}
};

void parcaBul(int sira) {
    bakildi[sira] = 1; 
    printf("%d ", sira);

    for (int j = 0; j < MAX; j++) {
       
        if (matris[sira][j] == 1 && bakildi[j] == 0) {
            parcaBul(j);
        }
    }
}

int main() {
    int grupNo = 0;

    for (int i = 0; i < MAX; i++) {
        bakildi[i] = 0;
    }

    printf("Bulunan Gruplar:\n");
    for (int i = 0; i < MAX; i++) {
        if (bakildi[i] == 0) {
            grupNo++;
            printf("Grup %d -> ", grupNo);
            parcaBul(i);
            printf("\n");
        }
    }

    return 0;
}