#include<stdlib.h>
#include<dirent.h>
#include<stdio.h>
#include<string.h>
int main(int argc, char* argv[])
{
	DIR* dir = NULL;
	if( (dir = opendir(argv[1])) == NULL)
	{
		printf("open dir failed.");
		return 0;
	}
	struct dirent* ptr = NULL;
	
	while((ptr = readdir(dir)) != NULL)
	{
		if(strcmp(ptr->d_name, ".")==0 || strcmp(ptr->d_name, "..")==0)
		{
			continue;
		}
		else if(ptr->d_type == 8)
		{
			printf("file name:%s\n",ptr->d_name);
		}
		else if(ptr->d_type == 4)
		{
			printf("dir name:%s\n",ptr->d_name);
		}
	}
	closedir(dir);
	return 0;
}
