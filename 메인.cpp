#include "WeatherData.h"
#include "Wdevice.h"
int main()
{
	auto WD{ std::make_shared<WeatherData>() };
	auto wd{ std::make_shared<Wdevice>(WD.get()) };
	WD->setWData();
	wd->show();
	WD->setWData();
	wd->show();
	// 生嬢嬢
	// しし
	// しし/
	//しし
	//
}