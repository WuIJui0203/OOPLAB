#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Water.h"
#include "Player.h"
#include "Slime.h"
#include "Potion.h"
namespace game_framework {
	Potion::Potion()//初始化
	{
		is_alive = true;
		is_got = false;
		x = y = px = py = 0;
	}
	bool Potion::isGrabbed() {//回傳藥水有沒有被拿走
		return is_got;
	}
	bool Potion::hitplayer(int nx, int ny) {//碰到玩家時
		if (!is_alive||is_got) {
			return FALSE;
		};
		if (nx == px && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	bool Potion::hitslime(int nx, int ny, Slime* s) {//遇到怪物時，會被吃掉
		if (is_got && slime_eaten == s) {
			px = x;
			py = y;
			return TRUE;
		};
		if (nx == px && ny == py) {
			is_got = true;
			slime_eaten = s;
			return TRUE;
		}
		return FALSE;
	}
	void Potion::Release() {//怪物死後會放掉藥水
		is_got = false;
	}
	int Potion::GetPx() {//回傳藥水的px值
		return px;
	}
	int Potion::GetPy() {//回傳藥水的py值
		return py;
	}
	void Potion::SetPos(int nx, int ny) {//設定藥水的位置
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	bool Potion::IsAlive()//回傳藥水是否有被用掉
	{
		return is_alive;
	}
	void Potion::LoadBitmap()//載入資源
	{
		potion.LoadBitmap(IDB_POTION, RGB(255, 255, 255));		
	}
	void Potion::OnMove()//藥水若被用掉或被撿走，則不顯示
	{
		if (!is_alive||is_got)
			return;
		potion.SetTopLeft(x, y);
		potion.ShowBitmap();
	}
	void Potion::SetIsAlive(bool alive)//設定藥水是否有被用掉
	{
		is_alive = alive;
	}

	void Potion::SetXY(int nx, int ny)//設定藥水的xy值
	{
		x = nx; y = ny;
	}
	void Potion::OnShow()//藥水若被用掉或被撿走，則不顯示
	{
		if (!is_alive||is_got)
			return;
		potion.SetTopLeft(x, y);
		potion.ShowBitmap();
	}
}