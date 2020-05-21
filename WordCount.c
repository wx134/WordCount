#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int WordCount=1;
int CharCount=0;
char a;

int main(int argc, char *argv[]) {
	char str[1000];
	int n,i;
	FILE *fp;
	if((fp=fopen(argv[2],"w+"))==NULL){
		printf("该文件不存在！\n");
		exit(0);
	}
	if(strcmp(argv[1],"-c")==0)
	{
		while((a=fgetc(fp))!=EOF)
			CharCount++;
		fclose(fp);
		printf("字符数：%d\n",CharCount);
	}
	else if(strcmp(argv[1],"-w")==0){
		while(fgets(str,1000,fp)!=NULL){
			n=strlen(str);
			for(i=0;i<n;i++){
				if(str[i]==' '&&str[i-1]!=' ')
					WordCount++;
				else if(str[i]==','&&str[i-1]!=' ')
					WordCount++;
				else if(i==n-1)
					break;
			}
		}
		printf("单词数：%d\n",WordCount);
	}
	return 0;
}




