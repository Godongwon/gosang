#pragma once
#include "stdafx.h"


enum WARRIOR_WAY
{
	WARRIORWAY_LEFT,
	WARRIORWAY_RIGHT,
	WARRIORWAY_TOP,
	WARRIORWAY_BOTTOM
};
enum WARRIOR_MOTION
{
	WARRIORMONSION_IDLE,
	WARRIORMONSION_MOVE,
	WARRIORMONSION_ATK,
	WARRIORMONSION_DIE
};
enum WARRIOR_NUM
{
	WARRIOR_KIM,
	WARRIOR_MONK,
	WARRIOR_GENERAL
	
};
struct ITEM
{
	image* itemImg;
	RECT itemRC;
	int effect;
};
struct WARRIOR_INFO
{
	WARRIOR_NUM warriornum;			//용병종류
	WARRIOR_MOTION warriorMonsion;	//용병모션
	WARRIOR_WAY warriorWay;		//용병방향
	////어깨만
	//image* warriorImg;
	//RECT warriorRC;
	//ingame
	image* inGamewarriorImg;
	RECT inGamewarroirRC;
	animation* inGamewarriorAni;
	ITEM warriorItem[2];

	//중점
	int x;
	int y;
	//충돌
	RECT AtkRC;

	int HP;
	int atk;
	int def;
	int price;

	float frameSpeed;
	
	bool isSelect;
	bool isAtkmod;

	

};
