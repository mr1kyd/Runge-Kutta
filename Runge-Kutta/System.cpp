#include "System.h"

System createSystem() {
	System result;
	result.x = createEquation();
	result.y = createEquation();
	result.z = createEquation();
	return result;
}