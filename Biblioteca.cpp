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
            cout << "Nome: " << vEditora[meio].nome << endl;
            return meio;
        } else if (vEditora[meio].codigo < chave) {
            return buscaBinariaNaTabelaDeEditoras(vEditora, meio + 1, fim, chave);
        } else {
            return buscaBinariaNaTabelaDeEditoras(vEditora, inicio, meio - 1, chave);
        }
    } else {
        cout << "Editora nao encontrada" << endl;
        return -1;
    }
}

int buscaBinariaNaTabelaDeAutores(Autores vAutores[], int inicio, int fim, int chave){
    if(inicio <= fim){
        int meio = (inicio+fim) / 2;
        if(vAutores[meio].codigo == chave){
            cout << "Autor Encontrado!" << endl;
            cout << "Nome: " << vAutores[meio].nome << endl;
            return meio;
        }else if (vAutores[meio].codigo < chave){
            return buscaBinariaNaTabelaDeAutores(vAutores, meio + 1, fim, chave);
        } else{
            return buscaBinariaNaTabelaDeAutores(vAutores, inicio, meio - 1, chave);
        }
    } else{
        cout << "Autor nao encontrado " << endl;
        return -1;
    }
}

int buscaBinariaNaTabelaDeGeneros(Generos vGeneros[], int inicio, int fim, int chave){
    if(inicio <= fim){
        int meio = (inicio+fim) / 2;
        if(vGeneros[meio].codigo == chave){
            cout << "Genero Encontrado!" << endl;
            cout << "Descricao do Genero: " << vGeneros[meio].descricao << endl;
            return meio;
        }else if(vGeneros[meio].codigo < chave){
            return buscaBinariaNaTabelaDeGeneros(vGeneros, meio+1, fim, chave);
        } else{
            return buscaBinariaNaTabelaDeGeneros(vGeneros, inicio, meio - 1, chave);
        }
    } else{
        cout << "Genero nao encontrado " << endl;
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
        cout << "Livro nao encontrado" << endl;
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

void realizaEmprestimoLivro(Livros vLivro[], Editoras vEditoras[], Autores vAutores[], Pessoas vPessoas[], int quantidadeDeLivrosNoVetorDeLivro, int quantidadeDeEditoras, int quantidadeDeAutores, int quantidadeDePessoas){
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
    posicaoDaEditoraEncontrada = buscaBinariaNaTabelaDeEditoras(vEditoras, 0, quantidadeDeEditoras - 1, vLivro[codigoDoLivroDesejado].codigo_editora);
    posicaoDoAutorEncontrado = buscaBinariaNaTabelaDeAutores(vAutores, 0, quantidadeDeAutores - 1, vLivro[codigoDoLivroDesejado].codigo_autor);
    if(vLivro[codigoDoLivroDesejado].codigo_pessoa_emprestado == 0){
        cout << "Este livro esta disponivel para emprestimo! " << endl;
        cout << "Digite o codigo da pessoa que deseja emprestar o livro: ";
        cin >> codigoDaPessoaQueIraEmprestarLivro;
        posicaoDaPessoaEncontrada = buscaBinariaNaTabelaDePessoas(vPessoas, 0, quantidadeDePessoas - 1, vLivro[codigoDoLivroDesejado].codigo_pessoa_emprestado);
        vLivro[codigoDoLivroDesejado].qtde_emprestada++;
        while(!dataValida){
            cout << "Digite a data em que se esta realizando o emprestimo: (DD/MM/AAAA): ";
            char strData[11];
            gets(strData);
            sscanf(strData, "%d/%d/%d", &vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.dia, &vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.mes, &vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.ano);
            if(validaData(vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo)){
                dataValida = true;
            }else{
                cout << "Data invalida. Digite uma nova data. \n";
            }
        }
    }else{
        cout << "Nao e possivel realizar o emprestimo esse livro nao esta disponivel";
        data_disponivel.dia = vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.dia + 5;
        data_disponivel.mes = vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.mes;
        data_disponivel.ano = vLivro[codigoDoLivroDesejado].data_ultimo_emprestimo.ano;

        if(data_disponivel.dia > 31){
            data_disponivel.dia -= 31;
            data_disponivel.mes++;
        }
        if(data_disponivel.mes > 12){
            data_disponivel.mes = 1;
            data_disponivel.ano++;
        }

        cout << "O livro estara disponivel novamente em " << data_disponivel.dia << "/" << data_disponivel.mes << "/" << data_disponivel.ano << endl;
    }
}

void realizaDevolucaoLivro(Livros vLivrosS[], Livros vLivrosA[], int contS, int contT, int &contA, int livroTemporario[], int quantidadeDeLivrosParaSeremDevolvidos, Editoras vEditora[], Autores vAutor[], int quantidadeDeEditoras, int quantidadeDeAutores){
    //O vetor livroTemporario recebera os codigos dos livros a serem devolvidos
    int posDoLivroParaSerDevolvido;
    int posDaEditoraDoLivroParaSerDevolvido;
    int posDoAutorDoLivroParaSerDevolvido;
    bool osLivrosEstaoEmprestados = false;
    for(int cont = 0; cont < quantidadeDeLivrosParaSeremDevolvidos; cont++){
        posDoLivroParaSerDevolvido = buscaBinariaNaTabelaDeLivros(vLivrosS, 0, quantidadeDeLivrosParaSeremDevolvidos++, vLivrosS[cont].codigo);
        posDaEditoraDoLivroParaSerDevolvido = buscaBinariaNaTabelaDeEditoras(vEditora, 0, quantidadeDeEditoras - 1, vLivrosS[cont].codigo_editora);
        posDoAutorDoLivroParaSerDevolvido = buscaBinariaNaTabelaDeAutores(vAutor, 0, quantidadeDeAutores - 1, vLivrosS[cont].codigo_autor);
        vLivrosS[cont].codigo_pessoa_emprestado = 0;
        if(vLivrosS[cont].codigo_pessoa_emprestado != 0){
            osLivrosEstaoEmprestados = true;
        }
        else{
            cout << "Erro! um ou mais livros que voce digitou nao estao emprestados";
        }
    }
    int i = 0, j = 0, k = 0; // i (Contador vLivrosS) j (Contador livroTemporario) k (Contador vLivroA)

    //Funcao que fara a remocao dos livros da lista de livros Emprestados
    if(osLivrosEstaoEmprestados){
     for(;j < contT; i++){
        if(vLivrosS[i].codigo != livroTemporario[j]){
            vLivrosA[k].codigo = vLivrosS[i].codigo;
            vLivrosA[k].codigo_autor = vLivrosS[i].codigo_autor;
            vLivrosA[k].codigo_editora = vLivrosS[i].codigo_editora;
            vLivrosA[k].codigo_genero = vLivrosS[i].codigo_genero;
            vLivrosA[k].codigo_pessoa_emprestado = vLivrosS[i].codigo_pessoa_emprestado;
            vLivrosA[k].data_ultimo_emprestimo = vLivrosS[i].data_ultimo_emprestimo;
            strcpy(vLivrosA[k].nome, vLivrosS[i].nome);
            vLivrosA[k].qtde_emprestada = vLivrosS[i].qtde_emprestada;
            k++;
        }
        else{
            j++;
        }
    }
    while(i < contS){
            vLivrosA[k].codigo = vLivrosS[i].codigo;
            vLivrosA[k].codigo_autor = vLivrosS[i].codigo_autor;
            vLivrosA[k].codigo_editora = vLivrosS[i].codigo_editora;
            vLivrosA[k].codigo_genero = vLivrosS[i].codigo_genero;
            vLivrosA[k].codigo_pessoa_emprestado = vLivrosS[i].codigo_pessoa_emprestado;
            vLivrosA[k].data_ultimo_emprestimo = vLivrosS[i].data_ultimo_emprestimo;
            strcpy(vLivrosA[k].nome, vLivrosS[i].nome);
            vLivrosA[k].qtde_emprestada = vLivrosS[i].qtde_emprestada;
            i++;
            k++;
        }
        contA = k;
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

//OBS: TESTAR AS FUNÇÕES

int main(){

}
