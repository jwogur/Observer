#include "ObserverInterface.h"

void Subject::registerOb(std::weak_ptr<Observer> o)
{
	std::cout << "������ ��� �Ϸ� !" << std::endl;
	observers.emplace_front(o);
}

void Subject::removeOb(std::weak_ptr<Observer> o)
{
	std::cout << "������ ���� �Ϸ� !" << std::endl;
	observers.remove(o);
}

