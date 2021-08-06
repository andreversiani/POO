#include <string>
#include "pessoa.hpp"

#ifndef CONHECIDO_H
#define CONHECIDO_H

class Conhecido : public Pessoa {
  public:
    Conhecido(){email = "indefinido";};
    Conhecido(std::string nome, int idade, std::string email) : Pessoa(idade, email){this->email = email;};
    std::string get_email() override {return email;};
    void set_email(std::string email) {this->email = email;};
  private:
    std::string email;
};

#endif