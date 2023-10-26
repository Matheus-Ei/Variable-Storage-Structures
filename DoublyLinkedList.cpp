#include <iostream>

typedef struct nodo Nodo;
struct nodo {
    Nodo *prev = NULL;
    int value = 0;
    Nodo *next = NULL;
};

int menu();
Nodo *aloc(int valueAdd);
void addStart();
void addEnd();
void printStartEnd();
void printEndStart();
void printSize();
void deleteStart();
void deleteEnd();

Nodo *start = NULL;
Nodo *end = NULL;
int size = 0;

int main()
{
    int selection;
    
    while (true) {
        selection = menu();
        switch (selection) {
            case 0:
                addStart();
                break;
            case 1:
                addEnd();
                break;
            case 2:
                deleteStart();
                break;
            case 3:
                deleteEnd();
                break;
            case 4:
                printStartEnd();
                break;
            case 5:
                printEndStart();
                break;
            case 6:
                printSize();
                break;
        }
    }
    return 0;
}

int menu() {
    int selection;
    printf("\n@---- Menu de Seleção ----@\n");
    printf("0 - Adicionar um Elemento no Inicio da Lista\n");
    printf("1 - Adicionar um Elemento no Fim da Lista\n");
    printf("2 - Deletar um Elemento no Inicio da Lista\n");
    printf("3 - Deletar um Elemento no Fim da Lista\n");
    printf("4 - Percorrer a Lista do Inicio para o Fim e Printar cada Elemento\n");
    printf("5 - Percorrer a Lista do Fim para o Inicio e Printar cada Elemento\n");
    printf("6 - Printar Quantos Elementos a Lista Tem\n");
    printf("Selecione qual Operacao voce Deseja Fazer na Lista: ");
    
    scanf("%d", &selection);
    return selection;
}

Nodo *aloc(int valueAdd) {
    Nodo *element = (Nodo*)malloc(sizeof(Nodo));
    element->value = valueAdd;
    element->prev = NULL;
    element->next = NULL;
    return element;
}

void addStart() {
    int element;
    printf("\nDigite o Numero que Voce Deseja Adicionar na Lista: ");
    scanf("%d", &element);
    
    Nodo *elementAdd;
    elementAdd = aloc(element);
    
    if(start == NULL and end == NULL) {
        start = elementAdd;
        end = elementAdd;
    }
    else {
        Nodo *current;
        current = start;
        elementAdd->next = current;
        current->prev = elementAdd;
                    
        start = elementAdd;
    }
    size++;
}

void addEnd() {
    int element;
    printf("\nDigite o Numero que Voce Deseja Adicionar na Lista: ");
    scanf("%d", &element);
                
    Nodo *elementAdd;
    elementAdd = aloc(element);
                
    if(start == NULL and end == NULL) {
        start = elementAdd;
        end = elementAdd;
    }
    else {
        Nodo *current;
        current = end;
        elementAdd->prev = current;
        current->next = elementAdd;
                    
        end = elementAdd;
    }
    size++;
}

void printStartEnd() {
    if(start == NULL and end == NULL) {
        printf("A Lista Esta Vazia\n\n");
    }
    else {
        printf("\n");
        Nodo *elementP = start;
        while (elementP != end){
            printf("%d\n", elementP->value);
            elementP = elementP->next;
        }
        printf("%d\n", end->value);
    }
}

void printEndStart() {
    if(start == NULL and end == NULL) {
        printf("A Lista Esta Vazia\n\n");
    }
    else {
        printf("\n");
        Nodo *elementP = end;
        while (elementP != start){
            printf("%d\n", elementP->value);
            elementP = elementP->prev;
        }
        printf("%d\n", start->value);
    }
}

void printSize() {
    printf("\nO Tamanho Atual da Lista é de: %d Numeros\n", size);
}

void deleteStart() {
    if(start==NULL) {
        printf("\nA Lista Esta Vazia\n");
    }
    else if(size == 1) {
        start = NULL;
        end = NULL;
        printf("\nUltimo Elemento da Lista Deletado\n");
        size--;
    }
    else{
        Nodo *elementP = start;
        Nodo *current;
        current = elementP->next;
        current->prev = NULL;
        start = current;
        delete elementP;
        printf("\nElemento no Inicio da Lista Deletado\n");
        size--;
    }
}

void deleteEnd() {
    if(start==NULL) {
        printf("\nA Lista Esta Vazia\n");
    }
    else if(size == 1) {
        start = NULL;
        end = NULL;
        printf("\nUltimo Elemento da Lista Deletado\n");
        size--;
    }
    else{
        Nodo *elementP = end;
        Nodo *current;
        current = elementP->prev;
        current->prev = NULL;
        end = current;
        delete elementP;
        printf("\nElemento no Final da Lista Deletado\n");
        size--;
    }
}


