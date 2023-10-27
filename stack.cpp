#include <iostream>

typedef struct node Node;
struct node{
    Node *prev = NULL;
    int value = 0;
};

int menu();
Node *aloc(int Nvalue);
void printStack();
void push();
void pop();

Node *end = NULL;
Node *start = NULL;
int size = 0;

int main() {
    int op = 0;

    while(true) {
        op = menu();
        switch(op) {
            case 0:
                printStack();
                break;
            case 1:
                push();
                break;
            case 2:
                pop();
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
    printf("0 - Print the Stack\n");
    printf("1 - Push\n");
    printf("2 - Pop\n");

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

void printStack() {
    if(end == NULL){
        printf("\nThe Stack Is Empty\n");
    }
    else {
        Node *current = end;
        int counter = 0;

        printf("\n#--> Elements <--#");
        while(current != start) {
            printf("\n%d --> %d", counter, current->value);
            current = current->prev;
            counter++;
        }
        printf("\n%d --> %d\n", counter, current->value);
    }
}

void push() {
    int valueAdd;
    printf("\nDigit One Value to Add in the Stack: ");
    scanf("%d", &valueAdd);

    Node *element = aloc(valueAdd);
    if(end == NULL) {
        end = element;
        start = element;
        printf("\nElement Added in the Stack\n");
        printStack();
        size++;
    }
    else {
        element->prev = end;
        end = element;
        printf("\nNew Element Added in the Stack\n");
        printStack();
        size++;
    }
}

void pop() {
    if(size == 0) {
        end = NULL;
        start = NULL;
        printf("\nThe Stack Is Empty\n");
    }
    else {
        Node *current = end;
        end = current->prev;

        delete current;
        printf("\nElement Deleted of the Stack\n");
        printStack();
        size--;
    }
}