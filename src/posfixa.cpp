#include "../include/posfixa.hpp"
#include "../include/fila.hpp"
#include "../include/pilha.hpp"

int posfixa(Fila<char> &entrada){

    Pilha<int> pilha;
    
    while (!entrada.vazia()) {
        char token = entrada.desenfileira();
    
        if (std::isdigit(token)) {
            pilha.empilha(token - '0');
        }else if (pilha.vazia()) {
                throw std::runtime_error("Erro: número faltando");
            }
    
            int b = pilha.desempilha();
    
            if (pilha.vazia()) {
                throw std::runtime_error("Erro: número faltando");
            }
    
            int a = pilha.desempilha();
            int resultado = 0;
    
            switch (token) {
                case '+': resultado = n1 + n2; break;
                case '-': resultado = n1 - n2; break;
                case '*': resultado = n1 * n2; break;
                case '/':
                    if (b == 0) throw std::runtime_error("Erro: divisão por zero");
                    resultado = a / b;
                    break;
                default:
                    throw std::runtime_error("Operador inválido");
            }
    
            pilha.empilha(resultado);
        } else {
            throw std::runtime_error("Símbolo inválido na expressão");
        }
    }
    
    if (pilha.vazia()) {
        throw std::runtime_error("Expressão vazia");
    }
    
    int resposta = pilha.desempilha();
    
    if (!pilha.vazia()) {
        throw std::runtime_error("Erro: sobrou número na pilha");
    }
    
    return resposta;
    