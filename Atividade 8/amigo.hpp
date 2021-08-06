#include <string>
#include "pessoa.hpp"

#ifndef AMIGO_H
#define AMIGO_H

class Amigo : public Pessoa {
  public:
    Amigo(){aniversario = "indefinido";};
    Amigo(std::string nome, int idade, std::string aniversario) : Pessoa(idade, aniversario){this->aniversario = aniversario;};
    std::string get_aniversario() override {return aniversario;};
    void set_aniversario(std::string aniversario) {this->aniversario = aniversario;};
  private:
    std::string aniversario;
};

#endif