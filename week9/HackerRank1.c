#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    unsigned int Arr[6];
    unsigned int ArrSum = 0;
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &Arr[i]);
    }
    
    for(int i = 0; i < n; i++)
    {
        ArrSum += Arr[i];
    }  
    printf("%i", ArrSum);  
    return 0;
}
