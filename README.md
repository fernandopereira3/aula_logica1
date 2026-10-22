# Sistema de Gerenciamento de Estoque (C++)

Este é um sistema de gerenciamento de banco de dados em arquivos desenvolvido em C++. O software permite o controle completo de **Produtos, Clientes e Fornecedores**, oferecendo funcionalidades de CRUD (Criação, Leitura, Atualização e Exclusão) utilizando manipulação direta de arquivos binários.

## 🚀 Funcionalidades

O sistema conta com as seguintes funcionalidades principais:

*   **Cadastro:** Registro de novos produtos (com descrição, estoque, preços), clientes (nome, endereço, telefone) e fornecedores.
*   **Pesquisa:** Busca rápida de registros através do ID único.
*   **Edição:** Atualização de dados existentes de qualquer registro.
*   **Exclusão:** Remoção de registros do banco de dados de forma segura, reorganizando o arquivo binário.
*   **Relatórios:** Geração de relatórios sobre os dados cadastrados.
*   **Persistência de Dados:** Todas as informações são salvas em arquivos `.dat`, garantindo que os dados não sejam perdidos ao fechar o programa.

## 🛠️ Tecnologias Utilizadas

*   **Linguagem:** C++
*   **Manipulação de Arquivos:** `stdio.h` (uso de `fopen`, `fread`, `fwrite`, `fseek`, `ftell`).
*   **Sistema Operacional:** Compatível com ambientes Unix/Linux (devido ao uso de `std::system("clear")` e comandos de terminal).

## 📂 Estrutura de Arquivos

O sistema cria e gerencia automaticamente os seguintes arquivos binários:
*   `db_produtos.dat`: Armazena informações de produtos.
*   `db_clientes.dat`: Armazena informações de clientes.
*   `db_fornecedores.dat`: Armazena informações de fornecedores.

## 🔧 Como Compilar e Executar

Para compilar o projeto, você precisará de um compilador C++ (como `g++`).

1.  **Clone ou baixe o código fonte.**
2.  **Abra o terminal na pasta do projeto.**
3.  **Compile o código:**
    ```bash
    g++ -o sistema_gerenciamento main.cpp
    ```
4.  **Execute o programa:**
    ```bash
    ./sistema_gerenciamento
    ```

## 📝 Notas Técnicas de Implementação

*   **Lógica de Exclusão/Edição:** O sistema utiliza uma técnica de "deslocamento de registros". Ao excluir ou editar um registro no meio do arquivo, o programa move todos os registros subsequentes para preencher o espaço vazio e utiliza `ftruncate` para ajustar o tamanho final do arquivo.
*   **Segurança de Memória:** O uso de `fflush` e o fechamento correto dos ponteiros de arquivo (`fclose`) garantem a integridade dos dados durante as operações de escrita.

## ⚠️ Requisitos
*   Compilador C++ (GCC ou Clang).
*   Ambiente Linux ou macOS (devido aos comandos `clear` e `read` usados no código).

---
*Desenvolvido para fins de estudo de Estruturas de Dados e Manipulação de Arquivos.*