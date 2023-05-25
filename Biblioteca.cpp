#include <iostream>
#include <string.h>



using namespace std;



struct Data{
    int dia;
    int mes;
    int ano;
};

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
    Data data_ultimo_emprestimo;
};

bool validaData(Data data) {
    if (data.mes < 1 || data.mes > 12) {
        return false;
    }

    if (data.dia < 1) {
        return false;
    }

    int diasNoMes = 31;
    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11) {
        diasNoMes = 30;
    } else if (data.mes == 2) {
        if ((data.ano % 4 == 0 && data.ano % 100 != 0) || data.ano % 400 == 0) {
            diasNoMes = 29;
        } else {
            diasNoMes = 28;
        }
    }

    if (data.dia > diasNoMes) {
        return false;
    }

    return true;
}


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

int buscaBinariaNaTabelaDeEditoras(Editoras vEditora[], int inicio, int fim, int chave) {
    if (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        if (vEditora[meio].codigo == chave) {
            cout << "Editora encontrada!" << endl;
            cout << "Nome: " << vEditora[meio].nome;
            return meio;
        } else if (vEditora[meio].codigo < chave) {
            return buscaBinariaNaTabelaDeEditoras(vEditora, meio + 1, fim, chave);
        } else {
            return buscaBinariaNaTabelaDeEditoras(vEditora, inicio, meio - 1, chave);
        }
    } else {
        cout << "Editora nao encontrada \n" << endl;
        return -1;
    }
}

int buscaBinariaNaTabelaDeAutores(Autores vAutores[], int inicio, int fim, int chave){
    if(inicio <= fim){
        int meio = (inicio+fim) / 2;
        if(vAutores[meio].codigo == chave){
            cout << "Autor Encontrado!" << endl;
            cout << "Nome: " << vAutores[meio].nome;
            return meio;
        }else if (vAutores[meio].codigo < chave){
            return buscaBinariaNaTabelaDeAutores(vAutores, meio + 1, fim, chave);
        } else{
            return buscaBinariaNaTabelaDeAutores(vAutores, inicio, meio - 1, chave);
        }
    } else{
        cout << "Autor nao encontrado \n" << endl;
        return -1;
    }
}

int buscaBinariaNaTabelaDeGeneros(Generos vGeneros[], int inicio, int fim, int chave){
    if(inicio <= fim){
        int meio = (inicio+fim) / 2;
        if(vGeneros[meio].codigo == chave){
            cout << "Genero Encontrado!" << endl;
            cout << "Descricao do Genero: " << vGeneros[meio].descricao;
            return meio;
        }else if(vGeneros[meio].codigo < chave){
            return buscaBinariaNaTabelaDeGeneros(vGeneros, meio+1, fim, chave);
        } else{
            return buscaBinariaNaTabelaDeGeneros(vGeneros, inicio, meio - 1, chave);
        }
    } else{
        cout << "Genero nao encontrado \n" << endl;
        return -1;
    }
}

void leituraDeLivros(Livros vetorDeLivros[], int quantidadeDeLivros, Editoras* vetorDeEditoras, int quantidadeDeEditoras, Autores* vetorDeAutores, int quantidadeDeAutores, Generos* vetorDeGeneros, int quantidadeDeGeneros){
    bool editoraEncontrada = false;
    bool autorEncontrado = false;
    bool generoEncontrado = false;
    bool dataValida = false;
    int posicaoEditora;
    int posicaoAutor;
    int posicaoGenero;

    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        editoraEncontrada = false;
        autorEncontrado = false;
        generoEncontrado = false;
        dataValida = false;
        cout << "Digite o codigo do livro: ";
        cin >> vetorDeLivros[cont].codigo;
        cin.ignore();
        cout << "Digite o nome do livro: ";
        gets(vetorDeLivros[cont].nome);
        while(!editoraEncontrada){
           cout << "Digite o codigo da editora: ";
           cin >> vetorDeLivros[cont].codigo_editora;
           cin.ignore();
           posicaoEditora = buscaBinariaNaTabelaDeEditoras(vetorDeEditoras, 0, quantidadeDeEditoras - 1, vetorDeLivros[cont].codigo_editora);
           if(posicaoEditora != -1){
            editoraEncontrada = true;
           }else{
           cout << "Editora nao encontrada. Digite novamente \n";
           }
        }
        cin.ignore();
        while(!autorEncontrado){
            cout << "Digite o codigo do autor: ";
            cin >> vetorDeLivros[cont].codigo_autor;
            cin.ignore();
            posicaoAutor = buscaBinariaNaTabelaDeAutores(vetorDeAutores, 0, quantidadeDeAutores - 1, vetorDeLivros[cont].codigo_autor);
            if(posicaoAutor != -1){
                autorEncontrado = true;
            }else{
                cout << "Autor nao encontrado. Digite novamente \n";
            }
        }
        cin.ignore();
        while(!generoEncontrado){
            cout << "Digite o codigo do genero: ";
            cin >> vetorDeLivros[cont].codigo_genero;
            cin.ignore();
            posicaoGenero = buscaBinariaNaTabelaDeGeneros(vetorDeGeneros, 0, quantidadeDeGeneros - 1, vetorDeLivros[cont].codigo_genero);
            if(posicaoGenero != -1){
                generoEncontrado = true;
            }else{
                cout << "Genero nao encontrado. Digite novamente \n";
            }
        }
        cin.ignore();
        cout << "Digite o codigo da pessoa que emprestou o livro: ";
        cin >> vetorDeLivros[cont].codigo_pessoa_emprestado;
        cin.ignore();
        cout << "Digite a quantidade emprestada: ";
        cin >> vetorDeLivros[cont].qtde_emprestada;
        cin.ignore();
        while(!dataValida){
            cout << "Digite a data do ultimo emprestimo (DD/MM/AAAA): ";
            char strData[11];
            gets(strData);
            sscanf(strData, "%d/%d/%d", &vetorDeLivros[cont].data_ultimo_emprestimo.dia, &vetorDeLivros[cont].data_ultimo_emprestimo.mes, &vetorDeLivros[cont].data_ultimo_emprestimo.ano);
            if(validaData(vetorDeLivros[cont].data_ultimo_emprestimo)){
                dataValida = true;
            }else{
                cout << "Data invalida. Digite uma nova data. \n";
            }
        }
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
            vLivroAtualizado[contLivroAtualizado].codigo_genero = vLivroInicial[contLivroInicial].codigo_genero;
            vLivroAtualizado[contLivroAtualizado].codigo_pessoa_emprestado = vLivroInicial[contLivroInicial].codigo_pessoa_emprestado;
            vLivroAtualizado[contLivroAtualizado].qtde_emprestada = vLivroInicial[contLivroInicial].qtde_emprestada;
            vLivroAtualizado[contLivroAtualizado].data_ultimo_emprestimo = vLivroInicial[contLivroInicial].data_ultimo_emprestimo;
            contLivroInicial++;
        }else{
            vLivroAtualizado[contLivroAtualizado].codigo = vLivroTemporario[contLivroTemporario].codigo;
            strcpy(vLivroAtualizado[contLivroAtualizado].nome, vLivroTemporario[contLivroTemporario].nome);
            vLivroAtualizado[contLivroAtualizado].codigo_editora = vLivroTemporario[contLivroTemporario].codigo_editora;
            vLivroAtualizado[contLivroAtualizado].codigo_autor = vLivroTemporario[contLivroTemporario].codigo_autor;
            vLivroAtualizado[contLivroAtualizado].codigo_genero = vLivroTemporario[contLivroTemporario].codigo_genero;
            vLivroAtualizado[contLivroAtualizado].codigo_pessoa_emprestado = vLivroTemporario[contLivroTemporario].codigo_pessoa_emprestado;
            vLivroAtualizado[contLivroAtualizado].qtde_emprestada = vLivroTemporario[contLivroTemporario].qtde_emprestada;
            vLivroAtualizado[contLivroAtualizado].data_ultimo_emprestimo = vLivroTemporario[contLivroTemporario].data_ultimo_emprestimo;
            contLivroTemporario++;
        }
        contLivroAtualizado++;
    }

    while(contLivroInicial < quantidadeDeLivrosInicial){
        vLivroAtualizado[contLivroAtualizado].codigo = vLivroInicial[contLivroInicial].codigo;
        strcpy(vLivroAtualizado[contLivroAtualizado].nome, vLivroInicial[contLivroInicial].nome);
        vLivroAtualizado[contLivroAtualizado].codigo_editora = vLivroInicial[contLivroInicial].codigo_editora;
        vLivroAtualizado[contLivroAtualizado].codigo_autor = vLivroInicial[contLivroInicial].codigo_autor;
        vLivroAtualizado[contLivroAtualizado].codigo_genero = vLivroInicial[contLivroInicial].codigo_genero;
        vLivroAtualizado[contLivroAtualizado].codigo_pessoa_emprestado = vLivroInicial[contLivroInicial].codigo_pessoa_emprestado;
        vLivroAtualizado[contLivroAtualizado].qtde_emprestada = vLivroInicial[contLivroInicial].qtde_emprestada;
        vLivroAtualizado[contLivroAtualizado].data_ultimo_emprestimo = vLivroInicial[contLivroInicial].data_ultimo_emprestimo;
        contLivroInicial++;
        contLivroAtualizado++;
    }

    while(contLivroTemporario < quantidadeDeLivrosAtualizado){
        vLivroAtualizado[contLivroAtualizado].codigo = vLivroTemporario[contLivroTemporario].codigo;
        strcpy(vLivroAtualizado[contLivroAtualizado].nome, vLivroTemporario[contLivroTemporario].nome);
        vLivroAtualizado[contLivroAtualizado].codigo_editora = vLivroTemporario[contLivroTemporario].codigo_editora;
        vLivroAtualizado[contLivroAtualizado].codigo_autor = vLivroTemporario[contLivroTemporario].codigo_autor;
        vLivroAtualizado[contLivroAtualizado].codigo_genero = vLivroTemporario[contLivroTemporario].codigo_genero;
        vLivroAtualizado[contLivroAtualizado].codigo_pessoa_emprestado = vLivroTemporario[contLivroTemporario].codigo_pessoa_emprestado;
        vLivroAtualizado[contLivroAtualizado].qtde_emprestada = vLivroTemporario[contLivroTemporario].qtde_emprestada;
        vLivroAtualizado[contLivroAtualizado].data_ultimo_emprestimo = vLivroTemporario[contLivroTemporario].data_ultimo_emprestimo;
        contLivroTemporario++;
        contLivroAtualizado++;
    }
}

int buscaBinariaNaTabelaDeLivros(Livros vLivro[], int inicio, int fim, int chave){
    if(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if(vLivro[meio].codigo == chave){
            cout << "Livro Encontrado!" << endl;
            cout << "Nome do Livro: " << vLivro[meio].nome << endl;
            return meio;
        }else if(vLivro[meio].codigo < chave){
            return buscaBinariaNaTabelaDeLivros(vLivro, meio + 1, fim, chave);
        }else{
            return buscaBinariaNaTabelaDeLivros(vLivro, inicio, meio - 1, chave);
        }
    }else{
        cout << "Livro nao encontrado \n" << endl;
        return -1;
    }
}

int buscaBinariaNaTabelaDePessoas(Pessoas vPessoa[], int inicio, int fim, int chave){
    if(inicio <= fim){
        int meio = (inicio + fim) / 2;
        if(vPessoa[meio].codigo == chave){
            cout << "Pessoa Encontrada! " << endl;
            cout << "Nome da Pessoa: " << vPessoa[meio].nome << endl;
            return meio;
        }else if(vPessoa[meio].codigo < chave){
            return buscaBinariaNaTabelaDePessoas(vPessoa, meio + 1, fim, chave);
        }else{
            return buscaBinariaNaTabelaDePessoas(vPessoa, inicio, meio - 1, chave);
        }
    }else{
        cout << "Pessoa nao encontrada" << endl;
        return -1;
    }
}

void realizaEmprestimoLivro(Livros vLivro[], Editoras vEditoras[], Autores vAutores[], Pessoas vPessoas[], int quantidadeDeLivrosNoVetorDeLivro, int quantidadeDeEditoas, int quantidadeDeAutores, int quantidadeDePessoas){
    int codigoDoLivroDesejado;
    int posicaoDoLivroEncontrado;
    int posicaoDaEditoraEncontrada;
    int posicaoDoAutorEncontrado;
    int posicaoDaPessoaEncontrada;
    int codigoDaPessoaQueIraEmprestarLivro;
    bool dataValida = false;
    Data data_disponivel;

    cout << "Digite o codigo do livro para realizar emprestimo: ";
    cin >> codigoDoLivroDesejado;

    posicaoDoLivroEncontrado = buscaBinariaNaTabelaDeLivros(vLivro, 0, quantidadeDeLivrosNoVetorDeLivro - 1, codigoDoLivroDesejado);
    cout << "/n";
    posicaoDaEditoraEncontrada = buscaBinariaNaTabelaDeEditoras(vEditoras, 0, quantidadeDeEditoas - 1, vLivro[codigoDoLivroDesejado].codigo_editora);
    cout << "/n";
    posicaoDoAutorEncontrado = buscaBinariaNaTabelaDeAutores(vAutores, 0, quantidadeDeAutores - 1, vLivro[codigoDoLivroDesejado].codigo_autor);
    cout << "/n";
    if(vLivro[codigoDoLivroDesejado].codigo_pessoa_emprestado == 0){
        cout << "Este livro esta disponivel para emprestimo! \n";
        cout << "Digite o codigo da pessoa que deseja emprestar o livro: ";
        cin >> codigoDaPessoaQueIraEmprestarLivro;

        posicaoDaPessoaEncontrada = buscaBinariaNaTabelaDePessoas(vPessoas, 0, quantidadeDePessoas - 1, codigoDaPessoaQueIraEmprestarLivro);
        cout << "/n";
        vLivro[codigoDoLivroDesejado].qtde_emprestada++;

        while(!dataValida){
            cout << "Digite a data em que se esta realizando o emprestimo (DD/MM/AAAA)";
            char strData[11];
            cin.getline(strData, 11);
            sscanf(strData, "%d/%d/%d", &vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.dia, &vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.mes, &vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.ano);

            if(validaData(vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo)){
                dataValida = true;
            }else{
                cout << "Data invalida. Digite uma nova data.\n";
            }
        }

    }else{
        cout << "Nao e possivel realizar o emprestimo. Esse livro nao esta disponivel." << endl;

        data_disponivel.dia = vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.dia + 5;
        data_disponivel.mes = vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.mes;
        data_disponivel.ano = vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.ano;

        if(data_disponivel.dia > 31){
            data_disponivel.dia -= 31;
            data_disponivel.mes++;

            if(data_disponivel.mes > 12){
                data_disponivel.mes = 1;
                data_disponivel.ano++;
            }
        }

        cout << "O livro estara disponivel novamente em " << data_disponivel.dia << "/" << data_disponivel.mes << "/" << data_disponivel.ano << endl;
    }
}

void realizaDevolucaoLivro(Livros vLivro[], Editoras vEditora[], Autores vAutores[], int quantidadeDeEditoras, int quantidadeDeAutores, int quantidadeDeLivros, Pessoas vPessoa[], int quantidadeDePessoas){
    int codigoDoLivroParaSerDevolvido;
    cout << "Digite o codigo do livro para ser devolvido: ";
    cin >> codigoDoLivroParaSerDevolvido;
    int posicaoDoLivroParaSerDevolvido = buscaBinariaNaTabelaDeLivros(vLivro, 0, quantidadeDeLivros - 1, codigoDoLivroParaSerDevolvido);
    if(posicaoDoLivroParaSerDevolvido == -1){
        cout << "O livro nao foi encontrado" << endl;
        return;
    }
    if(vLivro[posicaoDoLivroParaSerDevolvido].codigo_pessoa_emprestado == 0){
        cout << "Esse livro encontra-se indisponivel para devolucao" << endl;
    }else{
        vLivro[posicaoDoLivroParaSerDevolvido].codigo_pessoa_emprestado = 0;
        cout << "Devolucao realizada com sucesso!" << endl;
    }
}

void mostraLivrosEmprestados(Livros vLivro[], int quantidadeDeLivros, Pessoas vPessoa[], int quantidadeDePessoas){
    int contDeLivrosDisponiveisParaEmprestimo;
    int contDeLivrosEmprestados;
    int codigoDaPessoaQueEmprestouLivro;
    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        if(vLivro[cont].codigo_pessoa_emprestado != 0){
            cout << "Livros Emprestados: " << endl;
            cout << "Codigo: " << vLivro[cont].codigo << "Nome: " << vLivro[cont].nome;
            codigoDaPessoaQueEmprestouLivro = buscaBinariaNaTabelaDePessoas(vPessoa, 0, quantidadeDePessoas - 1, vLivro[cont].codigo_pessoa_emprestado);
            contDeLivrosEmprestados++;
        }else{
            cout << "Livros Disponiveis para Emprestimo: " << endl;
            cout << "Codigo: " << vLivro[cont].codigo << "Nome: " << vLivro[cont].nome;
            contDeLivrosDisponiveisParaEmprestimo++;
        }
    }
    cout << "Quantidade de Livros emprestados: " << contDeLivrosEmprestados << endl;
    cout << "Quantidade de Livros disponiveis para emprestimo: " << contDeLivrosDisponiveisParaEmprestimo << endl;
}


void mostraLivroMaisEmprestado(Livros vLivro[], Editoras vEditora[], Autores vAutores[], int quantidadeDeLivros, int quantidadeDeEditoras, int quantidadeDeAutores){
    Livros livroMaisEmprestado = vLivro[0];
    int posEditoraMaisEmprestado;
    int posAutorMaisEmprestado;
    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        if(vLivro[cont].qtde_emprestada > livroMaisEmprestado.qtde_emprestada){
            livroMaisEmprestado = vLivro[cont];
        }
    }
    cout << "O livro mais emprestado e :" << livroMaisEmprestado.nome << endl;
    cout << "Numero de vezes em que foi emprestado: " << livroMaisEmprestado.qtde_emprestada;
    posAutorMaisEmprestado = buscaBinariaNaTabelaDeAutores(vAutores, 0, quantidadeDeAutores - 1, livroMaisEmprestado.codigo_autor);
    posEditoraMaisEmprestado = buscaBinariaNaTabelaDeEditoras(vEditora, 0, quantidadeDeEditoras - 1, livroMaisEmprestado.codigo_editora);
}

void mostraLivrosMenosEmprestados(Livros vLivro[], Editoras vEditora[], Autores vAutores[], int quantidadeDeLivros, int quantidadeDeEditoras, int quantidadeDeAutores){
    Livros livroMenosEmprestado = vLivro[0];
    int posEditoraMenosEmprestado;
    int posAutorMenosEmprestado;
    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        if(vLivro[cont].qtde_emprestada < livroMenosEmprestado.qtde_emprestada){
            livroMenosEmprestado = vLivro[cont];
        }
    }
    cout << "O livro menos emprestado e :" << livroMenosEmprestado.nome << endl;
    cout << "Numero de vezes em que foi emprestado: " << livroMenosEmprestado.qtde_emprestada;
    posAutorMenosEmprestado = buscaBinariaNaTabelaDeAutores(vAutores, 0, quantidadeDeAutores - 1, livroMenosEmprestado.codigo_autor);
    posEditoraMenosEmprestado = buscaBinariaNaTabelaDeEditoras(vEditora, 0, quantidadeDeEditoras - 1, livroMenosEmprestado.codigo_editora);
}

void mostraDadosDeLivrosComDevolucaoEmAtraso(Livros vLivro[], int quantidadeDeLivros, Data dataAtual, Editoras vEditora[], Autores vAutores[], int quantidadeDeEditoras, int quantidadeDeAutores){
    int posEditoraLivroAtraso;
    int posAutorLivroAtraso;
    int diasEmAtraso;
    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        if((vLivro[cont].data_ultimo_emprestimo.dia + 5) < dataAtual.dia + 5){
            posEditoraLivroAtraso = buscaBinariaNaTabelaDeEditoras(vEditora, 0, quantidadeDeEditoras - 1, vLivro[cont].codigo_editora);
            posAutorLivroAtraso = buscaBinariaNaTabelaDeAutores(vAutores, 0, quantidadeDeAutores - 1, vLivro[cont].codigo_autor);
            diasEmAtraso = (dataAtual.dia - vLivro[cont].data_ultimo_emprestimo.dia + 5);
            cout << "Livros em atraso: " << endl;
            cout << "Nome: " << vLivro[cont].nome << endl;
            cout << "Dias em atraso: " << diasEmAtraso;
        }
    }
}

void imprimeListaDePessoas(Pessoas vPessoa[], int quantidadeDePessoas){
    for(int cont = 0; cont < quantidadeDePessoas; cont++){
        cout << "Codigo: " << vPessoa[cont].codigo << "\n";
        cout << "Nome: " << vPessoa[cont].nome << "\n";
        cout << "Endereco: " << vPessoa[cont].endereco << "\n";
    }
}

void imprimeListaDeLivros(Livros vLivro[], int quantidadeDeLivros){
    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        cout << "Codigo: " << vLivro[cont].codigo << "\n";
        cout << "Nome: " << vLivro[cont].nome << "\n";
        cout << "Codigo Editora: " << vLivro[cont].codigo_editora << "\n";
        cout << "Codigo Autor: " << vLivro[cont].codigo_autor << "\n";
        cout << "Codigo Genero: " << vLivro[cont].codigo_genero << "\n";
        cout << "Codigo Pessoa Emprestado: " << vLivro[cont].codigo_pessoa_emprestado << "\n";
        cout << "Quantidade Emprestada: " << vLivro[cont].qtde_emprestada << "\n";
        cout << "Data Ultimo Emprestimo: " << vLivro[cont].data_ultimo_emprestimo.dia << "/" << vLivro[cont].data_ultimo_emprestimo.mes << "/" << vLivro[cont].data_ultimo_emprestimo.ano << "\n";
    }
}

int main(){
    int quantidadeDePessoas = 5;
    int quantidadeDeEditoras = 5;
    int quantidadeDeAutores = 5;
    int quantidadeDeGeneros= 5;
    int quantidadeDeLivros = 5;
    int quantidadeDePessoasParaSerAdicionado = 2;
    int quantidadeDeLivrosParaSerAdicionado = 2;
    int quantidadeDePessoasDepoisDeAdicionado = 7;
    int quantidadeDeLivrosDepoisDeAdicionado = 7;
    int opcao;
    bool dataValida = false;
    Data diaDeHoje;
    Pessoas vPessoa[5];
    Editoras vEditora[5];
    Autores vAutores[5];
    Generos vGeneros[5];
    Livros vLivros[5];
    Pessoas vPessoaTemporario[2];
    Livros vLivroTemporario[2];
    Pessoas vPessoaAtualizado[7];
    Livros vLivroAtualizado[7];
    while(!dataValida){
        cout << "Digite a data de hoje (DD/MM/AAAA): ";
        char strData[11];
        gets(strData);
        sscanf(strData, "%d/%d/%d", &diaDeHoje.dia, &diaDeHoje.mes, &diaDeHoje.ano);
        if(validaData(diaDeHoje)){
            dataValida = true;
        }else{
            cout << "Data invalida. Digite uma nova data. \n";
        }
    }
    do{
        cout << "Selecione uma opcao:\n";
        cout << "1 - Realizar leitura das estruturas\n";
        cout << "2 - Incluir Novo Registro na tabela de pessoas\n";
        cout << "3 - Incluir Novo registro na tabela de livros\n";
        cout << "4 - Realizar Emprestimo de Livro\n";
        cout << "5- Realizar Devolucao de Livro\n";
        cout << "6- Mostrar todos os livros emprestados\n";
        cout << "7- Mostrar Dados do Livro mais emprestado\n";
        cout << "8- Mostrar Dados do Livro menos emprestado\n";
        cout << "9- Mostrar Livros com Devolucao em atraso\n";
        cout << "10- Imprimir Lista De Pessoas\n";
        cout << "11- Imprimir Lista de Editoras\n";
        cout << "12-Imprimir lista de Autores\n";
        cout << "13-Imprimir Lista de Generos\n";
        cout << "14-Imprimir Lista de Livros\n";
        cout << "0 - Encerrar\n";
        cin >> opcao;
        system("cls");
        switch(opcao){
            case 1:
                cout << "Voce escolheu Realizar a leitura das estruturas\n";
                cout << "LEITURA DAS PESSOAS \n";
                leituraDePessoas(vPessoa, quantidadeDePessoas);
                system("cls");
                cout << "LEITURA DAS EDITORAS \n";
                leituraDeEditoras(vEditora, quantidadeDeEditoras);
                system("cls");
                cout << "LEITURA DOS AUTORES \n";
                leituraDeAutores(vAutores, quantidadeDeAutores);
                system("cls");
                cout << "LEITURA DOS GENEROS \n";
                leituraDeGeneros(vGeneros, quantidadeDeGeneros);
                system("cls");
                cout << "LEITURA DOS LIVROS \n";
                leituraDeLivros(vLivros, quantidadeDeLivros, vEditora, quantidadeDeEditoras, vAutores, quantidadeDeAutores, vGeneros, quantidadeDeGeneros);
                system("cls");
                break;
            case 2:
                cout << "Voce escolheu incluir novo registro na tabela de pessoas\n";
                //Leitura das Pessoas que serao adicionadas
                leituraDePessoas(vPessoaTemporario, quantidadeDePessoasParaSerAdicionado);
                insercaoNaTabelaDePessoas(vPessoa, vPessoaTemporario, vPessoaAtualizado, quantidadeDePessoas, quantidadeDePessoasParaSerAdicionado, quantidadeDePessoasDepoisDeAdicionado);
                cout << "Lista de Pessoas apos Adicao \n";

                system("cls");
                break;
            case 3:
                cout << "Voce escolheu incluir novo registro na tabela de livros\n";
                leituraDeLivros(vLivroTemporario, quantidadeDeLivrosParaSerAdicionado, vEditora, quantidadeDeEditoras, vAutores, quantidadeDeAutores, vGeneros, quantidadeDeGeneros);
                insercaoNaTabelaDeLivros(vLivros, vLivroTemporario, vLivroAtualizado, quantidadeDeLivros, quantidadeDeLivrosParaSerAdicionado, quantidadeDeLivrosDepoisDeAdicionado);
                system("cls");
                break;
            case 4:
                cout << "Voce escolheu realizar emprestimo de livro\n";
                realizaEmprestimoLivro(vLivroAtualizado, vEditora, vAutores, vPessoaAtualizado, quantidadeDeLivrosDepoisDeAdicionado, quantidadeDeEditoras, quantidadeDeAutores, quantidadeDeAutores);
                break;
            case 5:
                cout << "Voce escolheu realizar devolucao do livro\n";
                realizaDevolucaoLivro(vLivroAtualizado, vEditora, vAutores, quantidadeDeEditoras, quantidadeDeAutores, quantidadeDeLivrosDepoisDeAdicionado, vPessoaAtualizado, quantidadeDePessoasDepoisDeAdicionado);
                system("cls");
                break;
            case 6:
                cout << "Voce escolheu realizar mostrar todos os livros emprestados\n";
                mostraLivrosEmprestados(vLivroAtualizado, quantidadeDeLivrosDepoisDeAdicionado, vPessoaAtualizado, quantidadeDePessoasDepoisDeAdicionado);
                system("cls");
                break;
            case 7:
                cout << "Voce escolheu mostrar os dados do livro mais emprestado\n";
                mostraLivroMaisEmprestado(vLivroAtualizado, vEditora, vAutores, quantidadeDeLivrosDepoisDeAdicionado, quantidadeDeEditoras, quantidadeDeAutores);
                system("cls");
                break;
            case 8:
                cout << "Voce escolheu mostrar os dados do livro menos emprestado\n";
                mostraLivrosMenosEmprestados(vLivroAtualizado, vEditora, vAutores, quantidadeDeLivrosDepoisDeAdicionado, quantidadeDeEditoras, quantidadeDeAutores);
                system("cls");
                break;
            case 9:
                cout << "Voce escolheu mostrar os livros com devolucao em atraso\n";
                mostraDadosDeLivrosComDevolucaoEmAtraso(vLivroAtualizado, quantidadeDeLivrosDepoisDeAdicionado, diaDeHoje, vEditora, vAutores, quantidadeDeEditoras, quantidadeDeAutores);
                system("cls");
                break;
            case 10:
                cout << "Voce escolheu imprimir a lista de Pessoas\n";
                imprimeListaDePessoas(vPessoaAtualizado, quantidadeDePessoasDepoisDeAdicionado);
                break;
            case 11:
                cout << "Voce escolheu imprimir a lista de Editoras\n";
                break;
            case 12:
                cout << "Voce escolheu imprimir a lista de Autores\n";
                break;
            case 13:
                cout << "Voce escolheu imprimir a lista de Generos\n";
                break;
            case 14:
                cout << "Voce escolheu imprimir a lista de Livros\n";
                imprimeListaDeLivros(vLivroAtualizado, quantidadeDeLivrosDepoisDeAdicionado);
                break;
            case 0:
                cout << "Encerrando o programa...\n";
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    } while(opcao != 0);
    return 0;
}
