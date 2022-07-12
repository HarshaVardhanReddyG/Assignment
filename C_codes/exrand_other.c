#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void other(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
double U=0;
double V=0;
//Generate numbers
for (i = 0; i < len; i++){
    U=(double)rand()/RAND_MAX;
    V=-2*log(1-U);
fprintf(fp,"%lf\n",V);
}
fclose(fp);

}

int  main(){
other("other.dat", 1000000);
return 0;
}