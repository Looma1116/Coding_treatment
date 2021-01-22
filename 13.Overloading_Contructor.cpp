#include <iostream>

class Date{
  int year;
  int month;
  int day;

public:
  void SetDate(int year_, int month_, int date_);
  void AddDay(int inc);
  void AddMonth(int inc);
  void AddYear(int inc);

  int DaysMonthHas(int year_, int month_);

  void ShowDate();

  Date() {
    std::cout<<"기본 생성자!" <<std::endl;
    year = 2020;
    month = 1;
    day = 15;
  } //Default Contructor

  Date(int year_, int month_, int day_){
    std::cout<<"인자 3개 생성자!"<<std::endl;
    year = year_;
    month = month_;
    day = day_;
  }
};

void Date::SetDate(int year_, int month_, int day_){
  year = year_;
  month = month_;
  day = day_;
}

int Date:: DaysMonthHas(int year_, int month_){
  static int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  if (month_ !=2){
    return month_day[month_-1];
  }
  else if((year_ % 4 == 0 && year_ % 100 != 0)&& year_ % 400 ==0){
    return 29; //윤년
  }
  else return 28;
}

void Date::AddDay(int inc){
  while (true){
    int MonthDay = DaysMonthHas(year, month);

    if (day + inc <= MonthDay){
      day += inc;
      return;
    }
    else {
      inc -= (MonthDay - day + 1);
      day = 1;
      AddMonth(1);
    }    
  }
}

void Date::AddMonth(int inc){ 
  AddYear((month+inc-1)/12);
  month += inc;
  month = (month ==12 ? 12 : month%12);
}

void Date::AddYear(int inc){year += inc;}

void Date::ShowDate(){
  std::cout<<year<<"년"<<month<<"월"<<day<<"일 입니다."<<std::endl;
}

int main(){
  Date day1; //기본 생성자
  day1.ShowDate();
 
  Date day2(2020,1,30); //인자 3개 생성자
  day2.ShowDate();
}
