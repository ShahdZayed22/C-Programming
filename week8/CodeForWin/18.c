#include <stdio.h>

#define size 10

int* getSquaredNum(const int num, int* square);


int main(){
    //Write a C program to return multiple value from function using pointers.
    int SquaredNum[size];
    int i;

    getSquaredNum(size, SquaredNum);

    printf("First %d square numbers are:\n", size);
    for (i = 0; i < size; i++)
    {
        printf("%d ", *(SquaredNum + i));
    }

    return 0;
    
}

int* getSquaredNum (const int num, int* square){
    for (int i = 0; i < num; i++){
        *(square + i) = (i + 1) * (i + 1);
    }

    return square;
}
