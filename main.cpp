#include<stdio.h>
#include"DirOp.h"
void display_list(const std::list<std::string>& items)
{
	for(std::list<std::string>::const_iterator itr = items.begin(); itr != items.end(); ++itr)
	{
		printf("%s\n",(*itr).c_str());
	}
}
int main(int argc, char* argv[])
{
	DirOp dop(argv[1]);
	std::list<std::string> files;
	std::list<std::string> dirs;
	dop.GetAllFiles(files, false);
	display_list(files);
	printf("_________________________________________________\n");
	dop.GetAllSubDirs(dirs, false);
	display_list(dirs);
	
	printf("__________________________________________________\n");

	files.clear();
	dirs.clear();
	dop.GetAllFiles(files,true);
	display_list(files);
	printf("_________________________________________________\n");
	dop.GetAllSubDirs(dirs,true);
	display_list(dirs);

	return 0;
}
