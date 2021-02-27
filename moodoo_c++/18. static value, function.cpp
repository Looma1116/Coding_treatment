#include <iostream>
#include <cstring>

class Marine{
  static int total_marine_num; //static 변수는 클래스 내부에서만 전역변수처럼 작동

  char* name; //이름
  int hp; //체력
  int co_x, co_y; //좌표
  const int default_ap; //기본 공격력
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
    static void show_total_marine_num();
    void show_stat();
};
int Marine::total_marine_num = 0; //클래스 static 변수는 이렇게 초기화 해줘야 함 const static은 클래스 내부에서 초기화 가능하긴 함.

Marine::Marine() : hp(50), name(NULL), co_x(0), co_y(0), default_ap(5), is_dead(false){ total_marine_num++;}

Marine::Marine(int x, int y, char* cname) : hp(50), co_x(x), co_y(y), default_ap(5), is_dead(false){
  int len = strlen(cname);
  name = new char[len+1];
  strcpy(name, cname);
  total_marine_num++;
}

Marine::~Marine(){
  if (name) delete[] name;
  total_marine_num--;
}

Marine::Marine(const Marine &marine) : default_ap(5){
  hp = marine.hp;
  co_x = marine.co_x;
  co_y = marine.co_y;
  name = new char[(strlen(marine.name)+1)]; //깊은 복사 (deep copy)
  strcpy(name, marine.name);
  is_dead = marine.is_dead;
  total_marine_num++;
}

int Marine::attack() {return default_ap;}

void Marine::be_attacked(int damage){
  hp-=damage;
  if(hp<=0) is_dead = true;

  std::cout<<"Marine "<<name<<"이(가) 공격당했습니다!"<<std::endl;
  std::cout<<"받은 데미지: "<<damage<<std::endl;
  std::cout<<"현재 체력: "<<hp<<std::endl;
}

void Marine::move(int x, int y){
  co_x = x;
  co_y = y;
}

void Marine::show_total_marine_num(){
  std::cout << "총 마린의 수 : " << total_marine_num << std::endl; //객체가 없어도 호출 가능~
}

void Marine::show_stat(){
  std::cout << "<Marine " << name << ">"<< std::endl;
  std::cout << "체력 : " << hp<< std::endl;
  std::cout << "위치 : " <<co_x<<", "<<co_y<<std::endl;
  std::cout << "기본 공격력 : " <<default_ap<< std::endl;
  std::cout << "현재 총 마린 수 : " << total_marine_num << std::endl;
}

int main(){
  Marine marine1(1,2,"짐 레이너");
  marine1.show_stat();

  Marine marine2(marine1);
  marine2.show_stat();
  Marine marine3 = Marine(0,1,"infected");
  Marine::show_total_marine_num();

  marine3.be_attacked(marine2.attack());
  

}
