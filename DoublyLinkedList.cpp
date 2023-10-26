#include <iostream>

int menu();
void AddLast(int *ant, int *value, int *prox);

struct nodo {
    int *value;
    int *prox;
    int *ant;
};

int main()
{
    nodo DefaultNodo;
    int selection, temp;
    int *pointer;
    
    DefaultNodo.ant = NULL;
    DefaultNodo.prox = NULL;
    DefaultNodo.value = NULL;
    
    while (true) {
        selection = menu();
        switch (selection) {
            case 0:
                printf("\nVoce Selecionou Adicionar Elemento no Fim da Lista, \nDigite o Numero que voce Quer Adicionar: ");
                if (DefaultNodo.value != 0) {
                    DefaultNodo.ant = DefaultNodo.value;
                    
                    scanf("%d", &temp);
                    
                    DefaultNodo.value = (int *)malloc(sizeof(int) * 3);
                
                    int var;
                    var = *DefaultNodo.value;
                    *(DefaultNodo.value + sizeof(int)) = temp;
                    *(DefaultNodo.value + sizeof(int) + sizeof(int)) = 0;

                    
                    AddLast(DefaultNodo.ant, (DefaultNodo.value + sizeof(int)), DefaultNodo.prox);
                }
                else {
                    scanf("%d", &temp);  
                    DefaultNodo.value = (int *)malloc(sizeof(int) * 1);
                    
                    *DefaultNodo.value = temp;
                    AddLast(DefaultNodo.ant, DefaultNodo.value, DefaultNodo.prox);
                }
                break;
            case 1:
                int direction;
                printf("\nVoce Selecionou Percorrer a lista.\n");
                printf("0 - Percorrer do Inicio para o Fim\n");
                printf("1 - Percorrer do Fim para o Inicio\n");
                
                scanf("%d", &direction);
                
                switch (direction) {
                    case 0:
                        break;
                    case 1:
                        while (DefaultNodo.ant!=0) {
                            DefaultNodo.value = DefaultNodo.ant;
                            printf("%p", &DefaultNodo.value);
                            scanf("%d", DefaultNodo.value);
                        }
                        break;
                }
                break;
        }
    }
    return 0;
}

int menu() {
    int selection;
    //system("clear");
    printf("@---- Menu de Seleção ----@\n");
    printf("0 - Adicionar um Elemento no Fim da Lista\n");
    printf("1 - Percorrer a Lista\n");
    printf("Selecione qual Operação voce Deseja Fazer na Lista: ");
    
    scanf("%d", &selection);
    return selection;
}

void AddLast(int *ant, int *value, int *prox) {
    printf("\n%p\n", ant);
    printf("%p\n", value);
    printf("%p\n", prox);
    
    if (ant == 0) {
        if (prox == 0) {
            printf("Ele é o Unico Elemento da Lista\n\n");
        }
        else {
            printf("Ele é o Primeiro Elemento da Lista\n\n");
        }
    }
    else if (prox == 0) {
        printf("Ele é o Ultimo Elemento da Lista\n\n");
    }
}




