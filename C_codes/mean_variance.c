#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

int main(){
    double Mean = mean("../uni.dat");
    double Variance = variance("../uni.dat");
    printf("Mean = %lf\n Variance = %lf\n",Mean,Variance);
    return 0;
}