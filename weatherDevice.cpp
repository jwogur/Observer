#include "weatherDevice.h"

weatherDevice::weatherDevice(std::weak_ptr<Subject> sb)
	:Observer{sb}
{
	sb.lock()->registerOb(std::weak_ptr<Observer>{*this});
}
