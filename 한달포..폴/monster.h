#pragma once
#include"Monstor.h"
#include"base/gameNode.h"
struct MonsterCHILD
{
	int monsterChildNum;
	Monster_Motoin monsterChileMotion;
	MONSTER_WAY monsterChildWay;
	RECT monsterChildRC;
	image* monsterChildImg;
	animation* monsterChildAni;
	
	RECT atkRC;
	int x, y;
	int Hp;
	int atk;
	float frameSpeed;
	bool isAtkmod;
};


class monster : public gameNode
{
private:
	typedef vector<MonsterCHILD> V_MONSTERCHILD;
	typedef vector<MonsterCHILD>::iterator VI_MONSTERCHILD;

	V_MONSTERCHILD v_monsterChild;
	VI_MONSTERCHILD vi_monsterChild;

protected:

	void add_monsterIdleImg();
	void add_monsterMoveImg();
	void add_monsterAtkImg();
	void add_monsterDieImg();

	void release_monsterIdleImg();
	void release_monsterMoveImg();
	void release_monsterAtkImg();
	void release_monsterDieImg();

	void select_monsterImg(VI_MONSTERCHILD monsterChild);
	void monsterChild_Move(VI_MONSTERCHILD monsterChild);
	void monsterChild_SelectMove(VI_MONSTERCHILD monsterChild);
	void monsterChild_AtkRect(VI_MONSTERCHILD monsterChild);
	void monster_Die();



public:
	monster();
	~monster();

	HRESULT init();
	void release();
	void update();
	void render();
	V_MONSTERCHILD get_vMonsterChild() {return v_monsterChild;}
	VI_MONSTERCHILD get_viMonsterChild() {return vi_monsterChild;}
	
	bool get_monsterAtkMod(int vectorNum)
	{
		vi_monsterChild = v_monsterChild.begin() + vectorNum;
		return vi_monsterChild->isAtkmod;
	}
	RECT get_MonsterAtkRect(int vectorNum)
	{
		vi_monsterChild = v_monsterChild.begin() + vectorNum;
		return vi_monsterChild->atkRC;
	}
	void set_monsterChildXY(int vectorNum, int monsterX, int monsterY);
	void set_monsterAtkMod(int vectorNum, bool mod)
	{
		vi_monsterChild = v_monsterChild.begin() + vectorNum;
		vi_monsterChild->isAtkmod = mod;
	}
	void Minus_monsterHP(int vectorNum, int ATK)
	{
		vi_monsterChild = v_monsterChild.begin() + vectorNum;
		vi_monsterChild->Hp -= ATK;
	}
	void HP_render();
};

