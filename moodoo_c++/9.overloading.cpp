#include <iostream>

void print(int x) {std::cout<<"int: "<<x<<std::endl;}
void print(double x){std::cout<<"double: "<<x<<std::endl;}

int main(){ 
  int a = 10;
  char b = 'A';
  double c = 3.14f;

  print(a);
  print(b); //int를 인자로 갖는 함수로 overloading
  print(c);

  return(0);
}
