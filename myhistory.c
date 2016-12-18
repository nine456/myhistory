#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX 150

int main(int argc, char *argv[])
{
	FILE *fp;
	int num,i=1,j=0;
	char buff[MAX];

	fp = fopen("/home/family/.bash_history", "r");  // 파일 열기

	if(argv[1] == NULL)
	{
		while(!feof(fp))  // 파일의 끝이 아니라면
		{
			printf("%6d  ",i);
			fgets(buff,MAX,fp);
			printf("%s",buff);
			i++;
		}
		fclose(fp);
	}

	num=atoi(argv[1]);
	if(num)
	{
		while(!feof(fp))  // 파일의 끝이 아니라면
		{
			fgets(buff,MAX,fp);
			j += i;
		}

		for(i=0; i<num; i++)
		{
			printf("%6d  ",j);
			printf("%s",buff);
			j--;
		}
	}
}
