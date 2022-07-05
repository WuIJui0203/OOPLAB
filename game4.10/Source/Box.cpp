#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Water.h"
#include "Box.h"
namespace game_framework {
	Box::Box()//初始化
	{
		is_alive = true;
		isGrabbed = false;
		x = y = dx = dy = px = py = 0;
	}
	bool Box::NextToPlayer(int nx, int ny) {//判斷該位置使否有在箱子的上下左右
		if (!is_alive) {
			return FALSE;
		};
		if (nx == px && ny == py + 1) {
			return TRUE;
		}
		else if (nx == px && ny == py - 1) {
			return TRUE;
		}
		else if (nx == px + 1 && ny == py) {
			return TRUE;
		}
		else if (nx == px - 1 && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	void Box::GrabByPlayer() {//玩家撿起箱子
		if (!isGrabbed) {
			isGrabbed = true;
		}
	}
	void Box::ThrowByPlayer() {//玩家丟出箱子
		if (isGrabbed) {
			isGrabbed = false;
		}
	}
	bool Box::hitplayer(int nx, int ny) { //若有東西碰到箱子，且他沒有被撿起來或破壞，就回傳true
		if(!is_alive || isGrabbed){
			return FALSE;
		};
		if (nx == px && ny == py) {
			return TRUE;
		}
		return FALSE;
	}
	int Box::GetPx() {//回傳箱子的座標px
		return px;
	}
	int Box::GetPy() {//回傳箱子的座標py
		return py;
	}
	bool Box::HitWater(Water* w,int heading)//若是箱子被推進水裡，破壞水及箱子，並回傳true
	{	
		if (heading == 0) {
			if (w->HitBox(px-1, py)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		if (heading == 1) {
			if (w->HitBox(px+1, py)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		if (heading == 2) {
			if (w->HitBox(px, py - 1)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		if (heading == 3) {
			if (w->HitBox(px, py+1)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		return false;
	}
	bool Box::ThrowOnWater(Water* w) {//若是箱子被丟到水上，就破壞兩者
		if (w->GetPx() == px && w->GetPy() == py) {
			is_alive = false;
			w->SetIsAlive(false);
			return true;
		}
		else {
			return false;
		}
	}
	bool Box::HitSTH(int nx, int ny) {//判斷箱子的位置是否與輸入的重疊
		if (nx == px && ny == py) {
			is_alive = false;
			return true;
		}
		return false;
	}
	void Box::SetPos(int nx, int ny) {//設定箱子的座標，並轉換成像素座標xy
		px = nx;
		py = ny;
		x = px * 70+315;
		y = py * 70+195;
	}
	bool Box::IsAlive()//取得箱子是否有被破壞
	{
		return is_alive;
	}
	bool Box::IsGrabbed()//回傳是否有被抓走
	{
		return isGrabbed;
	}
	void Box::LoadBitmap()
	{
		box.LoadBitmap(IDB_BOX, RGB(255, 255, 255));			
	}

	void Box::OnMove()//若有被抓走或被破壞就不顯示
	{
		if (!is_alive || isGrabbed)
			return;
		box.SetTopLeft(x, y);
		box.ShowBitmap();
	}
	void Box::SetIsAlive(bool alive)//設定箱子是否被破壞
	{
		is_alive = alive;
	}
	void Box::SetXY(int nx, int ny)//設定箱子的xy座標
	{
		x = nx; y = ny;
	}
	void Box::OnShow()//若有被抓走或被破壞就不顯示
	{
		if (!is_alive || isGrabbed)
			return;
		box.SetTopLeft(x, y);
		box.ShowBitmap();
	}
}