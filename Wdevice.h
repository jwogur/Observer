#pragma once
#include "ObserveInter.h"
class Wdevice:private Observer,public Display {
private:
	WData wd;
	void Update(const WData& w)override {
		wd = w;
	}
public:
	Wdevice(Subject* sb) :Observer{ sb } {
		sb->registOb(this);
	}
	void show()const {
		Display{}(wd);
	}
	~Wdevice() {
		sb->removeOb(this);
	}
	void pullUpdate()override {
		WeatherData* temp{ static_cast<WeatherData*>(sb) };
		temp->setWData();
		wd = temp->getWData();
	}
};
