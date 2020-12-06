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

//Vari�veis que cont�m as informa��es dos produtos
int codigo[prodN];
char* genero[prodN][100];
char* tamanho[prodN][4];
char* marca[prodN][100];
char* cor[prodN][100];
float valor[prodN];
char* linha[prodN][100];
int ano[prodN];
char* tipo[prodN][100];
char* estilo[prodN][100];
int estoque[prodN];
int qtdCadastrada = 0;

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
        total += estoque[i];
    }

    printf("\nEstoque total: %d", total);

    //Fun��o que espera um caracter. Usado para para a execu��o. Qualquer tecla que seja clicada continua a execu��o
    getche();

}

//Fun��o que imprime os dados de um produto espec�fico
void imprimeProduto(int aux){
    printf("\n-------------------------\n");
    printf("CODIGO %d\n", codigo[aux]);
    printf("GENERO %s\n", genero[aux]);
    printf("TAMANHO %s\n",tamanho[aux]);
    printf("MARCA %s\n", marca[aux]);
    printf("VALOR %.2f\n", valor[aux]);
    printf("LINHA %s\n", linha[aux]);
    printf("ANO %d\n", ano[aux]);
    printf("ESTILO %s\n", estilo[aux]);
    printf("TIPO %s\n", tipo[aux]);


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
        estoque[aux] += qtd;

        printf("\n\nCadastrar outra compra (s/n)?: ");
        continua = getche();

        //Atribue -1 a aux para que outro c�digo seja informado,
        aux = -1;
    }

}

int busca_cod(int cod){
    int i;
    for (i = 0; i < qtdCadastrada; i++){
        if(codigo[i] == cod){
            return i;
        }
    }
    return -1;
}

void cadstro(){
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
        scanf("%d", &codigo[qtdCadastrada]);

        //2
        printf("\nInsira o genero da peca %d (masculino ou feminino): ", i + 1);
        scanf("%s", &genero[qtdCadastrada]);

        //3
        printf("\nInsira o tamanho da peca %d (PP, P, M, G, GG ou XGG): ", i + 1);
        scanf("%s", &tamanho[qtdCadastrada]);

        //4
        printf("\nInsira o marca da peca %d: ", i + 1);
        scanf("%s", &marca[qtdCadastrada]);

        //5
        printf("\nInsira a cor da peca %d: ", i + 1);
        scanf("%s", &cor[qtdCadastrada]);

        //6
        printf("\nInsira a valor da peca %d: ", i + 1);
        scanf("%f", &valor[qtdCadastrada]);

        //7
        printf("\nInsira o linha da peca %d: ", i + 1);
        scanf("%s", &linha[qtdCadastrada]);

        //8
        printf("\nInsira o ano da peca %d: ", i + 1);
        scanf("%d", &ano[qtdCadastrada]);

        //9
        printf("\nInsira o estilo da peca %d: ", i + 1);
        scanf("%s", &estilo[qtdCadastrada]);

        //10
        printf("\nInsira o tipo da peca %d: ", i + 1);
        scanf("%s", &tipo[qtdCadastrada]);


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
                if (codigo[i] == t_int){
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
                if (strcmp(t_str, genero[i]) == 0){
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
                if (strcmp(t_str, tamanho[i]) == 0){
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
                if (strcmp(t_str, marca[i]) == 0){
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
                if (strcmp(t_str, cor[i]) == 0){
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
                if (t_float == valor[i]){
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
                if (strcmp(t_str, linha[i]) == 0){
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
                if (t_int == ano[i]){
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
                if (strcmp(t_str, estilo[i]) == 0){
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
                if (strcmp(t_str, tipo[i]) == 0){
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
        scanf("%d", &codigo[cod]);

        //2
        printf("\nInsira o genero da peca (masculino ou feminino): ");
        scanf("%s", &genero[cod]);

        //3
        printf("\nInsira o tamanho da peca (PP, P, M, G, GG ou XGG): ");
        scanf("%s", &tamanho[cod]);

        //4
        printf("\nInsira o marca da peca: ");
        scanf("%s", &marca[cod]);

        //5
        printf("\nInsira a cor da peca: ");
        scanf("%s", &cor[cod]);

        //6
        printf("\nInsira a valor da peca: ");
        scanf("%f", &valor[cod]);

        //7
        printf("\nInsira o linha da peca: ");
        scanf("%s", &linha[cod]);

        //8
        printf("\nInsira o ano da peca: ");
        scanf("%d", &ano[cod]);

        //9
        printf("\nInsira o estilo da peca: ");
        scanf("%s", &estilo[cod]);

        //10
        printf("\nInsira o tipo da peca: ");
        scanf("%s", &tipo[cod]);


        printf("\nEdicao concluida!");
        getche();
    }
}

//Fun��o principal do C, engloba o Menu do trabalho
void main(void){

    int i;

    //Inicializa o vetor estoque com 0's para que a linha 115 possa ser executada (ou seja, utilzar o operador +=)
    for (i = 0; i < nProd; i++){
        estoque[i] = 0;
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
            cadstro();
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
