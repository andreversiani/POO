#include <string>
#include <vector>
#include "pessoa.hpp"
#include "conhecido.hpp"
#include  "amigo.hpp"
#include "time.h"

#ifndef AGENDA_H
#define AGENDA_H

class Agenda {
  public:
    Agenda(int qtd_pessoas);
    ~Agenda();
    void imprimeEmail();
    void imprimeAniversario();
    void add_informacoes();
  private:
    std::vector<Pessoa*> pessoas;
    int qtd_amigos;
    int qtd_conhecidos;
    int qtd_pessoas;
};

#endif