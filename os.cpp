#include<stdio.h> #include"thread.h" #include<stdlib.h> static void go(int n);

#define NTHREADS 4
static thread_t threads[NTHREADS];
static int n1=1000,m1=1000,n2=1000,m2=1000; double matA[1000][1000];
double matB[1000][1000]; double matC[1000][1000]; double matD[1000][1000];
int main(int argc,char** argv){ int i,j;
long exitValue;
//scanf("Enter the values of row and column for the first matrix %d %d",&m1,&m2);
//scanf("Enter the values of row and column for the first matrix %d %d",&n1,&n2);

for (i = 0; i < m1; i++) for (j = 0; j < m2; j++)
matA[i][j] = rand() % 10;

for (i = 0; i < n1; i++)
for (j = 0; j < n2; j++) matB[i][j] = rand() % 10;

for(i=0;i<NTHREADS;i++){
thread_create(&(threads[i]),&go,i);
}

for(i=0;i<NTHREADS;i++){
exitValue=thread_join(threads[i]); printf( "Thread %ld exits\n",exitValue);
}
for(int i=0;i<m1;i++){
for(int j=0;j<n2;j++){
double temp=0; for(int k=0;k<m2;k++){
temp += matA[i][k] * matB[k][j];
}
 
if(matC[i][j]!=temp) printf("Not equal\n");
}
}
printf("Verified.\n"); return 0;
}

void go(int n){
int start=250*n; int end=start+250; if(end>m1){
end=m1;
}
for(int i=start;i<end;i++){
for (int j = 0; j < n2; j++) { matC[i][j]=0;
for (int k = 0; k < m2; k++) {
matC[i][j] += matA[i][k] * matB[k][j];
}
}
}
thread_exit(n);
//Notreached
}
