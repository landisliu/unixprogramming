#include"FileBase.h"
void FileBase::show_stat()
{
	struct stat file_stat;
	char* member_name[]={
		"file_type & mode",
		"i node number",
		"file system device type",
		"special system device type",
		"link numbers",
		"user id of owner",
		"group id of owner",
		"size in bytes",
		"last access time",
		"last modify time",
		"last file status change",
		"block size",
		"blocknumbers"
	};
	if(fstatat(AT_FDCWD, m_file_path.c_str(), &file_stat, AT_SYMLINK_NOFOLLOW)==-1)
	{
		printf("not exists.\n");
		return;

	}
	printf("%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n%26s : %ld\n", member_name[0] ,file_stat.st_mode, member_name[1],file_stat.st_ino,member_name[2],file_stat.st_dev,member_name[3], file_stat.st_rdev,member_name[4], file_stat.st_nlink,member_name[5], file_stat.st_uid,member_name[6], file_stat.st_gid,member_name[7], file_stat.st_size,member_name[8], file_stat.st_atime,member_name[9], file_stat.st_mtime,member_name[10], file_stat.st_ctime,member_name[11], file_stat.st_blksize,member_name[12], file_stat.st_blocks);
}
void FileBase::show_type()
{
	struct stat file_stat;
	if(fstatat(AT_FDCWD, m_file_path.c_str(), &file_stat, AT_SYMLINK_NOFOLLOW)==-1)
	{
		printf("not exists.\n");
		return;
	}

	if(S_ISREG(file_stat.st_mode))
	{
		printf("is regular file.\n");
	}
	if(S_ISDIR(file_stat.st_mode))
	{
		printf("is dir.\n");
	}
	if(S_ISCHR(file_stat.st_mode))
	{
		printf("is char file.\n");
	}
	if(S_ISBLK(file_stat.st_mode))
	{
		printf("is block file.\n");
	}
	if(S_ISFIFO(file_stat.st_mode))
	{
		printf("is pipe or FIFO.\n");
	}
	if(S_ISLNK(file_stat.st_mode))
	{
		printf("is link.\n");
	}
	if(S_ISSOCK(file_stat.st_mode))
	{
		printf("is socket.\n");
	}
}
