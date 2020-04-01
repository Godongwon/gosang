#include "stdafx.h"
#include "interFaceWarriorDisplay.h"


interFaceWarriorDisplay::interFaceWarriorDisplay()
{
}


interFaceWarriorDisplay::~interFaceWarriorDisplay()
{
}

HRESULT interFaceWarriorDisplay::init()
{
	return S_OK;
}

void interFaceWarriorDisplay::release()
{

}

void interFaceWarriorDisplay::update()
{
	
	if (PLAYER->get_vPlayerWarrior().size() != 0&& v_display.size()==0)
	{
		for (int i = 0; i < PLAYER->get_vPlayerWarrior().size(); i++)
		{
			INTERFACEWARRIORDIPLAY _display;
			ZeroMemory(&_display, sizeof(INTERFACEWARRIORDIPLAY));
			_display.warriorDisplayimg = new image;
			_display.warriorDisplayimg = PLAYER->get_vPlayerWarrior()[i].warriorPotraitimg;
			_display.warriorDisplayRC = PLAYER->get_vPlayerWarrior()[i].warriorPotraitRC;
			_display.warriorproGressBar=new progressBar;
			_display.warriorproGressBar = PLAYER->get_vPlayerWarrior()[i].warriorProgressBar;
			v_display.push_back(_display);
		}
	}
}

void interFaceWarriorDisplay::render()
{
	if (v_display.size() != 0)
	{
		for (vi_display = v_display.begin(); vi_display != v_display.end(); ++vi_display)
		{
			vi_display->warriorDisplayimg->frameRender(getMemDC(), vi_display->warriorDisplayRC.left, vi_display->warriorDisplayRC.top,1,0);
			vi_display->warriorproGressBar->set_RECT(vi_display->warriorDisplayRC.left, vi_display->warriorDisplayRC.top);
			vi_display->warriorproGressBar->render();
		}
	}
}
