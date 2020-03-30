#pragma once
#include"base/gameNode.h"
#include "warriorHead.h"
#include "Kimyousin.h"
#include "monk.h"
#include "general.h"


class warriorControl : public gameNode, public singletonBase<warriorControl>
{
private:
	typedef vector<WARRIOR_INFO> V_Warrior;
	typedef vector<WARRIOR_INFO>::iterator VI_Warrior;

	V_Warrior v_warrior;
	VI_Warrior vi_warrior;

	Kimyousin* _kim;
	monk* _monk;
	general* _general;

public:
	warriorControl();
	~warriorControl();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void removeVector(int num);



	void WarriorMove(VI_Warrior warrior);
	V_Warrior get_Vwarrior() { return v_warrior; }
	VI_Warrior get_VIwarrior() { return vi_warrior; }
	Kimyousin* get_kim() { return _kim; }
	monk* get_monk() { return _monk; }
	general* get_general() { return _general; }
	void WarriorPush(WARRIOR_INFO temp)
	{
		v_warrior.push_back(temp);
	}

	void add_KimyouSin();
	void add_monk();
	void add_general();

	

	
};

#define WARRIORCONTROL warriorControl::getSingleton()
