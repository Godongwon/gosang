#pragma once
#include "base/gameNode.h"
#include "itemHead.h"
class inven :public gameNode,public singletonBase<inven>
{
private:

	typedef vector<STORE_ITEM> V_INVENITEM;
	typedef vector<STORE_ITEM>::iterator VI_INVENITEM;

	V_INVENITEM v_item;
	VI_INVENITEM vi_item;


	image* invenWindowimg;
	RECT invenRC;

protected:

	void add_image();
	

public:
	inven();
	~inven();

	HRESULT init();
	void release();
	void update();
	void render();

	void item_render();
	void set_invenRC(int x, int y);
	void inven_push(STORE_ITEM item)
	{
		v_item.push_back(item);
	}

};

#define Inven inven::getSingleton()
