#include<sys/stat.h>
#include<stdlib.h>
#include<dirent.h>
#include<string>
#include<list>
class DirOp
{
	public:
		DirOp(const std::string& dir_name)
			: m_mode(S_IRWXU|S_IRWXG|S_IRWXO)
			, m_path_name(dir_name)
		{}
		bool Exists();
		bool Mkdir();
		bool Rmdir();
		void GetAllFiles(std::list<std::string>& files, bool recursive = false );
		void GetAllSubDirs(std::list<std::string>& dirs, bool recursive = false );

	private:
	std::string m_path_name;
	int m_mode;
};
