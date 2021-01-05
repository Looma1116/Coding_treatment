#include <iostream>

int main() {
    int arr_size;
    std::cout<<"array size?? : ";
    std::cin>>arr_size;
    
    int *list = new int[arr_size];
    
    for(int i=0; i<arr_size;i++){
        std::cout<<i<<".element : ";
        std::cin>>*(list+i);
    }
    
    for (int i = 0; i < arr_size; i++) {
    std::cout << i << ".element of list : " << *(list+i) << std::endl;
    }
    
    delete[] list;
    return 0;
}
