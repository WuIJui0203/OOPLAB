#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Coin.h"
namespace game_framework {
	Coin::Coin()
	{
	}
	void Coin::LoadBitmap()//載入金幣動畫
	{
		char* coinfiles[4] = { ".\\img\\coin1.bmp",".\\img\\coin2.bmp",".\\img\\coin3.bmp",".\\img\\coin4.bmp" };
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
			coin.AddBitmap(coinfiles[i], RGB(255, 255, 255));	
	}
	bool Coin::hitplayer(int nx, int ny) {//判斷金幣碰到玩家
		if (nx == px && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	void Coin::OnMove()//金幣顯示
	{
		coin.SetTopLeft(x, y);
		coin.OnMove();
	}
	bool Coin::hit(int nx, int ny) {//判斷金幣碰到東西
		if (nx == px && ny == py) {
			return true;
		}
		else {
			return false;
		}
	}
	void Coin::Restart(int level)//設定金幣初始位置
	{
		if (level == 1) {
			px = 5;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level == 2) {
			px = 5;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level >= 3 && level <8) {
			px = 1;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else 
		{
			px = 2;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
	}
	void Coin::SetXY()//設定金幣的xy值
	{
		x = px * 70 + 295;
		y = py * 70 + 175;
	}
	void Coin::SetPos(int nx, int ny) {//設定金幣的座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 175;
	}
	void Coin::OnShow()//顯示
	{
		coin.SetTopLeft(x, y);
		coin.OnShow();
	}
}