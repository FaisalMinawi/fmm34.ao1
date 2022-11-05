#include <stdio.h>
#include <string.h>

//Global Size of the arrays
int SIZE = 10;

//requires: a 1D array of integers
//effects: print Indecies and the elements in order and vertically
void printArray(int a[]){
    printf("Index Value\n");//prints the header first and once
    for(int i = 0; i < SIZE; i++){
        printf("%5d%6d\n", i, a[i]);//prints the each iteration a space followed by the index
    }//followed by a space followed the element positioned at that index 
}
//requires: a 1D array of integers
//effects: print Type of elements, their occurance, and then string of stars 
//         of which length = occurance of each element
void arrayHistogram(int a[]){
    int freq_1 = 0, freq_2 = 0, freq_3 = 0;
    char stars_1[10] = "";
    char stars_2[10] = "";
    char stars_3[10] = "";
    for(int i = 0; i < SIZE; i++){
        //add 1 and star for each occurance depending if it is 1,2, or 3
        if (a[i] == 1){
            freq_1++;
            strcat(stars_1,"*");
        }
        else if (a[i] == 2){
            freq_2++;
            strcat(stars_2,"*");
        }
        else if (a[i] == 3){
            freq_3++;
            strcat(stars_3,"*");
        }
    }
    printf("Value Frequency Histogram\n");//prints the header first and once
    printf("%5d%10d%10s\n",1,freq_1,stars_1);//similar methedology to the printArray function 
    printf("%5d%10d%10s\n",2,freq_2,stars_2);
    printf("%5d%10d%10s\n",3,freq_3,stars_3);
}
//requires: a 1D array of integers - the two indicies whose elements are to be swaped 
//effects: swap the elements positioned at these indicies
void swapValue(int a[], int index_1, int index_2){
    int temp = a[index_1];
    a[index_1] = a[index_2];
    a[index_2] = temp;
}

//requires: a 1D array of integers
//effects: sort them in ascending order
void bubbleSort(int a[]){
    int i, j;
    for (i = 0; i < SIZE - 1; i++){
        for (j = 0; j < SIZE-i-1; j++){
            if (a[j]>a[j+1]){
                swapValue(a,j,j+1);
            }
        }
    }

}
//requires: a 1D array of integers
//effects: print the element positioned at the middle of the array 
//         if size of array is odd then it ouputs array[half its size]
//         otherwise the average between the middle elements explaining why the returned type is double
double median(int a[]){ 
    bubbleSort(a);//Note: the function mutates the array
    if (SIZE % 2 != 0){
        return a[SIZE/2];
    }
    else{
        return (a[SIZE/2] + a[(SIZE/2)-1])/2.0;
    }

}
//requires: a 1D array of integers
//effects: print the last positioned most occuring element 
int mode(int a[]) {
   int max_element = 0, max_occurance = 0, counter;

   for (int i = 0; i < SIZE; i++) {
      counter = 0;
      for (int j = 0; j < SIZE; j++){
         if (a[i] == a[j])//aslong the system is encountring the same element
         counter++;//encrement 1 to the counter
      }
      if (max_occurance <= counter){//checks if the max_occurance which refers to the max number of occurance of an element is the true max
         max_occurance = counter;//otherwise the max is assigned to it
         max_element = a[i];//"=" sign in the "<=" is the reason why the system takes the last maximum occuring element
      }
   }

   return max_element;
}
//requires: a 1D array of integers
//effects: if array is already sorted in ascending order -> prints 1 
//         otherwise, prints 0
int isSorted(int a[]){
    for(int i = 0; i < SIZE -1; i++){
        if (a[i]> a[i+1]){ //a[i] should be always less than the upcoming element in the array
            return 0;
        }
    }
    return 1;
}
//test cases
int main(){
    //normal test case
    int a[] = {1,1,1,1,1,2,2,2,3,3};
    printArray(a);
    printf("\n");
    arrayHistogram(a);
    swapValue(a,0,9);
    printf("%d\n", mode(a));
    printf("%.1f\n",median(a));
    printf("%d\n", isSorted(a));
    printf("**********\n");
    
    //before and after sorting case
    int b[] = {1,3,1,2,1,3,1,3,3,2};
    arrayHistogram(b);
    printf("%d\n", mode(b));
    printf("%d\n", isSorted(b));
    bubbleSort(b);
    printf("%d\n", isSorted(b));
    printf("%.1f\n",median(b));
    swapValue(b,2,8);
    printArray(b);
    printf("**********\n");

    //all elements are the same case
    int c[] = {2,2,2,2,2,2,2,2,2,2};
    arrayHistogram(c);
    swapValue(c,2,2);//same indix case
    printf("%d\n", mode(c));
    printf("%.1f\n",median(c));
    printArray(c);
    printf("%d\n", isSorted(c));
    printf("**********\n");

    //the array is in descending order
    int e[] = {3,3,3,2,2,2,1,1,1,1};
    printArray(e);
    bubbleSort(e);
    printArray(e);   
    printf("%d\n", mode(e));
    printf("%.1f\n",median(e)); 
    printf("**********\n");
    return 0;

}
