#pragma once
#include <iostream>
#include <memory>
#include <forward_list>
struct WData {
	float temper;
	float humidity;
	float press;
};
class Subject;
class Observer {
	friend class WeatherData;
protected:
	Subject* sb;
	Observer(Subject*  sb):sb{sb}{}
	virtual void Update(const WData&) = 0;
	virtual void pullUpdate() = 0;
};
class Subject {
	friend class Wdevice;
protected:
	std::forward_list< Observer*>obs;
	void registOb(Observer* o) {
		std::cout << "옵저버 등록 완료" << std::endl;
		obs.emplace_front(o);
	}
	void removeOb(Observer* o) {
		std::cout << "옵저버 삭제 완료" << std::endl;
		obs.remove(o);
	}
	virtual void notifyOb()const=0;
};
class Display {
public:
	void operator()(const WData& wd) {
		std::cout << "현재 온도 - " << wd.temper << std::endl;
		std::cout << "현재 습도 - " << wd.humidity << std::endl;
		std::cout << "현재 기압 - " << wd.press << std::endl;
	}
};

