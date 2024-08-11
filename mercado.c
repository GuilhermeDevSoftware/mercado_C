#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

typedef struct {
    int codigo;
    char nome[30];
    float preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} Carrinho;

void infoProduto(Produto prod);
void menu();
void cadastrarProduto();
void listarProduto();
void comprarProduto();
void visualizarCarrinho();
Produto pegarProdutoPorCodigo(int codigo);
int * temNoCarrinho(int codigo);
void fecharPedido();

static int contador_produto = 0;
static int contador_carrinho = 0;
static Carrinho carrinho[50];
static Produto produtos[50];

int main(){

    menu();
    return 0;
}

void infoProduto(Produto prod){
    printf("Codigo: %d \nNome: %s \nPreço: %.2f\n", prod.codigo, strtok(prod.nome, "\n"), prod.preco);
}

void menu(){
    printf("====================================================\n");
    printf("=============    BEM-VINDO(A)    ===================\n");
    printf("===========      GUIZERA SHOP     ==================\n");
    printf("====================================================\n");

    printf("Selecione um opção abaixo: \n");
    printf("[1] Cadastrar produto: \n");
    printf("[2] Listar produtos: \n");
    printf("[3] Comprar produto: \n");
    printf("[4] Visualizar carrinho: \n");
    printf("[5] Fechar pedido: \n");
    printf("[6] Sair: \n");

    int opcao;
    scanf("%d", &opcao);
    getchar();

    switch (opcao)
    {
    case 1:
        cadastrarProduto();
        break;
    case 2:
        listarProduto();
        break;
    case 3:
        comprarProduto();
        break;
    case 4:
        visualizarCarrinho();
    case 5:
        fecharPedido(); 
    case 6:
        printf("Volte sempre!\n");  
        Sleep(2);
        exit(0);         
    default:
        printf("Opção invalida\n");
        Sleep(2);
        menu();
        break;
    }
}

void cadastrarProduto(){
    printf("Cadastro de  Produto: \n");
    printf("===================== \n");

    printf("Informe o nome do produto: \n");
    fgets(produtos[contador_produto].nome, 30, stdin);
    printf("Informe o preço do produto: \n");
    scanf("%f", &produtos[contador_produto].preco);

    printf("O produto foi cadastrado com sucesso\n", strtok(produtos[contador_produto].nome, "\n"));

    produtos[contador_produto].codigo = (contador_produto + 1);
    contador_produto++;
}

void listarProduto(){
    if (contador_produto > 0){
        printf("Listagem de produtos: \n");
        printf("========================\n");
        for(int i = 0; i < contador_produto; i++){
            infoProduto(produtos[i]);
            printf("=======================\n");
            Sleep(1);
        }
    }
    else{
        printf("Não temos produto cadastrado!\n");
    }
}

void visualizarCarrinho(){
    if(contador_carrinho > 0){
        printf("PORDUTOS DO CARRINHO: \n");
        printf("============================\n");
        for (int i = 0; i < contador_carrinho; i ++){
            infoProduto(carrinho[i].produto);
            printf("Quantidade: %d\n", carrinho[i].quantidade);
            printf("=================================\n");
            Sleep(1);
        }
    }
    else{
        printf("Não temos produtos no carrinho!\n");
    }
}

Produto pegarProdutoPorCodigo(int codigo){
    Produto p;
    for (int i = 0; i < contador_produto; i++){
        if(produtos[i].codigo == codigo){
            p = produtos[i];
        }
    }
    return p;
}

int * temNoCarrinho(int codigo){
    int static retorno[] = {0, 0};
    for (int i = 0; i < contador_carrinho; i++){
        if(carrinho[i].produto.codigo == codigo){
            retorno[0] = 1; //Tem produto com esse código
            retorno[1] = i; //Indice do produto no carrinho
        }
    }
    return retorno;
}

void fecharPedido(){
    if(contador_carrinho > 0){
        float valorTotal= 0.0;
        printf("Produtos do carrinho: \n");
        printf("================================\n");
        for(int i = 0; i < contador_carrinho; i++){
            Produto p = carrinho[i].produto;
            int quantidade = carrinho[i].quantidade;
            valorTotal += p.preco * quantidade;
            infoProduto(p);
            printf("Quantidade %d: \n", quantidade);
            printf("================================\n");
            Sleep(1);
        }
        printf("Fatura: R$%.2f\n", valorTotal);

        //limpar carrinho
        contador_carrinho = 0;
        printf("Obrigado pela preferencia!\n");
        printf("================================\n");
        Sleep(2);
        menu();
    }
    else{
        printf("Você não tem produtos no carrinho ainda!\n");
        Sleep(3);
        menu();
    }
}

void comprarProduto(){
    if(contador_produto > 0){
        printf("Informe o código do produto que deseja adicionar ao carrinho: \n");
        printf("======== PRODUTOS DISPONIVEIS =============\n");
        for(int i = 0; i <contador_produto; i++){
            infoProduto(produtos[i]);
            printf("============================================\n");
            Sleep(1);
        }
        int codigo;
        scanf("%d", &codigo);
        getchar();

        //Verificar se existe
        int tem_mercado = 0;
        for(int i = 0; i < contador_produto; i ++){
            if(produtos[i].codigo == codigo){
                tem_mercado = 1;

                if(contador_carrinho > 0){
                    int * retorno = temNoCarrinho(codigo);

                    if(retorno[0] == 1){
                        carrinho[retorno[1]].quantidade++;
                        printf("Aumentei a quantidade do produto %s já existente no carrinho \n", strtok(carrinho[retorno[1]].produto.nome, "\n"));
                        Sleep(2);
                        menu();
                    }else{
                        Produto p = pegarProdutoPorCodigo(codigo);
                        carrinho[contador_carrinho].produto = p;
                        carrinho[contador_carrinho].quantidade = 1;
                        contador_carrinho++;
                        printf("O produto %s foi adicionado ao carrinho \n", strtok(p.nome, "\n"));
                        Sleep(2);
                        menu();
                    }
                }else{
                    Produto p = pegarProdutoPorCodigo(codigo);
                    carrinho[contador_carrinho].produto = p;
                    carrinho[contador_carrinho].quantidade = 1;
                    contador_carrinho++;
                    printf("O produto %s foi adicionado ao carrinho. ", strtok(p.nome, "\n"));
                    Sleep(2);
                    menu();
                }
            }
        }
        if(tem_mercado < 1){
            printf("Não foi encontrado o produto com codigo %d.\n", codigo);
            Sleep(2);
            menu();
        }
    }
    else{
        printf("Ainda não existem produtos para venda!\n");
        Sleep(2);
        menu();
    }
}