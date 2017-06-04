#include<ctime>

class Random
{
	public:
	static int GetRandomNumber()
	{
		srand(static_cast<int>(time(0)));
		return rand();
	}
};
