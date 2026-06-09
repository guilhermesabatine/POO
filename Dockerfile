FROM debian:bookworm-slim

# Instala apenas o compilador C++
RUN apt-get update && apt-get install -y g++ && rm -rf /var/lib/apt/lists/*

# Define diretório de trabalho
WORKDIR /app

# Copia os arquivos do projeto
COPY . .

# Compila todos os .cpp em um único binário
RUN g++ -std=c++17 -o sistema_agentes main.cpp AgenteIA.cpp

# Executa o binário automaticamente ao iniciar o container
CMD ["./sistema_agentes"]
