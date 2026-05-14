#ifndef AGENTEIA_H
#define AGENTEIA_H

#include <string>

class AgenteIA {
private:
    // Atributos privados garantindo encapsulamento [cite: 11, 14]
    std::string nome;
    std::string especialidade;
    int nivelEnergia;
    int tarefasConcluidas;

    // Método auxiliar privado para registrar logs 
    void registrarLog(const std::string& evento) const;

public:
    // Construtores [cite: 16]
    AgenteIA(); 
    AgenteIA(std::string n, std::string esp, int energia); 
    
    // Construtor de cópia [cite: 17]
    AgenteIA(const AgenteIA& outro); 
    
    // Destrutor [cite: 23]
    ~AgenteIA();

    // Métodos de acesso (Getters) [cite: 13, 14]
    std::string getNome() const;
    int getNivelEnergia() const;

    // Métodos obrigatórios [cite: 12]
    void exibirStatus() const;
    void executarTarefa(int custoEnergia);
    void recarregarEnergia(int quantidade);
};

#endif