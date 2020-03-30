#pragma once
#include "base/gameNode.h"
struct BUTTON
{
	image* buttonImg;
	RECT buttonRC;
	bool isPush;
};

class startScene : public gameNode
{
private:
	image* _backGroundback;
	image* _title;
	image* _backGroundfront;
	
	BUTTON button[3];
protected:

	void add_image();
	void release_image();

public:
	startScene();
	~startScene();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

