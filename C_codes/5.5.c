#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"

/*double verify(int X){
  int c_x1=0,c_y1=0;
  int c_x2=0,c_y2=0;
  double x,y;
  FILE *fp1, *fp2, *fp3;
  fp1=fopen("../bernouli.dat","r");
  fp2=fopen("../rand.dat","r");
  while(fscanf(fp1,"%lf",&x)!=-1){
    fscanf(fp2,"%lf",&y);
    if (x==-1){
      c_x1++;
      if(y>0) c_y1++;
    }
    if(x==1){
      c_x2++;
      if(y<=0) c_y2++;

    }
    fclose(fp1);
    fclose(fp2);
    if (X==1) return (double)c_y1/c_x1;
    else return (double)c_y2/c_x2;
  }
}*/

int main(){
    
    //printf("Mean = %lf\n Variance = %lf\n",Mean,Variance);
    printf("P_(e|1):%lf\n",Verify(1,"../rand.dat"));
    printf("P_(e|0):%lf\n",Verify(-1,"../rand.dat"));
    return 0;
}