#include "WeatherData.h"

void WeatherData::setData()
{
	std::default_random_engine rng;
	std::uniform_real_distribution<> uid{ 1,30 };
	wd.temper = uid(rng);
	wd.humidity = uid(rng);
	wd.press = uid(rng);
}

void WeatherData::notifyOb()const
{
	for (auto it{ observers.begin() }; it != observers.end(); ++it)
		(*it).lock()->Update(wd);
}
