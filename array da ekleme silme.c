#include <stdio.h>


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


void insertElement(int arr[], int *size, int element, int index) {
    for (int i = *size; i > index; i--) {
        arr[i] = arr[i - 1]; 
    }
    arr[index] = element; 
    (*size)++; 
}


void deleteElement(int arr[], int *size, int index) {
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1]; 
    }
    (*size)--; 
}


void reverseArray(int arr[], int size) {
    int temp;
    for (int i = 0; i < size / 2; i++) {
        temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp; 
    }
}

int main() {
    
    int arr[10] = {10, 20, 30, 40, 50}; 
    int size = 5;

    printf(" Dizi \n");
    printArray(arr, size);

    
    insertElement(arr, &size, 25, 2);
    printf("\n25 Eklendi (Araya):\n");
    printArray(arr, size);

    
    deleteElement(arr, &size, 4);
    printf("\nIndex 4 Silindi:\n");
    printArray(arr, size);

    
    reverseArray(arr, size);
    printf("\nDizi Ters Cevrildi:\n");
    printArray(arr, size);

    return 0;
}