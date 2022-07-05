#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Door.h"
namespace game_framework {
	Door::Door()
	{
	}
	void Door::LoadBitmap()//載入圖片
	{
		door.LoadBitmap(IDB_DOOR, RGB(255, 255, 255));
	}
	bool Door::GetOpen() {//回傳是否開啟
		return open;
	};
	void Door::Open(bool b) {//設定開門
		open = b;
	}
	bool Door::hit(int nx, int ny) {//判斷門是否關著且有東西撞上去
		if (nx == px && ny == py && !open) {
			return true;
		}
		return false;
	}
	void Door::OnMove()//顯示，若是開門就不顯示
	{		
		door.SetTopLeft(x, y);
		if (!open) {
			door.ShowBitmap();
		}
		else {
			return;
		}
	}
	void Door::Restart(int level)//初始化
	{
		open = false;
	}
	void Door::SetXY()//設定門的位置
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Door::SetPos(int nx, int ny) {//設定門的座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Door::OnShow()//顯示，門若關著不顯示
	{
		door.SetTopLeft(x, y);
		if (!open) {
			door.ShowBitmap();
		}
		else {
			return;
		}
	}
}