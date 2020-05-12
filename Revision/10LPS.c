#include <stdio.h>
//Longest Palindromic Subsequences
void reverse(char a[], char b[], int n)
{
    for (int i = 0; i < n; i++)
        b[i] = a[n - 1 - i];
    b[n] = '\0';
}
int isPalindromic(char a[], int n)
{
    for (int i = 0; i < n / 2; i++)
        if (a[i] != a[n - 1 - i])
            return 0;

    return 1;
}
int max(int a,int b){
    if(a<b)
        return b;
    return a;
}
int count=0;
int LCS(char a[],char b[],int m,int n){
    // printf("%d. a %s b %s, m %d, n %d\n",count++,a,b,m,n);
    if(m==0 || n==0)
        return 0;
    if(a[m-1]==b[n-1])
        return 1+LCS(a,b,m-1,n-1);
    else 
        return max(LCS(a,b,m-1,n), LCS(a,b,m,n-1));
}
int LPS(char a[],int n){
    char b[10];
    reverse(a,b,n);
    return LCS(a,b,n,n);
}
int main()
{
    char a[10], b[10];
    int n;
    printf("Enter the size of the String : ");
    scanf("%d", &n);
    printf("Enter the string : ");
    scanf("%s", a);
    // reverse(a, b, n);
    // printf("Entered String:\n%s\n%s\n", a, b);
    // printf("%s is Palindromic %d", a, isPalindromic(a, n));
    printf("Longest Plindromic Subsquences %d",LPS(a,n));
    return 0;
}