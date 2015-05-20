#pragma once

#include <cocos2d.h>
#include "Entity.h"

class Ladder : public Entity
{
	friend class Chunk;

private:

	cocos2d::Sprite* _sprite;
	bool ifActive = false;
	Ladder(Chunk* parent, const cocos2d::Vec2& location, int height);

public:

	bool update(class Level* level, float dt) override;

	cocos2d::Node* getNode() const
	{
		return _sprite;
	}
};
