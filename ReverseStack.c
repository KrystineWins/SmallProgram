//�õݹ�ߵ�һ��ջ����������ջ{1, 2, 3, 4, 5}��1��ջ�����ߵ�֮���ջΪ{5, 4, 3, 2, 1}��5����ջ����
#include <stdio.h>

void ReverseStack(int stack[],int top);
void AddToStackBottom(int stack[], int top, int a);

void main() {
    int length = 0;
    printf("Please input the length of array:\n");
	scanf("%d",&length);
	int stack[length];
	printf("Please input the array:\n");
	for(int i=0;i<length;i++){
	   scanf("%d",&stack[i]);
	}
	ReverseStack(stack,length - 1);
	for(int i=0;i<length;i++){
	   printf("%d ",stack[i]);
	}
}

void ReverseStack(int stack[],int top) {
    if(top != -1){
	   int this = stack[top];
	   top--;
	   ReverseStack(stack,top);
	   AddToStackBottom(stack, top, this);
	}	
}

void AddToStackBottom(int stack[], int top, int a){
	if(top == -1)
    {
        stack[++top] = a;
    }
    else
    {
	    int b = stack[top];
		top--;
        AddToStackBottom(stack, top, a);
        top++;		
        stack[++top] = b;
	}
}