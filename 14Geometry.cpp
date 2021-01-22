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
 
    int num=0;
    int& pnum = num;

  public:
    Geometry(Point **point_list){
      for(int i=0;i++;point_list[i]!=NULL){
        pnum++;
      }
      for(int i = 0; i++; i<=pnum){
        point_array[i]=point_list[i];
      }
      
    };
    Geometry();

    void AddPoint(Point &point);
    void PrintDistance();
    void PrintNumMeets();
    int GetDistance(Point &point_a,Point &point_b);
};
int Geometry::GetDistance(Point &point_a, Point &point_b){
    return(pow(point_a.x-point_b.x, point_a.x-point_b.x) + pow(point_a.y-point_b.y, point_a.y-point_b.y));
  };

void Geometry::AddPoint(Point &point){
  pnum++;
  point_array[pnum] = &point;
}

void Geometry::PrintDistance(){
  int distance;
  for(int i = 0 ; i++; i < pnum){
    for(int j = i ; j++; j<pnum){
      distance+=GetDistance(*point_array[i], *point_array[j]);
    }
  }

  std::cout<<"Distance :"<<distance<<std::endl;

}
int main(){

}
