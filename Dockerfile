FROM gcc:latest

WORKDIR /app

# Copia todos os arquivos do repositório para dentro da imagem
COPY . .
