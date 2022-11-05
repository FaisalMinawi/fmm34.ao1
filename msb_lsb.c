#include <stdio.h>


//requires: an integer
//effects: most significant "1" bit position in the binary representation 
int msb (int x){ //same description as in hamming_distance.c
    int counter =  -1;
    while (x != 0){
        counter++;
        x = x/2;
    }
    return counter;
}
//requires: an integer
//effects: lest significant "1" bit in the binary representation
int lsb(int x){
    //odd decimal integer number have the least significant 1 bit in the zero-position 
    if (x % 2 != 0){
        return 0;
    }
    //if the decimal integer number is even
    else{
        int counter = 0;
        //The methedology is to start dividing and adding bits from the left going to the right
        while((x!=0) && (x % 2 == 0)){//until we counter the first 1 bit that is considered the lsb 1 bit
            counter++; //of this decimal integer
            x = x/2;
        }
        return counter;
    }
}
//requires: a positive integer
//effects: keeps outputing the distance between the first and last bits set to 1
//         until the user inputs a non-positve integer
int main(){
    int input_1;
    while (1){
        scanf("%d", &input_1);
        if (input_1 <= 0){//input should be a positive integer
            break;
        }
        printf("%d\n",msb(input_1) - lsb(input_1));//prints the differnce ->distance
    }
    return 0;
}
