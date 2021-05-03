#include <stdio.h>

int main(){
    int array[10] ={1, 4, 5, 2, 6, 10, 9, 7, 8, 3};
    int tmp;

    for(int i=0;i<10;i++){
        for(int j = 0; j< 10-i; j++){
            if(array[j] > array[j+1]){
                tmp = array[j+1];
                array[j+1] = array[j];
                array[j] = tmp;
            }
        }
    }

    for(int i = 0 ; i <10;i++){
        printf("%d ", array[i]);
    }
    
    return 0;
}