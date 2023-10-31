#pragma once
#include "BlockBase.h"
class NormalBlock : public BlockBase
{
public:
	NormalBlock();
	virtual ~NormalBlock();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Draw() const override;
};

