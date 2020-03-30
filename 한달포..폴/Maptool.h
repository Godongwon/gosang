#pragma once
#include "base/gameNode.h"
#include "SubIsoMap.h"
#include "IsoMap.h"

#define SUBWINOPEN 1

class Maptool : public gameNode
{
private :
	IsoMap* map = new IsoMap;
	SubIsoMap* sub = new SubIsoMap;

public:
	Maptool();
	~Maptool();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(/*HDC hdc*/);
};

