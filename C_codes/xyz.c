#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    FILE *fp=fopen("abs.dat","w");
    for(int i=0;i<1000000;i++){
        int temp=i;
        fprintf(fp,"%d\n",temp);
    }
    fclose(fp);
    return 0;
}