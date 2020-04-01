#pragma once
#include"base/gameNode.h"
#include"interFaceWarriorDisplay.h"
class interFace : public gameNode
{
private:
	image* _interfaceimg;
	RECT _interfaceRC;
	interFaceWarriorDisplay* _warriorDisplay;
protected:
	void fontout();
public:
	interFace();
	~interFace();

	HRESULT init();
	void release();
	void update();
	void render(/*HDC hdc*/);
	interFaceWarriorDisplay* get_warriorDisplay(){return _warriorDisplay;}

	
};

