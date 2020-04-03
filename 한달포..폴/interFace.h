#pragma once
#include"base/gameNode.h"
#include"interFaceWarriorDisplay.h"
struct OPTIONBUTTON
{
	image* optionButtonimg;
	RECT optionButtonRC;
	bool isPush;
};
class interFace : public gameNode
{
private:
	image* _interfaceimg;
	RECT _interfaceRC;

	image* optionImg;
	RECT optionRC;
	bool isInoption;
	image* optionWinddowimg;
	RECT optionWinddowRC;

	OPTIONBUTTON _optionButton[2];

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
	bool get_isInoption() {	return isInoption;}
	void set_isInoption(bool is) { isInoption = is; }
	void optionWindow();
	void optionWindow_render();
	
};

