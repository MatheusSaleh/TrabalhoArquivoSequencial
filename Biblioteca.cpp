#include <iostream>
#include <string.h>

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

struct Autores{
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

void leituraDePessoas(Pessoas vetorDePessoas[], int quantidadeDePessoas){
    for(int cont = 0; cont < quantidadeDePessoas; cont++){
            cout << "Digite o codigo da Pessoa: ";
            cin >> vetorDePessoas[cont].codigo;
            cin.ignore();
            cout << "Digite o nome da Pessoa: ";
            gets(vetorDePessoas[cont].nome);
            cout << "Digite o endereco da Pessoa: ";
            gets(vetorDePessoas[cont].endereco);
    }
}

void leituraDeEditoras(Editoras vetorDeEditoras[], int quantidadeDeEditoras){
    for(int cont = 0; cont < quantidadeDeEditoras; cont++){
        cout << "Digite o codigo da editora: ";
        cin >> vetorDeEditoras[cont].codigo;
        cin.ignore();
        cout << "Digite o nome da editora: ";
        gets(vetorDeEditoras[cont].nome);
    }
}

void leituraDeAutores(Autores vetorDeAutores[], int quantidadeDeAutores){
    for(int cont = 0; cont < quantidadeDeAutores; cont++){
        cout << "Digite o codigo do autor: ";
        cin >> vetorDeAutores[cont].codigo;
        cin.ignore();
        cout << "Digite o nome do autor: ";
        gets(vetorDeAutores[cont].nome);
    }
}

void leituraDeGeneros(Generos vetorDeGeneros[], int quantidadeDeGeneros){
    for(int cont = 0; cont < quantidadeDeGeneros; cont++){
        cout << "Digite o codigo do genero: ";
        cin >> vetorDeGeneros[cont].codigo;
        cin.ignore();
        cout << "Digite a descricao do genero: ";
        gets(vetorDeGeneros[cont].descricao);
    }
}

void leituraDeLivros(Livros vetorDeLivros[], int quantidadeDeLivros){
    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        cout << "Digite o codigo do livro: ";
        cin >> vetorDeLivros[cont].codigo;
        cin.ignore();
        cout << "Digite o nome do livro: ";
        gets(vetorDeLivros[cont].nome);
        cout << "Digite o codigo da editora: ";
        cin >> vetorDeLivros[cont].codigo_editora;
        cin.ignore();
        cout << "Digite o codigo do autor: ";
        cin >> vetorDeLivros[cont].codigo_autor;
        cin.ignore();
        cout << "Digite o codigo do genero: ";
        cin >> vetorDeLivros[cont].codigo_genero;
        cin.ignore();
        cout << "Digite o codigo da pessoa que emprestou o livro: ";
        cin >> vetorDeLivros[cont].codigo_pessoa_emprestado;
        cin.ignore();
        cout << "Digite a quantidade emprestada: ";
        cin >> vetorDeLivros[cont].qtde_emprestada;
        cin.ignore();
        cout << "Digite a data do ultimo emprestimo: ";
        gets(vetorDeLivros[cont].data_ultimo_emprestimo);
    }
}

void insercaoNaTabelaDePessoas(Pessoas vPessoaInicial[], Pessoas vPessoaTemporario[], Pessoas vPessoaAtualizado[], int quantidadeDePessoasInicial, int quantidadeDePessoasTemporario, int quantidadeDePessoasAtualizado){
    int contPessoaInicial = 0;
    int contPessoaTemporario = 0;
    int contPessoaAtualizado = 0;
    while((contPessoaInicial < quantidadeDePessoasInicial) && (contPessoaTemporario < quantidadeDePessoasTemporario)){
        if(vPessoaInicial[contPessoaInicial].codigo < vPessoaTemporario[contPessoaTemporario].codigo){
            vPessoaAtualizado[contPessoaAtualizado].codigo = vPessoaInicial[contPessoaInicial].codigo;
            strcpy(vPessoaAtualizado[contPessoaAtualizado].nome, vPessoaInicial[contPessoaInicial].nome);
            strcpy(vPessoaAtualizado[contPessoaAtualizado].endereco, vPessoaInicial[contPessoaInicial].endereco);
            contPessoaInicial++;
        }else{
            vPessoaAtualizado[contPessoaAtualizado].codigo = vPessoaTemporario[contPessoaTemporario].codigo;
            strcpy(vPessoaAtualizado[contPessoaAtualizado].nome, vPessoaTemporario[contPessoaTemporario].nome);
            strcpy(vPessoaAtualizado[contPessoaAtualizado].endereco, vPessoaTemporario[contPessoaTemporario].endereco);
            contPessoaTemporario++;
        }
        contPessoaAtualizado++;
    }

    while(contPessoaInicial < quantidadeDePessoasInicial){
        vPessoaAtualizado[contPessoaAtualizado].codigo = vPessoaInicial[contPessoaInicial].codigo;
        strcpy(vPessoaAtualizado[contPessoaAtualizado].nome, vPessoaInicial[contPessoaInicial].nome);
        strcpy(vPessoaAtualizado[contPessoaAtualizado].endereco, vPessoaInicial[contPessoaInicial].endereco);
        contPessoaInicial++;
        contPessoaAtualizado++;
    }

    while(contPessoaTemporario < quantidadeDePessoasTemporario){
        vPessoaAtualizado[contPessoaAtualizado].codigo = vPessoaTemporario[contPessoaTemporario].codigo;
        strcpy(vPessoaAtualizado[contPessoaAtualizado].nome, vPessoaTemporario[contPessoaTemporario].nome);
        strcpy(vPessoaAtualizado[contPessoaAtualizado].endereco, vPessoaTemporario[contPessoaTemporario].endereco);
        contPessoaTemporario++;
        contPessoaAtualizado++;
    }

    cout << "--- LISTA DEPOIS DA INSERCAO ---" << endl;
    for(int cont = 0; cont < quantidadeDePessoasAtualizado; cont++){
        cout << "Codigo: " << vPessoaAtualizado[cont].codigo << endl;
        cout << "Nome: " << vPessoaAtualizado[cont].nome << endl;
        cout << "Endereco: " << vPessoaAtualizado[cont].endereco << endl;
    }
}

void insercaoNaTabelaDeLivros(Livros vLivroInicial[], Livros vLivroTemporario[], Livros vLivroAtualizado[], int quantidadeDeLivrosInicial, int quantidadeDeLivrosTemporario, int quantidadeDeLivrosAtualizado){
    int contLivroInicial = 0;
    int contLivroTemporario = 0;
    int contLivroAtualizado = 0;
    while((contLivroInicial < quantidadeDeLivrosInicial) && (contLivroTemporario < quantidadeDeLivrosTemporario)){
        if(vLivroInicial[contLivroInicial].codigo < vLivroTemporario[contLivroTemporario].codigo){
            vLivroAtualizado[contLivroAtualizado].codigo = vLivroInicial[contLivroInicial].codigo;
            strcpy(vLivroAtualizado[contLivroAtualizado].nome, vLivroInicial[contLivroInicial].nome);
            vLivroAtualizado[contLivroAtualizado].codigo_editora = vLivroInicial[contLivroInicial].codigo_editora;
            vLivroAtualizado[contLivroAtualizado].codigo_autor = vLivroInicial[contLivroInicial].codigo_autor;
        }
    }
}

//OBS: TESTAR AS FUNÇÕES DE LEITURA

int main(){

    int quantidadeDePessoasParaLer;
    int quantidadeDeEditorasParaLer;

    Pessoas vetorDePessoasInicial[4];
    Editoras vetorDeEditorasInicial[4];

    leituraDePessoas(vetorDePessoasInicial, 4);
}
