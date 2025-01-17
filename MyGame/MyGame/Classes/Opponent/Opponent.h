#pragma once

#include <string> 
#include "cocos2d.h"

using namespace cocos2d;

class Opponent
{
public:

	enum State
	{
		Undefined = 0,
		PatrollingA,
		PatrollingB,
		Shooting,
		SearchForPlayer,

		MAX
	};

protected:
	int _hp;
	std::string _name;
	Node* _node;
	PhysicsBody* _body;
	State _state;
	Vec2 _navPoints[2];

public:

	Opponent(std::string name);
	~Opponent();

	Node* getSprite() const
	{
		return _node;
	}

	State GetState() const
	{
		return _state;
	}

	void SetNavPoints(Vec2 navPoints[2])
	{
		memcpy(_navPoints, navPoints, 2 * sizeof(Vec2));
	}

	void SetNavPoints(Vec2 p1, Vec2 p2)
	{
		_navPoints[0] = p1;
		_navPoints[1] = p2;
	}

	float getHP() const
	{
		return _hp;
	}

	Rect getBox() const
	{
		return _node ? _node->getBoundingBox() : Rect();
	}

	virtual void update(float dt);
	virtual void onDamage(float damage)
	{
		_hp -= damage;
	}

	// Get opponent movement speed
	virtual float getSpeed() const
	{
		return 100.0f;
	}

protected:

	float calMoveDuration()
	{
		return 4;
		return _navPoints[0].distance(_navPoints[1]) / getSpeed();
	}
};