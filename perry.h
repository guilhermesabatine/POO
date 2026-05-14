#ifndef PERRY_H
#define PERRY_H

#include <string>

class AgenteIA {
private:
    std::string nome;
    std::string especialidade;
    int nivelEnergia;
    int tarefasConcluidas;

    void registrarLog(const std::string& evento) const;

public:
    AgenteIA(); 
    AgenteIA(std::string n, std::string esp, int energia); 
    
    AgenteIA(const AgenteIA& outro); 
    
    ~AgenteIA();

    std::string getNome() const;
    int getNivelEnergia() const;

    void exibirStatus() const;
    void executarTarefa(int custoEnergia);
    void recarregarEnergia(int quantidade);
};

#endif