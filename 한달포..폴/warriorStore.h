#pragma once
#include "base/gameNode.h"
#include "warriorHead.h"
struct WARRIORSTORE_BUTTON
{
	image* Buttonimg;
	RECT ButtonRC;
	bool isPush;
};
struct warriorDisplay
{
	image* warriorDisplayimg;
	RECT  warriorDisplayRC;
};
struct WARRIORPOTRAIT
{
	image* warriorPotraitimg;
	RECT  warriorPotraitRC;
	bool isClick;
};
struct PlayerWarriorDisplay
{
	image* PlayerwarriorDisplayimg;
	RECT  PlayerwarriorDisplayRC;
};
struct WARRIORACCOUNT
{
	image* _warriorAccountImg;
	RECT _warriorAccountRC;
};
class warriorStore :public gameNode
{
private:
	
	image* _warriorStoreImg;
	RECT _warriorStoreRC;

	image* _InwarriorStoreImg;
	RECT _InwarriorStoreRC;

	WARRIORACCOUNT warriorAccount[4];

	warriorDisplay _warriorDisplay[3];
	WARRIORPOTRAIT _warriorPotrait[3];

	PlayerWarriorDisplay _playerWarriorDisplay[3];
	WARRIORPOTRAIT _playerWarriorPotrait[3];

	POINT _warriorStoreFocus;

	WARRIORSTORE_BUTTON _warriorButton[3];

	int _kim;
	int _monk;
	int _gen;

	bool _isOpenWarriorStore;

	
	bool _isSoldKim;//김유신 품절
	bool _isSoldMonk;//스님 품절
	bool _isSoldGen;//장군 품절

	//플레이어가 가지고 있는지 확인
	bool _isPlayerKim;	
	bool _isPlayerMonk;
	bool _isPlayergen;

protected:
	void add_Img();
	void ButtonInit();
	void ButtonRender();
	void Button_isPush();
	void warrior_Display();
	void warrior_DisplayRender();
	void warrior_portrait();
	void Sold_outWarrior();
	void Player_isWarrior();
	void Player_warrior();
	void Player_warriorRender();
	void WarriorAccountinit();
	void WarriorAccountRender();
	void Player_Money();
public:
	warriorStore();
	~warriorStore();

	HRESULT init();
	void release();
	void update();
	void render();

	void set_warriorStore(int x, int y);
	bool get_isOpenWarriorStore() {	return _isOpenWarriorStore;}

	//용병추가
	void add_warrior();
	//용병구입
	void buy_warrior();
	//용병판매
	void pay_warrior();

	
};

