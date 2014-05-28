/********************************************************/
//���ܣ������������̣������̺��ӽ���֮��ͨ���ܵ��������ݣ���������
//	   �ӽ��̷����ַ���exit��ʾ���ӽ����˳������ҵȴ��ӽ��̷��أ�
//	   �ӽ��̲�ѯ�ܵ������ӹܵ������ַ���exit��ʱ�������
/********************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	pid_t pid;
	int fd[2];
	char buff[64];
	char *cmd = "exit";
	
	if(pipe(fd))	//�����ܵ�
	{
		perror("Create pipe fail!");
		return -1;
	}

	pid = fork();	//�����ӽ���
	if(-1 == pid)
	{
		perror("Create process fail!");
		return -1;	
	}
	else if(0 == pid)	//�ӽ���
	{
		close(fd[1]);	//�رչܵ�д����
		printf("Child process!Wait command from parent...\n");
		while(1)
		{
			read(fd[0],buff,64);
			if(0 == strcmp(buff,cmd))
			{
				printf("receive command:%s\n",buff);
				close(fd[0]);
				exit(0);
			}
			else
				printf("receive command:%s\n",buff);
			sleep(1);
		}
	}
	else	//������
	{
		printf("Parent process!Child process id:%d\n",pid);
		close(fd[0]);	//�رչܵ�������
		printf("Send command to child process...\n");
		sleep(2);
		write(fd[1],"This is a test.\n",strlen("This is a test.")+1);
		sleep(2);	
		write(fd[1],cmd,strlen(cmd)+1);
		close(fd[1]);
	}
	
	return 0;
}
