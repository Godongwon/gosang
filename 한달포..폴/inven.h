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
	bool _ismove;

protected:

	void add_image();
	

public:
	inven();
	~inven();

	HRESULT init();
	void release();
	void update();
	void render();

	V_INVENITEM get_vitem() {return v_item;}

	void set_itemRC(int i,int x,int y)
	{
		_ismove = true;
		vi_item = v_item.begin() + i;
		vi_item->rc = RectMakeCenter(x, y, 65, 66);
	}
	void set_isMove(bool is) { _ismove = is; }
	void item_render();
	void set_invenRC(int x, int y);
	void inven_push(STORE_ITEM item)
	{
		v_item.push_back(item);
	}
	void remove_vitem(int i)
	{
		v_item.erase(v_item.begin() + i);
	}
	RECT get_invenRC() {return invenRC;}
};

#define Inven inven::getSingleton()
