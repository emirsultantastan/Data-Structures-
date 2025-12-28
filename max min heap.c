#include <stdio.h>

int heap[100]; 
int size = 0;


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleUp(int index) {
   
    while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
        swap(&heap[(index - 1) / 2], &heap[index]);
        index = (index - 1) / 2;
    }
}


void bubbleDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        bubbleDown(smallest);
    }
}


void insert(int value) {
    heap[size] = value;
    bubbleUp(size);
    size++;
}


int extractMin() {
    if (size <= 0) return -1;
    int root = heap[0];
    heap[0] = heap[size - 1]; 
    size--;
    bubbleDown(0); 
    return root;
}

int main() {
    insert(15);
    insert(5);
    insert(20);
    insert(2);

    printf("En kucuk eleman cikariliyor: %d\n", extractMin());
    printf("Yeni kok eleman: %d\n", heap[0]);

    return 0;
}