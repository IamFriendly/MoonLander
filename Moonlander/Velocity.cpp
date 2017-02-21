#include "Velocity.h"


//default velocity is zero
Velocity::Velocity()
{
	Dx = 0;
	Dy = 0;
}

//you can set it if you want
Velocity::Velocity(float x, float y)
{
	Dx = x;
	Dy = y;
}
//we maintain inertia
void Velocity::setDx(float x)
{
	Dx += x;
}

void Velocity::setDy(float y)
{
	Dy += y;
}