#include <iostream>
#include <conio.h>
#include <string.h>

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
    for(int i = 0; i < 10; i++)
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
    for(int i = 0; i < 10; i++)
    {
        cout << "\n\nCodigo da Editora " << (i+1) << ": ";
        cin >> vetEditora[i].codigo;
        cout << "Nome: ";
        gets(vetEditora[i].nome);
    }
}

void leituraDeAutores(Autores vetAutor[])
{
    for(int i = 0; i < 10; i++)
    {
        cout << "\n\nCodigo do Autor " << (i+1) << ": ";
        cin >> vetAutor[i].codigo;
        cout << "\nNome: ";
        gets(vetAutor[i].nome);
    }
}

void leituraDeGeneros(Generos vetGenero[])
{
    for(int i = 0; i < 10; i++)
    {
        cout << "\n\nCodigo do Genero " << (i+1) << ": ";
        cin >> vetGenero[i].codigo;
        cout << "\nNome: ";
        gets(vetGenero[i].descricao);
    }
}

void leituraDeLivros(Livros vetLivro[])
{

    bool dataValida = false;

    for(int i = 0; i < 10; i++)
    {
        cout << "\n\nCodigo do Livro " << (i+1) << ": ";
        cin >> vetLivro[i].codigo;
        cout << "Nome do Livro: ";
        gets(vetLivro[i].nome);
        cout << "\nCodigo da Editora do Livro: ";
        cin >> vetLivro[i].codigo_editora;
        cout << "Codigo do Autor do Livro: ";
        cin >> vetLivro[i].codigo_autor;
        cout << "Codigo do Genero do Livro: ";
        cin >> vetLivro[i].codigo_genero;
        cout << "Codigo da Pessoa que emprestou o livro";
        cin >> vetLivro[i].codigo_pessoa_emprestado;
        cout << "Digite a quantidade emprestada do livro";
        cin >> vetLivro[i].qtde_emprestada;
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

void inclusaoEmPessoas(Pessoas vPessoasS[], int contS, Pessoas vPessoasT[], int contT, Pessoas vPessoasA[], int &contA)
{
    int i = 0, j = 0, k = 0;
    for(; i< contS && j < contT; k++)
    {
        if(vPessoasS[i].codigo < vPessoasT[j].codigo)
        {
            vPessoasA[k].codigo = vPessoasS[i].codigo;
            strcpy(vPessoasA[k].nome, vPessoasS[i].nome);
            strcpy(vPessoasA[k].endereco, vPessoasS[i].endereco);
            i++;
        }
        else
        {
            vPessoasA[k].codigo = vPessoasT[j].codigo;
            strcpy(vPessoasA[k].nome, vPessoasT[j].nome);
            strcpy(vPessoasA[k].endereco, vPessoasT[j].endereco);
            j++;
        }
    }
    while(i < contS)
    {
        vPessoasA[k].codigo = vPessoasS[i].codigo;
        strcpy(vPessoasA[k].nome, vPessoasS[i].nome);
        strcpy(vPessoasA[k].endereco, vPessoasS[i].endereco);
        i++;
        k++;
    }
    while(j < contT)
    {
        vPessoasA[k].codigo = vPessoasT[j].codigo;
        strcpy(vPessoasA[k].nome, vPessoasT[j].nome);
        strcpy(vPessoasA[k].endereco, vPessoasT[j].endereco);
        j++;
        k++;
    }
    contA = k;
}

void mostrarListaDePessoasDepoisDaInsercao(Pessoas vPessoasA[], int contA)
{
    cout << "\n\nLista dos Registros de Pessoas no Arquivo Atualizado" << endl;
    for(int i = 0; i < contA; i++)
    {
        cout << "\nCodigo: " << vPessoasA[i].codigo;
        cout << "\tNome: " << vPessoasA[i].nome;
        cout << "\tEndereco: " << vPessoasA[i].endereco;
    }
}

void inclusaoEmLivros(Livros livrosS[], int contS, Livros livrosT[], int contT, Livros livrosA[], int &contA)
{
    int i = 0, j = 0, k = 0;
    for(; i < contS && j < contT; k++)
    {
        if(livrosS[i].codigo < livrosT[j].codigo)
        {
            livrosA[k].codigo = livrosS[i].codigo;
            strcpy(livrosA[k].nome, livrosS[i].nome);
            livrosA[k].codigo_editora = livrosS[i].codigo_editora;
            livrosA[k].codigo_autor = livrosS[i].codigo_autor;
            livrosA[k].codigo_genero = livrosS[i].codigo_genero;
            livrosA[k].codigo_pessoa_emprestado = livrosS[i].codigo_pessoa_emprestado;
            livrosA[k].qtde_emprestada = livrosS[i].qtde_emprestada;
            livrosA[k].data_ultimo_emprestimo = livrosS[i].data_ultimo_emprestimo;
            i++;
        }
        else
        {
            livrosA[k].codigo = livrosT[j].codigo;
            strcpy(livrosA[k].nome, livrosT[j].nome);
            livrosA[k].codigo_editora = livrosT[j].codigo_editora;
            livrosA[k].codigo_autor = livrosT[j].codigo_autor;
            livrosA[k].codigo_genero = livrosT[j].codigo_genero;
            livrosA[k].codigo_pessoa_emprestado = livrosT[j].codigo_pessoa_emprestado;
            livrosA[k].qtde_emprestada = livrosT[j].qtde_emprestada;
            livrosA[k].data_ultimo_emprestimo = livrosT[j].data_ultimo_emprestimo;
            j++;
        }
    }
    while(i < contS)
    {
        livrosA[k].codigo = livrosS[i].codigo;
        strcpy(livrosA[k].nome, livrosS[i].nome);
        livrosA[k].codigo_editora = livrosS[i].codigo_editora;
        livrosA[k].codigo_autor = livrosS[i].codigo_autor;
        livrosA[k].codigo_genero = livrosS[i].codigo_genero;
        livrosA[k].codigo_pessoa_emprestado = livrosS[i].codigo_pessoa_emprestado;
        livrosA[k].qtde_emprestada = livrosS[i].qtde_emprestada;
        livrosA[k].data_ultimo_emprestimo = livrosS[i].data_ultimo_emprestimo;
        i++;
        k++;
    }
    while(j < contT)
    {
        livrosA[k].codigo = livrosT[j].codigo;
        strcpy(livrosA[k].nome, livrosT[j].nome);
        livrosA[k].codigo_editora = livrosT[j].codigo_editora;
        livrosA[k].codigo_autor = livrosT[j].codigo_autor;
        livrosA[k].codigo_genero = livrosT[j].codigo_genero;
        livrosA[k].codigo_pessoa_emprestado = livrosT[j].codigo_pessoa_emprestado;
        livrosA[k].qtde_emprestada = livrosT[j].qtde_emprestada;
        livrosA[k].data_ultimo_emprestimo = livrosT[j].data_ultimo_emprestimo;
        j++;
        k++;
    }
    contA = k;
}

void mostraListaDeLivrosDepoisDaInsercao(Livros livrosA[], int contA)
{
    cout << "\n\nLista dos Livros no Arquivo Atualizado" << endl;
    for(int i = 0; i < contA; i++)
    {
        cout << "\nCodigo: " << livrosA[i].codigo;
        cout << "\tNome: " << livrosA[i].nome;
        cout << "\tCodigo Editora: " << livrosA[i].codigo_editora;
        cout << "\tCodigo Autor: " << livrosA[i].codigo_autor;
        cout << "\tCodigo Genero: " << livrosA[i].codigo_genero;
        cout << "\tCodigo da Pessoa que emprestou: " << livrosA[i].codigo_pessoa_emprestado;
        cout << "\tQuantidade Emprestada: " << livrosA[i].qtde_emprestada;
        cout << "\tData do Ultimo Emprestimo: " << livrosA[i].data_ultimo_emprestimo.dia << "/" << livrosA[i].data_ultimo_emprestimo.mes << "/" << livrosA[i].data_ultimo_emprestimo.ano;
    }
}

void buscaNaTabelaDeEditoras(Editoras vEditora[], int cod)
{
    int i = 0, f = 10;
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
        cout << "\n\n Editora Encontrada";
        cout << "\nCodigo da Editora: " << vEditora[m].codigo;
        cout << "\tNome: " << vEditora[m].nome;
    }
    else
    {
        cout << "\n\n Editora nao encontrada";
    }
}

void buscaNaTabelaDeAutores(Autores vAutor[], int cod)
{
    int i = 0, f = 10;
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
        cout << "\nCodigo do Autor: " << vAutor[m].codigo;
        cout << "\tNome: " << vAutor[m].nome;
    }
    else
    {
        cout << "\n\n Autor nao encontrado ";
    }
}

void buscaNaTabelaDeGenero(Generos vGenero[], int cod)
{
    int i = 0, f = 10;
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
        cout << "\nCodigo do Genero: " << vGenero[m].codigo;
        cout << "\tNome: " << vGenero[m].descricao;
    }
    else
    {
        cout << "\n\n Genero Nao Encontrado ";
    }
}

Livros buscaNaTabelaDeLivro(Livros vLivro[], int cod)
{
    int i = 0, f = 10;
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
        cout << "\nNome: " << vLivro[m].nome;
        cout << "\tCodigo Da Editora: " << vLivro[m].codigo_editora;
        cout << "\tCodigo Do Autor: " << vLivro[m].codigo_autor;
        cout << "\tCodigo do Genero: " << vLivro[m].codigo_genero;
        cout << "\tCodigo da Pessoa que emprestou: " << vLivro[m].codigo_pessoa_emprestado;
        cout << "\tQuantidade Emprestada: " << vLivro[m].qtde_emprestada;
        cout << "\tData Do Ultimo Emprestimo: " << vLivro[m].data_ultimo_emprestimo.dia << "/" << vLivro[m].data_ultimo_emprestimo.mes << vLivro[m].data_ultimo_emprestimo.ano;
        return vLivro[m];
    }
    else
    {
        cout << "\n\n Livro nao encontrado";
    }
}

void buscaNaTabelaDePessoa(Pessoas vPessoa[], int cod)
{
    int i = 0, f = 10;
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
        cout << "\n\n Pessoa Encontrada ";
        cout << "\nNome: " << vPessoa[m].nome;
        cout << "\tEndereco: " << vPessoa[m].endereco;
    }
    else
    {
        cout << "\n\n Pessoa nao encontrada!";
    }
}

void realizaEmprestimoLivro(Livros vLivro[], Editoras vEditoras[], Autores vAutores[])
{
    int codigoDoLivroDesejado;
    int codigoDaPessoaQueIraEmprestaroLivro;
    Livros livroParaEmprestar;
    int dataValida = false;
    cout << "Digite o codigo do livro que voce deseja emprestar: ";
    cin >> codigoDoLivroDesejado;
    livroParaEmprestar = buscaNaTabelaDeLivro(vLivro, codigoDoLivroDesejado);
    cout << "\nO livro que voce quer emprestar e: " << livroParaEmprestar.nome << "\n";
    buscaNaTabelaDeEditoras(vEditoras, livroParaEmprestar.codigo_editora);
    buscaNaTabelaDeAutores(vAutores, livroParaEmprestar.codigo_autor);
    if(livroParaEmprestar.codigo_pessoa_emprestado == 0)
    {
        cout << "Digite o codigo da pessoa que ira emprestar o livro: ";
        cin >> codigoDaPessoaQueIraEmprestaroLivro;
        livroParaEmprestar.codigo_pessoa_emprestado = codigoDaPessoaQueIraEmprestaroLivro;
        livroParaEmprestar.qtde_emprestada++;
        while(!dataValida)
        {
            cout << "Digite a data em que se esta realizando o emprestimo: (DD/MM/AAAA) ";
            char strData[11];
            sscanf(strData, "%d/%d/%d", &livroParaEmprestar.data_ultimo_emprestimo.dia, &livroParaEmprestar.data_ultimo_emprestimo.mes, &livroParaEmprestar.data_ultimo_emprestimo.ano);
            if(validaData(livroParaEmprestar.data_ultimo_emprestimo))
            {
                dataValida = true;
            }
            else
            {
                cout << "Data Invalida. Digite uma nova Data. \n";
            }
        }
    }
    else
    {
        cout << "Livro Indisponivel para emprestimo, o livro estara disponivel novamente em : ";
    }
}

void realizaDevolucaoLivro(Livros vLivro[], Editoras vEditora[], Autores vAutores[], Pessoas vPessoas[])
{
    char respConfirmacaoDevolucao;
    int codigoDoLivroParaSerDevolvido;
    Livros livroParaDevolver;
    livroParaDevolver = buscaNaTabelaDeLivro(vLivro, codigoDoLivroParaSerDevolvido);
    buscaNaTabelaDeEditoras(vEditora, livroParaDevolver.codigo_editora);
    buscaNaTabelaDeAutores(vAutores, livroParaDevolver.codigo_autor);
    if(livroParaDevolver.codigo_pessoa_emprestado != 0)
    {
        cout << "Nome do Livro: " << livroParaDevolver.nome << "\n";
        buscaNaTabelaDePessoa(vPessoas, livroParaDevolver.codigo_pessoa_emprestado);
        cout << "Voce confirma a devolucao ? (S para Sim/ N para Nao): \n";
        if(respConfirmacaoDevolucao == 'S')
        {
            cout << "Devolucao realizada com sucesso! \n";
            livroParaDevolver.codigo_pessoa_emprestado = 0;
        }
        else
        {
            cout << "Devolucao nao realizada! \n";
        }
    }
    else
    {
        cout << "Nao e possivel devolver um livro que nao foi emprestado!";
    }
}

void mostraLivrosEmprestados(Livros vLivro[], Pessoas vPessoa[], int quantidadeDeLivros)
{
    cout << "LIVROS EMPRESTADO: \n";
    int cont = 0;
    int quantidadeDeLivrosEmprestados = 0;
    int quantidadeDeLivrosDisponiveisParaEmprestimo = 0;
    while(cont < quantidadeDeLivros)
    {
        if(vLivro[cont].codigo_pessoa_emprestado != 0)
        {
            cout << "Codigo do Livro: " << vLivro[cont].codigo << "\n";
            cout << "Nome do Livro: " << vLivro[cont].nome << "\n";
            buscaNaTabelaDePessoa(vPessoa, vLivro[cont].codigo_pessoa_emprestado);
            quantidadeDeLivrosEmprestados++;
        }
        else
        {
            quantidadeDeLivrosDisponiveisParaEmprestimo++;
        }
        cont++;
    }
}

void mostraDadosDosLivroMaiseMenosEmprestado(Livros vLivro[], Editoras vEditora[], Autores vAutor[], int quantidadeDeLivros){
    Livros livroMaisEmprestado = vLivro[0];
    Livros livroMenosEmprestado = vLivro[0];

    for(int cont = 0; cont < quantidadeDeLivros; cont++){
        if(vLivro[cont].qtde_emprestada > livroMaisEmprestado.qtde_emprestada){
            livroMaisEmprestado = vLivro[cont];
        }
        if(vLivro[cont].qtde_emprestada < livroMenosEmprestado.qtde_emprestada){
            livroMenosEmprestado = vLivro[cont];
        }
    }

    cout << "LIVRO MAIS EMPRESTADO: /n";
    cout << "Codigo: " << livroMaisEmprestado.codigo << "\n";
    cout << "Nome do Livro: " << livroMaisEmprestado.nome << "\n";
    //buscaNaTabelaDeEditoras(livroMaisEmprestado.codigo_editora);
    //buscaNaTabelaDeAutores(livroMaisEmprestado.codigo_autor);
    cout << "Quantidade de vezes que foi emprestado: " << livroMaisEmprestado.qtde_emprestada << "\n";

    cout << "LIVRO MENOS EMPRESTADO: /n";
    //cout << "Codigo: " << livroMenosEmprestado.nome << "\n";
    //cout << "Nome do Livro: " < livroMenosEmprestado.nome << "\n";
   // buscaNaTabelaDeEditoras(livroMenosEmprestado, livroMenosEmprestado.codigo_editora);
   // buscaNaTabelaDeAutores(livroMaisEmprestado, livroMenosEmprestado.codigo_autor);
    //cout << "Quantidade de vezes que foi emprestado: " << livroMenosEmprestado.qtde_emprestada << "\n";
}

int main()
{
    Pessoas vPessoaS[10], vPessoaT[10], vPessoaA[20];
    Livros vLivroS[10], vLivroT[10], vLivroA[20];
    Editoras vEditoras[20];
    Autores vAutores[20];
    Generos vGeneros[20];
    int opcao;
    int contPessoaS, contPessoaT, contPessoaA;
    int contLivroS, contLivroT, contLivroA;

    do{
        cout << "Selecione uma opcao:\n";
        cout << "1 - Realizar Leitura das Estruturas \n";
        cout << "2 - Incluir novo registro na tabela de pessoas \n";
        cout << "3 - Incluir Novo registro na tabela de livros\n";
        cout << "4 - Realizar Emprestimo de Livro\n";
        cout << "5- Realizar Devolucao de Livro\n";
        cout << "6- Mostrar todos os livros emprestados\n";
        cout << "7- Mostrar Dados do Livro mais e menos emprestado\n";
        cout << "0- Encerrar\n";
        cin >> opcao;
        switch(opcao){
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
            leituraDeLivros(vLivroS);
            break;
        case 2:
            cout << "Voce escolheu incluir novo registro na tabela de pessoas \n";
            cout << "\n\nLeitura do Arquivo T de Pessoas";
            leituraDePessoas(vPessoaT);
            inclusaoEmPessoas(vPessoaS, contPessoaS, vPessoaT, contPessoaT, vPessoaA, contPessoaA);
            break;
        case 3:
            cout << "Voce escolheu incluir novo registro na tabela de livros \n";
            leituraDeLivros(vLivroT);
            inclusaoEmLivros(vLivroS, contLivroS, vLivroT, contLivroT, vLivroA, contLivroA);
            break;
        case 4:
            cout << "Voce escolheu realizar emprestimo de livro \n";
            break;
        case 5:
            cout << "Voce escolheu realizar devolucao de livro \n";
            break;
        case 6:
            cout << "Voce escolheu mostrar todos os livros emprestados \n";
            break;
        case 7:
            cout << "Voce escolheu mostrar dados dos livros mais e menos emprestados \n";
            break;
        case 0:
            cout << "Encerrando o programa...\n";
            break;
        default:
            cout << "Opcao Invalida. Tente novamente. \n";
            break;
        }
    } while(opcao != 0);
    return 0;
}
