#pragma once
#include "stdafx.h"

//크기
#define TILE_WIDTH 64
#define TILE_HEIGHT 32

#define RADIUS_WIDTH (TILE_WIDTH/2)
#define RADIUS_HEIGHT (TILE_HEIGHT/2)

//초기좌표
#define INIT_X 3000
#define INIT_Y 550

//타일 갯수
#define TILE_COUNT_X 70
#define TILE_COUNT_Y 70

#define TILE_SIZE_X 5
#define TILE_SIZE_Y 10


#define TILE_MAX 3

enum TILEKIND
{
	TILEKIND_OBJECT = 0,
	TILEKIND_NOMAL,
	TILEKIND_SPEEDDOWN,
	TILEKIND_TREE,
	TILEKIND_NONE
};


struct tagTILE
{
	//아이소 그린것
	int left, top;
	int index;
	int centerX;
	int centerY;
	POINT p[5];
	int tileNum[TILE_MAX];
	TILEKIND tileKind[TILE_MAX];
	POINT tilePoint[TILE_MAX];
	int height;

	COLORREF color;
	bool walkable;  //지나갈수 있는지 여부
	bool liston;	//openlist에 추가
	int i, j;
	int F, G, H;
	tagTILE* parent; //tagtile 주소
	
};
