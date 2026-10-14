
#include<stdio.h>
#include<string.h>
#include"myheader.h"

// Single-line comment

/*
   Multi-line comment
   Testing comment removal
*/

//#define A 10
//#define B 20
#define HEADER_VALUE 30
#define MAX_VALUE 100
#define COUNT 5
#define MSG "Hello"

int main()
{
    int x = A;
    int y = B;
    int z = HEADER_VALUE;

    // Print values
    printf("A = %d\n", x);
    printf("B = %d\n", y);
    printf("HEADER_VALUE = %d\n", z);

    int a = MAX_VALUE;
    int b = COUNT;

    /* Inline comment */
    int c = MAX_VALUE;

    printf("%s\n", MSG);
    printf("%d\n", MAX_VALUE + COUNT);

    display();

    return 0;
}
