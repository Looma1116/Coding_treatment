//return the reference 

#include <iostream>

class A{
  int x;

  public:
    A(int c) : x(c) {}

    int& access_x() {return x;}
    int get_x() {return x;}
    void show_x() {std::cout<<x<<std::endl;}
};

int main(){
  A a(5);
  a.show_x();

  int& c = a.access_x(); //c가 x의 레퍼런스가 됨
  c = 4;
  a.show_x();

  int d = a.access_x(); //그냥 값의 복사가 일어남
  d = 3;
  a.show_x();

  /*****
  불가능
  int& e = a.get_x();
  e = 2;
  a.show_x();

  get_x()를 호출했을 때 임시로 생성된 x'가 x의 값을 전달 받고 x'가 e에 대입되는데, 이 x'는 임시로 생성되었다가 사라지는 변수이기 때문에 레퍼런스를 가질 수 없다.
  *****/

  int f = a.get_x(); //그냥 값의 복사가 일어남
  f = 1;
  a.show_x();

  a.access_x() = 3;
  a.show_x();

}

/***** output
5
4
4
4
3
*****/
