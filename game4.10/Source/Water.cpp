#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Player.h"
#include <windows.h>
#include "Water.h"
namespace game_framework {
	Water::Water()
	{
		is_alive = true;
		x = y = px = py = 0;
	}
	void Water::SetIsAlive(bool alive)//設定是否被破壞
	{
		is_alive = alive;
	}
	bool Water::HitBox(int nx, int ny) {//箱子填水
		if (!is_alive) {
			return false;
		}
		if (nx == px && ny == py) {
			is_alive = false;
			return true;
		}
		return false;
	}
	bool Water::HitPlayer(int nx, int ny) {//碰到東西阻擋
		if (!is_alive) {
			return false;
		}
		if (nx == px && ny == py && is_alive) {
			return true;
		}
		return false;
	}
	void Water::SetPos(int nx, int ny) {//設定座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Water::OnMove()//若是未被破壞則顯示
	{
		if (!is_alive) {
			return;
		}
		water.SetTopLeft(x, y);
		water.ShowBitmap();
	}
	int Water::GetPx() {//取得px座標
		return px;
	}
	int Water::GetPy() {//取得py座標
		return py;
	}
	void Water::OnShow()//若是未被破壞則顯示
	{
		if (is_alive) {
			water.SetTopLeft(x, y);
			water.ShowBitmap();
		}
	}
	void Water::LoadBitmap()//載入圖片資源
	{
		water.LoadBitmap(IDB_WATER, RGB(255, 255, 255));			
	}
}