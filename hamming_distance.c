#include <stdio.h>
//requires: an integer
//effects: absolute value of the input integer
int abs(int x);

//requires: an integer
//effects: most significant "1" bit position in the binary representation 
int msb (int x){
    int counter =  0;
    while (x != 0){ //the methodology is keep divindg the number 
        counter++; //each dividion is an addition to the overall binary represntation
        x = x/2; //for example, if there are 5 divisions in total, then (x)10 = (1xxxx)2 
    }            //5 bits: 4 are either 0 or 1 and the last bit is 1 normally
    return counter;
}

//requires: two positive integers
//effects: assuming the inputs are positive integers, keeps outputing the Hamming distance between the bit representations of those two integer
//         until the an non-positive integer is inputed
int main(){
    int input_1, input_2;
    while (1){
        scanf("%d", &input_1);
        if (input_1 > 0){//checks if the 1st input is positive
            break;
        }
        scanf("%d", &input_2);
        if (input_2 <= 0){//checks if the 2nd input is positive
            break;
        }
        printf("%d\n",abs(msb(input_1)-msb(input_2)));// prints the hamming distance 
    }
    
    return 0;    
}