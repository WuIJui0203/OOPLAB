#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Door.h"
#include "Water.h"
#include "Player.h"
#include "Slime.h"
#include "Key.h"
namespace game_framework {
	Key::Key()
	{
	}
	void Key::Link(Door* d)//連結鑰匙與門
	{
		linked_door = d;
	}
	void Key::LoadBitmap()//載入資源
	{
		key.LoadBitmap(IDB_KEY, RGB(255, 255, 255));
	}
	void Key::Release() {//丟出鑰匙
		got = false;
	}
	int Key::Getpx() {//回傳px座標
		return px;
	}
	void Key::Eaten(Slime* s) {//判斷有沒有被史萊姆吃掉，若是史萊姆死亡則會吐出來
		if (!is_eaten && s->IsAlive()) {
			eaten_slime = s;
			got = true;
			is_eaten = true;
			return;
		}
		else if(is_eaten){
			if (eaten_slime->IsAlive() == false) {
				is_eaten = false;
				got = false;
				return;
			}
		}
	};
	int Key::Getpy() {//取得py座標
		return py;
	}
	bool Key::WasGotByPlayer() {
		return by_player;
	}
	bool Key::PlayerGet(int nx, int ny) {//玩家取得鑰匙
		if (got && !is_eaten) {
			SetPos(nx, ny);
			return false;
		}
		if (!is_eaten && !got && nx == px && ny == py) {
			got = true;
			by_player = true;
			return TRUE;
		}
		if (is_eaten) {
			return FALSE;
		}
		return FALSE;
	}
	bool Key::WasGot() {//回傳是否有被撿走
		return got;
	}
	bool Key::SlimeRelease(Slime* s) {
		if (s->IsAlive() == false && s == eaten_slime) {
			return true;
		}
		else {
			return false;
		}
	}
	bool Key::SlimeGet(int nx, int ny, Slime* s) {//史萊姆取得鑰匙
		if (got && is_eaten && s == eaten_slime) {
			SetPos(nx, ny);
			return false;
		}
		if (nx == px && ny == py && !is_eaten && !got) {
			eaten_slime = s;
			got = true;
			TRACE("got:%d",got);
			return TRUE;
		}
		return FALSE;
	}
	void Key::OnMove()//顯示，被撿走就不顯示
	{
		if (!got) {
			key.SetTopLeft(x, y);
			key.ShowBitmap();
		}
	}
	void Key::Restart(int level)//重置參數
	{
		got = false;
	}
	void Key::SetXY()//設定xy值
	{
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Key::SetPos(int nx, int ny) {//設定座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Key::OnShow()//顯示，被撿走不顯示
	{
		if (!got) { 
			key.SetTopLeft(x, y);
			key.ShowBitmap();
		}
	}
}