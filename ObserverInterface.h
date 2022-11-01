#pragma once
#include <iostream>
#include <memory>
#include <forward_list>
#include <random>
struct WData {
	float temper;
	float humidity;
	float press;
};
class Subject;
class Observer {
protected:
	std::weak_ptr<Subject> sb;
public:
	Observer(std::weak_ptr<Subject>& sb):sb{sb}{}
	virtual void Update(const WData&){}
};
class Subject {
protected:
	std::forward_list<std::weak_ptr<Observer>> observers;
public:
	void registerOb(std::weak_ptr<Observer> o);
	void removeOb(std::weak_ptr<Observer> o);
	virtual void notifyOb()const =0;
};

class Display {
public:
	void operator()(WData& wd)
	{
		std::cout << "���� �µ� - " << wd.temper << std::endl;
		std::cout << "���� ���� - " << wd.humidity << std::endl;
		std::cout << "���� ��� - " << wd.press << std::endl;
	}
};
