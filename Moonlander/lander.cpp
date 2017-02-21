#include "lander.h"
#include "uiDraw.h"
#include "windows.h"
//default lander
Lander::Lander()
{
	Point points(150,180);
	setPoint(points);
	velocity;
	fuel = 500;
	alive = true;
	landed = false;
}
//where is the lander
void Lander::setPoint(Point pointA)
{
	point = pointA;
}
//draw the lander where it is
void Lander::draw()
{
	drawLander(getPoint());
}

void Lander::setFuel(int fuelA)
{
	fuel = fuelA;
}

void Lander::setAlive(bool aliveA)
{
	alive = aliveA;
}

void Lander::setLanded(bool landeda)
{
	landed = landeda;
}
//if we have fuel, are alive, and haven't landed yet, we can thrust
bool Lander::canThrust()
{
	if (getFuel() > 0 && isAlive() && !isLanded())
		return true;
	else
		return false;
}
//gravity pulls down
void Lander::applyGravity(float gravity)
{
	velocity.setDy(-gravity);
}
//move the lander according to its velocity
void Lander::advance()
{
	if (isAlive() && !isLanded())
	{
		point.setY(point.getY() + velocity.getDy());
		point.setX(point.getX() + velocity.getDx());
	}
}
//.3 velocity for 3 units of fuel
void Lander::applyThrustBottom()
{
	if (canThrust())
	{
		velocity.setDy(.3);
		setFuel(getFuel() - 3);
	}
}
//.1 velocity for 1
void Lander::applyThrustLeft()
{
	if (canThrust())
	{
		velocity.setDx(.1);
		setFuel(getFuel() - 1);
	}
}

void Lander::applyThrustRight()
{
	if (canThrust())
	{
		velocity.setDx(-.1);
		setFuel(getFuel() - 1);
	}
}

