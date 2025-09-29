#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// a
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Not enough space\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//b
void displayNodes(struct Node* head) {
    struct Node* current = head;
    if (current == NULL) {
        printf("Lista vacia\n");
        return;
    }
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
//c
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    newNode->next = *head_ref;
    *head_ref = newNode;
}
//d
void insertAtPosition(struct Node** head_ref, int position, int new_data) {
    if (position < 0) {
        printf("Error: La posición no puede ser negativa.\n");
        return;
    }
    if (position == 0) {
        insertAtBeginning(head_ref, new_data);
        return;
    }
    struct Node* newNode = createNode(new_data);
    struct Node* current = *head_ref;
    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }
    // Si la posición es inválida
    if (current == NULL) {
        printf("Error: La posición está fuera de los límites de la lista.\n");
        free(newNode);
        return;
    }
    newNode->next = current->next;
    current->next = newNode;
}
//e
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* newNode = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }
    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}
//f
void deleteAtBeginning(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("La lista ya está vacía.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    free(temp);
}
//g
void deleteAtEnd(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("La lista ya está vacía.\n");
        return;
    }
    if ((*head_ref)->next == NULL) {
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    struct Node* second_last = *head_ref;
    while (second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    free(second_last->next);
    second_last->next = NULL;
}
//h
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("La lista está vacía.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Error: La posición está fuera de los límites de la lista.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// --- Función Principal para Demostración ---
int main() {
    struct Node* head = NULL;

    printf("--- DEMOSTRACIÓN DE FUNCIONES ---\n");

    // Insertar nodos
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 2, 20); // Posición 2
    printf("Estado inicial de la lista:\n");
    displayNodes(head); // Esperado: 5 -> 10 -> 20 -> 30 -> NULL
    printf("\n");

    // Eliminar nodos
    printf("Eliminando el nodo del final (30):\n");
    deleteAtEnd(&head);
    displayNodes(head); // Esperado: 5 -> 10 -> 20 -> NULL
    printf("\n");

    printf("Eliminando el nodo del inicio (5):\n");
    deleteAtBeginning(&head);
    displayNodes(head); // Esperado: 10 -> 20 -> NULL
    printf("\n");

    printf("Añadiendo 40 y 50 para una prueba final de eliminación:\n");
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    displayNodes(head); // Esperado: 10 -> 20 -> 40 -> 50 -> NULL
    printf("\n");

    printf("Eliminando el nodo en la posición 1 (20):\n");
    deleteAtPosition(&head, 1);
    displayNodes(head); // Esperado: 10 -> 40 -> 50 -> NULL

    return 0;
}