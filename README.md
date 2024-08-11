# Guizera Shop

Guizera Shop é um simples sistema de compras desenvolvido em C, que permite cadastrar produtos, listar produtos disponíveis, adicionar produtos ao carrinho, visualizar o carrinho e fechar o pedido. Este sistema simula uma loja online básica com interface de linha de comando.

## Funcionalidades

- **Cadastrar Produto:** Permite o cadastro de novos produtos no sistema.
- **Listar Produtos:** Exibe todos os produtos cadastrados na loja.
- **Comprar Produto:** Adiciona produtos ao carrinho de compras.
- **Visualizar Carrinho:** Mostra todos os itens que foram adicionados ao carrinho.
- **Fechar Pedido:** Calcula o valor total da compra e finaliza o pedido.

## Requisitos

- Sistema Operacional Windows
- Compilador C (ex: GCC, MinGW)
- Biblioteca `windows.h` para funções de controle de tela e atraso (Sleep).

## Como Usar

Ao iniciar o sistema, o menu principal será exibido com as seguintes opções:

- **Cadastrar Produto:** Digite `1` para adicionar um novo produto.
- **Listar Produtos:** Digite `2` para ver a lista de produtos disponíveis.
- **Comprar Produto:** Digite `3` para adicionar um produto ao carrinho.
- **Visualizar Carrinho:** Digite `4` para ver os produtos no carrinho.
- **Fechar Pedido:** Digite `5` para calcular o total e finalizar a compra.
- **Sair:** Digite `6` para encerrar o programa.

## Estrutura do Código

O código é organizado da seguinte maneira:

- **Estruturas:** 
  - `Produto`: Representa um produto na loja.
  - `Carrinho`: Representa um item no carrinho de compras.
  
- **Funções Principais:**
  - `menu()`: Exibe o menu principal e controla o fluxo do programa.
  - `cadastrarProduto()`: Cadastra um novo produto.
  - `listarProduto()`: Lista todos os produtos disponíveis.
  - `comprarProduto()`: Adiciona um produto ao carrinho.
  - `visualizarCarrinho()`: Exibe os produtos no carrinho.
  - `fecharPedido()`: Calcula o total da compra e finaliza o pedido.
