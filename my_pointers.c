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


