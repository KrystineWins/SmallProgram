//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ���
//���磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��
#include <stdio.h>

void DeleteChars(char str[],int hashtable[]);

void main(){
   char input[100];
   int deleted[256];
   char c;
   printf("Please input the string:");
   scanf("%s",input);
   printf("Please input the deletedchar:");
   getchar();
   while((c=getchar())!='\n'){
      deleted[c] = 1;
   }
   DeleteChars(input,deleted);   
   int i = 0;
   while(input[i]!='\0'){
	 printf("%c",input[i++]);     	 
   }
}

void DeleteChars(char str[],int hashtable[]){
    int i = 0,j = i;
	while(str[j]!='\0'){
	   if(hashtable[str[j]]!=1){
	      str[i] = str[j];
		  i++;
	   }
	   j++;
	}
	str[i] = '\0';
}