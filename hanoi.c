#include <stdio.h>

// n disk adedini  k kaynak diski  h hedef diski  y ise yardımcı diski temsil ediyor
void kuleleri_tasi(int n, char k, char h, char y) {
    
    // eğer sadece 1 disk varsa direkt taşıyoruz
    if (n == 1) {
        printf("Disk 1: %c sutunundan %c sutununa gecti\n", k, h);
    } 
    else {
        // önce üstteki n-1 diski yardımcıya alıyoruz
        kuleleri_tasi(n - 1, k, y, h);
        
        // ana diski hedefe taşıyoruz
        printf("Disk %d: %c sutunundan %c sutununa gecti\n", n, k, h);
        
        // yardımcıdaki n-1 diski hedefe geri topluyoruz
        kuleleri_tasi(n - 1, y, h, k);
    }
}

int main() {
    int adet;

    printf("Kac tane disk değissin istersiniz: ");
    scanf("%d", &adet);

    printf("\n--- SONUC ---\n");
    kuleleri_tasi(adet, 'A', 'C', 'B');

    return 0;
}