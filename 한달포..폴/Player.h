#pragma once
#include "base/gameNode.h"
#include"warriorHead.h"
enum Player_Way
{
	PlayerWay_bottom,
	PlayerWay_leftbottom,
	PlayerWay_left,
	PlayerWay_lefttop,
	PlayerWay_top,
	PlayerWay_right
};
enum Player_Motion
{
	Player_Idle,
	Player_Move
};
struct playerInfo
{
	Player_Way playerWay;
	Player_Motion playerMotion;
	RECT playerimgRC;
	RECT playerRC;
	image* playerimg;
	animation* playerAni;
	float frameSpeed;
	int money;
	POINT playerPoint;
};
class Player:public gameNode, public singletonBase<Player>
{
private:
	playerInfo _playerInfo;

	typedef vector<WARRIOR_INFO> V_PLAYERWRRIOR;
	typedef vector<WARRIOR_INFO>::iterator VI_PLAYERWRRIOR;
	
	V_PLAYERWRRIOR	v_playerWarrior;
	VI_PLAYERWRRIOR vi_playerWarrior;

	int _PlayerKim;
	int _PlayerMonk;
	int _PlayerGen;


	//플레이어 이미지 추가
	void playerIdleImgAdd();
	void playerMoveImgAdd();
	//플레이어 이미지 삭제
	void playerIdleImgRelese();
	void playerMoveImgRelese();
	//플레이어 이미지 선택
	void PlayerImgSelect();
	//카메라움직임
	void CameraMove();
	//플레이어 포인트
	void PlayerPointMake();
	
	//플레이어 중점
	int _focusPlayerimgX, _focusPlayerimgY;
	int _focusPlayerX, _focusPlayerY;

	bool _isDebug;
public:
	Player();
	~Player();


	HRESULT init();
	void release();
	void update();
	void render();

	int Player_getFocusX() {return _focusPlayerX;}
	int Player_getFocusY() {return _focusPlayerY;}
	void player_setFocus(int x,int y);
	int Player_Money() { return _playerInfo.money; }
	void Plus_Playermoney(int money) 
	{
		_playerInfo.money = _playerInfo.money + money;
	}
	void Minus_Playermoney(int money)
	{
		_playerInfo.money = _playerInfo.money - money;
	}
	RECT player_getplayerRECT() {return _playerInfo.playerRC;}

	V_PLAYERWRRIOR get_vPlayerWarrior() {  return v_playerWarrior;	}

	VI_PLAYERWRRIOR get_viPlayerWarrior() { return vi_playerWarrior; }

	void removePlayer(int i);
	void get_vPlayerWarriorPush(WARRIOR_INFO temp) { v_playerWarrior.push_back(temp); }

	int get_Playerkim() { return _PlayerKim; }
	int get_PlayerMonk() { return _PlayerMonk; }
	int get_PlayerGen() { return _PlayerGen; }

	//bool : ture +  false -
	void set_PlayerWarrior(WARRIOR_NUM warrior, int num, bool plus);
	

};

