#include <iostream>
#include <string>
#include <vector>
#include "pessoa.hpp"
#include "conhecido.hpp"
#include  "amigo.hpp"
#include "agenda.hpp"

int main() {
  Agenda a = Agenda(3);
  a.add_informacoes();
  a.imprimeEmail();
  a.imprimeAniversario();
}