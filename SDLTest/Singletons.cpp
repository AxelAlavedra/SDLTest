#include "Singletons.h"
Video* sVideoManager;

void instanceSingletons()
{
	sVideoManager = Video::getInstance();
}

void destroySingletons()
{
	delete sVideoManager;
}
