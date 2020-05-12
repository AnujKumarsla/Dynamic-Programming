#include<stdio.h>

int max(int a,int b){
	if(a<b)
			return b;
	return a;
}
int LCS(char *str1,char *str2,int m,int n){
	if(n==0 || m==0)
			return 0;
	if(str1[m-1]==str2[n-1])
			return (1+LCS(str1,str2,m-1,n-1));
	else if(str1[m-1]!=str2[n-1])
			return max(LCS(str1,str2,m-1,n) , LCS(str1,str2,m,n-1));
}

int TD[10][10];
int TDLCS(char *str1,char *str2,int m,int n){
	for(int i=0;i<n+1;i++)
		for(int j=0;j<m+1;j++)
			if(i==0 || j==0)
				TD[i][j]=0;
	
	for(int i=1;i<m+1;i++)
		for(int j=1;j<n+1;j++){
			if(str1[i-1]==str2[j-1]){
				TD[i][j]=1+TD[i-1][j-1];
			}
			else{
				TD[i][j]=max(TD[i][j-1],TD[i-1][j]);
			}
		}

	return TD[m][n];

}

int LCSS(char *str1,char *str2,int m,int n){
static int result=0;
	for(int i=0;i<n+1;i++)
		for(int j=0;j<m+1;j++)
			if(i==0 || j==0)
				TD[i][j]=0;


	for(int i=1;i<m+1;i++)
		for(int j=1;j<n+1;j++){
			if(str1[i-1]==str2[j-1])
				result = max(result,TD[i][j] = (1+TD[i-1][j-1]));
			else
				TD[i][j] = 0;
		}

	// return TD[n][m];
	return result ;
}

char str[20];
int count=0;
void backTrack(char *str1,char *str2,int m,int n){
	if(m==0 || n==0)
		return;
	if(str1[m-1]==str2[n-1]){
		str[count++]=str1[m-1];
		backTrack(str1,str2,m-1,n-1);
	}
	else{
		if(TD[m-1][n]<TD[m][n-1])
			backTrack(str1,str2,m,n-1);
		else
			backTrack(str1,str2,m-1,n);
	}
}
char lcs[21];

void backTrace(char *X,char *Y,int m,int n){
	int index=0;
   int i = m, j = n; 
   while (i > 0 && j > 0) 
   { 
      if (X[i-1] == Y[j-1]) 
      { 
          lcs[index++] = X[i-1]; 
          i--; j--;     
      }  
      else if (TD[i-1][j] > TD[i][j-1]) 
         i--; 
      else
         j--; 
   }
   lcs[index]='\0';
}
int main(){
	
	char str1[10],str2[10];
	int m,n;
	lcs[20]='\0';
	printf("Enter the size of the String1 and String2 : ");
	scanf("%d %d",&m,&n);
	printf("Enter the String1 and String 2 : \n");
	scanf("%s\n%s",str1,str2);
	// printf("Size of the str1 and str2 : %d %d %d %c %c",m,n,sizeof(char),str1[m],str2[n]);
	// printf("%s %s",str1,str2);
	// printf("Longest common Subsquences : %d\n",TDLCS(str1,str2,m,n));
	printf("Longest common Substring : %d\n",LCSS(str1,str2,m,n));
	// Pass the number of characters not size of the string

	// 	for(int i=0;i<m+1;i++){
	// 	for(int j=0;j<n+1;j++)
	// 		printf("%d\t",TD[i][j]);
	// 		printf("\n");
	// 	}
	// backTrace(str1,str2,m,n);
	// printf("\n%s",lcs);
	// backTrack(str1,str2,m,n);
	// printf("\n%s",str);
	return 0;
}