#include <stdio.h>

int RC(int len[],int pr[],int length, int n){
        if(length ==0 || n==0)
                return 0;
        
        if(len[n-1]<=lenght)
                return max( pr[n-1]+RC(len,pr,length-len[n-1],n) ,RC(len,pr,length,n-1));
        else if(len[n-1]>length)
                return RC(len,pr,length,n-1);
}
int main()
{
        
        printf("Hello, world!\n");
        
        return 0;
}