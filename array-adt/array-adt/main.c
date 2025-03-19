//
//  main.c
//  array-adt
//
//  Created by Hugo Juarez on 3/18/25.
//

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void display(Array* a);

int main(int argc, const char * argv[]) {
    
    Array a;
    
    printf("Enter the size of the array: ");
    scanf("%d", &a.size);
    
    a.A = (int *) malloc(a.size*sizeof(int));
    
    printf("\nEnter the length of numbers you wanna input: ");
    scanf("%d", &a.lenght);
    
    printf("\nEnter the numbers of the array: ");
    for(int i=0; i<a.lenght; ++i)
        scanf("%d", &a.A[i]);
    
    display(&a);
    
    free(a.A);
    
    return 0;
}

void display(Array* a){
    printf("\nThis are the items in the array: \n");
    for(int i=0; i< (a->lenght); ++i)
        printf("%d\t", a->A[i]);
}
