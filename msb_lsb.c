#include <stdio.h>


int msb (int x){ 
    int counter =  -1;
    while (x != 0){
        counter++;
        x = x/2;
    }
    return counter;
}

int lsb(int x){

    if (x % 2 != 0){
        return 0;
    }

    else{
        int counter = 0;

        while((x!=0) && (x % 2 == 0)){
            counter++; 
            x = x/2;
        }
        return counter;
    }
}

int main(){
    int input_1;
    while (1){
        scanf("%d", &input_1);
        if (input_1 <= 0){
            break;
        }
        printf("%d\n",msb(input_1) - lsb(input_1));
    }
    return 0;
}
