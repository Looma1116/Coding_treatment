#include <iostream>

typedef struct Animal{
    char name[30];
    int age;
    
    int health;
    int happy;
    int food;
    int clean;
}Animal;

void creat_Animal(Animal *ani){
    std::cout<<"동물의 이름: ";
    std::cin>>ani->name;
    std::cout<<"동물의 나이 : ";
    std::cin>>ani->age;
    
    ani->health = 100;
    ani->food = 100;
    ani->clean = 100;
    ani->happy = 100;
}

void play(Animal *animal) {
  animal->health -= 10;
  animal->food -= 10;
  animal->clean -= 10;
  animal->happy += 30;
}

void feed(Animal *animal) {
  animal->health += 10;
  animal->food += 35;
  animal->clean -= 30;
  animal->happy +=5;
}

void wash(Animal *animal) {
  animal->health += 10;
  animal->food -= 15;
  animal->clean += 50;
  animal->happy -=20;
}

void one_day_pass(Animal *animal) {
	std::cout<<"하루가 지났어요"<<std::endl;
  animal->health -= 10;
  animal->food -= 10;
  animal->clean -= 10;
  animal->happy -= 15;
}

void show_stat(Animal *animal) {
  std::cout << animal->name << "의 상태" << std::endl;
  std::cout << "체력    : " << animal->health << std::endl;
  std::cout << "배부름  : " << animal->food << std::endl;
  std::cout << "청결    : " << animal->clean << std::endl;
  std::cout << "행복도  : " << animal->happy <<std::endl;
}

int main() {
    Animal *list[10];
    int animal_num = 0;
	int time=3;
    
    for(;;){
        std::cout << "1. 동물 추가하기" << std::endl;
        std::cout << "2. 놀기 " << std::endl;
        std::cout << "3. 밥주기 " << std::endl;
        std::cout << "4. 씻기기 " << std::endl;
        std::cout << "5. 상태보기 "<< std::endl;
        
        int input;
        std::cin >> input;
        
        switch (input) {
            case 1:
				list[animal_num] = new Animal;
                creat_Animal(list[animal_num]);
                animal_num++;
                show_stat(list[animal_num-1]);
                break;
            case 2:
                std::cout <<"누구랑 놀게?"<<std::endl;
                for(int i=0;i<animal_num;i++){
                    std::cout<<i<<" : "<<list[i]->name<<std::endl;
                }
                int with;
                std::cin>>with;
                
                if (with<animal_num){
                    play(list[with]);
                    show_stat(list[with]);
                }
				time--;
				std::cout<<"남은 시간 : "<<time<<std::endl;
                break;
            case 3:
                std::cout <<"누구 밥주게?"<<std::endl;
                for(int i=0;i<animal_num;i++){
                    std::cout<<i<<" : "<<list[i]->name<<std::endl;
                }
                
                std::cin>>with;
                
                if (with<animal_num){
                    feed(list[with]);
                    show_stat(list[with]);
                }
				time--;
				std::cout<<"남은 시간 : "<<time<<std::endl;
                break;
            case 4:
                std::cout <<"누구 씻기게?"<<std::endl;
                for(int i=0;i<animal_num;i++){
                    std::cout<<i<<" : "<<list[i]->name<<std::endl;
                }
                
                std::cin>>with;
                
                if (with<animal_num){
                    wash(list[with]);
                    show_stat(list[with]);
                }
				time--;
				std::cout<<"남은 시간 : "<<time<<std::endl;
                break;
            case 5:
                std::cout <<"누구 상태?"<<std::endl;
                for(int i=0;i<animal_num;i++){
                    std::cout<<i<<" : "<<list[i]->name<<std::endl;
                }
                
                std::cin>>with;
                
                if (with<animal_num){
                    show_stat(list[with]);
                }
				time--;
				std::cout<<"남은 시간 : "<<time<<std::endl;
                break;
        }
		if(time == 0){
			 for (int i = 0; i != animal_num; i++) {
      			one_day_pass(list[i]);
    		}
		time = 3;
		}
		
		
    }
    
    
    return 0;
}
