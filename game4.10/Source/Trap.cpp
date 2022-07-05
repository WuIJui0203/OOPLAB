#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Trap.h"
namespace game_framework {
	Trap::Trap()
	{
	}
	void Trap::LoadBitmap()//載入圖片資源，有打開跟關閉兩種
	{
		trap[0].LoadBitmap(IDB_TRAP1, RGB(255, 255, 255));
		trap[1].LoadBitmap(IDB_TRAP2, RGB(255, 255, 255));
	}
	bool Trap::GetTrigger() {//回傳是否被激活
		return triggered;
	};
	void Trap::trigger(bool b) {//激活陷阱
		triggered = b;
	}
	bool Trap::hit(int nx, int ny) {//判斷是否有碰到
		if (nx == px && ny == py && !triggered) {
			return true;
		}
		return false;
	}
	void Trap::OnMove()//根據現在的狀態顯示他的開關
	{
		trap[1].SetTopLeft(x, y);
		trap[0].SetTopLeft(x, y);
		if (triggered) {
			trap[1].ShowBitmap();
		}
		else {
			trap[0].ShowBitmap();
		}
	}
	void Trap::Restart(int level)//重設參數
	{
		triggered = false;
		if (level == 4) {
			SetPos(3,3);
		}
		if (level == 6) {
			SetPos(3, 3);
		}
		if (level == 8) {
			SetPos(3, 3);
		}
	}
	void Trap::SetXY()//設定陷阱的xy
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Trap::SetPos(int nx, int ny) {//設定陷阱的座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Trap::OnShow()//根據現在的狀態顯示他的開關
	{
		trap[1].SetTopLeft(x, y);
		trap[0].SetTopLeft(x, y);
		if (triggered) {
			trap[1].ShowBitmap();
		}
		else {
			trap[0].ShowBitmap();
		}
	}
}