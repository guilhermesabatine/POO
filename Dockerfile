# Utiliza a imagem oficial do GCC
FROM gcc:latest

# Define o diretório de trabalho dentro do container
WORKDIR /app

# Copia os arquivos do diretório atual para o container
COPY . /app

# Compila o código C++
RUN g++ -o sistema_agentes main.cpp AgenteIA.cpp

# Comando padrão para executar a aplicação interativa
CMD ["./sistema_agentes"]