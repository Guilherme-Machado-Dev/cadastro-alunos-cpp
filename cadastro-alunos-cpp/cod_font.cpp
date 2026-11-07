#include <iostream>
#include <string>

using namespace std;

// Estrutura que armazena os dados de um aluno
struct Aluno {
    string nome;
    int idade;
    int matricula;
    float notaFinal;
};

// Protótipos das funções
void inserirAluno(Aluno alunos[], int &quantidade);
void listarAlunos(Aluno alunos[], int quantidade);
void buscarAluno(Aluno alunos[], int quantidade, int matricula);
void atualizarNota(Aluno alunos[], int quantidade, int matricula);

int main() {
    // Vetor para armazenar até 100 alunos
    Aluno alunos[100];

    // Controla quantos alunos foram cadastrados
    int quantidade = 0;

    // Variável para armazenar a opção do menu
    int opcao;

    do {
        // Exibição do menu principal
        cout << "\n--- Sistema de Cadastro de Alunos ---\n";
        cout << "1. Inserir novo aluno\n";
        cout << "2. Listar alunos\n";
        cout << "3. Buscar aluno por matricula\n";
        cout << "4. Atualizar nota\n";
        cout << "0. Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        // Executa a opção escolhida pelo usuário
        switch(opcao) {

            // Inserir um novo aluno
            case 1:
                inserirAluno(alunos, quantidade);
                break;

            // Listar todos os alunos cadastrados
            case 2:
                listarAlunos(alunos, quantidade);
                break;

            // Buscar aluno pela matrícula
            case 3: {
                int mat;
                cout << "Digite a matricula: ";
                cin >> mat;
                buscarAluno(alunos, quantidade, mat);
                break;
            }

            // Atualizar a nota de um aluno
            case 4: {
                int mat;
                cout << "Digite a matricula: ";
                cin >> mat;
                atualizarNota(alunos, quantidade, mat);
                break;
            }
        }

    } while(opcao != 0); // Continua até o usuário escolher sair

    return 0;
}

// Função para inserir um novo aluno
void inserirAluno(Aluno alunos[], int &quantidade) {

    // Verifica se ainda há espaço no vetor
    if (quantidade < 100) {

        cout << "Nome: ";

        // Limpa o buffer para evitar problemas com getline
        cin.ignore();

        // Lê o nome completo do aluno
        getline(cin, alunos[quantidade].nome);

        cout << "Idade: ";
        cin >> alunos[quantidade].idade;

        cout << "Matricula: ";
        cin >> alunos[quantidade].matricula;

        cout << "Nota final: ";
        cin >> alunos[quantidade].notaFinal;

        // Incrementa a quantidade de alunos cadastrados
        quantidade++;

    } else {
        cout << "Limite de alunos atingido!\n";
    }
}

// Função para listar todos os alunos cadastrados
void listarAlunos(Aluno alunos[], int quantidade) {

    // Percorre todo o vetor de alunos cadastrados
    for (int i = 0; i < quantidade; i++) {

        cout << "Nome: " << alunos[i].nome
             << " | Idade: " << alunos[i].idade
             << " | Matricula: " << alunos[i].matricula
             << " | Nota: " << alunos[i].notaFinal
             << endl;
    }
}

// Função para buscar aluno pela matrícula
void buscarAluno(Aluno alunos[], int quantidade, int matricula) {

    // Procura a matrícula informada
    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].matricula == matricula) {

            cout << "Aluno encontrado: "
                 << alunos[i].nome
                 << " | Nota: "
                 << alunos[i].notaFinal
                 << endl;

            return;
        }
    }

    // Caso não encontre o aluno
    cout << "Aluno nao encontrado.\n";
}

// Função para atualizar a nota de um aluno
void atualizarNota(Aluno alunos[], int quantidade, int matricula) {

    // Procura o aluno pela matrícula
    for (int i = 0; i < quantidade; i++) {

        if (alunos[i].matricula == matricula) {

            cout << "Digite a nova nota: ";
            cin >> alunos[i].notaFinal;

            cout << "Nota atualizada com sucesso!\n";
            return;
        }
    }

    // Caso a matrícula não exista
    cout << "Aluno nao encontrado.\n";
}