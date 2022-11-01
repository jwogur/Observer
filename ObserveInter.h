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
		std::cout << "������ ��� �Ϸ�" << std::endl;
		obs.emplace_front(o);
	}
	void removeOb(Observer* o) {
		std::cout << "������ ���� �Ϸ�" << std::endl;
		obs.remove(o);
	}
	virtual void notifyOb()const=0;
};
class Display {
public:
	void operator()(const WData& wd) {
		std::cout << "���� �µ� - " << wd.temper << std::endl;
		std::cout << "���� ���� - " << wd.humidity << std::endl;
		std::cout << "���� ��� - " << wd.press << std::endl;
	}
};

