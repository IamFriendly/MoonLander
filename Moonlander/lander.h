#ifndef LANDER_H
#define LANDER_H
#include "point.h"
#include "Velocity.h"

class Lander
{
	//Where the lander is
	Point point;
	//amount of fuel
	int fuel;
	//direction lander is traveling
	Velocity velocity;
	//are we dead
	bool alive;
	//did we win
	bool landed;
public:
	Lander();
	Point getPoint() const {return point;};
	void setPoint(Point pointA);
	void draw();
	int getFuel() { return fuel; };
	void setFuel(int FuelA);
	Velocity getVelocity() const { return velocity; };
	bool isLanded() { return landed; };
	void setAlive(bool alive);
	bool isAlive() { return alive; };
	void setLanded(bool landed);
	bool canThrust();
	void applyGravity(float gravity);
	void advance();
	void applyThrustBottom();
	void applyThrustLeft();
	void applyThrustRight();
};
#endif

