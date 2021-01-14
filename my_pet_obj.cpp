#include <iostream>

class Animal{
  private:
   int food;
   int weight;
  int happy;

  public:

    void set_animal(int _food, int _weight, int _happy){
     food = _food;
     weight = _weight;
     happy = _happy;
   }
   void food_animal(int inc){
      food += inc;
      weight += (inc/3);
      happy += (inc/2);
   }
    void veiw_stat(){
     std::cout<<"food: "<<food<<std::endl;
     std::cout<<"weight: "<<weight<<std::endl;
     std::cout<<"happy: "<<happy<<std::endl;
    }
};

int main() {
  Animal animal;

  animal.set_animal(100,50,50);
  animal.veiw_stat();
  animal.food_animal(30);
  animal.veiw_stat();

  return 0;
}
