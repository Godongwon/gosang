#pragma once
#include "Monstor.h"
#include"base/gameNode.h"
struct Monster
{
	int monsterNum;
	int x, y;
	Monster_Motoin monsterMotion;
	MONSTER_WAY monsterWay;
	RECT monsterRC;
	image* monsterImg;
	animation* monsterAni;
	image* countImg;
	RECT collisionRC;
	int colisionCount;
	int MoveNum;
	int MotionNum;
	int MoveCount;
	float frameSpeed;
	bool isCollision;
	bool isMove;
	bool isturnMonster;
};
class townMonster : public gameNode
{
private:
	typedef vector<Monster> V_Monster;
	typedef vector<Monster>::iterator VI_Monster;

	V_Monster v_monster;
	VI_Monster vi_monster;
	
	int imgY;

	bool _isSceneChange;
	bool _isDebug;

protected:

	void add_MonsterIdleImg();
	void add_MonsterMoveImg();

	void release_MonsterIdleImg();
	void release_MonsterMoveImg();

	void select_MonsterImg(VI_Monster monster);
	void townMonster_move();
	void townMonster_moveRC();
	void turnMonster();


public:
	townMonster();
	~townMonster();

	HRESULT init();
	void release();
	void update();
	void render();
	
	V_Monster get_vMonster() { return v_monster; }
	VI_Monster get_viMonster() { return vi_monster; }
	int get_viMonsterX(int vecternum)
	{
		vi_monster= v_monster.begin() + vecternum;
		return vi_monster->x;
	}

	int get_viMonsterY(int vecternum)
	{
		vi_monster = v_monster.begin() + vecternum;
		return vi_monster->y;
	}
	POINT get_viMonsterXY(int vecternum)
	{
		vi_monster = v_monster.begin() + vecternum;;
		return PointMake(vi_monster->x, vi_monster->y);
	}
	void set_Monsterturn(int vecternum, bool _bool)
	{
		vi_monster = v_monster.begin() + vecternum;
		vi_monster->isturnMonster = _bool;
	}
	void set_TwonMonsterXY(int vecterNum, int monsterX, int monsterY);
	MONSTER_WAY get_MonsterWay(int vecterNum)
	{
		vi_monster = v_monster.begin() + vecterNum;
		return vi_monster->monsterWay;
	}
	bool get_isSceneChange() {return _isSceneChange;}
	void set_MonsterWay(int vecterNum, MONSTER_WAY way)
	{
		vi_monster = v_monster.begin() + vecterNum;
		vi_monster->monsterWay = way;
	}
	void set_SceneChange(bool b)
	{
		_isSceneChange = b;
	}
	void countRender();
};

