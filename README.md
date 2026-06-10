
---

# 🧩 POO - Sistema de Agentes em C++

Este projeto implementa um sistema de agentes em C++ como parte dos estudos de Programação Orientada a Objetos (POO).  
O código contém uma classe `AgenteIA` e um programa principal (`main.cpp`) que demonstra seu funcionamento.

---

## 📂 Estrutura do Repositório
- `main.cpp` → ponto de entrada da aplicação.
- `AgenteIA.cpp` → implementação da classe de agente.
- `AgenteIA.h` → cabeçalho da classe.
- `Dockerfile` → define a imagem base (`poo_agent`) e copia os arquivos.
- `docker-compose.yml` → compila os fontes e executa o binário automaticamente.
- `README.md` → documentação do projeto.

---

## 🚀 Execução com Docker Compose

### 1. Criar a imagem
A imagem é definida no `Dockerfile` e chamada **poo_agent**:

docker build -t poo_agent .

### 2. Subir o container
O `docker-compose.yml` compila os arquivos e executa o binário:

docker compose up

### 3. Abrir console interativo
No Portainer ou via terminal:

docker exec -it poo_agentes bash
O programa `./sistema_agentes` já será iniciado automaticamente.

---

- **image: poo_agent** → usa a imagem criada pelo Dockerfile.  
- **command** → compila os arquivos e executa o binário.  
- **./sistema_agentes** → garante que o programa seja o processo principal do container.  
- **stdin_open + tty** → permitem abrir console interativo no Portainer.

---

## ⚠️ Observações Importantes
- Se novos arquivos `.cpp` forem adicionados, ajuste o `command` para incluir todos (ex: `*.cpp`).  
- O container compila os fontes **sempre que sobe**, garantindo que você está rodando a versão mais atualizada.  
- Se quiser manter o container ativo mesmo após o programa terminar, altere o comando para:
  ```yaml
  command: bash -c "g++ -std=c++17 -o sistema_agentes *.cpp && ./sistema_agentes; tail -f /dev/null"
  ```

---

## 🛠️ Requisitos
- Docker >= 20.10  
- Docker Compose >= 1.29  
- GCC (já incluído na imagem base)

---

