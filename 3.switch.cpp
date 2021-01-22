#include <iostream>

using std::cout;
using std::cin;
using std::endl;

	
int main(){
	int user_input;
	cout << "저의 정보를 표시해줍니다." << endl;
	cout << "1 : name" << endl;
	cout << "2 : age" << endl;
	cout << "3 : gender" << endl;
	cin >> user_input;
	
	switch (user_input){
		case 1:
			cout << "Looma" <<endl;
			break;
		case 2:
			cout << "23" <<endl;
			break;
		case 3:
			cout << "male" <<endl;
			break;
		default:
			cout <<"궁금한게 없군요."<<endl;
			break;
	
	}
	
	return 0;
}
