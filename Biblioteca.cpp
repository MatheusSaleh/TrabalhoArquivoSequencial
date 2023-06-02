#include <iostream>
#include <conio.h>
#include <string.h>
#include <ctime>

using namespace std;

struct Data
{
    int dia;
    int mes;
    int ano;
};

struct Pessoas
{
    int codigo;
    char nome[40];
    char endereco[60];
};

struct Editoras
{
    int codigo;
    char nome[40];
};

struct Autores
{
    int codigo;
    char nome[40];
};

struct Generos
{
    int codigo;
    char descricao[40];
};

struct Livros
{
    int codigo;
    char nome[40];
    int codigo_editora;
    int codigo_autor;
    int codigo_genero;
    int codigo_pessoa_emprestado;
    int qtde_emprestada;
    Data data_ultimo_emprestimo;
};

bool validaData(Data data)
{
    if (data.mes < 1 || data.mes > 12)
    {
        return false;
    }

    if (data.dia < 1)
    {
        return false;
    }

    int diasNoMes = 31;
    if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
    {
        diasNoMes = 30;
    }
    else if (data.mes == 2)
    {
        if ((data.ano % 4 == 0 && data.ano % 100 != 0) || data.ano % 400 == 0)
        {
            diasNoMes = 29;
        }
        else
        {
            diasNoMes = 28;
        }
    }

    if (data.dia > diasNoMes)
    {
        return false;
    }

    return true;
}


void leituraDePessoas(Pessoas vetPessoa[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "\n\nCodigo da Pessoa " << (i+1) << ": ";
        cin >> vetPessoa[i].codigo;
        cin.ignore();
        cout << "Nome: ";
        gets(vetPessoa[i].nome);
        cout << "\nEndereco: ";
        gets(vetPessoa[i].endereco);
    }
}

void leituraDeEditoras(Editoras vetEditora[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "\n\nCodigo da Editora " << (i+1) << ": ";
        cin >> vetEditora[i].codigo;
        cin.ignore();
        cout << "Nome: ";
        gets(vetEditora[i].nome);
    }
}

void leituraDeAutores(Autores vetAutor[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "\n\nCodigo do Autor " << (i+1) << ": ";
        cin >> vetAutor[i].codigo;
        cin.ignore();
        cout << "\nNome: ";
        gets(vetAutor[i].nome);
    }
}

void leituraDeGeneros(Generos vetGenero[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "\n\nCodigo do Genero " << (i+1) << ": ";
        cin >> vetGenero[i].codigo;
        cin.ignore();
        cout << "\nNome: ";
        gets(vetGenero[i].descricao);
    }
}



void inclusaoEmPessoas(Pessoas vPessoasS[], Pessoas vPessoasT[], Pessoas vPessoasA[], int quantidadeDePessoasInicial, int quantidadeDePessoasTemporario, int quantidadeDePessoasAtualizado)
{
    int contPessoaInicial = 0;
    int contPessoaTemporario = 0;
    int contPessoaAtualizado = 0;

    while((contPessoaInicial < quantidadeDePessoasInicial) && (contPessoaTemporario < quantidadeDePessoasTemporario))
    {
        if(vPessoasS[contPessoaInicial].codigo < vPessoasT[contPessoaTemporario].codigo)
        {
            vPessoasA[contPessoaAtualizado].codigo = vPessoasS[contPessoaInicial].codigo;
            strcpy(vPessoasA[contPessoaAtualizado].nome, vPessoasS[contPessoaInicial].nome);
            strcpy(vPessoasA[contPessoaAtualizado].endereco, vPessoasS[contPessoaInicial].endereco);
            contPessoaInicial++;
        }
        else
        {
            vPessoasA[contPessoaAtualizado].codigo = vPessoasT[contPessoaTemporario].codigo;
            strcpy(vPessoasA[contPessoaAtualizado].nome, vPessoasT[contPessoaTemporario].nome);
            strcpy(vPessoasA[contPessoaAtualizado].endereco, vPessoasT[contPessoaTemporario].endereco);
            contPessoaTemporario++;
        }
        contPessoaAtualizado++;
    }

    while(contPessoaInicial < quantidadeDePessoasInicial)
    {
        vPessoasA[contPessoaAtualizado].codigo = vPessoasS[contPessoaInicial].codigo;
        strcpy(vPessoasA[contPessoaAtualizado].nome, vPessoasS[contPessoaInicial].nome);
        strcpy(vPessoasA[contPessoaAtualizado].endereco, vPessoasS[contPessoaInicial].endereco);
        contPessoaInicial++;
        contPessoaAtualizado++;
    }

    while(contPessoaTemporario < quantidadeDePessoasTemporario)
    {
        vPessoasA[contPessoaAtualizado].codigo = vPessoasT[contPessoaTemporario].codigo;
        strcpy(vPessoasA[contPessoaAtualizado].nome, vPessoasT[contPessoaTemporario].nome);
        strcpy(vPessoasA[contPessoaAtualizado].endereco, vPessoasT[contPessoaTemporario].endereco);
        contPessoaTemporario++;
        contPessoaAtualizado++;
    }

    cout << "\n\nLista dos Registros de Pessoa no Arquivo Atualizado " << endl;
    for(int i = 0; i < contPessoaAtualizado; i++)
    {
        cout << "\nCodigo: " << vPessoasA[i].codigo;
        cout << "\tNome: " << vPessoasA[i].nome;
        cout << "\tEndereco: " << vPessoasA[i].endereco << "\n";
    }
}

void inclusaoEmLivros(Livros vLivroS[], Livros vLivroT[], Livros vLivroA[], int quantidadeDeLivrosInicial, int quantidadeDeLivrosTemporario, int quantidadeDeLivrosAtualizado)
{
    int contLivroInicial = 0;
    int contLivroTemporario = 0;
    int contLivroAtualizado = 0;

    while((contLivroInicial < quantidadeDeLivrosInicial) && (contLivroTemporario < quantidadeDeLivrosTemporario))
    {
        if(vLivroS[contLivroInicial].codigo < vLivroT[contLivroTemporario].codigo)
        {
            vLivroA[contLivroAtualizado].codigo = vLivroS[contLivroInicial].codigo;
            strcpy(vLivroA[contLivroAtualizado].nome, vLivroS[contLivroInicial].nome);
            vLivroA[contLivroAtualizado].codigo_editora = vLivroS[contLivroInicial].codigo_editora;
            vLivroA[contLivroAtualizado].codigo_autor = vLivroS[contLivroInicial].codigo_autor;
            vLivroA[contLivroAtualizado].codigo_genero = vLivroS[contLivroInicial].codigo_genero;
            vLivroA[contLivroAtualizado].codigo_pessoa_emprestado = vLivroS[contLivroInicial].codigo_pessoa_emprestado;
            vLivroA[contLivroAtualizado].qtde_emprestada = vLivroS[contLivroInicial].qtde_emprestada;
            vLivroA[contLivroAtualizado].data_ultimo_emprestimo = vLivroS[contLivroInicial].data_ultimo_emprestimo;
            contLivroInicial++;
        }
        else
        {
            vLivroA[contLivroAtualizado].codigo = vLivroT[contLivroTemporario].codigo;
            strcpy(vLivroA[contLivroAtualizado].nome, vLivroT[contLivroTemporario].nome);
            vLivroA[contLivroAtualizado].codigo_editora = vLivroT[contLivroTemporario].codigo_editora;
            vLivroA[contLivroAtualizado].codigo_autor = vLivroT[contLivroTemporario].codigo_autor;
            vLivroA[contLivroAtualizado].codigo_genero = vLivroT[contLivroTemporario].codigo_genero;
            vLivroA[contLivroAtualizado].codigo_pessoa_emprestado = vLivroT[contLivroTemporario].codigo_pessoa_emprestado;
            vLivroA[contLivroAtualizado].qtde_emprestada = vLivroT[contLivroTemporario].qtde_emprestada;
            vLivroA[contLivroAtualizado].data_ultimo_emprestimo = vLivroT[contLivroTemporario].data_ultimo_emprestimo;
            contLivroTemporario++;
        }
        contLivroAtualizado++;
    }

    while(contLivroInicial < quantidadeDeLivrosInicial)
    {
        vLivroA[contLivroAtualizado].codigo = vLivroS[contLivroInicial].codigo;
        strcpy(vLivroA[contLivroAtualizado].nome, vLivroS[contLivroInicial].nome);
        vLivroA[contLivroAtualizado].codigo_editora = vLivroS[contLivroInicial].codigo_editora;
        vLivroA[contLivroAtualizado].codigo_autor = vLivroS[contLivroInicial].codigo_autor;
        vLivroA[contLivroAtualizado].codigo_genero = vLivroS[contLivroInicial].codigo_genero;
        vLivroA[contLivroAtualizado].codigo_pessoa_emprestado = vLivroS[contLivroInicial].codigo_pessoa_emprestado;
        vLivroA[contLivroAtualizado].qtde_emprestada = vLivroS[contLivroInicial].qtde_emprestada;
        vLivroA[contLivroAtualizado].data_ultimo_emprestimo = vLivroT[contLivroTemporario].data_ultimo_emprestimo;
        contLivroInicial++;
        contLivroAtualizado++;
    }

    while(contLivroTemporario < quantidadeDeLivrosTemporario)
    {
        vLivroA[contLivroAtualizado].codigo = vLivroT[contLivroTemporario].codigo;
        strcpy(vLivroA[contLivroAtualizado].nome, vLivroT[contLivroTemporario].nome);
        vLivroA[contLivroAtualizado].codigo_editora = vLivroT[contLivroTemporario].codigo_editora;
        vLivroA[contLivroAtualizado].codigo_autor = vLivroT[contLivroTemporario].codigo_autor;
        vLivroA[contLivroAtualizado].codigo_genero = vLivroT[contLivroTemporario].codigo_genero;
        vLivroA[contLivroAtualizado].codigo_pessoa_emprestado = vLivroT[contLivroTemporario].codigo_pessoa_emprestado;
        vLivroA[contLivroAtualizado].qtde_emprestada = vLivroT[contLivroTemporario].qtde_emprestada;
        vLivroA[contLivroAtualizado].data_ultimo_emprestimo = vLivroT[contLivroTemporario].data_ultimo_emprestimo;
        contLivroTemporario++;
        contLivroAtualizado++;
    }

    cout << "\n\nLista dos Registros de Livro No Arquivo Atualizado" << endl;
    for(int i = 0; i < contLivroAtualizado; i++)
    {
        cout << "\nCod.: " << vLivroA[i].codigo;
        cout << "\tNome: " << vLivroA[i].nome;
        cout << "\tCod.Editora: " << vLivroA[i].codigo_editora;
        cout << "\tCod.Autor: " << vLivroA[i].codigo_autor;
        cout << "\tCod.Genero: " << vLivroA[i].codigo_genero;
        cout << "\tCod.Pessoa: " << vLivroA[i].codigo_pessoa_emprestado;
        cout << "\tQtd Emprestada: " << vLivroA[i].qtde_emprestada;
        cout << "\tData Ult. Emp.: " << vLivroA[i].data_ultimo_emprestimo.dia << "/" << vLivroA[i].data_ultimo_emprestimo.mes << "/" << vLivroA[i].data_ultimo_emprestimo.ano << "\n";
    }
}


Editoras buscaNaTabelaDeEditoras(Editoras vEditora[], int cod)
{
    int i = 0, f = 3;
    int m = (i + f) / 2;
    for(; f >= i && cod != vEditora[m].codigo; m = (i + f) / 2)
    {
        if(cod > vEditora[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == vEditora[m].codigo)
    {
        cout << "\n\n Editora Encontrada\n";
        cout << "\nCodigo da Editora: " << vEditora[m].codigo << "\n\n";
        cout << "\tNome: " << vEditora[m].nome << "\n";
        return vEditora[m];
    }
    else
    {
        cout << "\n\n Editora nao encontrada";
    }
}

Autores buscaNaTabelaDeAutores(Autores vAutor[], int cod)
{
    int i = 0, f = 3;
    int m = (i + f) / 2;
    for(; f >= i && cod != vAutor[m].codigo; m = (i + f) / 2)
    {
        if(cod > vAutor[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == vAutor[m].codigo)
    {
        cout << "\n\n Autor Encontrado";
        cout << "\nCodigo do Autor: " << vAutor[m].codigo << "\n\n";
        cout << "\tNome: " << vAutor[m].nome << "\n";
        return vAutor[m];
    }
    else
    {
        cout << "\n\n Autor nao encontrado " << "\n";
    }
}

Generos buscaNaTabelaDeGenero(Generos vGenero[], int cod)
{
    int i = 0, f = 3;
    int m = (i + f) / 2;
    for(; f >= i && cod != vGenero[m].codigo; m = (i + f) / 2)
    {
        if(cod > vGenero[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == vGenero[m].codigo)
    {
        cout << "\n\n Genero Encontrado";
        cout << "\nCodigo do Genero: " << vGenero[m].codigo << "\n\n";
        cout << "\tNome: " << vGenero[m].descricao << "\n";
        return vGenero[m];
    }
    else
    {
        cout << "\n\n Genero Nao Encontrado"  << "\n";
    }
}

Livros buscaNaTabelaDeLivro(Livros vLivro[], int cod)
{
    int i = 0, f = 3;
    int m = (i + f) / 2;
    for(; f >= i && cod != vLivro[m].codigo; m = (i + f ) / 2)
    {
        if(cod > vLivro[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == vLivro[m].codigo)
    {
        cout << "\n\n Livro Encontrado";
        cout << "\nNome: " << vLivro[m].nome << "\n";
        cout << "\tCodigo Da Editora: " << vLivro[m].codigo_editora << "\n";
        cout << "\tCodigo Do Autor: " << vLivro[m].codigo_autor << "\n";
        cout << "\tCodigo do Genero: " << vLivro[m].codigo_genero << "\n";
        cout << "\tCodigo da Pessoa que emprestou: " << vLivro[m].codigo_pessoa_emprestado << "\n";
        cout << "\tQuantidade Emprestada: " << vLivro[m].qtde_emprestada << "\n";
        cout << "\tData Do Ultimo Emprestimo: " << vLivro[m].data_ultimo_emprestimo.dia << "/" << vLivro[m].data_ultimo_emprestimo.mes << "/" << vLivro[m].data_ultimo_emprestimo.ano << "\n";
        return vLivro[m];
    }
    else
    {
        cout << "\n\n Livro nao encontrado \n";
    }
}

Pessoas buscaNaTabelaDePessoa(Pessoas vPessoa[], int cod)
{
    int i = 0, f = 3;
    int m = (i + f) / 2;
    for(; f >= i && cod != vPessoa[m].codigo; m = (i+f) / 2)
    {
        if(cod > vPessoa[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if(cod == vPessoa[m].codigo)
    {
        cout << "\n\n Pessoa Encontrada " << "\n";
        cout << "\nNome: " << vPessoa[m].nome << "\n";
        cout << "\tEndereco: " << vPessoa[m].endereco << "\n";
        return vPessoa[m];
    }
    else
    {
        cout << "\n\n Pessoa nao encontrada!" << "\n";
        Pessoas pessoaInvalida;
        return pessoaInvalida;
    }
}

void leituraDeLivros(Livros vetLivro[], Editoras vEditora[], Autores vAutor[], Generos vGenero[])
{
    int codigoEditora;

    for(int i = 0; i < 3; i++)
    {
        bool dataValida = false;

        cout << "\n\nCodigo do Livro " << (i+1) << ": ";
        cin >> vetLivro[i].codigo;
        cin.ignore();
        cout << "Nome do Livro: ";
        gets(vetLivro[i].nome);
        cout << "\nCodigo da Editora do Livro: ";
        cin >> vetLivro[i].codigo_editora;
        codigoEditora = vetLivro[i].codigo_editora;
        cin.ignore();
        buscaNaTabelaDeEditoras(vEditora, codigoEditora);
        cout << "Codigo do Autor do Livro: ";
        cin >> vetLivro[i].codigo_autor;
        cin.ignore();
        buscaNaTabelaDeAutores(vAutor, vetLivro[i].codigo_autor);
        cout << "Codigo do Genero do Livro: ";
        cin >> vetLivro[i].codigo_genero;
        cin.ignore();
        buscaNaTabelaDeGenero(vGenero, vetLivro[i].codigo_genero);
        cout << "Codigo da Pessoa que emprestou o livro: ";
        cin >> vetLivro[i].codigo_pessoa_emprestado;
        cin.ignore();
        cout << "Digite a quantidade emprestada do livro: ";
        cin >> vetLivro[i].qtde_emprestada;
        cin.ignore();

        while(!dataValida)
        {
            cout << "Digite a data do ultimo emprestimo (DD/MM/AAAA): ";
            char strData[11];
            gets(strData);
            sscanf(strData, "%d/%d/%d", &vetLivro[i].data_ultimo_emprestimo.dia, &vetLivro[i].data_ultimo_emprestimo.mes, &vetLivro[i].data_ultimo_emprestimo.ano);
            if(validaData(vetLivro[i].data_ultimo_emprestimo))
            {
                dataValida = true;
            }
            else
            {
                cout << "Data invalida. Digite uma nova data. \n";
            }
        }
    }
}

void realizarEmprestimo(Livros* livros, int codigoPessoa, int codigoLivro, Editoras* vEditora, Autores* vAutores)
{
    Livros livroQueVaiSerEmprestado = buscaNaTabelaDeLivro(livros, codigoLivro);
    buscaNaTabelaDeEditoras(vEditora, livroQueVaiSerEmprestado.codigo_editora);
    buscaNaTabelaDeAutores(vAutores, livroQueVaiSerEmprestado.codigo_autor);
    for (int i = 0; i < 6; i++)
    {
        if (livros[i].codigo == codigoLivro)
        {
            if (livros[i].codigo_pessoa_emprestado == 0)
            {
                livros[i].codigo_pessoa_emprestado = codigoPessoa;
                livros[i].qtde_emprestada += 1;

                time_t now = time(nullptr);
                tm* localTime = localtime(&now);

                livros[i].data_ultimo_emprestimo.dia = localTime->tm_mday;
                livros[i].data_ultimo_emprestimo.mes = localTime->tm_mon + 1;
                livros[i].data_ultimo_emprestimo.ano = localTime->tm_year + 1900;

                cout << "Emprestimo realizado com sucesso!" << std::endl;

                cout << "\n\n LISTA DE LIVRO DEPOIS DO EMPRESTIMO\n";
                for(int i = 0; i < 6; i++)
                {
                    cout << "\nCod.: " << livros[i].codigo;
                    cout << "\tNome: " << livros[i].nome;
                    cout << "\tCod.Editora: " << livros[i].codigo_editora;
                    cout << "\tCod. Autor: " << livros[i].codigo_autor;
                    cout << "\tCod. Genero: " << livros[i].codigo_genero;
                    cout << "\tCod. Pessoa: " << livros[i].codigo_pessoa_emprestado;
                    cout << "\tQtd Emprestada: " << livros[i].qtde_emprestada;
                    cout << "\tData Ultm Emp.: " << livros[i].data_ultimo_emprestimo.dia << "/" << livros[i].data_ultimo_emprestimo.mes << "/" << livros[i].data_ultimo_emprestimo.ano << "\n";
                }

                return;
            }
            else
            {
                cout << "O Livro já está emprestado." << endl;

                struct tm dueDate = {0};
                dueDate.tm_mday = livros[i].data_ultimo_emprestimo.dia + 5;
                dueDate.tm_mon = livros[i].data_ultimo_emprestimo.mes - 1;
                dueDate.tm_year = livros[i].data_ultimo_emprestimo.ano - 1900;

                time_t dueTime = mktime(&dueDate);
                tm* localDueTime = localtime(&dueTime);

                cout << "O livro estara disponivel novamente em: " << localDueTime->tm_mday << "/" << localDueTime->tm_mon + 1 << "/" << localDueTime->tm_year + 1900 << endl;

                return;
            }
        }
    }

    std::cout << "Livro não encontrado." << std::endl;
}

void realizaDevolucaoLivro(Livros* vLivro, int codigoLivro, Editoras* vEditora, Autores* vAutor, Pessoas* vPessoa)
{
    int usuarioConfirmaDevolver;
    Livros livroQueVaiSerDevolvido = buscaNaTabelaDeLivro(vLivro, codigoLivro);
    buscaNaTabelaDeEditoras(vEditora, livroQueVaiSerDevolvido.codigo_editora);
    buscaNaTabelaDeAutores(vAutor, livroQueVaiSerDevolvido.codigo_autor);
    for(int i = 0; i < 6; i++)
    {
        if(vLivro[i].codigo == codigoLivro)
        {
            if(vLivro[i].codigo_pessoa_emprestado != 0)
            {
                buscaNaTabelaDePessoa(vPessoa, vLivro[i].codigo_pessoa_emprestado);
                cout << "\nVoce Confirma a Devolucao do Livro ? (1 Para Sim/0 Para Nao): ";
                cin >> usuarioConfirmaDevolver;
                if(usuarioConfirmaDevolver == 1)
                {
                    vLivro[i].codigo_pessoa_emprestado = 0;
                    cout << "\nDevolucao Confirmada com sucesso!\n";
                    cout << "\n\nLISTA DE LIVROS DEPOIS DA DEVOLUCAO";
                    for(int i = 0; i < 6; i++){
                        cout << "\nCod.: " << vLivro[i].codigo;
                        cout << "\tNome.: " << vLivro[i].nome;
                        cout << "\tCod.Editora: " << vLivro[i].codigo_editora;
                        cout << "\tCod.Autor: " << vLivro[i].codigo_autor;
                        cout << "\tCod. Genero: " << vLivro[i].codigo_genero;
                        cout << "\tCod. Pessoa: " << vLivro[i].codigo_pessoa_emprestado;
                        cout << "\tQtde Emprestada " << vLivro[i].qtde_emprestada;
                        cout << "\tData Ultm Emp.: " << vLivro[i].data_ultimo_emprestimo.dia << "/" << vLivro[i].data_ultimo_emprestimo.mes << "/" << vLivro[i].data_ultimo_emprestimo.ano << "\n";
                    }
                    return;
                }
                else
                {
                    cout << "\nDevolucao Cancelada";
                    return;
                }
            }
        }
        else
        {
            cout << "Nao e possivel devolver um livro que nao esta emprestado" << endl;
            return;
        }
    }
}

void mostraLivrosEmprestados(Livros* vLivro, Pessoas* vPessoa){
    int quantidadeDeLivrosEmprestados = 0;
    cout << "\n\n LIVROS EMPRESTADOS\n";
    for(int i = 0; i < 6; i++){
        if(vLivro[i].codigo_pessoa_emprestado != 0){
            cout << "\nCod.: " << vLivro[i].codigo;
            cout << "\tNome: " << vLivro[i].nome;
            cout << "\tCod.Editora: " << vLivro[i].codigo_editora;
            cout << "\tCod. Autor: " << vLivro[i].codigo_autor;
            cout << "\tCod. Genero: " << vLivro[i].codigo_genero;
            cout << "\tCod. Pessoa: " << vLivro[i].codigo_pessoa_emprestado;
            cout << "\tQtd Emprestada: " << vLivro[i].qtde_emprestada;
            cout << "\tData Ultm Emp.: " << vLivro[i].data_ultimo_emprestimo.dia << "/" << vLivro[i].data_ultimo_emprestimo.mes << "/" << vLivro[i].data_ultimo_emprestimo.ano << "\n";

            Pessoas pessoaEmprestada = buscaNaTabelaDePessoa(vPessoa, vLivro[i].codigo_pessoa_emprestado);
            if(pessoaEmprestada.codigo != -1){
                cout << "\nNome da Pessoa: " << pessoaEmprestada.nome << "\n";
                cout << "\tEndereco: " << pessoaEmprestada.endereco << "\n";
            }
            else{
                cout << "\nEsse livro nao foi emprestado por nenhuma pessoa!\n";
            }
            quantidadeDeLivrosEmprestados++;
        }
    }
    cout << "\nHa um total de " << quantidadeDeLivrosEmprestados << " livros disponiveis para emprestimo \n";
}

void mostraLivroMaisMenosEmprestado(Livros* vLivro, Editoras* vEditora, Autores* vAutor){
    Livros livroMaisEmprestado = vLivro[0];
    Livros livroMenosEmprestado = vLivro[0];
    for(int i = 0; i < 6; i++){
        if(vLivro[i].qtde_emprestada > livroMaisEmprestado.qtde_emprestada)
            livroMaisEmprestado = vLivro[i];
        if(vLivro[i].qtde_emprestada < livroMenosEmprestado.qtde_emprestada)
            livroMenosEmprestado = vLivro[i];
    }

    cout << "\n\nINFORMACOES DO LIVRO MENOS EMPRESTADO \n";
    cout << "\nCod.: " << livroMenosEmprestado.codigo;
    cout << "\tNome: " << livroMenosEmprestado.nome;
    cout << "\tCod. Editora: " << livroMenosEmprestado.codigo_editora;
    cout << "\tCod. Autor: " << livroMenosEmprestado.codigo_autor;
    cout << "\tCod. Genero: " << livroMenosEmprestado.codigo_genero;
    cout << "\tCod. Pessoa: " << livroMenosEmprestado.codigo_pessoa_emprestado;
    cout << "\tQtd Emprestada: " << livroMenosEmprestado.qtde_emprestada;
    cout << "\tData Ultm Emp.: " << livroMenosEmprestado.data_ultimo_emprestimo.dia << "/" << livroMenosEmprestado.data_ultimo_emprestimo.mes << "/" << livroMenosEmprestado.data_ultimo_emprestimo.ano << "\n";
    buscaNaTabelaDeEditoras(vEditora, livroMenosEmprestado.codigo_editora);
    buscaNaTabelaDeAutores(vAutor, livroMenosEmprestado.codigo_autor);


    cout << "\n\nINFORMACOES DO LIVRO MAIS EMPRESTADO \n";
    cout << "\nCod.: " << livroMaisEmprestado.codigo;
    cout << "\tNome: " << livroMaisEmprestado.nome;
    cout << "\tCod. Editora: " << livroMaisEmprestado.codigo_editora;
    cout << "\tCod. Autor: " << livroMaisEmprestado.codigo_autor;
    cout << "\tCod. Genero: " << livroMaisEmprestado.codigo_genero;
    cout << "\tCod. Pessoa: " << livroMaisEmprestado.codigo_pessoa_emprestado;
    cout << "\tQtd Emprestada: " << livroMaisEmprestado.qtde_emprestada;
    cout << "\tData Ultm Emp.: " << livroMaisEmprestado.data_ultimo_emprestimo.dia << "/" << livroMaisEmprestado.data_ultimo_emprestimo.mes << "/" << livroMaisEmprestado.data_ultimo_emprestimo.ano << "\n";
    buscaNaTabelaDeEditoras(vEditora, livroMaisEmprestado.codigo_editora);
    buscaNaTabelaDeAutores(vAutor, livroMaisEmprestado.codigo_autor);
}

int diferencaDias(Data data1, Data data2)
{
    std::tm tm1 = { 0 };
    tm1.tm_year = data1.ano - 1900;
    tm1.tm_mon = data1.mes - 1;
    tm1.tm_mday = data1.dia;

    std::tm tm2 = { 0 };
    tm2.tm_year = data2.ano - 1900;
    tm2.tm_mon = data2.mes - 1;
    tm2.tm_mday = data2.dia;

    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);

    const int secondsPerDay = 60 * 60 * 24;
    int diffDays = (time2 - time1) / secondsPerDay;

    return diffDays;
}

void mostrarLivrosAtrasados(Livros* vLivro, int quantidadeDeLivros, Editoras* vEditora, Autores* vAutor){
    time_t now;
    time(&now);
    struct tm* data = localtime(&now);

    Data dataAtual;
    dataAtual.dia = data->tm_mday;
    dataAtual.mes = data->tm_mon + 1;
    dataAtual.ano = data->tm_year + 1900;

    cout << "\nLIVROS EM ATRASO\n";
    for(int i = 0; i < quantidadeDeLivros; i++){
        if(vLivro[i].codigo_pessoa_emprestado != 0 && diferencaDias(vLivro[i].data_ultimo_emprestimo, dataAtual) > 5){
            cout << "\nCod.:" << vLivro[i].codigo;
            cout << "\tNome: " << vLivro[i].nome;
            cout << "\tCod. Editora: " << vLivro[i].codigo_editora;
            cout << "\tCod. Autor: " << vLivro[i].codigo_autor;
            cout << "\tCod. Genero: " << vLivro[i].codigo_genero;
            cout << "\tCod. Pessoa: " << vLivro[i].codigo_pessoa_emprestado;
            cout << "\tQtd Emprestada: " << vLivro[i].qtde_emprestada;
            cout << "\tDias em atraso: " << diferencaDias(vLivro[i].data_ultimo_emprestimo, dataAtual);
            cout << "\tData Ultm Emp.: " << vLivro[i].data_ultimo_emprestimo.dia << "/" << vLivro[i].data_ultimo_emprestimo.mes << "/" << vLivro[i].data_ultimo_emprestimo.ano << "\n";
            buscaNaTabelaDeEditoras(vEditora, vLivro[i].codigo_editora);
            buscaNaTabelaDeAutores(vAutor, vLivro[i].codigo_autor);
        }
    }
}


int main()
{
    Pessoas vPessoaS[3], vPessoaT[3], vPessoaA[6];
    Livros vLivroS[3], vLivroT[3], vLivroA[6];
    Editoras vEditoras[3];
    Autores vAutores[3];
    Generos vGeneros[3];
    int opcao;
    int contPessoaS, contPessoaT, contPessoaA;
    int contLivroS, contLivroT, contLivroA;
    int codigoDoLivroQueSeraEmprestado;
    int codigoDaPessoaQueVaiEmprestar;
    int codigoDoLivroQueVaiSerDevolvido;

    do
    {
        cout << "Selecione uma opcao:\n";
        cout << "1 - Realizar Leitura das Estruturas \n";
        cout << "2 - Incluir novo registro na tabela de pessoas \n";
        cout << "3 - Incluir Novo registro na tabela de livros\n";
        cout << "4 - Realizar Emprestimo de Livro\n";
        cout << "5- Realizar Devolucao de Livro\n";
        cout << "6- Mostrar todos os livros emprestados\n";
        cout << "7- Mostrar Dados do Livro mais e menos emprestado\n";
        cout << "8- Mostrar livros com devolucao em atraso\n";
        cout << "0- Encerrar\n";
        cin >> opcao;
        switch(opcao)
        {
        case 1:
            cout << "Voce escolheu realizar leitura das estruturas \n";

            cout << "\n\nLeitura do Arquivo S de Pessoas";
            leituraDePessoas(vPessoaS);

            cout << "\n\nLeitura da Editoras";
            leituraDeEditoras(vEditoras);


            cout << "\n\nLeitura de Autores";
            leituraDeAutores(vAutores);

            cout << "\n\nLeitura de Generos";
            leituraDeGeneros(vGeneros);

            cout << "\n\nLeitura do Arquivo S de Livros";
            leituraDeLivros(vLivroS, vEditoras, vAutores, vGeneros);

            break;
        case 2:
            cout << "Voce escolheu incluir novo registro na tabela de pessoas \n";
            cout << "\n\nLeitura do Arquivo T de Pessoas";
            leituraDePessoas(vPessoaT);

            inclusaoEmPessoas(vPessoaS, vPessoaT, vPessoaA, 3, 3, 6);

            break;
        case 3:
            cout << "Voce escolheu incluir novo registro na tabela de livros \n";
            cout << "\n\nLeitura do Arquivo T de Livros";
            leituraDeLivros(vLivroT, vEditoras, vAutores, vGeneros);

            inclusaoEmLivros(vLivroS, vLivroT, vLivroA, 3, 3, 6);

            break;
        case 4:
            cout << "Voce escolheu realizar emprestimo de livro \n";
            cout << "Digite o codigo do livro que voce deseja emprestar: ";
            cin >> codigoDoLivroQueSeraEmprestado;
            cout << "Digite o codigo da pessoa que vai emprestar esse livro: ";
            cin >> codigoDaPessoaQueVaiEmprestar;
            realizarEmprestimo(vLivroA, codigoDaPessoaQueVaiEmprestar, codigoDoLivroQueSeraEmprestado, vEditoras, vAutores);
            break;
        case 5:
            cout << "Voce escolheu realizar devolucao de livro \n";
            cout << "Digite o codigo do livro que voce deseja devolver: ";
            cin >> codigoDoLivroQueVaiSerDevolvido;
            realizaDevolucaoLivro(vLivroA, codigoDoLivroQueVaiSerDevolvido, vEditoras, vAutores, vPessoaA);
            break;
        case 6:
            cout << "Voce escolheu mostrar todos os livros emprestados \n";
            mostraLivrosEmprestados(vLivroA, vPessoaA);
            break;
        case 7:
            cout << "Voce escolheu mostrar dados dos livros mais e menos emprestados \n";
            mostraLivroMaisMenosEmprestado(vLivroA, vEditoras, vAutores);
            break;
        case 8:
            cout << "Voce escolheu mostrar os livros com devolucao em atraso \n";
            mostrarLivrosAtrasados(vLivroA, 6, vEditoras, vAutores);
            break;
        case 0:
            cout << "Encerrando o programa...\n";
            break;
        default:
            cout << "Opcao Invalida. Tente novamente. \n";
            break;
        }
    }
    while(opcao != 0);
    return 0;
}
