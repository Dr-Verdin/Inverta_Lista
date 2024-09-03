#include <stdio.h>
#include <stdlib.h>

// Inverter lista de forma recursiva; inv_node(node **head)

typedef struct _node {
    int data;
    struct _node *next; // Ponteiro para o próximo nó
} NODE;

NODE *criar_node(int data); // Função para criar um novo nó
NODE *inv_node(NODE *head); // Função para inverter a lista
void imprimir_lista(NODE *head); // Função para imprimir a lista

int main() {
    int n, data;
    NODE *head = NULL; // Inicializa a cabeça da lista como NULL
    NODE *tail = NULL; // Inicializa a cauda da lista como NULL

    printf("Número de elementos da lista:\n");
    scanf("%d", &n);

    printf("Elementos da lista:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        NODE *elemento = criar_node(data);

        if (head == NULL) {
            head = elemento; // Define o primeiro nó/elemento como a cabeça da lista
            tail = head; // Define a cauda da lista como o primeiro nó
        } else {
            tail->next = elemento; // Adiciona novo nó/elemento à lista
            tail = elemento; // Atualiza a cauda da lista
        }
    }

    head = inv_node(head); // Inverte a lista

    printf("Lista invertida:\n");
    imprimir_lista(head); // Imprime lista invertida

    NODE *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

NODE *criar_node(int data) {
    NODE *novoNode = (NODE*)malloc(sizeof(NODE));
    if (novoNode == NULL) {
        printf("Erro ao criar nó!\n");
        exit(1);
    }

    novoNode->data = data; // Inicializa o valor do nó
    novoNode->next = NULL; // Define próximo nó como NULL (nó final da lista)

    return novoNode;
}

NODE *inv_node(NODE *head) {
    if (head == NULL || head->next == NULL) { // Se a lista estiver vazia ou com apenas um nó
        return head; // Retorna o nó atual como a nova cabeça da lista invertida
    }

    NODE *rest = inv_node(head->next); // Recursivamente inverte a lista a partir do segundo nó
    head->next->next = head; // Faz o nó atual apontar para o nó anterior
    head->next = NULL; // Define o próximo nó como NULL (novo final da lista)

    return rest; // Retorna a nova cabeça da lista invertida
}

void imprimir_lista(NODE *head) {
    NODE *temp = head; // Começa a partir da cabeça da lista
    while (temp != NULL) { // Enquanto não atingir o final da lista
        printf("%d\n", temp->data); // Imprime o valor do nó atual
        temp = temp->next; // Move para o próximo nó
    }
}