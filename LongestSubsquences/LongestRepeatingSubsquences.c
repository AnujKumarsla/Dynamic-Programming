#include<stdio.h>

int LRS(char a[],int n){
    char b[20];
    int lrs=0;
    for(int i=0;i<n;i++)
        b[i]=a[i];
    b[n]='\0';

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(a[i]==b[j]){
                lrs++;
                break;
            }
        }
    
    return lrs/2;
}
int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int TD[20][20];
int TDLRS(char a[],int n){
    char b[20];

    for(int i=0;i<n;i++)
        b[i]=a[i];
    b[n]='\0';

    for(int i=0;i<n+1;i++)
        for(int j=0;j<n+1;j++)
            if(j==0 || i==0)
                TD[i][j]=0;
    
    for(int i=1;i<n+1;i++)
        for(int j=1;j<n+1;j++){
            if(a[i-1]==b[j-1] && i!=j )
                TD[i][j]=1+TD[i-1][j-1];
            else 
                TD[i][j]=max(TD[i-1][j] , TD[i][j-1]);
        }

    return TD[n][n];
}
int main(){
    char a[20];
    int n=0;
    printf("Enter the nuber n and string : ");
    scanf("%d %s",&n,a);
    printf("The Longest Repeating Subsquences : %d\n",TDLRS(a,n));
    printf("The Longest Repeating Subsquences : %d\n",LRS(a,n));
    printf("\t\t");
    for(int i=0;i<n;i++)
        printf("%c\t",a[i]);
    printf("\n");
    for(int i=0;i<n+1;i++){
        if(i>0)
            printf("%c\t",a[i-1]);
        else 
            printf("\t");
        for(int j=0;j<n+1;j++)
            printf("%d\t",TD[i][j]);
    printf("\n");
    }
    return 0;
}