#pragma once
#include "base/gameNode.h"
#include "warriorHead.h"

class battle : public gameNode
{
private:

	typedef vector<WARRIOR_INFO> V_battlePlayerWarrior;
	typedef vector<WARRIOR_INFO>::iterator VI_battlePlayerWarrior;

	V_battlePlayerWarrior v_battlePlayerWarrior;
	VI_battlePlayerWarrior vi_battlePlayerWarrior;

	bool _isAtkMod;
protected:
	int _atkMouseX;
	int _atkMouseY;

	void copy_playerVector();
	void select_warior(VI_battlePlayerWarrior warrior);
	void warrior_Move(VI_battlePlayerWarrior warrior);
	void Atk_MouseClick();
	void Atk_Rectmake(VI_battlePlayerWarrior warrior);
	void warrior_die();

public:

	battle();
	~battle();

	HRESULT init();
	void release();
	void update();
	void render();

	V_battlePlayerWarrior get_vBattlePlayerWarrior() {return v_battlePlayerWarrior;}
	VI_battlePlayerWarrior get_viBattlePlayerWarrior() {return vi_battlePlayerWarrior;}
	void warrior_RCmake(int num,int x,int y);
	// Minus_warriorHP(벡터 번호 , 몬스터 공격력);
	void Minus_warriorHP(int num,int monsterAtk);

	void set_PlayerWarriorAtkmod(int num,bool mod)
	{
		vi_battlePlayerWarrior = v_battlePlayerWarrior.begin()+num;
		vi_battlePlayerWarrior->isAtkmod = mod;
	}
	bool get_PlayerWarriorAtkMod(int num)
	{
		vi_battlePlayerWarrior = v_battlePlayerWarrior.begin() + num;
		return vi_battlePlayerWarrior->isAtkmod;
	}
	RECT get_PlayerWarriorAtkRC(int num)
	{
		vi_battlePlayerWarrior = v_battlePlayerWarrior.begin() + num;
		return vi_battlePlayerWarrior->AtkRC;
	}
	DWORD get_framePlayerWarrior(int num)
	{
		vi_battlePlayerWarrior = v_battlePlayerWarrior.begin() + num;
		return vi_battlePlayerWarrior->inGamewarriorAni->getNowIndex();
	}
	int get_maxframePlayerWarrior(int num)
	{
		vi_battlePlayerWarrior = v_battlePlayerWarrior.begin() + num;
		return vi_battlePlayerWarrior->inGamewarriorImg->getMaxFrameX();
	}
	void warScene_render();
};

