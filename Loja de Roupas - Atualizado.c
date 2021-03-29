#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define prodN 100

// O trabalho foi divido em fun��es pois seria mais simples de organizar as rotinas
// As vari�veis foram declaradas fora do main() para que elas sejam globais e possam ser acessadas por diferentes fun��es

//Defini��o das vari�veis que ser�o utilizadas no trabalho
//Quantidade maxima de produtos que podem ser cadastrados
const int nProd = prodN;

//Struct Produto
typedef struct{
    int codigo;
    char* genero[100];
    char* tamanho[4];
    char* marca[100];
    char* cor[100];
    float valor;
    char* linha[100];
    int ano;
    char* tipo[100];
    char* estilo[100];
    int estoque;
} Product;

//criando um vetor de strucs
Product produtos[prodN];//com uma capacidade
int qtdCadastrada = 0; // qtd cadastrada

//Fun��o que imprime a listagem dos produtos
void relatorio(){
    int i;
    int total = 0;

    system("cls");
    printf("======================== \n");
    printf("RELATORIO DE PRODUTOS \n");
    printf("======================== \n");

    // La�o que percorre a quantidade de produtos cadastrados. A vari�vel qtdCadastrada guarda esse n�mero
    for (i=0; i < qtdCadastrada; i++){
        imprimeProduto(i);

        //Acumulador que soma os estques dos produtos
        total += produtos[i].estoque;
    }

    printf("\nEstoque total: %d", total);

    //Fun��o que espera um caracter. Usado para para a execu��o. Qualquer tecla que seja clicada continua a execu��o
    getche();

}

//Fun��o que imprime os dados de um produto espec�fico
void imprimeProduto(int aux){
    Product* p = &produtos[aux];
    printf("\n-------------------------\n");
    printf("CODIGO %d\n", p->codigo);
    printf("GENERO %s\n", p->genero);
    printf("TAMANHO %s\n",p->tamanho);
    printf("MARCA %s\n", p->marca);
    printf("VALOR %.2f\n", p->valor);
    printf("LINHA %s\n", p->linha);
    printf("ANO %d\n", p->ano);
    printf("ESTILO %s\n", p->estilo);
    printf("TIPO %s\n", p->tipo);


    printf("-------------------------\n");
}


//Fun��o que representa uma compra de produto;
void compra(){
    char continua = 's';
    int aux;

    //La�o se repete enquanto continua � igual a "s", ou seja, enquanto queremos cadastrar compras
    while (continua == 's'){
        char op = 'n';
        system("cls");
        printf("======================== \n");
        printf("COMPRA\n");
        printf("======================== \n");

        //Testa se a vari�vel qtdCadastrada � igual a zero, se sim, indica que nenhum produto foi cadastrado
        if (qtdCadastrada == 0){
            printf("Nenhum produto cadastrado!");
            getche();

            //Finaliza a exeu��o da fun��o
            return;
        }
        while (op != 's' && op != 'S'){

            system("cls");
            printf("======================== \n");
            printf("COMPRA\n");
            printf("======================== \n");

            //L� o c�digo do produto que o estoque ser� atualizado
            printf("Informe o codigo do produto ou '-1' para sair: ");
            scanf("%d", &aux);

            if (aux == -1){
                return;
            }

            aux = busca_cod(aux);

            //Testa se o c�digo informado � v�lido
            if (aux < 0){
                printf("\nCodigo Invalido!");
                getche();
            } else {
                imprimeProduto(aux);
                printf("Continua (s/n)? ");
                op = getche();

            }
        }

        system("cls");
        printf("======================== \n");
        printf("COMPRA\n");
        printf("======================== \n");

        imprimeProduto(aux);

        int qtd;
        //l� a quantidade de produtos comprados
        printf("Quantidade comprada: ");
        scanf("%d", &qtd);

        //Atualiza o estoque do produto. O operador += soma o valor que est� guardado em estoque[aux] com o valor qtd e
        //guarda o resultado em estoque[aux]
        produtos[aux].estoque += qtd;

        printf("\n\nCadastrar outra compra (s/n)?: ");
        continua = getche();

        //Atribue -1 a aux para que outro c�digo seja informado,
        aux = -1;
    }

}

int busca_cod(int cod){
    int i;
    for (i = 0; i < qtdCadastrada; i++){
        if(produtos[i].codigo == cod){
            return i;
        }
    }
    return -1;
}

void cadastro(){
    int i;
    int aux;
    char opcao = 's';
    int cadastros;

    system("cls");

    printf("======================== \n");
    printf("CADASTRO DE PRODUTOS \n");
    printf("======================== \n");


    printf("\nQuantas pecas voce deseja cadastrar?");
    scanf("%d", &cadastros);

    //Executa o trecho entquanto o usua�rio quiser cadastrar produtos ou at� o limite ser atingido
    for (i = 0; i < cadastros && qtdCadastrada < prodN; i ++){
        system("cls");

        printf("======================== \n");
        printf("CADASTRO DE PRODUTOS \n");
        printf("======================== \n");

        //1
        printf("\nInsira o codigo do produto %d: ", i + 1);
        scanf("%d", &produtos[qtdCadastrada].codigo);

        //2
        printf("\nInsira o genero da peca %d (masculino ou feminino): ", i + 1);
        scanf("%s", &produtos[qtdCadastrada].genero);

        //3
        printf("\nInsira o tamanho da peca %d (PP, P, M, G, GG ou XGG): ", i + 1);
        scanf("%s", &produtos[qtdCadastrada].tamanho);

        //4
        printf("\nInsira o marca da peca %d: ", i + 1);
        scanf("%s", &produtos[qtdCadastrada].marca);

        //5
        printf("\nInsira a cor da peca %d: ", i + 1);
        scanf("%s", &produtos[qtdCadastrada].cor);

        //6
        printf("\nInsira a valor da peca %d: ", i + 1);
        scanf("%f", &produtos[qtdCadastrada].valor);

        //7
        printf("\nInsira o linha da peca %d: ", i + 1);
        scanf("%s", &produtos[qtdCadastrada].linha);

        //8
        printf("\nInsira o ano da peca %d: ", i + 1);
        scanf("%d", &produtos[qtdCadastrada].ano);

        //9
        printf("\nInsira o estilo da peca %d: ", i + 1);
        scanf("%s", &produtos[qtdCadastrada].estilo);

        //10
        printf("\nInsira o tipo da peca %d: ", i + 1);
        scanf("%s", &produtos[qtdCadastrada].tipo);


        //Atualiza a quantidade de produtos cadastrados. O operador ++ soma +1 no valor contido em qtdCadastrada
        qtdCadastrada++;

        printf("\nCadastro realizado com sucesso !");

        getche();
    }
}

void consultar(){

    int aux2;
    int i = 0;
    int t_int;
    char* t_str[100];
    float t_float;
    bool flag;

    flag = false;

    system("cls");
    printf("======================== \n");
    printf("CONSULTAR PRODUTOS\n");
    printf("======================== \n");

    if (qtdCadastrada == 0){
            printf("Nenhum produto cadastrado!");
            getche();

            //Finaliza a exeu��o da fun��o
            return;
    }

    printf("Digite o numero referente ao filtro que voce deseja usar em sua cosultar");
    printf("\n1\tCodigo\n2\tGenero\n3\tTamanho\n4\tMarca\n5\tCor\n6\tValor\n7\tLinha\n8\tAno de Lancamento\n9\tEstilo\n10\tTipo\n");
    scanf("%d", &aux2);

    switch(aux2){
        case 1 :
            printf("\nInsira o codigo que voce esta procurando: ");
            scanf("%d", &t_int);
            for(i = 0; i < qtdCadastrada; i++){
                if (produtos[i].codigo == t_int){
                    flag = true;
                    imprimeProduto(i);
                }
            }

            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 2 :
            printf("\nInsira o genero que voce esta procurando: ");
            scanf("%s", &t_str);
            for(i = 0; i < qtdCadastrada; i++){
                if (strcmp(t_str, produtos[i].genero) == 0){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 3:
            printf("\nInsira o tamanho que voce esta procurando: ");
            scanf("%s", &t_str);
            for(i = 0; i < qtdCadastrada; i++){
                if (strcmp(t_str, produtos[i].tamanho) == 0){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 4 :
            printf("\nInsira o marca que voce esta procurando: ");
            scanf("%s", &t_str);
            for(i = 0; i < qtdCadastrada; i++){
                if (strcmp(t_str, produtos[i].marca) == 0){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 5 :
            printf("\nInsira o cor que voce esta procurando: ");
            scanf("%s", &t_str);
            for(i = 0; i < qtdCadastrada; i++){
                if (strcmp(t_str, produtos[i].cor) == 0){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 6 :
            printf("\nInsira o valor que voce esta procurando: ");
            scanf("%f", &t_float);
            for(i = 0; i < qtdCadastrada; i++){
                if (t_float == produtos[i].valor){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 7 :
            printf("\nInsira o linha que voce esta procurando: ");
            scanf("%s", &t_str);
            for(i = 0; i < qtdCadastrada; i++){
                if (strcmp(t_str, produtos[i].linha) == 0){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 8 :
            printf("\nInsira o ano que voce esta procurando: ");
            scanf("%d", &t_int);
            for(i = 0; i < qtdCadastrada; i++){
                if (t_int == produtos[i].ano){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 9 :
            printf("\nInsira o estilo que voce esta procurando: ");
            scanf("%s", &t_str);
            for(i = 0; i < qtdCadastrada; i++){
                if (strcmp(t_str, produtos[i].estilo) == 0){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;

        case 10 :
            printf("\nInsira o tipo que voce esta procurando: ");
            scanf("%s", &t_str);
            for(i = 0; i < qtdCadastrada; i++){
                if (strcmp(t_str, produtos[i].tipo) == 0){
                    imprimeProduto(i);
                    flag = true;
                }
            }
            if (!flag){
                printf("\nNenhum produto encontrado");
            }
            break;
    }

    getche();
}


void editar(){

    int t_int, cod;

    system("cls");
    printf("======================== \n");
    printf("EDITAR PRODUTO\n");
    printf("======================== \n");

    printf("\nInsira o codigo que voce esta procurando: ");
    scanf("%d", &t_int);

    cod = busca_cod(t_int);

    if (cod == -1){
        printf("\nCodigo Invalido!");
        getche();
        return;
    } else {
        imprimeProduto(cod);
        printf("\Insira as novas informa��es:\n");

        //1
        printf("\nInsira o codigo do produto: ");
        scanf("%d", &produtos[cod].codigo);

        //2
        printf("\nInsira o genero da peca (masculino ou feminino): ");
        scanf("%s", &produtos[cod].genero[cod]);

        //3
        printf("\nInsira o tamanho da peca (PP, P, M, G, GG ou XGG): ");
        scanf("%s", &produtos[cod].tamanho);

        //4
        printf("\nInsira o marca da peca: ");
        scanf("%s", &produtos[cod].marca);

        //5
        printf("\nInsira a cor da peca: ");
        scanf("%s", &produtos[cod].cor);

        //6
        printf("\nInsira a valor da peca: ");
        scanf("%f", &produtos[cod].valor);

        //7
        printf("\nInsira o linha da peca: ");
        scanf("%s", &produtos[cod].linha);

        //8
        printf("\nInsira o ano da peca: ");
        scanf("%d", &produtos[cod].ano);

        //9
        printf("\nInsira o estilo da peca: ");
        scanf("%s", &produtos[cod].estilo);

        //10
        printf("\nInsira o tipo da peca: ");
        scanf("%s", &produtos[cod].tipo);


        printf("\nEdicao concluida!");
        getche();
    }
}

//Fun��o principal do C, engloba o Menu do trabalho
void main(void){

    int i;

    //Inicializa o vetor estoque com 0's para que a linha 115 possa ser executada (ou seja, utilzar o operador +=)
    for (i = 0; i < nProd; i++){
        produtos[i].estoque = 0;
    }

    char opcao = 'n';

    while (opcao != 's' && opcao != 'S'){
        system("cls");
        printf("======================== \n");
        printf("MENU\n");
        printf("======================== \n");
        printf("1 - Cadastro\n");
        printf("2 - Compra\n");
        printf("3 - Relatorio\n");
        printf("4 - Consultar\n");
        printf("5 - Editar\n");
        printf("S - Sair\n");
        printf("-------------------------\n");
        printf("Digite uma opcao: ");
        opcao = getche();

        // Direciona a execu��o para alguma das op��es
        if (opcao == '1'){
            cadastro();
        } else if (opcao == '2'){
            compra();
        } else if (opcao == '3'){
            relatorio();
        } else if (opcao == '4'){
            consultar();
        } else if (opcao == '5'){
            editar();
        }

    }
}
