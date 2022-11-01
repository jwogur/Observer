#include "ObserverInterface.h"

void Subject::registerOb(std::weak_ptr<Observer> o)
{
	std::cout << "옵저버 등록 완료 !" << std::endl;
	observers.emplace_front(o);
}

void Subject::removeOb(std::weak_ptr<Observer> o)
{
	std::cout << "옵저버 제거 완료 !" << std::endl;
	observers.remove(o);
}

