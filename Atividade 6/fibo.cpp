#include <iostream>
using namespace std;

template<class Template>
Template fibo(int num) {
  if (num <= 1) return num;
  return fibo<Template>(num-1) + fibo<Template>(num-2);
}

int main() {
  cout << fibo<int>(9) << endl;
  cout << fibo<double>(9) << endl;
}