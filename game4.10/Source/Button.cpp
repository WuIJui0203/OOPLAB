#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Trap.h"
#include "Button.h"
namespace game_framework {
	Button::Button()
	{
	}
	void Button::Link(Trap* t)//綁定按鈕及陷阱
	{
		linked_trap = t;
	}
	void Button::LoadBitmap()//載入圖形
	{
		button.LoadBitmap(IDB_BUTTON, RGB(255, 255, 255));
	}
	bool Button::GetTrapT() {//取得對應的陷阱
		return linked_trap->GetTrigger();
	}
	bool Button::trigger(int nx, int ny) {//若有東西在上面就觸發
		if (nx == px && ny == py) {
			triggered = true;
			linked_trap->trigger(true);
			return TRUE;
		}
		triggered = false;
		linked_trap->trigger(false);
		return FALSE;
	}
	void Button::OnMove()//顯示
	{
		button.SetTopLeft(x, y);
		button.ShowBitmap();
	}
	void Button::Restart(int level)//設定初始位置
	{
		triggered = false;
		if (level == 4) {
			px = 6;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 195;
		}
		if (level == 6) {
			px = 6;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 195;
		}
		if (level == 8) {
			px = 6;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 195;
		}
	}
	void Button::SetXY()//設定xy值
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Button::SetPos(int nx, int ny) {//設定他的座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;

	}
	void Button::OnShow()//顯示
	{
		button.SetTopLeft(x, y);
		button.ShowBitmap();
	}
}