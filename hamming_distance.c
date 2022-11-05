#include <stdio.h>

int abs(int x);

int msb (int x){
    int counter =  0;
    while (x != 0){ 
        counter++; 
        x = x/2;  
    } 
    return counter;
}

int main(){
    int input_1, input_2;
    while (1){
        scanf("%d", &input_1);
        if (input_1 > 0){
            break;
        }
        scanf("%d", &input_2);
        if (input_2 <= 0){
            break;
        }
        printf("%d\n",abs(msb(input_1)-msb(input_2))); 
    }
    
    return 0;    
}