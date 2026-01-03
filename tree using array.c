#include <stdio.h>

#define BOYUT 10

void agaci_yazdir(char agac[]) {
    printf("\n--- Mevcut Agac Yapisi ---\n");
    for(int i = 0; i < BOYUT; i++) {
        if(agac[i] != '-') {
            printf("Indis %d: %c\n", i, agac[i]);
        } else {
            printf("Indis %d: Bos\n", i);
        }
    }
}

int main() {
    char ikili_agac[BOYUT];

  
    for(int i = 0; i < BOYUT; i++) {
        ikili_agac[i] = '-';
    }

    ikili_agac[0] = 'A'; 

   
    
    ikili_agac[1] = 'B'; 
    ikili_agac[2] = 'C'; 
    
    ikili_agac[3] = 'D'; 
    ikili_agac[4] = 'E';

    ikili_agac[5] = 'F'; 

    agaci_yazdir(ikili_agac);


    int bakilan_indis = 4; 
    int ebeveyn = (bakilan_indis - 1) / 2;
    printf("\n%c dugumunun ebeveyni: %c\n", ikili_agac[bakilan_indis], ikili_agac[ebeveyn]);

    return 0;
}