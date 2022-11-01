#pragma once
#include "ObserveInter.h"
#include <random>
class WeatherData :public Subject {
private:
	WData wd;
	void notifyOb()const override
	{
		auto it{ obs.begin() };
		while (it!= obs.end()) {
			(*it)->Update(wd);
			++it;
		}
	}
public:
	void setWData()
	{
		std::mt19937 rng{ std::random_device{}() };
		std::uniform_real_distribution<> urd{ 1,20 };
		wd.temper = urd(rng);
		wd.humidity = urd(rng);
		wd.press = urd(rng);
		notifyOb();
	}
	WData getWData()const { return wd; }
};

