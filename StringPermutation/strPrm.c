#include <stdio.h>
int count=0;
void swap(char *a,char *b){
        char temp;
        temp=*a;
        *a=*b;
        *b=temp;
}
void Prm(char *str,int start,int end){
        // printf("count=%d start=%d end=%d %s\n",count++,start,end,str);
        if(start==end){
                printf("%d. %s\n",count++,str);
        }
        else{
                for(int i=start;i<=end;i++){
                        swap(str+start,str+i);
                        Prm(str,start+1,end);
                        swap(str+start,str+i);
                }
        }
}
int main(){
        char str[20];
        int start=0,end;
        printf("Enter the size of the string : ");
        scanf("%d",&end);
        printf("Enter the string : ");
        scanf("%s",str);
        Prm(str,start,end-1);

        return 0;
}