#include<stdio.h>
/*
test Cases
I/P : 
8 8
ABCIDEFK
HABGCDJE
O/P : HABGCIDJEFK

I/P : 
6 6
XYZABC
ABXYZD
O/P ABXYZABCD
*/
int TD[20][20];
int max(int a,int b){
    if(a<b)
        return b;
    return a;
}

void reverse(char a[],int n){
    char temp;
    for(int i=0;i<n/2;i++){
        temp=a[n-1-i];
        a[n-1-i]=a[i];
        a[i]=temp;
    }
}
int LCS(char a[],char b[],int m,int n){
    for(int i=0;i<n+1;i++)
        for(int j=0;j<m+1;j++){
            if(m==0 || n==0)
                TD[i][j]=0;
        }
    // printf("HEllo, World!");

    for(int i=1;i<n+1;i++)
        for(int j=1;j<m+1;j++){
            if(a[j-1]==b[i-1])
                TD[i][j]=1+TD[i-1][j-1];
            else 
                TD[i][j]=max(TD[i-1][j],TD[i][j-1]);
        }
    
    return TD[m][n];
}
void PSCS(char str[],char a[],char b[],int m,int n){
    int x,y,i,j,counter;
    int count=0;
    counter=0;
    x=j=m;
    y=i=n;
    
    while(i!=0 || j!=0){
        if(a[j-1]==b[i-1]){
            str[counter++]=a[j-1];
            printf("%d. %c i=%d j=%d TD=%d Equal\n",count++,str[counter-1],i,j,TD[i][j]);
            j--;i--;
        }
        else
            if(TD[i-1][j]<TD[i][j-1]){
                str[counter++]=a[j-1];
                // str[counter++]=a[j-1];
                printf("%d. %c i=%d j=%d TD=%d left\n",count++,str[counter-1],i,j,TD[i][j-1]);
                j--;
            }
            else{
                str[counter++]=b[i-1];
                // str[counter++]=b[i-1];
                printf("%d. %c i=%d j=%d TD=%d upper\n",count++,str[counter-1],i,j,TD[i-1][j]);
                i--; 
            }
    }
    str[counter]='\0';
    reverse(str,counter);


}
int main()
{
    char a[10], b[10],str[20];
    int n,m;
    printf("Enter the size of the String : ");
    scanf("%d %d", &m,&n);
    printf("Enter the string : \n");
    scanf("%s %s", a,b);
    // reverse(a, b, n);
    // printf("Entered String:\n%s\n%s\n", a, b);
    // printf("%s is Palindromic %d", a, isPalindromic(a, n));
    printf("HEllo, World!");
    printf("Longest Common Subsquences %d\n",LCS(a,b,m,n));
    PSCS(str,a,b,m,n);
    printf("shortest common Subsquences : %s\n",str);

    printf("\t\t");
    for(int i=0;i<m;i++)
        printf("%c\t",a[i]);
    printf("\n");

    for(int i=0;i<m+1;i++){
        if(i!=0)
            printf("%c\t",b[i-1]);
        else 
            printf("\t");
        for(int j=0;j<n+1;j++)
            printf("%d\t",TD[i][j]);
        printf("\n");
    }
    return 0;
}