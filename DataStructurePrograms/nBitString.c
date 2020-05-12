#include<stdio.h>
int count=0;
void bit(char *str,int start,int n){
	if(n==0){
		printf("%d. %s\n",count++,str);
		return;
	}
	str[start]='0';
	bit(str,start+1,n-1);
	str[start]='1';
	bit(str,start+1,n-1);
}
int main(){
	char str[10];
	int n=3;
	bit(str,0,n);
	return 0;
}