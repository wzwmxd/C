#include <stdio.h>
#include <stdlib.h>
int f(int n)
{
    int i=0;
    int *p=(int*)malloc(n*sizeof(int));
    int *q,*r=p;
    *p=1;q=(++p);*p=1;++p;
    for(i=0;i<n-2;i++)
    {
       *p=*q+*r;
       p++;q++;r++;
    }
    return *q; 
}
int main(int argc,char *argv[])
{
    int n=0;
    if(argc==2)
        n=atoi(argv[1]);
    printf("fib(%d)=%d",n,f(n));
    return 0;
}
