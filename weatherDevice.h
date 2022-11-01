#pragma once
#include "ObserverInterface.h"
class weatherDevice:public Observer,public Display{
private:
	WData wd;
public:
	weatherDevice(std::weak_ptr<Subject> sb);
	void show()const
	{
		Display(wd);
	}
};


