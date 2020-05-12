#include<stdio.h>

struct Node{
	int info;
	struct Node * link;
};
int main(){
	printf("%d\n",sizeof(int));
	printf("size of : %d",sizeof(struct Node));
    return 0;
}