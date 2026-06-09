#include <iostream>
#include <vector>
#include <fstream>
#include "AgenteIA.h"

using namespace std;

// Cria o arquivo de log do zero a cada execução para testes
void limparLog() {
    ofstream arquivo("log_execucao.txt", ios::trunc);
    arquivo.close();
}

int main() {
    limparLog();

    // Identificação Obrigatória [cite: 45]
    cout << "========================================" << endl;
    cout << "DISCIPLINA: POO EM C++" << endl;
    cout << "ALUNO: Guilherme Henrique da Silva Sabatine (2023200681)" << endl;
    cout << "ID ENTREGA: TUTORIAL-2026-Guilherme Henrique da Silva Sabatine (2023200681)" << endl;
    cout << "========================================" << endl << endl;

    // Instanciação Estática [cite: 20]
    AgenteIA agenteEstatico("Athena", "Analise de Dados", 100);
    
    // Vetor de ponteiros para alocação dinâmica [cite: 22]
    vector<AgenteIA*> agentes;

    int opcao = 0;
    while (opcao != 7) {
        cout << "\n--- MENU INTERATIVO ---" << endl; // Menu obrigatório 
        cout << "1. Criar Agente Dinamico" << endl;
        cout << "2. Listar Agentes" << endl;
        cout << "3. Executar Tarefa" << endl;
        cout << "4. Recarregar Energia" << endl;
        cout << "5. Copiar Agente Estatico" << endl;
        cout << "6. Remover Agente Dinamico" << endl;
        cout << "7. Encerrar Sistema" << endl;
        cout << "Escolha uma opcao: ";
        
        if (!(cin >> opcao)) {
            cout << "Opcao invalida. Digite um numero." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (opcao == 1) { // Criação Dinâmica (new) [cite: 21, 22]
            string nome, esp;
            int energia;
            cout << "Nome: "; cin >> nome;
            cout << "Especialidade: "; cin >> esp;
            cout << "Energia: "; cin >> energia;
            AgenteIA* novoAgente = new AgenteIA(nome, esp, energia);
            agentes.push_back(novoAgente);
            cout << "Agente dinamico criado com sucesso!" << endl;

        } else if (opcao == 2) { // Listar
            cout << "\n[Agente Estatico]" << endl;
            agenteEstatico.exibirStatus();
            cout << "\n[Agentes Dinamicos]" << endl;
            for (size_t i = 0; i < agentes.size(); i++) {
                cout << "Indice [" << i << "]:" << endl;
                agentes[i]->exibirStatus();
            }

        } else if (opcao == 3) { // Executar tarefa
            int indice, custo;
            cout << "Custo de energia da tarefa: "; cin >> custo;
            cout << "Executar com agente dinamico (digite o indice) ou -1 para o agente Estatico: ";
            cin >> indice;
            if (indice == -1) {
                agenteEstatico.executarTarefa(custo);
            } else if (indice >= 0 && indice < agentes.size()) {
                agentes[indice]->executarTarefa(custo);
            } else {
                cout << "Indice invalido!" << endl;
            }

        } else if (opcao == 4) { // Recarregar
            int indice, quant;
            cout << "Quantidade de energia a recarregar: "; cin >> quant;
            cout << "Recarregar agente dinamico (digite o indice) ou -1 para o agente Estatico: ";
            cin >> indice;
            if (indice == -1) {
                agenteEstatico.recarregarEnergia(quant);
            } else if (indice >= 0 && indice < agentes.size()) {
                agentes[indice]->recarregarEnergia(quant);
            } else {
                cout << "Indice invalido!" << endl;
            }

        } else if (opcao == 5) { // Copiar Agente (Construtor de Cópia) [cite: 18, 25]
            AgenteIA* agenteCopiado = new AgenteIA(agenteEstatico); 
            agentes.push_back(agenteCopiado);
            cout << "Agente copiado com sucesso para a lista de dinamicos!" << endl;

        } else if (opcao == 6) { // Remover (delete) [cite: 23]
            int indice;
            cout << "Digite o indice do agente a remover: "; cin >> indice;
            if (indice >= 0 && indice < agentes.size()) {
                delete agentes[indice]; // Destruição dinâmica obrigatória [cite: 23]
                agentes.erase(agentes.begin() + indice);
                cout << "Agente removido." << endl;
            } else {
                cout << "Indice invalido!" << endl;
            }

        } else if (opcao == 7) { // Sair
            cout << "Encerrando sistema e liberando memoria..." << endl;
            // Destruindo todos os agentes alocados [cite: 23, 44]
            for (AgenteIA* ag : agentes) {
                delete ag; 
            }
            agentes.clear();
            ofstream arquivo("log_execucao.txt", ios::app);
            arquivo << "[SISTEMA] Sistema encerrado." << endl;
        } else {
            cout << "Opcao invalida" << endl; // Validação adicional para o vídeo [cite: 41, 42]
        }
    }
    return 0;
}