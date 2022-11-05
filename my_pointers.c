#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char** merge(char* a[], char* b[], int size_a, int size_b){
    int size_merged = size_a + size_b;
    char **merged;
    merged = (char **)malloc(sizeof(char*) * size_merged);
    int i,j;
    for (i = 0; i < size_a; i++){
        merged[i] = a[i];
    }
    for (i = 0; i < size_b; i++){
        merged[size_a + i] = b[i];
    }

    char* temp_string;

    for (i = 0; i < size_merged; i++){
        for (j = i + 1; j < size_merged; j++){
            if (strcmp(merged[i],merged[j])>0){
                temp_string = merged[i];
                merged[i] = merged[j];
                merged[j] = temp_string;
            }
        }
    }
    return merged;

}

