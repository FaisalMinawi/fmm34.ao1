#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char** concat(char* a[][3], int row){
    int i,j;
    char temp_str[100] = "";
    int column = sizeof(a[0])/ sizeof(a[0][0]);
    char **merged = (char**)malloc(sizeof(char*) * row);

    for (i = 0; i < row; i++){
        temp_str[0] = 0; 
        merged[i] = (char*)malloc(sizeof(char));

        for (j = 0; j < column; j++){
            strcat(temp_str,a[i][j]); 
            strcat(temp_str," ");
        }
        strcpy(merged[i],temp_str);
    }
    return merged;
}


