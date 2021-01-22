#include <iostream>
#include <cmath>

class Point{
  public: 
    int x,y;

  public:
    Point(int pos_x, int pos_y){
      x = pos_x;
      y = pos_y;
    }
};

class Geometry{
  //점 100개를 보관하는 배열
  Point* point_array[100];
  int num;
  public:
    Geometry(Point **point_list, int pnum){
      num= pnum;
      for(int i = 0; i<=num; i++){
        point_array[i]=point_list[i];
      }
      
    };
    Geometry();

    void AddPoint(Point &point);
    void PrintDistance();
    void PrintNumMeets();
    
};

void Geometry::AddPoint(Point &point){
  num++;
  point_array[num] = &point;
}

void Geometry::PrintDistance(){
  int distance=0;
  int &d = distance;
  
  for(int i = 0 ; i < num; i++){
    for(int j = 0 ;j<i; j++){
      d += pow((point_array[i]->x-point_array[j]->x),2);
      d += pow((point_array[i]->y-point_array[j]->y),2);
    }
  }

  std::cout<<"점들의 거리 합:"<<distance<<std::endl;

}
int main(){
  Point* pointArray[100];
  int num=0;
  std::cout<<"점 개수 몇 개? :";
  std::cin>>num;

  for(int i=0; i<num; i++){
    int x, y;
    std::cout<<"x좌표 :";
    std::cin>>x;
    std::cout<<"y좌표 :";
    std::cin>>y;
    pointArray[i] = new Point(x,y);
  }
  
  Geometry G(pointArray, num);

  G.PrintDistance();


  

}

