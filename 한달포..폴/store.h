#pragma once
#include "base/gameNode.h"
#include"itemHead.h"

struct STORE_INFO
{
	image* storeImg;
	RECT storeRC;

	image* InstoreImg;
	RECT InstoreRC;
};
struct STORE_BUTTON
{
	image* storeButtonImg;
	RECT storeButtonRC;
	bool isPush;
};
class store : public gameNode
{
private:
	
	STORE_INFO storeInfo;

	STORE_BUTTON _storeButton[5];


	typedef vector<STORE_ITEM> V_ITEM;
	typedef vector<STORE_ITEM>::iterator VI_ITEM;

	V_ITEM v_item;
	VI_ITEM vi_item;

	bool isOpenStore;
	bool isNotSelect;
	int NotSelectCount;

protected:

	void add_itemImg();
	void release_itemImg();
	void add_vItem(string name, STORE_KIND kind, int effect,int itemnum,int price);
	void add_Buttoninit();
	void Button_Push(int i);
	void Button_PushRender(VI_ITEM item);
	void Not_select(bool is);
public:
	store();
	~store();

	HRESULT init();
	void release();
	void update();
	void render();


	bool get_isOpenStore() {return isOpenStore;}
	void set_storeXY(int x, int y);
	void select_item(VI_ITEM item);
	void buy_item();
	void pay_item();
	
};

