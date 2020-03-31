#pragma once
#include"stdafx.h"
enum STORE_KIND
{
	STOREKIND_WEAPON,
	STOREKIND_POTION,
	STOREKIND_ARMER
};
struct STORE_ITEM
{
	int itemnum;
	//string name;
	STORE_KIND kind;
	image* Img;
	RECT rc;
	int effect;
	image* itemDisplayImg;
	RECT itemDisplayRC;
	bool isSelect;
	int price;
};