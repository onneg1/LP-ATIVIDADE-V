#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define dias_maximos 30

//criar um programa para uma biblioteca, nesse programa o usuario consegue
//adicionar um livro, consultar quanto tempo falta para ele devolver o livro
//o tempo máximo é 30 dias, exibir todos livros já adicionados, e finalizar a 
//escolha.

struct ficha_livro{
    char nome_livro[500];
    char genero[250];
    char data_aluguel[250];
};
struct ficha_livro livro[i];
int i;

void limpatela (){
    system ("cls || clear");
    fflush (stdin);
}

char cadastro_livro (struct ficha_livro *livros, int *livros_cadastrados){
    if (*livros_cadastrados >= 500){
        printf ("A biblioteca atingiu o limite de livros cadastrados!\n");
        return 'n';
    }
    printf ("Digite o nome do livro: \n");
    fgets (livros[*livros_cadastrados].nome_livro, 500, stdin);

    printf ("Digite o genero do livro: \n");
    fgets (livros[*livros_cadastrados].genero, 500, stdin);

    printf ("Digite a data que você adquiriu o livro: \n");
    fgets (livros[*livros_cadastrados].data_aluguel, 500, stdin);

    (*livros_cadastrados)++;

    return 's';
}

char exibir_adicionados (livros, *livros_cadastrados){
    printf ("Exibindo os livros que já estão no nosso armazenamento...\n");

    for (i = 0 ; i < livros_cadastrados, i++){
        printf ("%d livro:\n", i+1);
        printf ("Nome: %s", livros[*livros_cadastrados].nome_livro);
        printf ("Genero: %s", livros[*livros_cadastrados].genero);
        printf ("Data de aluguel: %s", livros[*livros_cadastrados].data_aluguel);
        printf ("\n")
    }
}

int main (){
    int livros_cadastrados = 0;
    struct ficha_livro livros[500];
    int opcao, dias_com_livro;

    do{
    printf ("||___________________-_BIBLIOTECA_-________________||\n");
    printf ("||CÓDIGO||              ESCOLHA                    ||\n");
    printf ("||______||_________________________________________||\n");
    printf ("||  1   ||         ADICIONAR UM LIVRO              ||\n");
    printf ("||  2   || CONSULTAR PERÍODO DISPONÍVEL COM O LIVRO||\n");
    printf ("||  3   ||    EXIBIR TODOS LIVROS JÁ ADICIONADOS   ||\n");
    printf ("||  4   ||          FINALIZAR ESCOLHA              ||\n")
    printf ("||______||_________________________________________||\n");
    printf ("||      ||      Escolha a opção desejada...        ||\n");
    printf ("||______||_________________________________________||\n");
    scanf ("%d", &opcao);

    limpatela();

    switch (opcao){

        case 1: if (cadastro_livro(livros, &livros_cadastrados)) == 's'){
            printf ("Livro cadastrado com sucesso!\n");
        } else {
            printf ("Não foi possível cadastrar novos livros.\n");
        }
        break;


        case 2: 
        printf ("Quantos dias você tem com o livro?");
        fgets (dias_com_livro, 250, stdin);
        if ((dias_com_livro - dias_maximos)> 0){
            printf ("Você excedeu em %d dias, e não pode mais ficar com o livro.", dias_com_livro-dias_maximos)
        } else{
            printf ("Você ficou apenas %d dias com o livro, ainda tem %d dias restantes.", dias_com_livro, dias_com_livro - dias_maximos);
        }
        break;

        case 3: exibir_adicionados(nome_Livros, livros_cadastrados);
        break;

        case 4: printf ("Finalizando a sessão... Obrigado por comprar conosco!\n");
        break;
    }
    while (opcao != 4);

    return 0;
}
