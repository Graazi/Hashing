#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10
#define MAX_DESCRICAO 100
#define MAX_PRODUTOS 100

// Estrutura para armazenar os registros dos produtos
typedef struct {
    int codigo;
    char descricao[MAX_DESCRICAO];
    float preco;
    int quantidade;
} Produto;

// Estrutura para os registros da tabela de hashing
typedef struct {
    int codigo_produto;
    int posicao_arquivo;
    int status; // 0 - livre, 1 - em uso
    int proximo; // Encadeamento interno
} RegistroHash;

// Função de hashing simples
int hashFunction(int codigo) {
    return codigo % TABLE_SIZE;
}

// Função para buscar um registro na tabela de hashing pelo código do produto
RegistroHash buscarRegistro(RegistroHash tabela_hash[], int codigo) {
    int indice = hashFunction(codigo);
    while (tabela_hash[indice].status != 0 && tabela_hash[indice].codigo_produto != codigo && tabela_hash[indice].proximo != -1) {
        indice = tabela_hash[indice].proximo;
    }
    return tabela_hash[indice];
}

// Função para cadastrar um novo produto
void cadastrarProduto(Produto produtos[], RegistroHash tabela_hash[]) {
    Produto novo_produto;
    RegistroHash novo_registro;
    
    printf("Digite o código do produto: ");
    scanf("%d", &novo_produto.codigo);
    printf("Digite a descrição do produto: ");
    scanf(" %[^\n]", novo_produto.descricao);
    printf("Digite o preço do produto: ");
    scanf("%f", &novo_produto.preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &novo_produto.quantidade);

    int indice = hashFunction(novo_produto.codigo);
    while (tabela_hash[indice].status != 0 && tabela_hash[indice].proximo != -1) {
        indice = tabela_hash[indice].proximo;
    }

    novo_registro.codigo_produto = novo_produto.codigo;
    novo_registro.posicao_arquivo = indice;
    novo_registro.status = 1;
    novo_registro.proximo = -1;

    tabela_hash[indice] = novo_registro;
    produtos[indice] = novo_produto;

    printf("Produto cadastrado com sucesso.\n");
}

// Função para exibir os dados de um produto
void exibirProduto(Produto produto) {
    printf("Código: %d\n", produto.codigo);
    printf("Descrição: %s\n", produto.descricao);
    printf("Preço: %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
}

// Função para alterar os dados de um produto
void alterarProduto(Produto produtos[], int indice) {
    printf("Digite a nova descrição do produto: ");
    scanf(" %[^\n]", produtos[indice].descricao);
    printf("Digite o novo preço do produto: ");
    scanf("%f", &produtos[indice].preco);
    printf("Digite a nova quantidade em estoque: ");
    scanf("%d", &produtos[indice].quantidade);

    printf("Produto alterado com sucesso.\n");
}

// Procedimento para listar todos os produtos
void listarProdutos(Produto produtos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (produtos[i].codigo != 0) {
            exibirProduto(produtos[i]);
            printf("\n");
        }
    }
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    RegistroHash tabela_hash[TABLE_SIZE];
    
    // Inicializa a tabela de hash
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela_hash[i].codigo_produto = 0;
        tabela_hash[i].posicao_arquivo = -1;
        tabela_hash[i].status = 0;
        tabela_hash[i].proximo = -1;
    }

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Exibir dados de um produto\n");
        printf("3. Alterar dados de um produto\n");
        printf("4. Listar todos os produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, tabela_hash);
                break;

            case 2:
                int codigo;
                printf("Digite o código do produto: ");
                scanf("%d", &codigo);
                RegistroHash registro = buscarRegistro(tabela_hash, codigo);
                if (registro.status == 0 || registro.codigo_produto != codigo) {
                    printf("Produto não encontrado.\n");
                } else {
                    exibirProduto(produtos[registro.posicao_arquivo]);
                }
                break;

            case 3:
                printf("Digite o código do produto que deseja alterar: ");
                scanf("%d", &codigo);
                registro = buscarRegistro(tabela_hash, codigo);
                if (registro.status == 0 || registro.codigo_produto != codigo) {
                    printf("Produto não encontrado.\n");
                } else {
                    alterarProduto(produtos, registro.posicao_arquivo);
                }
                break;

            case 4:
                listarProdutos(produtos, MAX_PRODUTOS);
                break;

            case 0:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
