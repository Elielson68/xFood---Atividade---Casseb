#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIMITE_CARRINHO 45

char *** CriarCarrinho();
float * CriarConta();
void MostrarMenu();
void Clear();
int ItemNoCarrinho(char ***carrinho, char **item, int tamanho);
int IndiceItemNoCarrinho(char ***carrinho, char **item, int tamanho);
void ExtratoCarrinho(char ***carrinho, float *conta, int tamanho, int frutas, int verduras, int legumes, int bebidas_alc, int congelados);
void SelecaoProduto(int *usu, int *qtd_itens, int *tipo, int *qtd_item1, int *qtd_item2, int *qtd_item3, char ***carrinho,  float *conta, int *tamanho_carrinho, char produto1[], char produto2[], char produto3[], float preco1, float preco2, float preco3);

int main(void) {
  char ***carrinho = CriarCarrinho();
  float *conta = CriarConta();
  int tamanho_carrinho = 0, quantidade_itens = 0,tamanho_char = 10,frutas=0,verduras=0,legumes=0,proteinas=0,congelados=0,bebidas=0,bebidas_alc=0, panificadora=0,qtd_banana=20, qtd_maca=12, qtd_goiaba=9,qtd_alface=4, qtd_couve=10, qtd_espinafre=6,qtd_abobora=5, qtd_berinjela=13, qtd_chuchu=20,qtd_carne=8, qtd_ovo=40, qtd_queijo=30,qtd_lasanha=12, qtd_pizza=12, qtd_nugget=26,qtd_cupuacu=14, qtd_caju=16, qtd_laranja=20,qtd_bohemia=17, qtd_vinho=14, qtd_whisky=12, qtd_pao_caseiro=34, qtd_pao_queijo=40, qtd_pao_doce=26;
  char *produto = malloc(tamanho_char*sizeof(char));
  char *quantidade = malloc(tamanho_char*sizeof(char));
  int usu;
  printf("Bem-vindo ao XFood 2044. Para acessar uma sessão, basta inserir o valor correspondente a ela. Seu carrinho possui o limite de 45 itens. Para sair e imprimir seu extrato em conjunto com os valores, basta utilizar o 0.\n");
  while(usu!=0){
    printf("\nItens no carrinho: %d\n", quantidade_itens);
    MostrarMenu();
    printf("\nVocê: ");
    scanf("%d", &usu);
    if(usu < 0 || usu > 8){
      Clear();
      printf("\nOpção inválida!\n");
    }
    else{
      switch(usu){
      case 1:
        printf("Frutas:\n1. Banana | R$ 1,00 | Unidades: %d\n2. Maçã | R$ 3,00 | Unidades: %d\n3. Goiaba | R$ 2,00 | Unidades: %d", qtd_banana, qtd_maca, qtd_goiaba);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &frutas, &qtd_banana, &qtd_maca, &qtd_goiaba, carrinho, conta, &tamanho_carrinho, "Banana", "Maçã", "Goiaba", 1,3,2);
      break;
      case 2:
        printf("Verduras:\n1. Alface| R$ 3,00 | Unidades: %d\n2. Couve| R$ 4,00 | Unidades: %d\n3. Espinafre| R$ 4,00 | Unidades: %d", qtd_alface, qtd_couve, qtd_espinafre);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &verduras, &qtd_alface, &qtd_couve, &qtd_espinafre, carrinho, conta, &tamanho_carrinho, "Alface", "Couve", "Espinafre", 1,3,2);
      break;
      case 3:
        printf("Legumes:\n1. Abóbora| R$ 6,00 | Unidades: %d\n2. Berinjela| R$ 4,00 | Unidades: %d\n3. Chuchu| R$ 1,00 | Unidades: %d", qtd_abobora, qtd_berinjela, qtd_chuchu);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &legumes, &qtd_abobora, &qtd_berinjela, &qtd_chuchu, carrinho, conta, &tamanho_carrinho, "Abóbora", "Berinjela", "Chuchu", 6,4,1);
      break;
      case 4:
        printf("Proteínas:\n1. Carne vermelha| R$ 25,00 | Unidades: %d\n2. Ovo| R$ 0,50 | Unidades: %d\n3. Queijo | R$ 7,00 | Unidades: %d", qtd_carne, qtd_ovo, qtd_queijo);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &proteinas, &qtd_carne, &qtd_ovo, &qtd_queijo, carrinho, conta, &tamanho_carrinho, "Carne Vermelha", "Ovo", "Queijo", 25,0.5,7);
      break;
      case 5:
        printf("Congelados:\n1. Sardinha | R$ 12,00 | Unidades: %d\n2. Dourada | R$ 25,00 | Unidades: %d\n3. Pirarucu | R$ 8,00 | Unidades: %d", qtd_lasanha, qtd_pizza, qtd_nugget);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &congelados, &qtd_lasanha, &qtd_pizza, &qtd_nugget, carrinho, conta, &tamanho_carrinho, "Sardinha", "Dourada", "Pirarucu", 12,25,8);
      break;
      case 6:
        printf("Bebidas:\n1. Cupuaçu | R$ 6,00 | Unidades: %d\n2. Caju | R$ 5,00 | Unidades: %d\n3. Laranja | R$ 3,00 | Unidades: %d", qtd_cupuacu, qtd_caju, qtd_laranja);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &bebidas, &qtd_cupuacu, &qtd_caju, &qtd_laranja, carrinho, conta, &tamanho_carrinho, "Cupuaçu", "Caju", "Laranja", 6,5,3);
      break;
      case 7:
        printf("Bebidas alcoolicas:\n1. Bohemia | R$ 8,00 | Unidades: %d\n2. Vinho | R$ 46,00 | Unidades: %d\n3. Whisky | R$ 88,00 | Unidades: %d", qtd_bohemia, qtd_vinho, qtd_whisky);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &bebidas_alc, &qtd_bohemia, &qtd_vinho, &qtd_whisky, carrinho, conta, &tamanho_carrinho, "Bohemia", "Vinho", "Whisky", 8,46,88);
      break;
      case 8:
        printf("Panificadora:\n1. Pão caseiro | R$ 2,50 | Unidades: %d\n2. Pão de queijo | R$ 1,00 | Unidades: %d\n3. Pão doce | R$ 3,00 | Unidades: %d", qtd_pao_caseiro, qtd_pao_queijo, qtd_pao_doce);
        printf("\nVocê: ");
        scanf("%d", &usu);
        SelecaoProduto(&usu, &quantidade_itens, &panificadora, &qtd_pao_caseiro, &qtd_pao_queijo, &qtd_pao_doce, carrinho, conta, &tamanho_carrinho, "Pão caseiro", "Pão de queijo", "Pão doce", 2.5,1,3);
      break;
      }
    }
  }
  ExtratoCarrinho(carrinho, conta, tamanho_carrinho, frutas, verduras, legumes, bebidas_alc, congelados); 
  return 0;
}

char *** CriarCarrinho(){
  int linha = 2;
  int coluna = 45;
  char ***Carrinho = (char***)malloc(2*sizeof(char**));
  Carrinho[0] = (char**) malloc(coluna*sizeof(char*));
  for (int i=0; i<45;i++){
    Carrinho[0][i] = (char*) malloc(coluna*sizeof(char));
  }
  Carrinho[1] = (char**) malloc(coluna*sizeof(char*));
  for (int i=0; i<45;i++){
    Carrinho[1][i] = (char*) malloc(coluna*sizeof(char));
  }
  return Carrinho;
}

float * CriarConta(){
  int coluna = 45;
  float *Conta = (float*) malloc(coluna*sizeof(float));
  return Conta;
}

void MostrarMenu(){
  printf("\nCardápio:\n1. Frutas:\n2. Verduras\n3. Legumes\n4. Proteínas\n5. Congelados\n6. Bebidas\n7. Bebidas Alcoolicas\n8. Panificadora.\n0. Finalizar compra e imprimir extrato.");
}

void Clear(){
  printf("\033[0;0H\033[2J");
}

int ItemNoCarrinho(char ***carrinho, char **item, int tamanho){
  for(int i=0; i<tamanho; i++){
    if(strcmp(*item, carrinho[0][i]) == 0){
      return 1;
    }
  }
  return 0;
}

int IndiceItemNoCarrinho(char ***carrinho, char **item, int tamanho){
    for(int i=0; i<tamanho; i++){
    if(strcmp(*item, carrinho[0][i]) == 0){
      return i;
    }
  }
  return -1;
}

void ExtratoCarrinho(char ***carrinho, float *conta, int tamanho, int frutas, int verduras, int legumes, int bebidas_alc, int congelados){
  float total;
  printf("\n\t\t\t\t\t\tEXTRATO\n");
  for(int i=0; i<tamanho; i++){
    float preco = conta[i]/atoi(carrinho[1][i]);
    printf("\nProduto: %s\t|\tPreço item: R$ %.2f\t|\tQuantidade: %s\t|\t Preço total: R$ %.2f", carrinho[0][i], preco, carrinho[1][i], conta[i]);
    total += conta[i];
  }
  printf("\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", total);
  if(frutas > 10){
    float desconto = (total*0.05);
    total -= desconto;
    printf("\nDesconto de 5%% pela compra de frutas acima de 10 itens.\nDesconto dê: R$ %.2f\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", desconto, total);
  }
  if(verduras > 8 && legumes > 8){
    float desconto = (total*0.07);
    total -= desconto;
    printf("\nDesconto de 7%% pela compra de legumes e verduras acima de 8 itens.\nDesconto dê: R$ %.2f\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", desconto, total);
  }
  if(bebidas_alc >= 6){
    char *bebida = malloc(10*sizeof(char));
    int quant = bebidas_alc/6;
    bebida = "Bohemia";
    int possui1 = ItemNoCarrinho(carrinho, &bebida, tamanho);
    bebida = "Vinho";
    int possui2 = ItemNoCarrinho(carrinho, &bebida, tamanho);
    bebida = "Whisky";
    int possui3 = ItemNoCarrinho(carrinho, &bebida, tamanho);
    if(possui1){
      float desconto = quant*8;
      total -= desconto;
      printf("\nDesconto de 1 bebida alcoólica grátis a cada 6 compradas.\nDesconto dê: R$ %.2f\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", desconto, total);
    }
    else if(possui2){
      float desconto = quant*46;
      total -= desconto;
      printf("\nDesconto de 1 bebida alcoólica grátis a cada 6 compradas.\nDesconto dê: R$ %.2f\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", desconto, total);
    }
    else if(possui3){
      float desconto = quant*88;
      total -= desconto;
      printf("\nDesconto de 1 bebida alcoólica grátis a cada 6 compradas.\nDesconto dê: R$ %.2f\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", desconto, total);
    }
  }
  if(congelados > 0){
    float desconto = (total*0.10);
    total -= desconto; 
    printf("\nDesconto de 10%% pela compra de Peixe.\nDesconto dê: R$ %.2f\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", desconto, total);
  }
  if(total >= 75){
    printf("\nFrete grátis pela compra acima de R$ 75,00.\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", total);
  }
  else if(tamanho>0){
    total = total + 7;
    printf("\nFrete de entrega R$ 7,00.\n_________________\n░TOTAL: R$ %.2f░\n¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯", total);
  }
  printf("\n");
}

void SelecaoProduto(int *usu, int *qtd_itens, int *tipo, int *qtd_item1, int *qtd_item2, int *qtd_item3, char ***carrinho, float *conta, int *tamanho_carrinho, char produto1[], char produto2[], char produto3[], float preco1, float preco2, float preco3){
  char *produto = malloc(20*sizeof(char));
  char *quantidade = malloc(20*sizeof(char));
  float valor;
  if(*usu > 3 || *usu<1){
    Clear();
    *usu = -1;
    printf("\nOpção inválida!\n");
  }
  else{
  printf("Quantidade: ");
  scanf("%s", quantidade);
  if(atoi(quantidade) < 1){
    Clear();
    printf("\nSó é possível adicionar ao carrinho itens a partir de 1 unidade pra cima.\n");
  }
  else if(*qtd_itens > LIMITE_CARRINHO){
    Clear();
    printf("\nCarrinho cheio!!\n");
  }
  else if((*qtd_itens+atoi(quantidade))>LIMITE_CARRINHO){
    Clear();
    printf("\nQuantidade excede o limite do carrinho!\n");
  }
  else{
    switch(*usu){
          case 1:
            produto = produto1;
            if(atoi(quantidade) > *qtd_item1){
              Clear();
              printf("\nQuantidade de %s excede o limite de unidades\n", produto);
              break;
            }
            *qtd_itens += atoi(quantidade);
            *qtd_item1 -= atoi(quantidade);
            if(ItemNoCarrinho(carrinho, &produto, *tamanho_carrinho)){
              int i = IndiceItemNoCarrinho(carrinho, &produto, *tamanho_carrinho);
              int soma = atoi(quantidade)+atoi(carrinho[1][i]);
              sprintf(carrinho[1][i],"%d",soma);
              *tipo += atoi(quantidade);
              valor = preco1*atoi(quantidade);
              conta[i] += valor;  
              Clear();
              printf("\t\n\nProduto adicionado no carrinho!\n\n");
              break;
            }
            *tipo += atoi(quantidade);
            valor = preco1*atoi(quantidade);
            conta[*tamanho_carrinho] = valor;
            carrinho[0][*tamanho_carrinho] = produto;
            carrinho[1][*tamanho_carrinho] = quantidade;
            *tamanho_carrinho += 1;
            Clear();
            printf("\t\n\nProduto adicionado no carrinho!\n\n");
            *usu=-1;
          break;
          case 2:
            produto = produto2;
            if(atoi(quantidade) > *qtd_item2){
              Clear();
              printf("\nQuantidade de %s excede o limite de unidades\n", produto);
              break;
            }
            *qtd_itens += atoi(quantidade);
            *qtd_item2 -= atoi(quantidade);
            if(ItemNoCarrinho(carrinho, &produto, *tamanho_carrinho)){
              printf("Entrou aqui");
              int i = IndiceItemNoCarrinho(carrinho, &produto, *tamanho_carrinho);
              int soma = atoi(quantidade)+atoi(carrinho[1][i]);
              sprintf(carrinho[1][i],"%d",soma);
              *tipo += atoi(quantidade);
              valor = preco2*atoi(quantidade);
              conta[i] += valor;
              Clear();
              printf("\t\n\nProduto adicionado no carrinho!\n\n");
              break;
            }
            *tipo += atoi(quantidade);
            valor = preco2*atoi(quantidade);
            conta[*tamanho_carrinho] = valor;
            carrinho[0][*tamanho_carrinho] = produto;
            carrinho[1][*tamanho_carrinho] = quantidade;
            *tamanho_carrinho += 1;
            Clear();
            printf("\t\n\nProduto adicionado no carrinho!\n\n");
            *usu=-1;
          break;
          case 3:
            produto = produto3;
            if(atoi(quantidade) > *qtd_item3){
              Clear();
              printf("\nQuantidade de goiaba excede o limite de unidades\n");
              break;
            }
            *qtd_itens += atoi(quantidade);
            *qtd_item3 -= atoi(quantidade);
            if(ItemNoCarrinho(carrinho, &produto, *tamanho_carrinho)){
              int i = IndiceItemNoCarrinho(carrinho, &produto, *tamanho_carrinho);
              int soma = atoi(quantidade)+atoi(carrinho[1][i]);
              sprintf(carrinho[1][i],"%d",soma);
              *tipo += atoi(quantidade);
              valor = preco3*atoi(quantidade);
              conta[i] += valor;
              Clear();
              printf("\t\n\nProduto adicionado no carrinho!\n\n");            
              break;
            }
            *tipo += atoi(quantidade);
            valor = preco3*atoi(quantidade);
            conta[*tamanho_carrinho] = valor;
            carrinho[0][*tamanho_carrinho] = produto;
            carrinho[1][*tamanho_carrinho] = quantidade;
            *tamanho_carrinho += 1;
            Clear();
            printf("\t\n\nProduto adicionado no carrinho!\n\n");
            *usu=-1;
          break;
        }
  }
  }

}