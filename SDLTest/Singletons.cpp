#include "Singletons.h"
Video* VideoManager;

void instanceSingletons()
{
	VideoManager = Video::getInstance();
}

void destroySingletons()
{
	VideoManager->~Video();
}
