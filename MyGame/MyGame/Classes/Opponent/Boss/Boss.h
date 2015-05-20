#pragma once

#include <string> 
#include "cocos2d.h"
#include "Opponent/Opponent.h"

using namespace cocos2d;

class Boss : public Opponent
{
private:

	float _timeAcc;
	Vec2 _p1, _p2;

public:

	Boss(Chunk* parent, Vec2 p1, Vec2 p2);
	~Boss();

	bool update(Level* level, float dt) override;

public:

	float calMoveDuration()
	{
		return _p1.distance(_p2) / getSpeed();
	}
};