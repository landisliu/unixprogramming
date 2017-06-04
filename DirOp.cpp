#include"DirOp.h"
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
bool DirOp::Exists()
{
	struct stat dir_stat;
	if(fstatat(AT_FDCWD, m_path_name.c_str(), &dir_stat, AT_SYMLINK_NOFOLLOW)==-1)
		return false;
	if(S_ISDIR(dir_stat.st_mode))
		return true;
	return false;
}

bool DirOp::Mkdir()
{
	if(mkdir(m_path_name.c_str(),m_mode)==-1)
		return false;
	return true;
}
bool DirOp::Rmdir()
{
	if(rmdir(m_path_name.c_str()) == -1)
		return false;
	return true;
};

void DirOp::GetAllFiles(std::list<std::string>& files, bool recursive )
{
	DIR* dir = NULL;
	if( (dir = opendir(m_path_name.c_str())) == NULL)
	{
		printf("open dir failed. dir：%s\n",m_path_name.c_str());
		return;
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
			files.push_back(ptr->d_name);
		}
		else if(ptr->d_type == 4)
		{
			if(recursive)
			{
				std::string sub_dir_name = m_path_name + "/" + ptr->d_name;
				DirOp sub(sub_dir_name);
				sub.GetAllFiles(files, recursive);
			}
		}
	}
	closedir(dir);
}
void DirOp::GetAllSubDirs(std::list<std::string>& dirs, bool recursive )
{
	DIR* dir = NULL;
	if( (dir = opendir(m_path_name.c_str())) == NULL)
	{
		printf("open dir failed.dir:%s\n",m_path_name.c_str());
		return;
	}
	struct dirent* ptr = NULL;
	
	while((ptr = readdir(dir)) != NULL)
	{
		if(strcmp(ptr->d_name, ".")==0 || strcmp(ptr->d_name, "..")==0)
		{
			continue;
		}
		else if(ptr->d_type == 4)
		{
			dirs.push_back(ptr->d_name);
			if(recursive)
			{
				std::string sub_dir_name = m_path_name + "/" + ptr->d_name;
				DirOp sub(sub_dir_name);
				sub.GetAllSubDirs(dirs, recursive);
			}
		}
	}
	closedir(dir);
}
