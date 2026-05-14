#include "AgenteIA.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>

using namespace std;

// Função auxiliar para registrar logs 
void AgenteIA::registrarLog(const string& evento) const {
    ofstream arquivo("log_execucao.txt", ios::app);
    if (arquivo.is_open()) {
        time_t t = time(nullptr);
        tm* tm_local = localtime(&t);
        arquivo << "[" << setfill('0') << setw(2) << tm_local->tm_hour << ":" 
                << setfill('0') << setw(2) << tm_local->tm_min << "] " 
                << evento << endl;
        arquivo.close();
    }
}

// Construtor Padrão [cite: 16]
AgenteIA::AgenteIA() : nome("Desconhecido"), especialidade("Nenhuma"), nivelEnergia(100), tarefasConcluidas(0) {
    registrarLog("Agente padrao criado.");
}

// Construtor Parametrizado [cite: 16]
AgenteIA::AgenteIA(string n, string esp, int energia) {
    nome = n;
    especialidade = esp;
    nivelEnergia = (energia >= 0) ? energia : 0; // Validação 
    tarefasConcluidas = 0;
    registrarLog("Agente " + nome + " criado.");
}

// Construtor de Cópia [cite: 17, 18]
AgenteIA::AgenteIA(const AgenteIA& outro) {
    nome = outro.nome + "_Copia";
    especialidade = outro.especialidade;
    nivelEnergia = outro.nivelEnergia;
    tarefasConcluidas = outro.tarefasConcluidas;
    registrarLog("Agente " + nome + " copiado do agente " + outro.nome + ".");
}

// Destrutor [cite: 23]
AgenteIA::~AgenteIA() {
    cout << "Liberando agente " << nome << " da memoria..." << endl; // Mensagem obrigatória [cite: 23, 24]
    registrarLog("Agente " + nome + " destruido.");
}

std::string AgenteIA::getNome() const { return nome; }
int AgenteIA::getNivelEnergia() const { return nivelEnergia; }

// Exibir status do agente [cite: 12]
void AgenteIA::exibirStatus() const {
    cout << "--- Status do Agente ---" << endl;
    cout << "Nome: " << nome << endl;
    cout << "Especialidade: " << especialidade << endl;
    cout << "Energia: " << nivelEnergia << "%" << endl;
    cout << "Tarefas Concluidas: " << tarefasConcluidas << endl;
    cout << "------------------------" << endl;
}

// Executar tarefa [cite: 12]
void AgenteIA::executarTarefa(int custoEnergia) {
    if (nivelEnergia >= custoEnergia) { // Regra: sem energia não executa [cite: 26]
        nivelEnergia -= custoEnergia;
        tarefasConcluidas++; // Tarefas não decrementadas manualmente [cite: 15]
        cout << "Tarefa executada com sucesso pelo agente " << nome << "!" << endl;
        registrarLog("Tarefa executada por " + nome + ". Energia reduzida para " + to_string(nivelEnergia) + "."); // [cite: 43]
    } else {
        cout << "Erro: O agente " << nome << " nao tem energia suficiente para esta tarefa." << endl;
    }
}

// Recarregar energia [cite: 12]
void AgenteIA::recarregarEnergia(int quantidade) {
    if (quantidade > 0) {
        nivelEnergia += quantidade;
        if (nivelEnergia > 100) nivelEnergia = 100;
        cout << "Energia do agente " << nome << " recarregada para " << nivelEnergia << "%." << endl;
        registrarLog("Energia de " + nome + " recarregada para " + to_string(nivelEnergia) + ".");
    }
}