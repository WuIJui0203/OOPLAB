#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "mygame.h"
#include <map>
#include <array>
#include <string>
#include <iostream>
#include <random>       
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	/////////////////////////////////////////////////////////////////////////////
	CGameStateInit::CGameStateInit(CGame* g)
		: CGameState(g)
	{
	}
	int unlock_level;//現在已解鎖的關卡
	CGameMap::CGameMap()//地圖的class
		: X(315), Y(195), MW(70), MH(70)
	{
	}
	int CGameMap::GetMap(int x, int y) { //用座標獲取關卡地圖
		return map[y][x];
	}
	int CGameMap::GetLv() { //獲取現在的關卡等級
		return Level;
	}
	void CGameMap::LoadMap() { //載入遊戲地圖

		if (Level == 1) { //第一關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level1_Map[i][j];
				}
			}
		}
		else if (Level == 2) {//第二關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level2_Map[i][j];
				}
			}
		}
		else if (Level == 3) {//第三關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level3_Map[i][j];
				}
			}
		}
		else if (Level == 4) {//第四關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level4_Map[i][j];
				}
			}
		}
		else if (Level == 5) {//第五關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level5_Map[i][j];
				}
			}
		}
		else if (Level == 6) {//第六關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level6_Map[i][j];
				}
			}
		}
		else if (Level == 7) {//第七關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level7_Map[i][j];
				}
			}
		}
		else if (Level == 8) {//第八關
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 8; j++) {
					map[i][j] = Level8_Map[i][j];
				}
			}
		}
	}
	void CGameMap::SetLevel(int level)//設定關卡等級
	{
		Level = level;
	}
	void CGameMap::LoadBitmap() {//載入地圖資源
		floor1.LoadBitmap(IDB_FLOOR1);
		floor2.LoadBitmap(IDB_FLOOR2);
		water.LoadBitmap(IDB_WATER);
		wall1.LoadBitmap(IDB_WALL1);
		wall2.LoadBitmap(IDB_WALL2);
		wall3.LoadBitmap(IDB_WALL3);
		wall4.LoadBitmap(IDB_WALL4);
		wall5.LoadBitmap(IDB_WALL5);
		wall6.LoadBitmap(IDB_WALL6);
		wall7.LoadBitmap(IDB_WALL7);
		wall8.LoadBitmap(IDB_WALL8);
		wall9.LoadBitmap(IDB_WALL9);
		wall10.LoadBitmap(IDB_WALL10);
		wall11.LoadBitmap(IDB_WALL11);
		wall12.LoadBitmap(IDB_WALL12);
		wall13.LoadBitmap(IDB_WALL13);
		wall14.LoadBitmap(IDB_WALL14);
		corner1.LoadBitmap(IDB_CORNER1);
		corner2.LoadBitmap(IDB_CORNER2);
		corner3.LoadBitmap(IDB_CORNER3);
		corner4.LoadBitmap(IDB_CORNER4);
		black.LoadBitmap(IDB_BLACK);
	}
	void CGameMap::OnShow() { //把地圖用座標貼到該位置，共有21種地形
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 6; j++) {
				switch (map[j][i]) {
				case 0:
					black.SetTopLeft(X + MW * i, Y + MH * j);
					black.ShowBitmap();
					break;
				case 1:
					floor1.SetTopLeft(X + MW * i, Y + MH * j);
					floor1.ShowBitmap();
					break;
				case 2:
					floor2.SetTopLeft(X + MW * i, Y + MH * j);
					floor2.ShowBitmap();
					break;
				case 3:
					water.SetTopLeft(X + MW * i, Y + MH * j);
					water.ShowBitmap();
					break;
				case 4:
					wall1.SetTopLeft(X + MW * i, Y + MH * j);
					wall1.ShowBitmap();
					break;
				case 5:
					wall2.SetTopLeft(X + MW * i, Y + MH * j);
					wall2.ShowBitmap();
					break;
				case 6:
					wall3.SetTopLeft(X + MW * i, Y + MH * j);
					wall3.ShowBitmap();
					break;
				case 7:
					wall4.SetTopLeft(X + MW * i, Y + MH * j);
					wall4.ShowBitmap();
					break;
				case 8:
					wall5.SetTopLeft(X + MW * i, Y + MH * j);
					wall5.ShowBitmap();
					break;
				case 9:
					wall6.SetTopLeft(X + MW * i, Y + MH * j);
					wall6.ShowBitmap();
					break;
				case 10:
					wall7.SetTopLeft(X + MW * i, Y + MH * j);
					wall7.ShowBitmap();
					break;
				case 11:
					wall8.SetTopLeft(X + MW * i, Y + MH * j);
					wall8.ShowBitmap();
					break;
				case 12:
					wall9.SetTopLeft(X + MW * i, Y + MH * j);
					wall9.ShowBitmap();
					break;
				case 13:
					wall10.SetTopLeft(X + MW * i, Y + MH * j);
					wall10.ShowBitmap();
					break;
				case 14:
					wall11.SetTopLeft(X + MW * i, Y + MH * j);
					wall11.ShowBitmap();
					break;
				case 15:
					wall12.SetTopLeft(X + MW * i, Y + MH * j);
					wall12.ShowBitmap();
					break;
				case 16:
					wall13.SetTopLeft(X + MW * i, Y + MH * j);
					wall13.ShowBitmap();
					break;
				case 17:
					wall14.SetTopLeft(X + MW * i, Y + MH * j);
					wall14.ShowBitmap();
					break;
				case 18:
					corner1.SetTopLeft(X + MW * i, Y + MH * j);
					corner1.ShowBitmap();
					break;
				case 19:
					corner2.SetTopLeft(X + MW * i, Y + MH * j);
					corner2.ShowBitmap();
					break;
				case 20:
					corner3.SetTopLeft(X + MW * i, Y + MH * j);
					corner3.ShowBitmap();
					break;
				case 21:
					corner4.SetTopLeft(X + MW * i, Y + MH * j);
					corner4.ShowBitmap();
					break;
				default:
					ASSERT(1);
				}
			}
		}
	}
	void CGameStateInit::OnInit()
	{
		in_intro = false;
		in_about = false;
		sound = true;
		logo.LoadBitmap(IDB_NEWLOGO); //貼上遊戲logo
		mainmenu.LoadBitmapA(IDB_MAINMENU);//主畫面
		levels.LoadBitmapA(IDB_LEVELS);//選關卡的畫面
		l2.LoadBitmapA(IDB_L2);//過第二關後選關的畫面
		l3.LoadBitmapA(IDB_L3);//過第三關後選關的畫面
		l4.LoadBitmapA(IDB_L4);//過第四關後選關的畫面
		l5.LoadBitmapA(IDB_L5);//過第五關後選關的畫面
		l6.LoadBitmapA(IDB_L6);//過第六關後選關的畫面
		l7.LoadBitmapA(IDB_L7);//過第七關後選關的畫面
		l8.LoadBitmapA(IDB_L8);//過第八關後選關的畫面
		intro.LoadBitmapA(IDB_INTRO);//遊戲介紹的畫面
		about.LoadBitmap(IDB_ABOUT);//關於的畫面
		sound_off.LoadBitmapA(IDB_SOUND_OFF);//關閉遊戲聲音的按鈕
		sound_off.SetTopLeft(0, -100);//關閉遊戲聲音設定初始位置
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_1, RGB(255, 255, 255));//主畫面角色動畫1
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_2, RGB(255, 255, 255));//主畫面角色動畫2
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_3, RGB(255, 255, 255));//主畫面角色動畫3
		charactor.AddBitmap(IDB_PLAYER_ALIVE_RIGHT_4, RGB(255, 255, 255));//主畫面角色動畫4
		slime.AddBitmap(IDB_SLIME1, RGB(255, 255, 255));//主畫面怪物動畫1
		slime.AddBitmap(IDB_SLIME2, RGB(255, 255, 255));//主畫面怪物動畫2
		slime.AddBitmap(IDB_SLIME3, RGB(255, 255, 255));//主畫面怪物動畫3
		CAudio::Instance()->Load(AUDIO_BGM, "sounds\\bgm.wav");//背景音樂
		CAudio::Instance()->Play(AUDIO_BGM, true);
	}
	void CGameStateInit::OnBeginState()
	{
	}
	void CGameStateInit::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char KEY_ESC = 27;						// 切換至GAME_STATE_RUN
		if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}
	void CGameStateInit::OnLButtonDown(UINT nFlags, CPoint point)
	{
		if (!in_levels && !in_intro) {//判斷所在的畫面
			if (point.x >= 500 && point.x <= 700 && point.y >= 195 && point.y <= 285 && !in_about && !in_intro) { //判斷點的位置若是開始
				GotoGameState(GAME_STATE_RUN);
			}
			else if (point.x >= 500 && point.x <= 700 && point.y >= 360 && point.y <= 450 && !in_about && !in_intro) { //判斷點的位置若是關於
				ax = 0;
				in_about = true;
			}
			else if (point.x >= 500 && point.x <= 700 && point.y >= 525 && point.y <= 615 && !in_about && !in_intro) { //判斷點的位置若是介紹
				ix = 0;
				in_intro = true;
			}
		}
		else if (in_intro && point.x >= 495 && point.x <= 705 && point.y >= 626 && point.y <= 734) { //判斷若是在關於的畫面且點的位置是回到主畫面
			ix = 1500;
			in_intro = false;
		}
	}
	void CGameStateInit::OnLButtonUp(UINT nFlags, CPoint point)
	{
		if (in_about && point.x >= 495 && point.x <= 705 && point.y >= 626 && point.y <= 734) {//判斷若是在介紹的畫面且點的位置是回到主畫面
			ax = 1198;
			in_about = false;
		}
		else if (point.x >= 1103 && point.x <= 1183 && point.y >= 13 && point.y <= 93) {//判斷若是點音樂開關
			if (sound) {//開啟音樂
				CAudio::Instance()->Stop(AUDIO_BGM);
				sound = false;
				sound_off.SetTopLeft(1103, 13);
			}
			else if (!sound) {//關閉音樂
				CAudio::Instance()->Play(AUDIO_BGM, true);
				sound = true;
				sound_off.SetTopLeft(0, -100);
			}
		}
	}
	void CGameStateInit::OnShow()
	{
		mainmenu.SetTopLeft(0, 0);//主畫面位置設定
		mainmenu.ShowBitmap();//顯示主畫面
		if (!sound) {
			sound_off.SetTopLeft(1103, 13);
		}
		sound_off.ShowBitmap();//顯示音樂按鈕
		charactor.SetTopLeft(200, 400);//主畫面角色位置
		charactor.OnMove();//主畫面角色動畫
		charactor.OnShow();
		slime.SetTopLeft(800, 400);//主畫面怪物位置
		slime.OnMove();//主畫面怪物動畫
		slime.OnShow();
		if (unlock_level == 1)//判斷通關的關卡數為何，並把對應的關卡選單貼上去
		{
			levels.SetTopLeft(lx, 0);
			levels.ShowBitmap();
		}
		else if (unlock_level == 2) {
			l2.SetTopLeft(lx, 0);
			l2.ShowBitmap();
		}
		else if (unlock_level == 3) {

			l3.SetTopLeft(lx, 0);
			l3.ShowBitmap();
		}
		else if (unlock_level == 4) {
			l4.SetTopLeft(lx, 0);
			l4.ShowBitmap();
		}
		else if (unlock_level == 5) {
			l5.SetTopLeft(lx, 0);
			l5.ShowBitmap();
		}
		else if (unlock_level == 6) {
			l6.SetTopLeft(lx, 0);
			l6.ShowBitmap();
		}
		else if (unlock_level == 7) {
			l7.SetTopLeft(lx, 0);
			l7.ShowBitmap();
		}
		else if (unlock_level == 8) {
			l8.SetTopLeft(lx, 0);
			l8.ShowBitmap();
		}
		intro.SetTopLeft(ix, 0);
		intro.ShowBitmap();
		about.SetTopLeft(ax, 0);
		about.ShowBitmap();
	}
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	/////////////////////////////////////////////////////////////////////////////
	CGameStateOver::CGameStateOver(CGame* g)
		: CGameState(g)
	{
	}
	void CGameStateOver::OnMove()
	{
		counter--;
		if (counter < 0)
			GotoGameState(GAME_STATE_INIT);
	}
	void CGameStateOver::OnBeginState()
	{
		counter = 30 * 2; // 5 seconds
	}
	void CGameStateOver::OnInit()
	{
		unlock_level = 1;
		ending.LoadBitmap(IDB_ENDING);//載入通關畫面
		ending.SetTopLeft(0, 0);//設定通關畫面位置
	}
	void CGameStateOver::OnShow()
	{
		ending.ShowBitmap();//顯示通關畫面
	}
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	/////////////////////////////////////////////////////////////////////////////
	CGameStateRun::CGameStateRun(CGame* g)
		: CGameState(g)
	{
		pipe = new Pipe[Pipenum];
		torch = new Torch[Torchnum];
		box = new Box[Boxesnum[gamemap.GetLv() - 1]];//init
		water = new Water[Waternum[gamemap.GetLv() - 1]];
		slime = new Slime[Slimenum[gamemap.GetLv() - 1]];
		trap = new Trap[Trapnum[gamemap.GetLv() - 1]];
		button = new Button[Buttonnum[gamemap.GetLv() - 1]];
		door = new Door[Doornum[gamemap.GetLv() - 1]];
		key = new Key[Doornum[gamemap.GetLv() - 1]];
		potion = new Potion[Potionnum[gamemap.GetLv() - 1]];

	}
	CGameStateRun::~CGameStateRun()
	{
		delete[] box; //防止memory leak刪除用完的資源
		delete[] water;
		delete[] slime;
		delete[] trap;
		delete[] button;
		delete[] potion;
		delete[] door;
		delete[] key;
		delete[] torch;
		delete[] pipe;
	}
	void CGameStateRun::OnBeginState()
	{
		sound_off.SetTopLeft(0, -100);//調整音樂開關的按鈕位置
		sound_on.SetTopLeft(1103, 13);//調整音樂開關的按鈕位置
		logo.SetTopLeft(25, 25);//設定遊戲logo位置
		banner.SetTopLeft(385, 0);//設定上方選單位置
		fail_logo.SetTopLeft(-1198, 0);//設定失敗提示位置
		pass_logo.SetTopLeft(-1198, 0);//設定通過提示位置
	}
	void CGameStateRun::OnMove()							// 移動遊戲元素
	{
		
		for (int i = 0; i < Torchnum; i++)
			torch[i].OnMove();
		for (int i = 0; i < Pipenum; i++)
			pipe[i].OnMove();
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++)
			box[i].OnMove();
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++)
			water[i].OnMove();

		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++)
			slime[i].OnMove();
		coin.OnMove();

		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			key[i].OnMove();
			door[i].OnMove();
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) {
			potion[i].OnMove();
		}
		potion_num.ShowBitmap();
		key_num.ShowBitmap();
		player.OnMove();
		fail_logo.ShowBitmap();
		pass_logo.ShowBitmap();
	}
	void CGameStateRun::OnInit()  								// 遊戲的初值及圖形設定
	{
		potion_num.LoadBitmap(nums[potion_get]); //載入藥水數量
		key_num.LoadBitmap(nums[key_get]); //載入鑰匙數量
		potion_num.SetTopLeft(930, 55);//設定數量位置
		key_num.SetTopLeft(930, 5);//設定數量位置
		int h[8] = { IDB_HINT1, IDB_HINT2, IDB_HINT3, IDB_HINT4, IDB_HINT5, IDB_HINT6, IDB_HINT7, IDB_HINT8};//載入提示
		for (int i = 0; i < 8; i++) {
			hint[i].LoadBitmap(h[i]);
			hint[i].SetTopLeft(0, 100);
		}
		for (int i = 0; i < Torchnum; i++)
			torch[i].LoadBitmap();
		for (int i = 0; i < Pipenum; i++)
			pipe[i].LoadBitmap();
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++)//載入箱子
			box[i].LoadBitmap();
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++)//載入水坑
			water[i].LoadBitmap();
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++)//載入怪物
			slime[i].LoadBitmap();
		for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++)//載入陷阱
			trap[i].LoadBitmap();
		for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++)//載入按鈕
			button[i].LoadBitmap();
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++)//載入藥水
			potion[i].LoadBitmap();
		sound_off.LoadBitmapA(IDB_SOUND_OFF);//載入音樂關 
		sound_on.LoadBitmapA(IDB_SOUND_ON);//載入音樂開
		logo.LoadBitmapA(IDB_NEWLOGO);//載入遊戲logo
		banner.LoadBitmapA(IDB_BANNER);//載入上面選單
		gamemap.LoadBitmap();//載入遊戲地圖
		gamemap.LoadMap();
		player.Restart(1);//玩家初始化
		player.LoadBitmap();//玩家動畫載入
		coin.Restart(1);//金幣初始化
		coin.LoadBitmap();//金幣載入
		fail_logo.LoadBitmap(IDB_FAIL);//失敗提示載入
		pass_logo.LoadBitmap(IDB_PASS);//通關提示載入
		//選關卡畫面載入
		levels.LoadBitmap(IDB_LEVELS);
		l2.LoadBitmapA(IDB_L2);
		l3.LoadBitmapA(IDB_L3);
		l4.LoadBitmapA(IDB_L4);
		l5.LoadBitmapA(IDB_L5);
		l6.LoadBitmapA(IDB_L6);
		l7.LoadBitmapA(IDB_L7);
		l8.LoadBitmapA(IDB_L8);
		//載入音樂
		CAudio::Instance()->Load(AUDIO_DING, "sounds\\ding.wav");
		CAudio::Instance()->Load(AUDIO_WATER, "sounds\\water.mp3");
		CAudio::Instance()->Load(AUDIO_BOX, "sounds\\box_move.mp3");
		CAudio::Instance()->Load(AUDIO_EAT, "sounds\\eat.mp3");
		CAudio::Instance()->Load(AUDIO_COIN, "sounds\\coin.mp3");
		CAudio::Instance()->Load(AUDIO_PASS, "sounds\\pass.mp3");
		CAudio::Instance()->Load(AUDIO_FAIL, "sounds\\fail.mp3");
		CAudio::Instance()->Load(AUDIO_TRAP_OPEN, "sounds\\trap_open.mp3");
		CAudio::Instance()->Load(AUDIO_TRAP_CLOSE, "sounds\\trap_close.mp3");
		CAudio::Instance()->Load(AUDIO_DOOR, "sounds\\door.mp3");
		CAudio::Instance()->Load(AUDIO_THROW, "sounds\\throw.mp3");
		in_levels = false;
		Reset(1);
	}
	void CGameStateRun::Reset(int level) { //關卡重置
		//刪除資源
		delete[] box;
		delete[] water;
		delete[] slime;
		delete[] trap;
		delete[] pipe;
		delete[] torch;
		delete[] button;
		delete[] potion;
		//參數初始化
		key_get = 0;
		Torchnum = rand() % 5;
		Pipenum = rand() % 5;
		key_num = CMovingBitmap();
		key_num.LoadBitmap(nums[key_get]);
		key_num.SetTopLeft(930, 5);
		potion_get = 0;
		potion_num = CMovingBitmap();
		potion_num.LoadBitmap(nums[potion_get]);
		potion_num.SetTopLeft(930, 55);
		gamemap.SetLevel(level);
		gamemap.LoadMap();
		player.Restart(level);
		coin.Restart(level);
		box = new Box[Boxesnum[level - 1]];
		water = new Water[Waternum[level - 1]];
		slime = new Slime[Slimenum[level - 1]];
		trap = new Trap[Trapnum[level - 1]];
		button = new Button[Buttonnum[level - 1]];
		door = new Door[Doornum[level - 1]];
		key = new Key[Doornum[level - 1]];
		potion = new Potion[Potionnum[level - 1]];
		pipe = new Pipe[Pipenum];
		torch = new Torch[Torchnum];
		//依照關卡等級設定不同位置
		std::vector<position> clear;
		array<int,6> wall = { 7,8,9,10,11,14 };
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 6; j++) {
				if (find(std::begin(wall), std::end(wall),gamemap.GetMap(i, j)) != std::end(wall)) {
					clear.push_back({ i,j });
				}
			}
		}
		random_shuffle(clear.begin(), clear.end());
		
		
		for (int i = 0; i < Torchnum; i++) {
			torch[i].LoadBitmap();
			TRACE("error:(%d,%d)", clear[clear.size() - 1].x, clear[clear.size() - 1].y);
			torch[i].SetPos(clear[clear.size()-1].x, clear[clear.size() - 1].y);
			clear.pop_back();
		}
			
		for (int i = 0; i < Pipenum; i++) {
			pipe[i].LoadBitmap();
			pipe[i].SetPos(clear[clear.size() - 1].x, clear[clear.size() - 1].y);
			clear.pop_back();
		}
			
				
		if (level == 1) {
		}
		else if (level == 2) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV2BoxPos[i][0], LV2BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV2WaterPos[i][0], LV2WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
		}
		else if (level == 3) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV3BoxPos[i][0], LV3BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV3WaterPos[i][0], LV3WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV3SlimePos[i][0], LV3SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
		}
		else if (level == 4) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV4BoxPos[i][0], LV4BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(4);
			}

			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(4);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV4SlimePos[i][0], LV4SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
		}
		else if (level == 5) {
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV5BoxPos[i][0], LV5BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(5);
			}
			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(5);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV5SlimePos[i][0], LV5SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV5DoorPos[i][0], LV5DoorPos[i][1]);
				key[i].SetPos(LV5KeyPos[i][0], LV5KeyPos[i][1]);
			}
		}
		else if (level == 6) {
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV6WaterPos[i][0], LV6WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV6BoxPos[i][0], LV6BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(6);
			}
			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(6);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV6SlimePos[i][0], LV6SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV6DoorPos[i][0], LV6DoorPos[i][1]);
				key[i].SetPos(LV6KeyPos[i][0], LV6KeyPos[i][1]);
			}
			for (int i = 0; i < Potionnum[level - 1]; i++) {
				potion[i].LoadBitmap();
				potion[i].SetPos(LV6PotionPos[i][0], LV6PotionPos[i][1]);
				potion[i].SetIsAlive(true);
			}
		}
		else if (level == 7) {

			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV7BoxPos[i][0], LV7BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}


			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV7WaterPos[i][0], LV7WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}

			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV7SlimePos[i][0], LV7SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}

			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV7DoorPos[i][0], LV7DoorPos[i][1]);
				key[i].SetPos(LV7KeyPos[i][0], LV7KeyPos[i][1]);
			}
			for (int i = 0; i < Potionnum[level - 1]; i++) {
				potion[i].LoadBitmap();
				potion[i].SetPos(LV7PotionPos[i][0], LV7PotionPos[i][1]);
				potion[i].SetIsAlive(true);
			}
		}
		else if (level == 8) {
			for (int i = 0; i < Waternum[level - 1]; i++) {
				water[i].LoadBitmap();
				water[i].SetPos(LV8WaterPos[i][0], LV8WaterPos[i][1]);
				water[i].SetIsAlive(true);
			}
			for (int i = 0; i < Boxesnum[level - 1]; i++) {
				box[i].LoadBitmap();
				box[i].SetPos(LV8BoxPos[i][0], LV8BoxPos[i][1]);
				box[i].SetIsAlive(true);
			}
			for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
				trap[i].LoadBitmap();
				trap[i].Restart(8);
			}
			for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
				button[i].LoadBitmap();
				button[i].Restart(8);
				button[i].Link(&trap[i]);
			}
			for (int i = 0; i < Slimenum[level - 1]; i++) {
				slime[i].LoadBitmap();
				slime[i].SetPos(LV8SlimePos[i][0], LV8SlimePos[i][1]);
				slime[i].SetIsAlive(true);
			}
			for (int i = 0; i < Doornum[level - 1]; i++) {
				door[i].LoadBitmap();
				key[i].LoadBitmap();
				key[i].Link(&door[i]);
				door[i].SetPos(LV8DoorPos[i][0], LV8DoorPos[i][1]);
				key[i].SetPos(LV8KeyPos[i][0], LV8KeyPos[i][1]);
			}
			for (int i = 0; i < Potionnum[level - 1]; i++) {
				potion[i].LoadBitmap();
				potion[i].SetPos(LV8PotionPos[i][0], LV8PotionPos[i][1]);
				potion[i].SetIsAlive(true);
			}
		}
	};
	void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		const char R = 0x52;
		const char N = 0x4E;
		const char KEY_ESC = 27;						// 切換至GAME_STATE_RUN
		//密技R 重新開始關卡
		if (nChar == R) {
			Reset(gamemap.GetLv());
		}
		//密技N 跳下一關
		if (nChar == N) {
			if (gamemap.GetLv() == unlock_level && unlock_level != 8) {
				unlock_level += 1;
				Reset(gamemap.GetLv() + 1);
			}
			else if (gamemap.GetLv() == 8) {//last level
				Reset(1);
				GotoGameState(GAME_STATE_OVER);
				return;
			}
		}
		if (nChar == KEY_ESC)								// Demo 關閉遊戲的方法
			PostMessage(AfxGetMainWnd()->m_hWnd, WM_CLOSE, 0, 0);	// 關閉遊戲
	}
	void CGameStateRun::OnCharacterMove(int dir) { //角色移動及碰撞判斷
		player.SetHeading(dir); //玩家設定轉向
		TrapCheck(); //陷阱檢查
		//目標位置
		int px = 0; 
		int py = 0; 
		//目標的下一個位置
		int pnx = 0;
		int pny = 0;
		//目標的下下一個位置
		int wx = 0;
		int wy = 0;
		if (dir == 0) {
			px = player.GetX() - 1;
			py = pny = wy = player.GetY();
			pnx = player.GetX() - 2;
			wx = player.GetX() - 3;
		}
		else if (dir == 1) {
			px = player.GetX() + 1;
			py = pny = wy = player.GetY();
			pnx = player.GetX() + 2;
			wx = player.GetX() + 3;
		}
		else if (dir == 2) {
			px = pnx = wx = player.GetX();
			py = player.GetY() - 1;
			pny = player.GetY() - 2;
			wy = player.GetY() - 3;
		}
		else {
			px = pnx = wx = player.GetX();
			py = player.GetY() + 1;
			pny = player.GetY() + 2;
			wy = player.GetY() + 3;
		}
		if (coin.hitplayer(px, py)) { //觸碰到金幣通關		
			if (sound) {
				CAudio::Instance()->Play(AUDIO_COIN, false);
			}
			if (gamemap.GetLv() == unlock_level && unlock_level != 8) {
				unlock_level += 1;
				Reset(gamemap.GetLv() + 1);
			}
			else if (gamemap.GetLv() == 8) {//last level
				GotoGameState(GAME_STATE_OVER);
				Reset(1);
				return;
			}
			else if (unlock_level <= 8) {
				if (gamemap.GetLv() != 8) {
					Reset(gamemap.GetLv() + 1);
				}
			}
			
			pflag = true;
			Sleep(100);
			return;
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) { //碰到藥水
			if (potion[i].hitplayer(px, py)) {
				potion[i].SetIsAlive(false);
				if (sound) {
					CAudio::Instance()->Play(AUDIO_DING, false);
				}
				potion_get += 1;
				potion_num = CMovingBitmap();
				potion_num.LoadBitmap(nums[potion_get]);
				potion_num.SetTopLeft(930, 55);
			}
		}
		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			if (door[i].hit(px, py)) { //如果人碰到門
				if (key[i].WasGotByPlayer()) {
					if (sound) {
						CAudio::Instance()->Play(AUDIO_DOOR, false);
					}
					door[i].Open(true);
					key_num = CMovingBitmap();
					key_get -= 1;
					key_num.LoadBitmap(nums[key_get]);
					key_num.SetTopLeft(930, 5);
				}
				ButtonCheck();
				return;
			}
		}
		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			if (key[i].PlayerGet(px, py)) { //如果人碰到鑰匙
				if (sound) {
					CAudio::Instance()->Play(AUDIO_DING, false);
				}
				key_num = CMovingBitmap();
				key_get += 1;
				key_num.LoadBitmap(nums[key_get]);
				key_num.SetTopLeft(930, 5);
			}
		}
		for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
			if (water[j].HitPlayer(px, py)) //判斷人碰到水
			{
				ButtonCheck();
				Sleep(100);
				return;
			}
		}
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
			if (box[i].hitplayer(px, py)) { //判斷人碰到箱子
				if (coin.hitplayer(pnx, pny)) //如果箱子前面有錢幣就推不動
				{
					if (sound) {
						CAudio::Instance()->Play(AUDIO_COIN, false);
					}
					if (gamemap.GetLv() == unlock_level && unlock_level != 8) {
						unlock_level += 1;
						Reset(gamemap.GetLv() + 1);
					}
					else if (gamemap.GetLv() == 8) {//last level
						GotoGameState(GAME_STATE_OVER);
						Reset(1);
						return;
					}
					else if (unlock_level == 8) {
						if (gamemap.GetLv() != 8) {
							Reset(gamemap.GetLv() + 1);
						}
					}
					ButtonCheck();
					Sleep(100);
					return;
				}
				for (int j = 0; j < Potionnum[gamemap.GetLv() - 1]; j++) {
					if (potion[j].GetPx() == pnx && potion[j].GetPy() == pny && (potion[j].IsAlive() && !potion[j].isGrabbed())) //如果箱子前面是藥水就不動
					{
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
					if (box[i].HitWater(&water[j], dir)) //如果箱子前面是水就填水
					{
						if (sound) {
							CAudio::Instance()->Play(AUDIO_WATER, false);
						}
						player.SetPos(px, py);
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++)				{
					if (box[j].hitplayer(pnx, pny)) {//如果箱子前面還有一個箱子就推不動
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Trapnum[gamemap.GetLv() - 1]; j++) {
					if (trap[j].hit(pnx, pny)) {  //如果箱子前面有陷阱
						ButtonCheck();
						Sleep(100);
						return;
					}
				}
				for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {
					if (door[j].hit(pnx, pny)) { //如果箱子前面有門
						ButtonCheck();
						return;
					}
					if (key[j].Getpx() == pnx && key[j].Getpy() == pny && !key[j].WasGot()) {
						ButtonCheck();
						return;
					}
				}
				for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++)				{

					if (slime[j].GetX() == pnx && slime[j].GetY() == pny && slime[j].IsAlive()) {//如果箱子前面有一個史萊姆
						for (int k = 0; k < Slimenum[gamemap.GetLv() - 1]; k++) {
							if (slime[k].GetX() == wx && slime[k].GetY() == wy) {//如果史萊姆前面還有一個史萊姆就推不動
								ButtonCheck();
								Sleep(100);
								return;
							}
						}
						for (int k = 0; k < Trapnum[gamemap.GetLv() - 1]; k++) {
							if (trap[k].hit(wx, wy)) {  //如果史萊姆前面有陷阱
								ButtonCheck();
								Sleep(100);
								return;
							}
						}
						for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {
							if (door[k].hit(wx, wy)) { //如果史萊姆前面有門
								return;
							}
						}
						for (int k = 0; k < Waternum[gamemap.GetLv() - 1]; k++)	{
							if (slime[j].HitWater(&water[k], dir)) {//如果史萊姆填水
								if (sound) {
									CAudio::Instance()->Play(AUDIO_WATER, false);
								}
								box[i].SetPos(pnx, pny);
								player.SetPos(px, py);
								for (int l = 0; l < Doornum[gamemap.GetLv() - 1]; l++) { //判斷有沒有鑰匙被吃掉
									if (key[l].SlimeRelease(&slime[j])) {
										key[l].SetPos(wx, wy);
										key[l].Eaten(&slime[j]);
									}
								}
								for (int l = 0; l < Potionnum[gamemap.GetLv() - 1]; l++) { //判斷有沒有藥水被吃掉
									if (potion[l].GetPx() == slime[j].GetX() && potion[l].GetPy() == slime[j].GetY()) {
										potion[l].Release();
									}
								}
								ButtonCheck();
								Sleep(100);
								return;
							}
						}
						if (!MapCheck(dir, slime[j].GetX(), slime[j].GetY(), &slime[j])) { // 移動方向碰撞判斷
							ButtonCheck();
							Sleep(100);
							return;
						}
						if (sound) {
							CAudio::Instance()->Play(AUDIO_BOX, false);
						}
						//上述條件都沒發生就推史萊姆前進
						box[i].SetPos(pnx, pny);
						player.SetPos(px, py);
						slime[j].SetPos(wx, wy);
						ButtonCheck();
						Sleep(100);
						return;
					}
				}				
				if (gamemap.GetMap(pnx, pny) == 1 || gamemap.GetMap(pnx, pny) == 2) {//如果箱子前面沒有東西就推
					if (sound) {
						CAudio::Instance()->Play(AUDIO_BOX, false);
					}
					box[i].SetPos(pnx, pny);
					player.SetPos(px, py);
					ButtonCheck();
					Sleep(100);
					return;
				}
				ButtonCheck();
				Sleep(100);
				return;
			}
		}
		
		if (gamemap.GetMap(px, py) == 1 || gamemap.GetMap(px, py) == 2) {//如果人前面沒有東西就前進
			for (int j = 0; j < Trapnum[gamemap.GetLv() - 1]; j++) {
				if (trap[j].hit(px, py)) {
					ButtonCheck();
					Sleep(100);
					return;
				}
			}
			player.SetPos(px, py);
			ButtonCheck();
			Sleep(100);
		}
	}
	void CGameStateRun::ButtonCheck() {//檢查有沒有東西觸發按鈕
		for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
			bool flag = false;
			bool TrapT = button[i].GetTrapT();
			for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) { //檢查史萊姆觸發
				flag = button[i].trigger(slime[j].GetX(), slime[j].GetY());
				if (flag == true) {
					if (TrapT != button[i].GetTrapT() && sound) {
						CAudio::Instance()->Play(AUDIO_TRAP_OPEN, false);
					}
					break;
				}
			}
			if (flag == true) {
				continue;
			}
			for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {//檢查箱子觸發
				flag = button[i].trigger(box[j].GetPx(), box[j].GetPy());
				if (flag == true) {
					if (TrapT != button[i].GetTrapT() && sound) {
						CAudio::Instance()->Play(AUDIO_TRAP_OPEN, false);
					}
					break;
				}
			}
			if (flag == true) {
				continue;
			}
			if (button[i].trigger(player.GetX(), player.GetY())) { ///檢查人觸發
				if (TrapT != button[i].GetTrapT() && sound) {
					CAudio::Instance()->Play(AUDIO_TRAP_OPEN, false);
				}
				continue;
			}
			if (TrapT != button[i].GetTrapT() && sound) {
				CAudio::Instance()->Play(AUDIO_TRAP_CLOSE, false);
			}
		}
		TrapCheck();
	}
	void CGameStateRun::TrapCheck() {//陷阱檢查
		for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
			if (trap[i].GetTrigger()) {//陷阱開著就沒事
				continue;
			}
			for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {//陷阱上有箱子就破壞
				if (trap[i].hit(box[j].GetPx(), box[j].GetPy())) {
					box[j].SetIsAlive(false);
				}
			}
			for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) {//陷阱上有史萊姆就殺死
				if (trap[i].hit(slime[j].GetX(), slime[j].GetY())) {
					slime[j].SetIsAlive(false);
					for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {//判斷有沒有鑰匙被吃掉
						key[k].Eaten(&slime[j]);
					}
					for (int l = 0; l < Potionnum[gamemap.GetLv() - 1]; l++) { //判斷有沒有藥水被吃掉
						if (potion[l].GetPx() == slime[j].GetX() && potion[l].GetPy() == slime[j].GetY()) {
							potion[l].Release();
						}
					}
				}
			}
			if (trap[i].hit(player.GetX(), player.GetY())) {//陷阱觸碰到人
				player.SetIsAlive(false);
				fflag = true;
			}
		}
	}
	bool CGameStateRun::MapCheck(int dir, int x, int y, Slime* s) {//史萊姆碰撞檢查
		//若是被暈眩就沒事
		if (s->IsShock()) {
			s->Move(dir);
			fflag = s->HitPlayer(&player);
			if (fflag && sound) {
				CAudio::Instance()->Play(AUDIO_EAT, false);
			}
			return false;
		}
		if (dir == 0) {
			x = x - 1;
		}
		else if (dir == 1) {
			x = x + 1;
		}
		else if (dir == 2) {
			y = y - 1;
		}
		else if (dir == 3) {
			y = y + 1;
		}
		else {
			return false;
		}
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++)
		{
			if (box[i].hitplayer(x, y)) {//如果前面有一個箱子
				return false;
			}
		}
		for (int j = 0; j < Trapnum[gamemap.GetLv() - 1]; j++) {
			if (trap[j].hit(x, y)) {  //如果前面有陷阱
				ButtonCheck();
				return false;
			}
		}
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++) {//前面還有一隻史萊姆
			if (slime[i].GetX() == x && slime[i].GetY() == y && slime[i].IsAlive()) {
				if (!MapCheck(dir, x, y, &slime[i]))
				{
					return false;
				}
			}
		}
		for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {
			if (door[j].hit(x, y)) {  //如果前面有門
				ButtonCheck();
				return false;
			}
			if (key[j].SlimeGet(x, y,s)) {//吃掉鑰匙變色
				s->Change_Color("blue");
				key[j].Eaten(s);
				ButtonCheck();
			}
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) {//吃掉藥水變色
			if (potion[i].hitslime(x, y, s)) {
				s->Change_Color("red");
			}
		}
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++) {//碰到水
			if (water[i].HitPlayer(x,y)) {
				return false;
			}
		}
		if (gamemap.GetMap(x, y) == 1 || gamemap.GetMap(x, y) == 2) {//前面是牆
			return true;
		}
		return false;
	}
	void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
	{
		if (countdown > 0) {
			return;
		}
		const char KEY_LEFT = 0x25; // keyboard左箭頭
		const char KEY_UP = 0x26; // keyboard上箭頭
		const char KEY_RIGHT = 0x27; // keyboard右箭頭
		const char KEY_DOWN = 0x28; // keyboard下箭頭
		const char A = 0x41;
		const char W = 0x57;
		const char D = 0x44;
		const char S = 0x53;
		if (nChar == KEY_LEFT || nChar == A) {//方向鍵左或A控制角色向左
			OnCharacterMove(0);
		}
		if (nChar == KEY_RIGHT || nChar == D) {//方向鍵右或D控制角色向右
			OnCharacterMove(1);
		}
		if (nChar == KEY_UP || nChar == W) {//方向鍵上或W控制角色向上
			OnCharacterMove(2);
		}
		if (nChar == KEY_DOWN || nChar == S) {//方向鍵下或S控制角色向下
			OnCharacterMove(3);
		}
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++) {
			ButtonCheck();
			int dirs = slime[i].FindPlayer(&player);//史萊姆取得角色相對她的方向
			if (dirs == -2) {//-2 就是重疊
				fflag = true;
				if (fflag && sound) {
					CAudio::Instance()->Play(AUDIO_EAT, false);
				}
				return;
			}
			//檢查地形
			if (MapCheck(dirs, slime[i].GetX(), slime[i].GetY(), &slime[i])) {

				slime[i].Move(dirs);
				fflag = slime[i].HitPlayer(&player);
				if (fflag && sound) {
					CAudio::Instance()->Play(AUDIO_EAT, false);
				}
				if (fflag) {
					countdown = 5;
					fflag = false;
					fail_logo.SetTopLeft(310, 250);
					Reset(gamemap.GetLv());
					if (sound) {
						CAudio::Instance()->Play(AUDIO_FAIL, false);
					}
				}
			}
		}
	}

	void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{

		//開關音效
		if (sound && point.x >= 1103 && point.x <= 1183 && point.y >= 13 && point.y <= 93) {
			CAudio::Instance()->Stop(AUDIO_BGM);
			sound = false;
			sound_off.SetTopLeft(1103, 13);
		}
		else if (!sound && point.x >= 1103 && point.x <= 1183 && point.y >= 13 && point.y <= 93) {
			CAudio::Instance()->Play(AUDIO_BGM, true);
			sound = true;
			sound_off.SetTopLeft(0, -100);
		}
		//上方選單
		else if (point.x >= 383 && point.x <= 533 && point.y >= 22 && point.y <= 100) {//restart
			Reset(gamemap.GetLv());
		}
		else if (!in_levels && point.x >= 666 && point.x <= 815 && point.y >= 22 && point.y <= 100) {//choose levels
			lx = 0;
			in_levels = true;
		}
		//選關卡畫面，依照按的位置選擇關卡
		else if (in_levels) {
			if (point.x >= 107 && point.x <= 219 && point.y >= 134 && point.y <= 211) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(1);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 230 && point.x <= 342 && point.y >= 134 && point.y <= 211 && unlock_level >= 2) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(2);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 353 && point.x <= 465 && point.y >= 134 && point.y <= 211 && unlock_level >= 3) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(3);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 476 && point.x <= 588 && point.y >= 134 && point.y <= 211 && unlock_level >= 4) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(4);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 599 && point.x <= 711 && point.y >= 134 && point.y <= 211 && unlock_level >= 5) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(5);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 722 && point.x <= 834 && point.y >= 134 && point.y <= 211 && unlock_level >= 6) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(6);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 845 && point.x <= 967 && point.y >= 134 && point.y <= 211 && unlock_level >= 7) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(7);
				Reset(gamemap.GetLv());
			}
			else if (point.x >= 977 && point.x <= 1089 && point.y >= 134 && point.y <= 211 && unlock_level >= 8) {
				lx = -1198;
				in_levels = false;
				gamemap.SetLevel(8);
				Reset(gamemap.GetLv());
			}
		}
		else if (int((point.x - 315) / 70) > 0 && int((point.y - 195) / 70) > 0) { //點擊地圖內
			for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
				//如果點的地方有箱子且在玩家的上下左右，且玩家持有藥水，就會消耗藥水撿起箱子
				if (potion_get > 0 && box[i].GetPx() == int((point.x - 315) / 70) && box[i].GetPy() == int((point.y - 195) / 70) && box[i].NextToPlayer(player.GetX(), player.GetY())) {
					box[i].GrabByPlayer();
					if (sound) {
						CAudio::Instance()->Play(AUDIO_EAT, false);
					}
					potion_get -= 1;
					potion_num = CMovingBitmap();
					potion_num.LoadBitmap(nums[potion_get]);
					potion_num.SetTopLeft(930, 55);
					return;
				}
			}
			//若是點的位置在地圖中，會去判斷丟箱子.
			if (point.x >= player.GetX() * 70 + 315 && point.x <= player.GetX() * 70 + 385 && point.y >= 70 + 195 && point.y <= 5 * 70 + 195) {//判斷水平位置及所選位置是否有障礙物
				for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
					if (box[i].IsGrabbed() && (gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 1 || gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 2)) {
						for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {
							if (box[j].GetPx() == int(floor((point.x - 315) / 70)) && box[j].GetPy() == int(floor((point.y - 195) / 70)) && box[j].IsAlive() && !box[j].IsGrabbed()) {//被箱子擋住
								return;
							}
						}
						for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {//被門或鑰匙擋住
							if (door[j].hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
							if (key[j].Getpx() == int(floor((point.x - 315) / 70)) && key[j].Getpy() == int(floor((point.y - 195) / 70)) && !key[j].WasGot()) {
								return;
							}
						}
						for (int j = 0; j < Potionnum[gamemap.GetLv() - 1]; j++) {//被藥水擋住
							if (potion[j].hitplayer(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
						}
						if (coin.hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {//被金幣擋住
							return;
						}
						box[i].SetPos(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)));
						box[i].ThrowByPlayer();
						ButtonCheck();
						if (sound) {
							CAudio::Instance()->Play(AUDIO_THROW, false);
						}
						for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) {//判斷有沒有丟到史萊姆
							if (slime[j].GetX() == box[i].GetPx() && slime[j].GetY() == box[i].GetPy() && slime[j].IsAlive()) {
								slime[j].Shock(); //暈眩或殺死史萊姆 
								box[i].SetIsAlive(false); //毀掉箱子
								if (!slime[j].IsAlive()) //如果殺死史萊姆，就把它吃掉的特殊道具吐出來
								{
									for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {
										key[k].Eaten(&slime[j]);
									}
									for (int k = 0; k < Potionnum[gamemap.GetLv() - 1]; k++) {
										if (potion[k].GetPx() == slime[j].GetX() && potion[k].GetPy() == slime[j].GetY()) {
											potion[k].Release();
										}
									}
								}
							}
						}
						for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
							if (box[i].ThrowOnWater(&water[j])) //如果丟到水就填水
							{
								if (sound) {
									CAudio::Instance()->Play(AUDIO_WATER, false);
								}
								Sleep(100);
								return;
							}
						}
						ButtonCheck();
					}
				}
			}
			else if (point.x >= 70 + 315 && point.x <= 6 * 70 + 385 && point.y >= player.GetY() * 70 + 195 && point.y <= player.GetY() * 70 + 265) {//跟上面一樣步驟，只是判斷是方向是垂直的
				for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
					if (box[i].IsGrabbed() && (gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 1 || gamemap.GetMap(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70))) == 2)) {
						for (int j = 0; j < Boxesnum[gamemap.GetLv() - 1]; j++) {
							if (box[j].GetPx() == int(floor((point.x - 315) / 70)) && box[j].GetPy() == int(floor((point.y - 195) / 70)) && box[j].IsAlive() && !box[j].IsGrabbed()) {
								return;
							}
						}
						for (int j = 0; j < Doornum[gamemap.GetLv() - 1]; j++) {
							if (door[j].hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
							if (key[j].Getpx() == int(floor((point.x - 315) / 70)) && key[j].Getpy() == int(floor((point.y - 195) / 70)) && !key[j].WasGot()) {
								return;
							}
						}
						for (int j = 0; j < Potionnum[gamemap.GetLv() - 1]; j++) {
							if (potion[j].hitplayer(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
								return;
							}
						}
						if (coin.hit(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)))) {
							return;
						}
						box[i].SetPos(int(floor((point.x - 315) / 70)), int(floor((point.y - 195) / 70)));
						box[i].ThrowByPlayer();
						ButtonCheck();
						if (sound) {
							CAudio::Instance()->Play(AUDIO_THROW, false);
						}
						for (int j = 0; j < Slimenum[gamemap.GetLv() - 1]; j++) {
							if (slime[j].GetX() == box[i].GetPx() && slime[j].GetY() == box[i].GetPy() && slime[j].IsAlive()) {
								slime[j].Shock();
								box[i].SetIsAlive(false);
								if (!slime[j].IsAlive()) {
									for (int k = 0; k < Doornum[gamemap.GetLv() - 1]; k++) {
										key[k].Eaten(&slime[j]);
									}
									for (int k = 0; k < Potionnum[gamemap.GetLv() - 1]; k++) {
										if (potion[k].GetPx() == slime[j].GetX() && potion[k].GetPy() == slime[j].GetY()) {
											potion[k].Release();
										}
									}
								}
							}
						}
						for (int j = 0; j < Waternum[gamemap.GetLv() - 1]; j++) {
							if (box[i].ThrowOnWater(&water[j]))
							{
								if (sound) {
									CAudio::Instance()->Play(AUDIO_WATER, false);
								}
								Sleep(100);
								return;
							}
						}
						ButtonCheck();
					}
				}
			}
		}
	}
	void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
		
	}
	void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
	}
	void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point)  // 處理滑鼠的動作
	{
	}
	void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point)	// 處理滑鼠的動作
	{
	}
	void CGameStateRun::OnShow()
	{
		//如果失敗就會貼一個失敗的提示+放音效
		if (fflag) {
			countdown = 5;
			fflag = false;
			fail_logo.SetTopLeft(310, 250);
			Reset(gamemap.GetLv());
			if (sound) {
				CAudio::Instance()->Play(AUDIO_FAIL, false);
			}
		}
		//如果成功就會貼一個成功的提示+放音效
		if (pflag) {
			countdown = 5;
			pflag = false;
			pass_logo.SetTopLeft(310, 250);
			if (sound) {
				CAudio::Instance()->Play(AUDIO_PASS, false);
			}
		}
		//倒數
		if (countdown > 0) {
			Sleep(500);
			countdown--;
			if (countdown == 0) {
				fail_logo.SetTopLeft(-1198, 0);
				pass_logo.SetTopLeft(-1198, 0);
			}
		}
		//底下是所有圖形的顯示
		
		banner.ShowBitmap();
		hint[gamemap.GetLv() - 1].ShowBitmap();
		logo.ShowBitmap();
		gamemap.OnShow();
		
		
		for (int i = 0; i < Waternum[gamemap.GetLv() - 1]; i++) {
			water[i].OnShow();
		}
		for (int i = 0; i < Torchnum; i++) {
			torch[i].OnShow();
		}
		for (int i = 0; i < Pipenum; i++) {
			pipe[i].OnShow();
		}
		for (int i = 0; i < Buttonnum[gamemap.GetLv() - 1]; i++) {
			button[i].OnShow();
		}
		for (int i = 0; i < Potionnum[gamemap.GetLv() - 1]; i++) {
			potion[i].OnShow();
		}
		for (int i = 0; i < Trapnum[gamemap.GetLv() - 1]; i++) {
			trap[i].OnShow();
		}
		for (int i = 0; i < Boxesnum[gamemap.GetLv() - 1]; i++) {
			box[i].OnShow();
		}
		for (int i = 0; i < Slimenum[gamemap.GetLv() - 1]; i++) {
			slime[i].OnShow();
		}
		for (int i = 0; i < Doornum[gamemap.GetLv() - 1]; i++) {
			door[i].OnShow();
			key[i].OnShow();
		}
		coin.OnShow();
		potion_num.ShowBitmap();
		key_num.ShowBitmap();
		player.OnShow();
		fail_logo.ShowBitmap();
		pass_logo.ShowBitmap();
		if (unlock_level == 1) {
			levels.SetTopLeft(lx, 0);
			levels.ShowBitmap();
		}
		else if (unlock_level == 2) {
			l2.SetTopLeft(lx, 0);
			l2.ShowBitmap();
		}
		else if (unlock_level == 3) {
			l3.SetTopLeft(lx, 0);
			l3.ShowBitmap();
		}
		else if (unlock_level == 4) {
			l4.SetTopLeft(lx, 0);
			l4.ShowBitmap();
		}
		else if (unlock_level == 5) {
			l5.SetTopLeft(lx, 0);
			l5.ShowBitmap();
		}
		else if (unlock_level == 6) {
			l6.SetTopLeft(lx, 0);
			l6.ShowBitmap();
		}
		else if (unlock_level == 7) {
			l7.SetTopLeft(lx, 0);
			l7.ShowBitmap();
		}
		else if (unlock_level == 8) {
			l8.SetTopLeft(lx, 0);
			l8.ShowBitmap();
		}
		if (!sound) {
			sound_off.SetTopLeft(1103, 13);
		}
		sound_on.ShowBitmap();
		sound_off.ShowBitmap();
	}
}