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
//testing 
int main(){
    char* a[2][3] = {{"I", "LOVE", "CODING"}, {"THIS","IS","SPARTA"}};
    char **result = concat(a,2);
    for (int i=0; i < 2; i++){
       printf("%s\n", result[i]);
    }
    free(result);
    return 0;
}

