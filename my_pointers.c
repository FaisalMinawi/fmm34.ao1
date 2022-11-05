#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//requires: 2 arrays of strings and their sizes 
//effects: merging them in alphatical order of their elements (strings) to a new array reprsented as a pointer
char** merge(char* a[], char* b[], int size_a, int size_b){
    int size_merged = size_a + size_b;
    char **merged;
    merged = (char **)malloc(sizeof(char*) * size_merged);//the array is represented as a char **pointer 
    int i,j;
    for (i = 0; i < size_a; i++){//the 1st elements of the merged array are the elements of the 1st array
        merged[i] = a[i];
    }
    for (i = 0; i < size_b; i++){//the others elements of the merged array are the elements of the 2nd array
        merged[size_a + i] = b[i];
    }

    char* temp_string;//intialize a temporary string to facilitate the swaping procedure
    //insertion sort: sorts the newly merged array of the 1st and 2nd arrays
    for (i = 0; i < size_merged; i++){
        for (j = i + 1; j < size_merged; j++){
            if (strcmp(merged[i],merged[j])>0){//alphabetical check if merged[j] should be positioned before the merged[j]
                temp_string = merged[i];//then they are swaped
                merged[i] = merged[j];
                merged[j] = temp_string;
            }
        }
    }
    return merged;

}

int main() {//test cases

    //normal test case
    char* a[] = {"zzzzc", "ac"};
    char* b[] = {"za", "zb", "ab"};

    //printing the final output
    for (int i=0; i < 5; i++){
        printf("%s\n", merge(a,b,2,3)[i]);
    }
    free(merge(a,b,2,3));
    printf("\n");

    char* c[] = {"abbb", "aa"};
    char* d[] = {""};//empty string case
    for (int i=0; i < 3; i++){
        printf("%s\n", merge(c,d,2,1)[i]);
    }
    free(merge(c,d,2,1));
    printf("\n");
    //other normal test case but a litte more complix complix
    char* e[] = {"zaz","cbb","baba"};
    char* f[] = {"zal", "bb", "ba"};
    for (int i=0; i < 6; i++){
        printf("%s\n", merge(e,f,3,3)[i]);
    }
    free(merge(e,f,3,3));
    
    return 0;
}