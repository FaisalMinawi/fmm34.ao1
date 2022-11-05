#include <stdio.h>
#include <string.h>


int SIZE = 10;


void printArray(int a[]){
    printf("Index Value\n");
    for(int i = 0; i < SIZE; i++){
        printf("%5d%6d\n", i, a[i]);
    }
}

void arrayHistogram(int a[]){
    int freq_1 = 0, freq_2 = 0, freq_3 = 0;
    char stars_1[10] = "";
    char stars_2[10] = "";
    char stars_3[10] = "";
    for(int i = 0; i < SIZE; i++){

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
    printf("Value Frequency Histogram\n");
    printf("%5d%10d%10s\n",1,freq_1,stars_1);
    printf("%5d%10d%10s\n",2,freq_2,stars_2);
    printf("%5d%10d%10s\n",3,freq_3,stars_3);
}

void swapValue(int a[], int index_1, int index_2){
    int temp = a[index_1];
    a[index_1] = a[index_2];
    a[index_2] = temp;
}


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

double median(int a[]){ 
    bubbleSort(a);
    if (SIZE % 2 != 0){
        return a[SIZE/2];
    }
    else{
        return (a[SIZE/2] + a[(SIZE/2)-1])/2.0;
    }

}

int mode(int a[]) {
   int max_element = 0, max_occurance = 0, counter;

   for (int i = 0; i < SIZE; i++) {
      counter = 0;
      for (int j = 0; j < SIZE; j++){
         if (a[i] == a[j])
         counter++;
      }
      if (max_occurance <= counter){
         max_occurance = counter;
         max_element = a[i];
      }
   }

   return max_element;
}

int isSorted(int a[]){
    for(int i = 0; i < SIZE -1; i++){
        if (a[i]> a[i+1]){ 
            return 0;
        }
    }
    return 1;
}

