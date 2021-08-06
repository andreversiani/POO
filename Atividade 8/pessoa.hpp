#include <string>

#ifndef PESSOA_H
#define PESSOA_H

class Pessoa {
  public:
    Pessoa(){idade = 0; nome = "indefinido";};
    Pessoa(int idade, std::string nome) {this->idade = idade; this->nome = nome;}
    virtual ~Pessoa(){};
    int get_idade() {return idade;};
    std::string get_nome() {return nome;};
    void set_idade(int idade) {this->idade = idade;};
    void set_nome(std::string nome) {this->nome = nome;};
    virtual std::string get_email() {return "";}
    virtual std::string get_aniversario() {return "";};
  private:
    int idade;
    std::string nome;
};

#endif