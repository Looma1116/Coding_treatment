#include <iostream>


class string {
  char *str;
  public:
  int len;

 public:
  string(char c, int n);  // 문자 c 가 n 개 있는 문자열로 정의
  string(const char *s); 
  string(const string &s); //복사 생성자
  ~string(); //소멸자

  void add_string(const char *s);   // str 뒤에 s 를 붙인다.
  void copy_string(const char *s);  // str 에 s 를 복사한다.
  int strlen(const char *str);     // 문자열 길이 리턴
  void print_string(); //str 출력 
};

string::string(char c, int n){
  len = n;
  str = new char[len+1];
  for(int i=0; i<len; i++){
    str[i] = c;
  }
  str[len] = '\0';
}

string::string(const char *s){
  copy_string(s);
}

string::string(const string &s){
  copy_string(s.str);
}

string::~string(){
  if(len) delete[] str;
}

void string::add_string(const char* s){
  int i = len + strlen(s);
  char *str1 = new char[i+1];

  for(int j = 0; j<len; j++){
    str1[j] = str[j];
  }
  int k=0;
  for(int j = len; j<i; j++){
    str1[j] = s[k];
    k++;
  }
  str1[i]= '\0';

  copy_string(str1);
}

void string::copy_string(const char* s){
  len = strlen(s);
  str = new char[len+1];
  for(int i = 0; i<len; i++){
    str[i] = s[i];
  }
  str[len] = '\0';

}

int string::strlen(const char* str){
  int i=0;
  while(str[i] != '\0'){
    i++;
  }

  return i;
}

void string::print_string(){
  for(int i = 0 ; str[i] != '\0'; i++){
    std::cout<<str[i];
  }
  printf("\n");
}


int main(){
  string str('a', 5);
  str.print_string();
  std::cout<<str.len<<std::endl;
  
  string str1(str);
  str1.print_string();

  char name[5] = "Joon";
  str.add_string(name);
  str.print_string();

  str.copy_string(name);
  str.print_string();

  char hello[6] = "Hello";
  string str2(hello);
  str2.print_string();

}
