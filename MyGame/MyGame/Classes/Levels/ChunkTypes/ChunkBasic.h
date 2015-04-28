
#pragma once

#include <vector>
#include <cocos2d.h>
#include <string.h>
#include "../Chunk.h"

class ChunkBasic : public Chunk
{
public:

	~ChunkBasic()
	{
	}

	bool init() override;
	CHUNKS_CREATE(ChunkBasic);

	inline Type getType() override
	{
		return Type::Basic;
	}

	void Generate() override;
};
