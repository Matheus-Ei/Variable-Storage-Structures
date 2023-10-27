#include <iostream>

typedef struct node Node;
struct node {
    Node *prev = NULL;
    int value = 0;
};

int menu();
Node *aloc(int Nvalue);
void printQueue();
void enqueue();
void dequeue();

Node *start = NULL;
Node *end = NULL;
int size;

int main() {
    int op = 0;

    while(true) {
        op = menu();
        switch(op) {
            case 0:
                printQueue();
                break;
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            default:
                printf("\nInvalid Option\n");
                break;
        }
    }
    return 0;
}

int menu() {
    int op;
    printf("\n##----> Menu <----##\n");
    printf("0 - Print the Queue\n");
    printf("1 - Enqueue\n");
    printf("2 - Dequeue\n");

    printf("Digit the Number of the Operation: ");
    scanf("%d", &op);
    return op;
}

Node *aloc(int Nvalue) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    newNode->value = Nvalue;
    newNode->prev = NULL;

    return newNode;
}

void printQueue() {
    Node *current = start;
    int counter = 0;

    if(start == NULL) {
        printf("\nThe Queue Is Empty\n");
    }
    else {
        while (current != end) {
            printf("\n%d --> %d", counter, current->value);
            current = current->prev;
            counter++;
        }
        printf("\n%d --> %d\n", counter, current->value);
    }
}

void enqueue() {
    int valueAdd;
    printf("\nDigit a Number to Add in the Queue: ");
    scanf("%d", &valueAdd);

    Node *element = aloc(valueAdd);

    if(start == NULL) {
        start = element;
        end = element;
        printQueue();
        size++;
    }
    else {
        Node *current;
        current = end;
        
        current->prev = element;
        end = element;
        printQueue();
        size++;
    }
}

void dequeue() {
    if(start == NULL) {
        printf("\nThe Queue is Empty\n");
    }
    else {
        Node *current = start;
        Node *Pcurrent = current->prev;

        start = Pcurrent;
        delete current;
        printQueue();
        size--;
    }
}