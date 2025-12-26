#include <stdio.h>


int derece(char islem) {
    if (islem == '*' || islem == '/') {
        return 2;
    } else if (islem == '+' || islem == '-') {
        return 1;
    }
    return 0;
}

void donustur(char *metin) {
    char stack[50]; 
    int ust = -1;   
    
    printf("Sonuc: ");

    for (int i = 0; metin[i] != '\0'; i++) {
        char k = metin[i];

        if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z') || (k >= '0' && k <= '9')) {
            printf("%c", k);
        }
        else if (k == '(') {
            stack[++ust] = k;
        }
        else if (k == ')') {
            while (ust > -1 && stack[ust] != '(') {
                printf("%c", stack[ust--]);
            }
            ust--; 
        }
        else {
            
            while (ust > -1 && derece(stack[ust]) >= derece(k)) {
                printf("%c", stack[ust--]);
            }
            stack[++ust] = k;
        }
    }

    
    while (ust > -1) {
        printf("%c", stack[ust--]);
    }
    printf("\n");
}

int main() {
    char input[] = "x+(y*z-a)/b"; 
    printf("Giris: %s\n", input);
    donustur(input);
    return 0;
}