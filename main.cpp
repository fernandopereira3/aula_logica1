#include <unistd.h>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

FILE *db_produto, *db_cliente, *db_fornecedor;


typedef struct Produto {
    char descricao[50];
    long int pdID;
    long int fnID;
    int quantidade;
    double PC;
    double PV;
    time_t cadastro;
} Reg_produto;

typedef struct Cliente {
    char nome[50];
    long int clID;
    char endereco[100];
    char telefone[15];
    time_t cadastro;
} Reg_cliente;

typedef struct Fornecedor {
    char nome[50];
    long int fnID;
    char endereco[100];
    char telefone[15];
    time_t cadastro;
} Reg_fornecedor;

int cadastro_produto() {
    Reg_produto produto;
    int operador = 2;

    db_produto = fopen("db_produtos.dat", "ab");
    if (db_produto == NULL) {
        cout << "Erro ao abrir o arquivo de produtos!" << endl;
        return -1;
    }

    do {
        cout << "Digite o ID do produto: ";
        cin >> produto.pdID;
        cout << "Digite a descricao do produto: ";
        cin.ignore();
        cin.getline(produto.descricao, 50);
        cout << "Digite o ID do fornecedor: ";
        cin >> produto.fnID;
        cout << "Digite a quantidade em estoque: ";
        cin >> produto.quantidade;
        cout << "Digite o preco de compra (use ponto, ex: 10.50): ";
        cin >> produto.PC;
        cout << "Digite o preco de venda (use ponto, ex: 15.90): ";
        cin >> produto.PV;
        produto.cadastro = time(nullptr);
        fwrite(&produto, sizeof(Reg_produto), 1, db_produto);
        cout << "Produto cadastrado com sucesso!" << endl;


        cout << "Digite 1 para continuar ou 2 para sair: ";
        cin >> operador;
    } while (operador == 1);

    fclose(db_produto);
    return 0;
}

int cadastro_cliente() {
    Reg_cliente cliente;
    int operador = 2;

    db_cliente = fopen("db_clientes.dat", "ab");
    if (db_cliente == NULL) {
        cout << "Erro ao abrir o arquivo de clientes!" << endl;
        return -1;
    }

    do {
        cout << "Digite o ID do cliente: ";
        cin >> cliente.clID;
        cout << "Digite o nome do cliente: ";
        cin.ignore();
        cin.getline(cliente.nome, 50);
        cout << "Digite o endereco do cliente: ";
        cin.getline(cliente.endereco, 100);
        cout << "Digite o telefone do cliente: ";
        cin.getline(cliente.telefone, 15);
        cliente.cadastro = time(nullptr);
        fwrite(&cliente, sizeof(Reg_cliente), 1, db_cliente);
        cout << "Cliente cadastrado com sucesso!" << endl;

        cout << "Digite 1 para continuar ou 2 para sair: ";
        cin >> operador;
    } while (operador == 1);

    fclose(db_cliente);
    return 0;
}

int cadastro_fornecedor() {
    Reg_fornecedor fornecedor;
    int operador = 2;

    db_fornecedor = fopen("db_fornecedores.dat", "ab");
    if (db_fornecedor == NULL) {
        cout << "Erro ao abrir o arquivo de fornecedores!" << endl;
        return -1;
    }

    do {
        cout << "Digite o ID do fornecedor: ";
        cin >> fornecedor.fnID;
        cout << "Digite o nome do fornecedor: ";
        cin.ignore();
        cin.getline(fornecedor.nome, 50);
        cout << "Digite o endereco do fornecedor: ";
        cin.getline(fornecedor.endereco, 100);
        cout << "Digite o telefone do fornecedor: ";
        cin.getline(fornecedor.telefone, 15);
        fornecedor.cadastro = time(nullptr);
        fwrite(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor);
        cout << "Fornecedor cadastrado com sucesso!" << endl;

        cout << "Digite 1 para continuar ou 2 para sair: ";
        cin >> operador;
    } while (operador == 1);

    fclose(db_fornecedor);
    return 0;
}

int pesquisa_produtos() {
    Reg_produto produto;
    long int id;
    char op;

    db_produto = fopen("db_produtos.dat", "rb");
    if (db_produto == NULL) {
        cout << "Erro ao abrir o arquivo de produtos!" << endl;
        return -1;
    }

    do{
        bool encontrado = false;
        rewind(db_produto);
        cout << "Digite o ID do produto que deseja pesquisar: ";
        cin >> id;
        while (fread(&produto, sizeof(Reg_produto), 1, db_produto)) {
            if (produto.pdID == id) {
                cout << "Produto encontrado!" << endl;
                cout << "ID: " << produto.pdID << endl;
                cout << "Descricao: " << produto.descricao << endl;
                cout << "ID do Fornecedor: " << produto.fnID << endl;
                cout << "Quantidade em estoque: " << produto.quantidade << endl;
                cout << "Preco de compra: " << produto.PC << endl;
                cout << "Preco de venda: " << produto.PV << endl;
                cout << "Data de cadastro: " << ctime(&produto.cadastro) << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Produto nao encontrado!" << endl;
        }
        cout << "Deseja pesquisar outro produto? (S/N): ";
        cin >> op;

    }while(op == 's' || op == 'S');
    fclose(db_produto);
    return 0;
}

int pesquisa_clientes() {
    Reg_cliente cliente;
    long int id;
    char op;

    db_cliente = fopen("db_clientes.dat", "rb");
    if (db_cliente == NULL) {
        cout << "Erro ao abrir o arquivo de clientes!" << endl;
        return -1;
    }

    do{
        bool encontrado = false;
        rewind(db_cliente);
        cout << "Digite o ID do cliente que deseja pesquisar: ";
        cin >> id;
        while (fread(&cliente, sizeof(Reg_cliente), 1, db_cliente)) {
            if (cliente.clID == id) {
                cout << "Cliente encontrado!" << endl;
                cout << "ID: " << cliente.clID << endl;
                cout << "Nome: " << cliente.nome << endl;
                cout << "Endereco: " << cliente.endereco << endl;
                cout << "Telefone: " << cliente.telefone << endl;
                cout << "Data de cadastro: " << ctime(&cliente.cadastro) << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Cliente nao encontrado!" << endl;
        }
        cout << "Deseja pesquisar outro cliente? (S/N): ";
        cin >> op;

    }while(op == 's' || op == 'S');
    fclose(db_cliente);
    return 0;
}

int pesquisa_fornecedores() {
    Reg_fornecedor fornecedor;
    long int id;
    char op;

    db_fornecedor = fopen("db_fornecedores.dat", "rb");
    if (db_fornecedor == NULL) {
        cout << "Erro ao abrir o arquivo de fornecedores!" << endl;
        return -1;
    }

    do{
        bool encontrado = false;
        rewind(db_fornecedor);
        cout << "Digite o ID do fornecedor que deseja pesquisar: ";
        cin >> id;
        while (fread(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor)) {
            if (fornecedor.fnID == id) {
                cout << "Fornecedor encontrado!" << endl;
                cout << "ID: " << fornecedor.fnID << endl;
                cout << "Nome: " << fornecedor.nome << endl;
                cout << "Endereco: " << fornecedor.endereco << endl;
                cout << "Telefone: " << fornecedor.telefone << endl;
                cout << "Data de cadastro: " << ctime(&fornecedor.cadastro) << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Fornecedor nao encontrado!" << endl;
        }
        cout << "Deseja pesquisar outro fornecedor? (S/N): ";
        cin >> op;

    }while(op == 's' || op == 'S');
    fclose(db_fornecedor);
    return 0;
}

void menu_pesquisa() {
    char op;
    while(true){
        std::system("clear");
        cout << "==================================================" << endl;
        cout << "                PESQUISA (BUSCA POR ID)           " << endl;
        cout << "===================================================" << endl;
        cout << "1. Pesquisar Produto" << endl;
        cout << "2. Pesquisar Cliente" << endl;
        cout << "3. Pesquisar Fornecedor" << endl;
        cout << "0. Voltar ao Menu Principal" << endl;
        cout << "===================================================" << endl;
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case '1': std::system("clear"); pesquisa_produtos(); break;
            case '2': std::system("clear"); pesquisa_clientes(); break;
            case '3': std::system("clear"); pesquisa_fornecedores(); break;
            case '0': return;
            default: cout << "Opcao invalida!" << endl;
        }
    }
}

// RELATORIOS DE PRODUTOS, CLIENTES E FORNECEDORES
int relarios() {
    Reg_produto produto;
    Reg_cliente cliente;
    Reg_fornecedor fornecedor;
    char op; 
    while(true){
        std::system("clear");
        cout << "==================================================" << endl;
        cout << "                GERAR RELATORIOS                  " << endl;
        cout << "===================================================" << endl;
        cout << "1. Relatorio de Produtos" << endl;
        cout << "2. Relatorio de Clientes" << endl;
        cout << "3. Relatorio de Fornecedores" << endl;
        cout << "0. Voltar ao Menu Principal" << endl;
        cout << "===================================================" << endl;
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case '1': //RELATORIO DE PRODUTOS
                std::system("clear");
                db_produto = fopen("db_produtos.dat", "rb");
                if (db_produto == NULL) {
                    cout << "Nenhum produto cadastrado!" << endl;
                } else {
                    cout << "===================================================================================" << endl;
                    cout << "                             PRODUTOS NO ESTOQUE                                   " << endl;
                    cout << "===================================================================================" << endl;
                    cout << left << setw(6) << "ID" << setw(30) << "Descricao" << setw(12) << "Fornecedor"
                         << setw(8) << "Qtd" << setw(12) << "P. Compra" << setw(12) << "P. Venda" << setw(10) << "Cadastrado" << endl;
                    cout << "-----------------------------------------------------------------------------------" << endl;
                    while (fread(&produto, sizeof(Reg_produto), 1, db_produto)) {
                        cout << left << setw(6) << produto.pdID << setw(30) << produto.descricao
                             << setw(12) << produto.fnID << setw(8) << produto.quantidade
                             << setw(12) << produto.PC << setw(12) << produto.PV << setw(10) << ctime(&produto.cadastro) << "\n" << endl;
                    }
                    fclose(db_produto);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '2': //RELATORIO DE CLIENTES
                std::system("clear");
                db_cliente = fopen("db_clientes.dat", "rb");
                if (db_cliente == NULL) {
                    cout << "Nenhum cliente cadastrado!" << endl;
                } else {
                    cout << "===================================================================================" << endl;
                    cout << "                                       CLIENTES                                    " << endl;
                    cout << "===================================================================================" << endl;
                    cout << left << setw(6) << "ID" << setw(30) << "Nome" << setw(35) << "Endereco"
                         << setw(15) << "Telefone" << setw(10) << "Cadastrado" << endl;
                    cout << "-----------------------------------------------------------------------------------" << endl;
                    while (fread(&cliente, sizeof(Reg_cliente), 1, db_cliente)) {
                        cout << left << setw(6) << cliente.clID << setw(30) << cliente.nome
                             << setw(35) << cliente.endereco << setw(15) << cliente.telefone << setw(10) << ctime(&cliente.cadastro) << "\n" << endl;
                    }
                    fclose(db_cliente);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '3': //RELATORIO DE FORNECEDORES
                std::system("clear");
                db_fornecedor = fopen("db_fornecedores.dat", "rb");
                if (db_fornecedor == NULL) {
                    cout << "Nenhum fornecedor cadastrado!" << endl;
                } else {
                    cout << "===================================================================================" << endl;
                    cout << "                                       FORNECEDORES                                " << endl;
                    cout << "===================================================================================" << endl;
                    cout << left << setw(6) << "ID" << setw(30) << "Nome" << setw(35) << "Endereco"
                         << setw(15) << "Telefone" << setw(10) << "Cadastrado" << endl;
                    cout << "-----------------------------------------------------------------------------------" << endl;
                    while (fread(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor)) {
                        cout << left << setw(6) << fornecedor.fnID << setw(30) << fornecedor.nome
                             << setw(35) << fornecedor.endereco << setw(15) << fornecedor.telefone << setw(10) << ctime(&fornecedor.cadastro)    << "\n" << endl;
                    }
                    fclose(db_fornecedor);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '0':
                return 0;

            default:
                cout << "Opcao invalida!" << endl;
                std::system("read -p 'Pressione Enter para continuar...' var");
        }
    }
    return 0;
}


int editar_registro() {
    Reg_produto produto;
    Reg_cliente cliente; 
    Reg_fornecedor fornecedor;
    char op; 
    while(true){
        std::system("clear");
        cout << "===================================================================" << endl;
        cout << "                    QUAL REGISTRO DESEJA EDITAR?                   " << endl;
        cout << "===================================================================" << endl;
        cout << "1. Produtos" << endl;
        cout << "2. Clientes" << endl;
        cout << "3. Fornecedores" << endl;
        cout << "0. Voltar ao Menu Principal" << endl;
        cout << "===================================================================" << endl;
        cout << "Opcao: ";
        cin >> op;
        switch (op) {
            case '1': //EDITAR PRODUTOS
                std::system("clear");
                db_produto = fopen("db_produtos.dat", "rb");
                if (db_produto == NULL) {
                    cout << "Nenhum produto cadastrado!" << endl;
                } else {
                    long int id;
                    bool encontrado = false;
                    cout << "ID do produto a editar: ";
                    cin >> id;
                    // percorre o arquivo procurando o registro e apaga ele
                    fclose(db_produto);
                    db_produto = fopen("db_produtos.dat", "r+b");
                    long pos_leitura = 0, pos_escrita = 0;
                    while (fread(&produto, sizeof(Reg_produto), 1, db_produto)) {
                        pos_leitura = ftell(db_produto);
                        if (produto.pdID == id) {
                            encontrado = true;
                        } else {
                            if (encontrado) { // desloca os registros seguintes para cobrir o apagado
                                fseek(db_produto, pos_escrita, SEEK_SET);
                                fwrite(&produto, sizeof(Reg_produto), 1, db_produto);
                                fseek(db_produto, pos_leitura, SEEK_SET);
                            }
                            pos_escrita += sizeof(Reg_produto);
                        }
                    }
                    fflush(db_produto);
                    if (encontrado) {
                        ftruncate(fileno(db_produto), pos_escrita);
                        // adiciona o novo registro no final do arquivo
                        fseek(db_produto, 0, SEEK_END);
                        cout << "Digite os novos dados do produto:" << endl;
                        cout << "Digite o ID do produto: ";
                        cin >> produto.pdID;
                        cout << "Digite a descricao do produto: ";
                        cin.ignore();
                        cin.getline(produto.descricao, 50);
                        cout << "Digite o ID do fornecedor: ";
                        cin >> produto.fnID;
                        cout << "Digite a quantidade em estoque: ";
                        cin >> produto.quantidade;
                        cout << "Digite o preco de compra (use ponto, ex: 10.50): ";
                        cin >> produto.PC;
                        cout << "Digite o preco de venda (use ponto, ex: 15.90): ";
                        cin >> produto.PV;
                        produto.cadastro = time(nullptr);
                        fwrite(&produto, sizeof(Reg_produto), 1, db_produto);
                        cout << "Produto editado com sucesso!" << endl;
                    } else {
                        cout << "Produto nao encontrado!" << endl;
                    }
                    fclose(db_produto);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '2': //EDITAR CLIENTES
                std::system("clear");
                db_cliente = fopen("db_clientes.dat", "rb");
                if (db_cliente == NULL) {
                    cout << "Nenhum cliente cadastrado!" << endl;
                } else {
                    long int id;
                    bool encontrado = false;
                    cout << "ID do cliente a editar: ";
                    cin >> id;
                    // percorre o arquivo procurando o registro e apaga ele
                    fclose(db_cliente);
                    db_cliente = fopen("db_clientes.dat", "r+b");
                    long pos_leitura = 0, pos_escrita = 0;
                    while (fread(&cliente, sizeof(Reg_cliente), 1, db_cliente)) {
                        pos_leitura = ftell(db_cliente);
                        if (cliente.clID == id) {
                            encontrado = true;
                        } else {
                            if (encontrado) { // desloca os registros seguintes para cobrir o apagado
                                fseek(db_cliente, pos_escrita, SEEK_SET);
                                fwrite(&cliente, sizeof(Reg_cliente), 1, db_cliente);
                                fseek(db_cliente, pos_leitura, SEEK_SET);
                            }
                            pos_escrita += sizeof(Reg_cliente);
                        }
                    }
                    fflush(db_cliente);
                    if (encontrado) {
                        ftruncate(fileno(db_cliente), pos_escrita);
                        // adiciona o novo registro no final do arquivo
                        fseek(db_cliente, 0, SEEK_END);
                        cout << "Digite os novos dados do cliente:" << endl;
                        cout << "Digite o ID do cliente: ";
                        cin >> cliente.clID;
                        cout << "Digite o nome do cliente: ";
                        cin.ignore();
                        cin.getline(cliente.nome, 50);
                        cout << "Digite o endereco do cliente: ";
                        cin.getline(cliente.endereco, 100);
                        cout << "Digite o telefone do cliente: ";
                        cin.getline(cliente.telefone, 15);
                        cliente.cadastro = time(nullptr);
                        fwrite(&cliente, sizeof(Reg_cliente), 1, db_cliente);
                        cout << "Cliente editado com sucesso!" << endl;
                    } else {
                        cout << "Cliente nao encontrado!" << endl;
                    }
                    fclose(db_cliente);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '3': //EDITAR FORNECEDORES
                std::system("clear");
                db_fornecedor = fopen("db_fornecedores.dat", "rb");
                if (db_fornecedor == NULL) {
                    cout << "Nenhum fornecedor cadastrado!" << endl;
                } else {
                    long int id;
                    bool encontrado = false;
                    cout << "ID do fornecedor a editar: ";
                    cin >> id;
                    // percorre o arquivo procurando o registro e apaga ele
                    fclose(db_fornecedor);
                    db_fornecedor = fopen("db_fornecedores.dat", "r+b");
                    long pos_leitura = 0, pos_escrita = 0;
                    while (fread(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor)) {
                        pos_leitura = ftell(db_fornecedor);
                        if (fornecedor.fnID == id) {
                            encontrado = true;
                        } else {
                            if (encontrado) { // desloca os registros seguintes para cobrir o apagado
                                fseek(db_fornecedor, pos_escrita, SEEK_SET);
                                fwrite(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor);
                                fseek(db_fornecedor, pos_leitura, SEEK_SET);
                            }
                            pos_escrita += sizeof(Reg_fornecedor);
                        }
                    }
                    fflush(db_fornecedor);
                    if (encontrado) {
                        ftruncate(fileno(db_fornecedor), pos_escrita);
                        // adiciona o novo registro no final do arquivo
                        fseek(db_fornecedor, 0, SEEK_END);
                        cout << "Digite os novos dados do fornecedor:" << endl;
                        cout << "Digite o ID do fornecedor: ";
                        cin >> fornecedor.fnID;
                        cout << "Digite o nome do fornecedor: ";
                        cin.ignore();
                        cin.getline(fornecedor.nome, 50);
                        cout << "Digite o endereco do fornecedor: ";
                        cin.getline(fornecedor.endereco, 100);
                        cout << "Digite o telefone do fornecedor: ";
                        cin.getline(fornecedor.telefone, 15);
                        fornecedor.cadastro = time(nullptr);
                        fwrite(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor);
                        cout << "Fornecedor editado com sucesso!" << endl;
                    } else {
                        cout << "Fornecedor nao encontrado!" << endl;
                    }
                    fclose(db_fornecedor);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '0':
                return 0;

            default:
                cout << "Opcao invalida!" << endl;
                std::system("read -p 'Pressione Enter para continuar...' var");
        }


    }
    return 0;
}


int excluir_registro(){
    Reg_produto produto;
    Reg_cliente cliente; 
    Reg_fornecedor fornecedor;
    char op; 
    while(true){
        std::system("clear");
        cout << "==================================================" << endl;
        cout << "            QUAL REGISTRO DESEJA EXCLUIR?         " << endl;
        cout << "===================================================" << endl;
        cout << "1. Produtos" << endl;
        cout << "2. Clientes" << endl;
        cout << "3. Fornecedores" << endl;
        cout << "0. Voltar ao Menu Principal" << endl;
        cout << "===================================================" << endl;
        cout << "Opcao: ";
        cin >> op;

        switch (op) {
            case '1': //EXCLUIR PRODUTOS
                std::system("clear");
                db_produto = fopen("db_produtos.dat", "rb");
                if (db_produto == NULL) {
                    cout << "Nenhum produto cadastrado!" << endl;
                } else {
                    long int id;
                    bool encontrado = false;
                    std::system("clear");
                    cout << "ID do produto a excluir: ";
                    cin >> id;
                    // percorre o arquivo procurando o registro e apaga ele
                    fclose(db_produto);
                    db_produto = fopen("db_produtos.dat", "r+b");
                    long pos_leitura = 0, pos_escrita = 0;
                    while (fread(&produto, sizeof(Reg_produto), 1, db_produto)) {
                        pos_leitura = ftell(db_produto);
                        if (produto.pdID == id) {
                            encontrado = true;
                        } else {
                            if (encontrado) { // desloca os registros seguintes para cobrir o apagado
                                fseek(db_produto, pos_escrita, SEEK_SET);
                                fwrite(&produto, sizeof(Reg_produto), 1, db_produto);
                                fseek(db_produto, pos_leitura, SEEK_SET);
                            }
                            pos_escrita += sizeof(Reg_produto);
                        }
                    }
                    fflush(db_produto);
                    if (encontrado) {
                        ftruncate(fileno(db_produto), pos_escrita);
                        cout << "Produto excluido com sucesso!" << endl;
                    } else {
                        cout << "Produto nao encontrado!" << endl;
                    }
                    fclose(db_produto);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '2': //EXCLUIR CLIENTES
                std::system("clear");
                db_cliente = fopen("db_clientes.dat", "rb");
                if (db_cliente == NULL) {
                    cout << "Nenhum cliente cadastrado!" << endl;
                } else {
                    long int id;
                    bool encontrado = false;
                    std::system("clear");
                    cout << "ID do cliente a excluir: ";
                    cin >> id;
                    // percorre o arquivo procurando o registro e apaga ele
                    fclose(db_cliente);
                    db_cliente = fopen("db_clientes.dat", "r+b");
                    long pos_leitura = 0, pos_escrita = 0;
                    while (fread(&cliente, sizeof(Reg_cliente), 1, db_cliente)) {
                        pos_leitura = ftell(db_cliente);
                        if (cliente.clID == id) {
                            encontrado = true;
                        } else {
                            if (encontrado) { // desloca os registros seguintes para cobrir o apagado
                                fseek(db_cliente, pos_escrita, SEEK_SET);
                                fwrite(&cliente, sizeof(Reg_cliente), 1, db_cliente);
                                fseek(db_cliente, pos_leitura, SEEK_SET);
                            }
                            pos_escrita += sizeof(Reg_cliente);
                        }
                    }
                    fflush(db_cliente);
                    if (encontrado) {
                        ftruncate(fileno(db_cliente), pos_escrita);
                        cout << "Cliente excluido com sucesso!" << endl;
                    } else {
                        cout << "Cliente nao encontrado!" << endl;
                    }
                    fclose(db_cliente);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '3': //EXCLUIR FORNECEDORES
                std::system("clear");
                db_fornecedor = fopen("db_fornecedores.dat", "rb");
                if (db_fornecedor == NULL) {
                    cout << "Nenhum fornecedor cadastrado!" << endl;
                } else {
                    long int id;
                    bool encontrado = false;
                    std::system("clear");
                    cout << "ID do fornecedor a excluir: ";
                    cin >> id;
                    // percorre o arquivo procurando o registro e apaga ele
                    fclose(db_fornecedor);
                    db_fornecedor = fopen("db_fornecedores.dat", "r+b");
                    long pos_leitura = 0, pos_escrita = 0;
                    while (fread(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor)) {
                        pos_leitura = ftell(db_fornecedor);
                        if (fornecedor.fnID == id) {
                            encontrado = true;
                        } else {
                            if (encontrado) { // desloca os registros seguintes para cobrir o apagado
                                fseek(db_fornecedor, pos_escrita, SEEK_SET);
                                fwrite(&fornecedor, sizeof(Reg_fornecedor), 1, db_fornecedor);
                                fseek(db_fornecedor, pos_leitura, SEEK_SET);
                            }
                            pos_escrita += sizeof(Reg_fornecedor);
                        }
                    }
                    fflush(db_fornecedor);
                    if (encontrado) {
                        ftruncate(fileno(db_fornecedor), pos_escrita)
                        cout << "Fornecedor excluido com sucesso!" << endl;
                    } else {
                        cout << "Fornecedor nao encontrado!" << endl;
                    }
                    fclose(db_fornecedor);
                }
                std::system("read -p 'Pressione Enter para continuar...' var");
                break;

            case '0':
                return 0;

            default:
                cout << "Opcao invalida!" << endl;
                std::system("read -p 'Pressione Enter para continuar...' var");
        }
    }
    return 0;


}




void menu() {
    char op = ' ';
    do {
std::system("clear");
cout << "==================================================" << endl;
cout << "                SISTEMA DE GERENCIAMENTO          " << endl;
cout << "===================================================" << endl;
cout << "1. Cadastro de Clientes" << endl;
cout << "2. Cadastro de Produtos" << endl;
cout << "3. Cadastro de Fornecedores" << endl;
cout << "4. Pesquisa (Busca por ID)" << endl;
cout << "5. Editar Registros" << endl;
cout << "6. Excluir Registros" << endl;
cout << "7. Gerar Relatórios" << endl;
cout << "0. Sair do Sistema" << endl;
cout << "===================================================" << endl;
cout << "Opcao: ";
cin >> op;

switch (op) {
    case '1':
        std::system("clear");
        cadastro_cliente();
        break;
    case '2':
        std::system("clear");
        cadastro_produto();
        break;
    case '3':
        std::system("clear");
        cadastro_fornecedor();
        break;
    case '4':
        std::system("clear");
        menu_pesquisa();
        break;
    case '5':
        std::system("clear");
        editar_registro();
        break;
    case '6':
        std::system("clear");
        excluir_registro();
        break;
    case '7':
        std::system("clear");
        relarios();
        break;
    case '0':
        std::system("clear");
        std::system("read -p 'Pressione Enter para sair...' var");
        break;
    default:
        cout << "Opcao invalida! Tente novamente." << endl;
}
    } while (op != '0');
}



int main(){
    menu();
}


//BUSCA TODO O ARQUIVO PARA ENCONTRAR UM REGISTRO ESPECIFICO
//long id;
//cout << "ID do produto a buscar: ";
//cin >> id;
//
//FILE *db = fopen("db_produtos.dat", "rb");
//if (db == NULL) {
//    cout << "Nenhum produto cadastrado!" << endl;
//} else {
//    Reg_produto produto;
//    bool encontrado = false;
//    long pos_registro = -1;
//
//    fseek(db, 0, SEEK_SET);                  // 1. começa do início do arquivo
//
//    while (fread(&produto, sizeof(Reg_produto), 1, db) == 1) {   // 2. lê um registro por vez
//        if (produto.pdID == id) {            // 3. compara o ID
//            encontrado = true;
//            pos_registro = ftell(db) - sizeof(Reg_produto);  // posição onde o registro começa
//            break;                           // 4. para ao achar
//        }
//    }
//
//    if (encontrado) {
//        cout << "Encontrado: " << produto.descricao << endl;
//    } else {
//        cout << "Produto nao encontrado." << endl;
//    }
//
//    fclose(db);
//}
//