// Gera 5000 registros em cada .dat (sobrescreve). Uso: g++ popular_dados.cpp -o popular && ./popular
#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>

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

const int N = 50;

int main() {
    srand(42);
    time_t agora = time(nullptr);

    FILE *f = fopen("db_produtos.dat", "wb");
    for (int i = 1; i <= N; i++) {
        Reg_produto p;
        memset(&p, 0, sizeof p);
        snprintf(p.descricao, sizeof p.descricao, "Produto %d", i);
        p.pdID = i;
        p.fnID = rand() % N + 1;
        p.quantidade = rand() % 500;
        p.PC = (rand() % 10000) / 100.0 + 1;
        p.PV = p.PC * 1.3;
        p.cadastro = agora;
        fwrite(&p, sizeof p, 1, f);
    }
    fclose(f);

    f = fopen("db_clientes.dat", "wb");
    for (int i = 1; i <= N; i++) {
        Reg_cliente c;
        memset(&c, 0, sizeof c);
        snprintf(c.nome, sizeof c.nome, "Cliente %d", i);
        c.clID = i;
        snprintf(c.endereco, sizeof c.endereco, "Rua %d, %d", rand() % 200 + 1, rand() % 999 + 1);
        snprintf(c.telefone, sizeof c.telefone, "9%04d-%04d", rand() % 10000, rand() % 10000);
        c.cadastro = agora;
        fwrite(&c, sizeof c, 1, f);
    }
    fclose(f);

    f = fopen("db_fornecedores.dat", "wb");
    for (int i = 1; i <= N; i++) {
        Reg_fornecedor r;
        memset(&r, 0, sizeof r);
        snprintf(r.nome, sizeof r.nome, "Fornecedor %d", i);
        r.fnID = i;
        snprintf(r.endereco, sizeof r.endereco, "Av. %d, %d", rand() % 200 + 1, rand() % 999 + 1);
        snprintf(r.telefone, sizeof r.telefone, "3%03d-%04d", rand() % 1000, rand() % 10000);
        r.cadastro = agora;
        fwrite(&r, sizeof r, 1, f);
    }
    fclose(f);
    return 0;
}
