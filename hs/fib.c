#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int f(int n)
{
    if(n==0||n==1)return 1;
    else return f(n-1)+f(n-2);
}
int main(int argc,char *argv[])
{
    time_t t=time(NULL);
    int i=0,n=atoi(argv[1]);
    if(argc==2)
        printf("fib %d=%d\n",n,f(n));
    printf("time: %d ms",time(NULL)-t);
    return 0;
}
