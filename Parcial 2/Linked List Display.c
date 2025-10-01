#include <stdio.h>
#include <stdlib.h>

// --- Definición de Nodo ---
struct Node {
    int data;
    struct Node *next;
};

// --- Definición de Cola (Queue) ---
struct Queue {
    struct Node *front; // inicio de la cola
    struct Node *rear; // final de la cola
};

// --- Crear una nueva cola vacía ---
struct Queue *createQueue() {
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// --- Crear un nuevo nodo ---
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("No hay memoria suficiente\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// --- Verificar si la cola está vacía ---
int isEmpty(struct Queue *q) {
    return (q->front == NULL);
}

// --- Encolar (insertar al final) ---
void enqueue(struct Queue *q, int data) {
    struct Node *newNode = createNode(data);
    if (q->rear == NULL) {
        // si la cola está vacía
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued: %d\n", data);
}

// --- Desencolar (eliminar al inicio) ---
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("La cola está vacía, no se puede eliminar.\n");
        return -1;
    }
    struct Node *temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) // si la cola queda vacía
        q->rear = NULL;

    free(temp);
    printf("Dequeued: %d\n", value);
    return value;
}

// --- Mostrar los elementos de la cola ---
void displayQueue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("La cola está vacía.\n");
        return;
    }
    struct Node *current = q->front;
    printf("Cola: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    struct Queue *q = createQueue();
    int choice, value;

    printf("Implementacion de cola con lista enlazada");

    do {
        printf("\nMenu: \n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Mostrar fila\n");
        printf("4. Salir\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingresa el numero a colocar: ");
                scanf("%d", &value);
                enqueue(q, value);
                break;

            case 2:
                printf("Dequeued: %d\n", dequeue(q));
                break;

            case 3:
                displayQueue(q);
                break;

            case 4:
                printf("Saliendo\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
