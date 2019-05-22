#include <iostream>
#include <string>
using namespace std;

//Credit : Youtube-CPPNUTS

class GameSetting
{
	static GameSetting * instance;
	int brightness;
	int height;
	int width;
	GameSetting() : brightness(100), height(1000), width(1000)
	{
		cout << "constructor called\n";
	}


	/*GameSetting(const GameSetting&);
	GameSetting& operator= (const GameSetting&);*/
public:
	static GameSetting* getInstance() 
	{
		if (instance == nullptr)
		{
			instance = new GameSetting();
		}
		return instance;
	}


	/*static GameSetting& getInstance()
	{
		static GameSetting GS;
		return GS;
	}*/

	/*GameSetting(const GameSetting&) = delete;
	GameSetting& operator= (const GameSetting&) = delete;*/

	void setWidth(int w) { width = w; }
	void setHeight(int h) { height = h; }
	void setBrightness(int b) { brightness = b; }

	int getWight() { return width; }
	int getHeight() { return height; }
	int getBrightness() { return brightness; }

	void DisplaySettings()
	{
		cout << "brightness: " << brightness << endl
			<< "height: " << height << endl
			<< "width: " << width << endl << endl;

	}
};

// Allocating and initializing GlobalClass's
// static data member.  The pointer is being
// allocated - not the object inself.
GameSetting* GameSetting::instance = nullptr;



//void foo()
//{
//  //Initialization on first use
//	GameSetting* settings = GameSetting::getInstance();
//	settings->DisplaySettings();
//	//GameSetting::getInstance().DisplaySettings();
//}

int main()
{

	/*GameSetting * settings = GameSetting::getInstance();
	settings->DisplaySettings();*/

	//GameSetting::getInstance()->DisplaySettings();




	//settings->setBrightness(50);
	//GameSetting::getInstance()->setBrightness(50);
	//foo();


	system("pause");
	return 0;
}


