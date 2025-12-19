

//Double Linked List  Sona Eleman Ekleme

void sonaEkle(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) last = last->next; 

    last->next = newNode;
    newNode->prev = last;
}





//Tüm Listeyi Silme Recursive 


void silmeRecursive(struct Node* head) {
    if (head == NULL) return; 

    deleteListRecursive(head->next); 
    
    printf("%d siliniyor...\n", head->data);
    free(head); 
}





//Double Linked Listte Araya Ekleme

void sonradanEkle(struct Node* prev_node, int data) {
    if (prev_node == NULL) return;

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}