#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    fp=fopen("../gau.dat","r");
    double sum=0;
    double a=0;
    int i=0;
    double m=0;
    while(fscanf(fp,"%lf",&a)!=-1){
        sum+=a;i++;
    }
    fclose(fp);
    //printf("%d\n",i);
    if(i==1000000){
        m=sum/1000000;
        printf("mean = %lf\n",m);
    }
    fp=fopen("../gau.dat","r");
    double b=0;
    double sq=0;
    i=0;
    //printf("%lf\n",m);
    while(fscanf(fp,"%lf",&b)!=-1){
        sq+=(b-m)*(b-m);i++;
    }
    fclose(fp);
    
    if(i==1000000){
        double v=sq/1000000;
        printf("variance = %lf\n",v);
    }
    return 0;
}