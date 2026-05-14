FROM gcc:latest

WORKDIR /app

COPY . /app

# O comando de compilação agora aponta para jinx.cpp
RUN g++ -o sistema_agentes main.cpp jinx.cpp

CMD ["./sistema_agentes"]