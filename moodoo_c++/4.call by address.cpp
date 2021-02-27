#include <iostream>


int change_val(int *p){
	int what;
	std::cout<<"뭐로 바꿀까요? ";
	std::cin>>what;
	
	*p = what;
	
	return 0;
}

int main(){
	int num;
	
	std::cout<<"숫자를 입력하세요: ";
	std::cin>>num;
	
	change_val(&num);
	
	std::cout<<"짜잔 : "<<num;
	
	return 0;
}
