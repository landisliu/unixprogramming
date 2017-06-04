#include"DirOp.h"
#include<unistd.h>
#include<fcntl.h>
bool DirOp::Exists()
{
	struct stat dir_stat;
	if(fstat(AT_FDCWD, m_path_name.c_str(), &dir_stat, AT_SYMLINK_NOFOLLOW)==-1)
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
