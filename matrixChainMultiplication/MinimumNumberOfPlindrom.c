#include<stdio.h>
#include<string.h>
#define INI_MAX 32768
int isPalindrom(char a[],int start,int end){
    int n=end-start+1;
    for(int i=0;i<n/2;i++)
        if(a[start+i]!=a[end-i])
            return 0;
    
    return 1;
}
int min(int a,int b){
    if(a<b)
        return a;
    return b;
}
/*int MPP(char a[],int start,int end){
    int temp=0,mm=INI_MAX;
    if(start>=end)
        return 0;
    if(isPalindrom(a,start,end))
        return 0;
    for(int k=start;k<=end-1;k++){
        temp=1+MPP(a,start,k)+MPP(a,k+1,end);
        mm=min(temp,mm);
    }
    return mm;
}
*/
int TD[40][40];
void menset(int row,int col){
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            TD[i][j]=-1;
}
int count=0;
int TMPP(char a[],int start,int end){
    int temp=0,mm=INI_MAX;
    count++;
    if(start>=end)
        return 0;
    if(isPalindrom(a,start,end))
        return 0;
    if(TD[start][end]!=-1)
        return TD[start][end];
    // for(int k=start;k<=end-1;k++){
    //     temp=1+TMPP(a,start,k)+TMPP(a,k+1,end);
    //     mm=min(mm,temp);
    // }
    for(int k=start;k<=end-1;k++){
        temp=1+
        /*left*/( TD[start][k]!=-1?TD[start][k]:( TD[start][k]=TMPP(a,start,k) ) )+
        /*right*/( TD[start][k]!=-1?TD[k+1][end]:( TD[k+1][end]=TMPP(a,k+1,end) ) );
        mm=min(mm,temp);
    }
    return mm;
}

int main(){
    char a[]="amar";
    int start=0,end=strlen(a)-1;
    // printf("Plindrom %d\n",isPalindrom(a,start,end));
    menset(end+1,end+1);
    printf(" count= %d Plindrom %d\n",count,TMPP(a,start,end));
    return 0;
}