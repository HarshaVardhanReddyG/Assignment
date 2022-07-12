double **createMat(int m,int n);
void readMat(double **p, int m,int n);
void print(double **p,int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_inv(double **mat, int m);
double **matmul(double **a, double **b, int m, int n, int p);
double **transpose(double **a,  int m, int n);
void uniform(char *str, int len);
void gaussian(char *str, int len);
double mean(char *str);
double variance(char *str);
void triangular(char *str, int len);
void bernouli(char* str ,int len);
void randomVar(char* str ,int len,double A);
void gau_other(char*str,int len,int n);
void gau_ray(char*str, int len);
double verify(int X);
void err(char*str);
double Gaussian();
//End function declaration


//Defining the function for matrix creation
double **createMat(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation


//Defining the function for reading matrix 
void readMat(double **p, int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%lf",&p[i][j]);
  }
 }
}
//End function for reading matrix

//Read  matrix from file
double **loadtxt(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%lf",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}


//Defining the function for printing
void print(double **p, int m,int n)
{
 int i,j;

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  printf("%lf ",p[i][j]);
 printf("\n");
 }
}
//End function for printing

//Defining the function for norm

double linalg_norm(double **a, int m)
{
int i;
double norm=0.0;

 for(i=0;i<m;i++)
 {
norm = norm + a[i][0]*a[i][0];
}
return sqrt(norm);

}
//End function for norm

//Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for inverse of 2x2 matrix


double **linalg_inv(double **mat, int m)
{
double **c, det;
c = createMat(m,m);

det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];

c[0][0] = mat[1][1]/det;
c[0][1] = -mat[1][0]/det;
c[1][0] = -mat[0][1]/det;
c[1][1] = mat[0][0]/det;

return c;

}
// End  function for inverse of 2x2 matrix


//Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c, temp =0;
c = createMat(m,p);

 for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat(n,m);

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
c[i][j]= a[j][i];
//  printf("%lf ",c[i][j]);
  }
 }
return c;

}
//End function for transpose of matrix

//Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}
//End function for generating uniform random numbers

//Defining the function for calculating the mean of random numbers
double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//End function for calculating the mean of random numbers

//Defining the function for generating Gaussian random numbers
void gaussian(char *str, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}

//finding Variance
double variance(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;
double m=mean(str);
fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp +=(x-m)*(x-m);
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//Defining the function for generating Triangular random numbers
void triangular(char *str, int len){
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 2; j++)
{
temp += (double)rand()/RAND_MAX;
}
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}
//Defining function to generate bernouli random variables
void bernouli(char *str ,int len){
  int i;
int temp;
FILE *fp;

fp = fopen(str,"w");

for (i = 0; i < len; i++)
{
if ((double)rand()/RAND_MAX <0.5) temp =-1;
else temp =1;

fprintf(fp,"%d\n",temp);
}
fclose(fp);

}

//
void randomVar(char* str ,int len,double A){
  double temp=0;
  int X,i;
  double N;
  FILE *fp1, *fp2, *fp3;
  fp1=fopen(str,"w");
  fp2=fopen("../bernouli.dat","r");
  fp3=fopen("../gau.dat","r");
for (i = 0; i < len; i++)
{ fscanf(fp2,"%d",&X);
  fscanf(fp3,"%lf",&N);
 temp=A*X+N;

fprintf(fp1,"%lf\n",temp);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);

}


void gau_other(char*str,int len,int n){
  int i;
  double x1,x2,temp;
  FILE *fp;
  while(len>0){
    
    temp=(x1*x1);
    for(int i=0;i<n;i++){
      x2=Gausssian()
     
      temp+=x2*x2;
    }
    fprintf(fp,"%lf\n",temp);
  }
  fclose(fp);
  
}

void gau_ray(char*str, int len){
  int i;
  double x1,x2,temp;
  FILE *fp1, *fp2,*fp3;
  gaussian("../gau1.dat",1000000);
  gaussian("../gau2.dat",1000000);
  fp1=fopen("../gau1.dat","r");
  fp2=fopen("../gau2.dat","r");
  fp3=fopen(str,"w");
  while(fscanf(fp1,"%lf",&x1)!=-1){
    fscanf(fp2,"%lf",&x2);
    temp=sqrt((x1*x1)+(x2*x2));
    fprintf(fp3,"%lf\n",temp);
  }
  fclose(fp1);
  fclose(fp2);
  fclose(fp3);
  remove("../gau1.dat");
  remove("../gau2.dat");
}


double Verify(int x,char *str){
  FILE *fp, *fp2;
  fp=fopen(str,"r");
  fp2 = fopen("../bernouli.dat", "r");
  long c1=0;
  long c2=0;
  double sum=0;
  double y;
  double i;
  while(fscanf(fp,"%lf",&y)!=-1)
  { 
    fscanf(fp2,"%lf",&i);
    if(x == 1 && i == 1){
      if(y<0) sum++;
      c1++;
    }
    else if(x == -1 && i == -1){
      if(y>0) sum++;
      c2++;
    }

    else if(i == 1){
      c1++;
      continue;
    }
    else{
      c2++;
      continue;
    }
  }
  fclose(fp);
  fclose(fp2);
  if(x == 1) return sum/c1;
  else return sum/c2;
}


void err(char* str){
  FILE *fp;
  fp = fopen(str,"w");
  for (double i=0;i<=10;i++){
    double A=pow(10,i/10);
    randomVar("../random.dat",1000000,A);
    double e0=Verify(1,"../random.dat");
    double e1=Verify(-1,"../random.dat");
    fprintf(fp,"%lf\n",(e0+e1)/2);
    remove("../random.dat");
  }
  fclose(fp);
  
}

double Gausssian(){
  int i,j;
double temp;
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)srand()/RAND_MAX;
}
temp-=6;
return temp;
}