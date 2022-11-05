#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//requires: a 2D array of characters assuming the nested array is no more than 3 columns/ 3 strings
//effects:  1D array containing the concatenation of elements in each element of the 2D array
//          with a space separation between each two elements
char** concat(char* a[][3], int row){
    int i,j;
    char temp_str[100] = "";// assuming the size of the strings are <= 100 characters
    int column = sizeof(a[0])/ sizeof(a[0][0]);
    char **merged = (char**)malloc(sizeof(char*) * row);

    for (i = 0; i < row; i++){
        temp_str[0] = 0; //reset string on each i-loop
        merged[i] = (char*)malloc(sizeof(char));

        for (j = 0; j < column; j++){
            strcat(temp_str,a[i][j]); //copying the elements of the 2D array to the temporary string
            strcat(temp_str," ");
        }
        strcpy(merged[i],temp_str); //the string is coped to the location of the 1D array 
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
