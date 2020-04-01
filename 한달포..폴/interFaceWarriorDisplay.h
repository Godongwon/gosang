#pragma once
#include "base/gameNode.h"
struct INTERFACEWARRIORDIPLAY
{
	image* warriorDisplayimg;
	RECT warriorDisplayRC;
	progressBar* warriorproGressBar;
};
class interFaceWarriorDisplay :public gameNode
{
private:
	typedef vector<INTERFACEWARRIORDIPLAY> V_display;
	typedef vector<INTERFACEWARRIORDIPLAY>::iterator VI_display;
	V_display v_display;
	VI_display vi_display;
public:
	interFaceWarriorDisplay();
	~interFaceWarriorDisplay();


	HRESULT init();
	void release();
	void update();
	void render();
	V_display get_vDisplay() { return v_display; }
		//VI_display
	void set_displayRC(int vectorNum, RECT rc, int x, int y)
	{
		vi_display = v_display.begin() + vectorNum;
		vi_display->warriorDisplayRC = RectMake(rc.left + x, rc.top + y, vi_display->warriorDisplayimg->getFrameWidth(), vi_display->warriorDisplayimg->getFrameHeight());
	}
	void Display_clear(bool is)
	{
		if (is)
		{
			v_display.clear();
		}
	}
};

