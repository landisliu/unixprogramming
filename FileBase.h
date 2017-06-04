#include<fcntl.h>
#include<sys/stat.h>
#include<string>
#include<cstdio>
class FileBase
{
	public:
		FileBase(const std::string file_path)
			: m_file_path(file_path)
		{}
		virtual ~FileBase()
		{}
		void show_stat();
		void show_type();
	private:
		std::string m_file_path;
};
