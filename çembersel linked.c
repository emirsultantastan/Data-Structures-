#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int deger;
    struct Dugum* sonraki;
};

// Listeyi Yazdirma
void listeyiYazdir(struct Dugum* bas) {
    struct Dugum* gecici = bas;
    if (bas != NULL) {
        do {
            printf("%d -> ", gecici->deger);
            gecici = gecici->sonraki;
        } while (gecici != bas); 
    }
    printf("(Baslangic)\n");
}

// Araya Eleman Ekleme
void arayaEkle(struct Dugum* bas, int yeniVeri, int hedefDeger) {
    if (bas == NULL) return;

    struct Dugum* yeni = (struct Dugum*)malloc(sizeof(struct Dugum));
    yeni->deger = yeniVeri;

    struct Dugum* temp = bas;
    
    while (temp->deger != hedefDeger && temp->sonraki != bas) {
        temp = temp->sonraki;
    }

    yeni->sonraki = temp->sonraki;
    temp->sonraki = yeni;
}

// 3. Eleman Silme 
void dugumSil(struct Dugum** basRef, int silinecek) {
    if (*basRef == NULL) return;

    struct Dugum *suan = *basRef, *onceki;

   
    if (suan->deger == silinecek) {
        
        if (suan->sonraki == *basRef) {
            free(suan);
            *basRef = NULL;
            return;
        }
        
        
        struct Dugum* son = *basRef;
        while (son->sonraki != *basRef) son = son->sonraki;
        
        son->sonraki = suan->sonraki;
        *basRef = suan->sonraki;
        free(suan);
        return;
    }

   
    while (suan->sonraki != *basRef && suan->deger != silinecek) {
        onceki = suan;
        suan = suan->sonraki;
    }

    if (suan->deger == silinecek) {
        onceki->sonraki = suan->sonraki;
        free(suan);
    }
}