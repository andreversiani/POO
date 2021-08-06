#include <string>
#ifndef PAGER_H
#define PAGER_H

class Pager {
  public:
    Pager(std::string pager) {this->pager = pager;};
    Pager(const Pager &p) {this->pager = p.pager;};
    std::string pager;
    Pager& operator= (const Pager &p){pager = p.pager; return *this;};
}; 

#endif