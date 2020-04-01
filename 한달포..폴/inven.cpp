#include "stdafx.h"
#include "inven.h"


void inven::add_image()
{
	IMAGEMANAGER->addImage("invenWindow", "resource/image/ÀÎº¥/inven.bmp", 348, 418);
}
//------------------------------------------------------------------------------
inven::inven(){}
inven::~inven(){}
//------------------------------------------------------------------------------

HRESULT inven::init()
{
	add_image();
	invenWindowimg = IMAGEMANAGER->findImage("invenWindow");
	_ismove = false;
	return S_OK;
}

void inven::release()
{

}

void inven::update()
{
	if (v_item.size() != 0)
	{
		for (int i = 0; i < v_item.size(); i++)
		{
			if (!_ismove)
			{
				if (i == 0)
				{
					vi_item = v_item.begin();
					vi_item->rc = RectMake(invenRC.left + 12, invenRC.top + 31, 65, 66);

				}
				else
				{
					vi_item = v_item.begin() + i;
					if (i % 5 != 0)
					{
						vi_item->rc = RectMake(v_item[i - 1].rc.right + 2, v_item[i - 1].rc.top, 65, 66);
					}
					else
					{
						vi_item->rc = RectMake(v_item[i - 5].rc.left, v_item[i - 5].rc.bottom + 2, 65, 66);
					}
				}
			}
		}
	}
}

void inven::render()
{
	invenWindowimg->render(getMemDC(), invenRC.left, invenRC.top);
	char str[128];
	sprintf_s(str, "%d", PLAYER->Player_Money());
	FontTextOut(getMemDC(), invenRC.left + 154, invenRC.top + 367, str, 18,"HY°ß°íµñ",RGB(254, 254, 254));
	

}

void inven::item_render()
{
	if (v_item.size()!=0)
	{
		vi_item = v_item.begin();
		for (; vi_item != v_item.end(); ++vi_item)
		{
			//Rectangle(getMemDC(), vi_item->rc.left, vi_item->rc.top, vi_item->rc.right, vi_item->rc.bottom);
			vi_item->Img->render(getMemDC(), vi_item->rc.left-15, vi_item->rc.top);
			
		}
	}
}

void inven::set_invenRC(int x, int y)
{
	invenRC = RectMakeCenter(x, y, invenWindowimg->getWidth(), invenWindowimg->getHeight());
	
}


