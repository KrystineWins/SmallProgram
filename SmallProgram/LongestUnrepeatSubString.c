//��Ŀ������������ظ��Ӵ�����abcdefgegcsgcasse������ظ��Ӵ�Ϊabcdefg������Ϊ7#include<stdio.h>

//˼·����һ�����鱣���ַ����ֵĴ�������i��j���б��������ַ�����
//��ĳ���ַ�û�г��ֹ�������+1�������ַ��Ѿ����ֹ�������+1���ҵ�����ַ�ǰ����ֵ�λ�õ���һ��λ�ã���Ϊi
//����֮ǰ����Щ�ַ�������-1������������ֱ��'\0'

#include<stdio.h>

int find(char str[],char *output)
{
	int i = 0 , j = 0;
	int cnt[26] = {0};
	int res = 0 , temp = 0;
	char *out = output;
	int final;
	while(str[j] != '\0')
	{
		if(cnt[str[j]-'a'] == 0)
		{
			cnt[str[j]-'a']++;

		}
		else
		{
			cnt[str[j]-'a']++;
			while(str[i] != str[j])
			{	
				cnt[str[i]-'a']--;
				i++;
			}
			cnt[str[i]-'a']--;
			i++;
		}	

		j++;
		temp = j-i;
		if(temp > res)
		{
			res = temp;
			final = i;
		}
	}
	//���������output����
	for(i = 0 ; i < res ; ++i)
		*out++ = str[final++];
	*out = '\0';
	return res;
}
int main(void)
{
	char a[] = "abcdefg";
	char b[100];
	int max = find(a,b);
	printf("%s\n",b);
	printf("length=%d",max);
	return 0;
}