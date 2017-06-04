#include<sys/stat.h>
#include<string>
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

	private:
	std::string m_path_name;
	int m_mode;
};
