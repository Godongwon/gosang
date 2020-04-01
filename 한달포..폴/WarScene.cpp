#include "stdafx.h"
#include "WarScene.h"
#include "IsoMap.h"



WarScene::WarScene()
{
}


WarScene::~WarScene()
{
}

HRESULT WarScene::init()
{

	IMAGEMANAGER->addFrameImage("Ground", "resource/image/맵툴/maptoolGround.bmp", 320, 320, 5, 10, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Mountin", "resource/image/맵툴/maptoolMountin.bmp", 320, 256, 5, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Water", "resource/image/맵툴/maptoolWater.bmp", 320, 192, 5, 6, true, RGB(255, 0, 255));
	warload();
	//===========================================================================================================================================================
	_monsterChild = new monster;
	_monsterChild->init();
	_monsterChild->set_monsterChildXY(0, _tileMap[49][11].centerX, _tileMap[49][11].centerY);
	_monsterChild->set_monsterChildXY(1, _tileMap[55][17].centerX, _tileMap[55][17].centerY);
	_monsterChild->set_monsterChildXY(2, _tileMap[49][3].centerX, _tileMap[49][3].centerY);
	_monsterChild->set_monsterChildXY(3, _tileMap[57][9].centerX, _tileMap[57][9].centerY);
	_monsterChild->set_monsterChildXY(4, _tileMap[64][17].centerX, _tileMap[64][17].centerY);

	PLAYER->player_setFocus(_tileMap[2][69].centerX, _tileMap[2][69].centerY);
	_battle = new battle;
	_battle->init();
	int a = _battle->get_vBattlePlayerWarrior().size();
	for (int i = 0; i < a; i++)
	{
		_battle->warrior_RCmake(i, _tileMap[2][67-i].centerX, _tileMap[2][67-i].centerY);
	}
	_isplayerWin = false;
	_isMonsterWin = false;

	IMAGEMANAGER->addImage("WarSceneWindow", "resource/image/warScene/상태창.bmp", 185*2, 45*2);
	IMAGEMANAGER->addFrameImage("WarSceneButton", "resource/image/warScene/확인버튼.bmp",300,30,3,1);

	_warSceneWindowImg = IMAGEMANAGER->findImage("WarSceneWindow");
	_buttonImg = IMAGEMANAGER->findImage("WarSceneButton");

	IMAGEMANAGER->addImage("Interface", "resource/image/warScene/interface.bmp", 360*1.5, 384 * 1.5);
	SOUNDMANAGER->addSound("warMusic", "resource/sound/Scene/warScene.wav", true, true);
	SOUNDMANAGER->addSound("playerV", "resource/sound/warScene/Win.wav",true);
	SOUNDMANAGER->addSound("playerL", "resource/sound/warScene/Lose.wav", true);
	SOUNDMANAGER->play("warMusic");

	return S_OK;
}

void WarScene::release()
{

	IMAGEMANAGER->deleteImage("Interface");
	_monsterChild->release();
	SAFE_DELETE(_monsterChild);
}

void WarScene::update()
{
	if (!_isMonsterWin && !_isplayerWin)
	{
		_isPush = false;
		_battle->update();
		_monsterChild->update();
		Collition();
		Warrior_Atk();
		Monster_Atk();
		PLAYER->update();
		if (_battle->get_vBattlePlayerWarrior().size() <= 0)
		{
			SOUNDMANAGER->pause("warMusic");
			SOUNDMANAGER->play("playerL");
			_isMonsterWin = true;
		}
		else if (_monsterChild->get_vMonsterChild().size() <= 0)
		{
			SOUNDMANAGER->pause("warMusic");
			SOUNDMANAGER->play("playerV");
			_isplayerWin = true;
			PLAYER->Plus_Playermoney(2000);
		}
	}
	else
	{
		_warSceneWindowRC = RectMakeCenter(PLAYER->Player_getFocusX(), PLAYER->Player_getFocusY(), _warSceneWindowImg->getWidth(), _warSceneWindowImg->getHeight());
		_buttonRC= RectMakeCenter(PLAYER->Player_getFocusX(), _warSceneWindowRC.bottom+100, _buttonImg->getFrameWidth(), _buttonImg->getFrameHeight());
		if (PtInRect(&_buttonRC, m_ptMouse))
		{
			_buttonImg->setFrameX(1);
			if(KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
			{
				_buttonImg->setFrameX(2);
				_isPush = true;
			}
		}
		else
		{
			_buttonImg->setFrameX(0);
		}
	}
	if (_isPush)
	{
		SOUNDMANAGER->pause("playerL");
		SOUNDMANAGER->pause("playerV");
		SCENEMANAGER->changeScene("Twon");
	}
}

void WarScene::render()
{
	Draw();
	IMAGEMANAGER->findImage("Interface")->render(CAMERAMANAGER->getCameraDC(), 1024- (360 * 1.5), 0);
	_monsterChild->HP_render();
	_battle->warScene_render();
	_monsterChild->render();
	_battle->render();
	PLAYER->render();


	
	if (_isplayerWin)
	{
		_warSceneWindowImg->render(getMemDC(), _warSceneWindowRC.left, _warSceneWindowRC.top);
		_buttonImg->frameRender(getMemDC(), _buttonRC.left, _buttonRC.top, _buttonImg->getFrameX(), 0);
		FontTextOut(getMemDC(), _warSceneWindowRC.left+35, (_warSceneWindowRC.bottom-(_warSceneWindowRC.bottom- _warSceneWindowRC.top)/2)-10,  "전투에서 승리하였습니다.", 20, "HY견고딕", RGB(255, 255, 255));
		FontTextOut(getMemDC(), _warSceneWindowRC.left+25, (_warSceneWindowRC.bottom-(_warSceneWindowRC.bottom- _warSceneWindowRC.top)/2)-30,  "승리품 : $2000", 20, "HY견고딕", RGB(255, 255, 255));
	}
	else if (_isMonsterWin)
	{
		_warSceneWindowImg->render(getMemDC(), _warSceneWindowRC.left, _warSceneWindowRC.top);
		_buttonImg->frameRender(getMemDC(), _buttonRC.left, _buttonRC.top, _buttonImg->getFrameX(), 0);
		FontTextOut(getMemDC(), _warSceneWindowRC.left + 70, (_warSceneWindowRC.bottom - (_warSceneWindowRC.bottom - _warSceneWindowRC.top) / 2) - 10, "전투에서 패배하였습니다.", 20, "HY견고딕", RGB(255, 255, 255));
	}

}

void WarScene::warload()
{
	HANDLE _map;
	DWORD read;
	//ZeroMemory(&ISOMAP->_tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y));
	_map = CreateFile("WARMAP.map", GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(_map, _tileMap, sizeof(tagTILE)*(TILE_COUNT_X* TILE_COUNT_Y), &read, NULL);
	CloseHandle(_map);
}

void WarScene::Draw()
{
	for (int i = 0; i < TILE_COUNT_X; i++)
	{
		for (int j = 0; j < TILE_COUNT_Y; j++)
		{
			if (CAMERAMANAGER->getCameraXY().x - 30 < _tileMap[i][j].p[1].x && (CAMERAMANAGER->getCameraXY().x + WINSIZEX) + 30 > _tileMap[i][j].p[3].x
				&& CAMERAMANAGER->getCameraXY().y - 30 < _tileMap[i][j].p[0].y && (CAMERAMANAGER->getCameraXY().y + WINSIZEY) + 30 > _tileMap[i][j].p[2].y)
			{

				for (int z = 0; z <= _tileMap[i][j].index; z++)
				{
					if (_tileMap[i][j].tileKind[z] != TILEKIND_NONE)
					{
						switch (_tileMap[i][j].tileNum[z])
						{
						case 0:
							IMAGEMANAGER->frameRender("Mountin", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height*z,
								_tileMap[i][j].tilePoint[z].x,
								_tileMap[i][j].tilePoint[z].y);
							break;
						case 1:
							IMAGEMANAGER->frameRender("Ground", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height*z,
								_tileMap[i][j].tilePoint[z].x,
								_tileMap[i][j].tilePoint[z].y);
							break;
						case 2:
							IMAGEMANAGER->frameRender("Water", getMemDC(),
								_tileMap[i][j].left,
								_tileMap[i][j].top - _tileMap[i][j].height * z,
								_tileMap[i][j].tilePoint[z].x,
								_tileMap[i][j].tilePoint[z].y);
							break;
						}
					}
				}

			}
		}
	}
}

void WarScene::Collition()
{
	for (int i = 0; i < _monsterChild->get_vMonsterChild().size(); i++)
	{
			for (int j = 0; j < _battle->get_vBattlePlayerWarrior().size(); j++)
			{
			RECT monster = _monsterChild->get_vMonsterChild()[i].monsterChildRC;
			RECT warrior = _battle->get_vBattlePlayerWarrior()[j].inGamewarroirRC;
			RECT temp;
			if (IntersectRect(&temp, &monster, &warrior))
			{
				if (getDistance(_battle->get_vBattlePlayerWarrior()[j].x, _battle->get_vBattlePlayerWarrior()[j].y, _monsterChild->get_vMonsterChild()[i].x, _monsterChild->get_vMonsterChild()[i].y) < 100)
				{
					_battle->set_PlayerWarriorAtkmod(j, true);
					_monsterChild->set_monsterAtkMod(i, true);
				}
			}
			else
			{
				_battle->set_PlayerWarriorAtkmod(j, false);
				_monsterChild->set_monsterAtkMod(i, false);
			}
			
			
		}
	}

	for (int j = 0; j < _battle->get_vBattlePlayerWarrior().size(); j++)
	{
		for (int i = 0; i < _monsterChild->get_vMonsterChild().size(); i++)
		{
			RECT monster = _monsterChild->get_vMonsterChild()[i].monsterChildRC;
			RECT warrior = _battle->get_vBattlePlayerWarrior()[j].inGamewarroirRC;
			RECT temp;
			if (IntersectRect(&temp, &monster, &warrior))
			{
				if (getDistance(_battle->get_vBattlePlayerWarrior()[j].x, _battle->get_vBattlePlayerWarrior()[j].y, _monsterChild->get_vMonsterChild()[i].x, _monsterChild->get_vMonsterChild()[i].y) < 100)
				{
					_battle->set_PlayerWarriorAtkmod(j, true);
					_monsterChild->set_monsterAtkMod(i, true);
				}
				else
				{
					_monsterChild->set_monsterAtkMod(i, false);
					_battle->set_PlayerWarriorAtkmod(j, false);
				}
			}

		}
	}
}

void WarScene::Warrior_Atk()
{
	/*
	아니면 용병이 공격을 하니깐
	몬스터를 먼저 돌린다.?
	*/
	for (int i = 0; i < _monsterChild->get_vMonsterChild().size(); i++)
	{
		for (int j = 0; j < _battle->get_vBattlePlayerWarrior().size(); j++)
		{
			RECT temp;
			RECT monster = _monsterChild->get_vMonsterChild()[i].monsterChildRC;
			RECT warriorAtk = _battle->get_PlayerWarriorAtkRC(j);
			bool warriorAtkmod = _battle->get_PlayerWarriorAtkMod(j);
			int currentFrame = _battle->get_framePlayerWarrior(j);
			int maxFrame = _battle->get_maxframePlayerWarrior(j);


			if (warriorAtkmod&&IntersectRect(&temp, &monster, &warriorAtk))
			{
				if (currentFrame >= maxFrame)
				{
					_monsterChild->Minus_monsterHP(i, _battle->get_vBattlePlayerWarrior()[j].atk);
					//_battle->set_PlayerWarriorAtkmod(j, false);
				}


			}
		}
	}
}

void WarScene::Monster_Atk()
{
	for (int i = 0; i < _battle->get_vBattlePlayerWarrior().size(); i++)
	{
		for (int j = 0; j < _monsterChild->get_vMonsterChild().size(); j++)
		{
			RECT temp;
			RECT warrior = _battle->get_vBattlePlayerWarrior()[i].inGamewarroirRC;
			RECT monsterAtk = _monsterChild->get_vMonsterChild()[j].atkRC;
			bool monsterAtkmod = _monsterChild->get_vMonsterChild()[j].isAtkmod;
			int currentFrame = _monsterChild->get_vMonsterChild()[j].monsterChildAni->getNowIndex();
			int maxFrame = _monsterChild->get_vMonsterChild()[j].monsterChildImg->getMaxFrameX();

			if (monsterAtkmod&&IntersectRect(&temp, &warrior, &monsterAtk))
			{
				if (currentFrame >= maxFrame)
				{
					_battle->Minus_warriorHP(i, 20);
					//_monsterChild->set_monsterAtkMod(j, false);
				}
			}			
		}
	}
}

