#include <iostream>

using namespace std;

struct Pessoas{
    int codigo;
    char nome[40];
    char endereco[60];
};

struct Editoras{
    int codigo;
    char nome[40];
};

struct Generos{
    int codigo;
    char descricao[40];
};

struct Livros{
    int codigo;
    char nome[40];
    int codigo_editora;
    int codigo_autor;
    int codigo_genero;
    int codigo_pessoa_emprestado;
    int qtde_emprestada;
    char data_ultimo_emprestimo[30];
};


int main(){

}
