#include <iostream>
#include <cstring>

class Marine{
  char* name;
  int hp; //체력
  int co_x, co_y;
  int ap; //공격력
  bool is_dead;

  public:
    Marine();  //기본 생성자
    Marine(int co_x, int co_y, char* name);  //x, y 좌표 생성자
    ~Marine(); //소멸자
    Marine(const Marine &marine); //복사 생성자

    int attack(); //데미지 리턴
    void be_attacked(int damage);
    void move(int x, int y);

    void show_stat();
};

Marine::Marine(){
  name = NULL;
  hp = 50;
  co_x = co_y = 0;
  ap = 5;
  is_dead = false;
}

Marine::Marine(int x, int y, char* cname){
  int len = strlen(cname);
  name = new char[len+1];
  strcpy(name, cname);
  hp = 50;
  co_x = x;
  co_y = y;
  ap = 5;
  is_dead = false;
}

Marine::~Marine(){
  if (name) delete[] name;
}

Marine::Marine(const Marine &marine){
  hp = marine.hp;
  co_x = marine.co_x;
  co_y = marine.co_y;
  name = new char[(strlen(marine.name)+1)]; //깊은 복사 (deep copy)
  strcpy(name,marine.name);
  is_dead = marine.is_dead;
}

int Marine::attack() {return ap;}

void Marine::be_attacked(int damage){
  hp-=damage;
  if(hp<=0) is_dead = true;
}

void Marine::move(int x, int y){
  co_x = x;
  co_y = y;
}

void Marine::show_stat(){
  std::cout << "<Marine " << name << ">"<< std::endl;
  std::cout << "체력 : " << hp<< std::endl;
  std::cout << "위치 : " <<co_x<<", "<<co_y<<std::endl;
}

int main(){
  Marine marine1(1,2,"marine1");
  Marine marine2(marine1);
  marine1.show_stat();
  marine2.show_stat();
}
