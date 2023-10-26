#include <iostream>

int menu();

struct nodo {
    int *ant = NULL;
    int *value = NULL;
    int *prox = NULL;
};

int main()
{
    nodo DefaultNodo;
    int selection;
    
    while (true) {
        selection = menu();
        switch (selection) {
            case 0:
                int element;
                scanf("%d", &element);
                
                if(DefaultNodo.ant == NULL and DefaultNodo.prox == NULL) {
                    DefaultNodo.value = new int;
                    DefaultNodo.ant = new int;
                    DefaultNodo.prox = new int;
                    
                    *DefaultNodo.value = element;
                    *DefaultNodo.ant = 0;
                    *DefaultNodo.prox = 0;
                    
                    printf("Primeiro Elemento a Ser Adicionado na Lista\n\n");
                }
                else if(*DefaultNodo.prox == 0) {
                    if(*DefaultNodo.ant == 0) {
                        DefaultNodo.ant = DefaultNodo.value;
                        DefaultNodo.value = DefaultNodo.prox;
                        
                        *DefaultNodo.value = element;
                        
                        DefaultNodo.prox = new int;
                        *DefaultNodo.prox = 0;
                        printf("A Lista Ja Tem um Unico Elemento\n\n");
                    }
                    else {
                        DefaultNodo.ant = DefaultNodo.value;
                        DefaultNodo.value = DefaultNodo.prox;
                        
                        *DefaultNodo.value = element;
                        
                        DefaultNodo.prox = new int;
                        *DefaultNodo.prox = 0;
                        printf("A Lista Ja Tem Mais de um Elemento\n\n");
                    }
                }
                break;
            case 1:
                if(DefaultNodo.ant == NULL and DefaultNodo.prox == NULL) {
                    printf("A Lista Esta Vazia\n\n");
                }
                else {
                    while(*DefaultNodo.ant != 0) {
                        DefaultNodo.prox = DefaultNodo.value;
                        DefaultNodo.value = DefaultNodo.ant;
                    }   
                }
        }
    }
    return 0;
}

int menu() {
    int selection;
    printf("@---- Menu de Seleção ----@\n");
    printf("0 - Adicionar um Elemento no Fim da Lista\n");
    printf("1 - Percorrer a Lista do Inicio para o Fim e Printar cada Elemento\n");
    printf("Selecione qual Operação voce Deseja Fazer na Lista: ");
    
    scanf("%d", &selection);
    return selection;
}




