/* file: c-main.c */
#include <stdio.h>

#define NUM 200
extern void sum_abs_(int *inp, int *num, int *asum);
int main(int argc, char **argv)
{
    int data[NUM], num, i, asum;

    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1;  /* NOTE: difference in array numbering */  
    }
    sum_abs_(data, &num, &asum);
    printf("sum=%d\n", asum);
    return 0;
}
