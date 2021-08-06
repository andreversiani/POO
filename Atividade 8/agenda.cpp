#include "agenda.hpp"
#include <iostream>
#include <ctime>

int num_generator() {
  int num = rand()%2;   
  return num;
};

void Agenda::add_informacoes() {
  srand((unsigned int) time (NULL));
  int randomNum;
  for (int i = 0; i < qtd_pessoas; i++) {
    randomNum = num_generator();
    int idade;
    std::string nome, outrainfo;

    std::cout << "Nome: ";
    std::cin >> nome;

    std::cout << "Idade: ";
    std::cin >> idade;

    if (randomNum == 1) std::cout << "Email: ";
    if (randomNum == 0) std::cout << "Aniversário: ";
    std::cin >> outrainfo;
  
    if (randomNum == 0) {Amigo *amigo = new Amigo(nome, idade, outrainfo);this->qtd_amigos++;this->pessoas.push_back(amigo);};
    if (randomNum == 1) {Conhecido *conhecido = new Conhecido(nome, idade, outrainfo);this->qtd_conhecidos++;this->pessoas.push_back(conhecido);};
  }
};

Agenda::~Agenda() {
  for (auto *pessoa : pessoas) {
    delete pessoa;
  }
}

Agenda::Agenda(int qtd_pessoas) {
  this->qtd_pessoas = qtd_pessoas;
};

void Agenda::imprimeEmail() {
  int i = 0;
  for (auto pessoa : this->pessoas) {
    std::string aniversario = this->pessoas[i]->get_aniversario();
    if (aniversario != "") {std::cout << aniversario << std::endl; i++;}
  }
};

void Agenda::imprimeAniversario() {
  int i = 0;
  for (auto pessoa : this->pessoas) {
    std::string email  = this->pessoas[i]->get_email();
    if (email != "") {std::cout << email << std::endl; i++;}
  }
};