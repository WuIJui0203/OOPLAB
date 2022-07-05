#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Water.h"
#include "Player.h"
#include "Slime.h"
namespace game_framework {
	Slime::Slime()//初始化
	{
		is_alive = true;
		px = py = x = y = 0;
	}
	void Slime::Shock() {//若沒有吃掉任何道具，則暈眩三回合，否則就殺死她
		if (IsGreen()) {
			is_shock = true;
			shock_count = 3;
		}
		else {
			is_alive = false;
		}
	}
	void Slime::Change_Color(string c) {//改變顏色
		color = c;
	}
	bool Slime::IsGreen() {//判斷是否沒有吃掉東西
		if (color == "green"){
			return true;
		}
		else {
			return false;
		}
	}
	void Slime::Move(int dir) {//若是死亡、暈眩則不能移動，否則會移動
		if (!is_alive) {
			return;
		}
		else if (is_shock) {
			shock_count -= 1;
			if (shock_count < 1) {
				is_shock = false;
			}
			return;
		}
		else if (dir == 0) {
			px = px - 1;
			x = px * 70 + 315;
		}
		else if (dir == 1) {
			px = px + 1;
			x = px * 70 + 315;
		}
		else if (dir == 2) {
			py =  py - 1;
			y = py * 70 + 195;
		}
		else if (dir == 3) {
			py = py + 1;
			y = py * 70 + 195;
		}
	}
	int Slime::GetX() {//回傳史萊姆的x座標
		return px;
	}
	int Slime::GetY() {//回傳史萊姆的y座標
		return py;
	}
	bool Slime::HitPlayer(Player* player) {//若是史萊姆還活著，且碰到玩家，就殺死她
		if (!is_alive) {
			return false;
		}
		if (player->HitMonster(px, py)) {
			return true;
		}
		return false;
	}
	bool Slime::HitWater(Water* w, int heading) {//若是史萊姆被推到水里，就填水
		if (!is_alive) {
			return false;
		}
		if (heading == 0) {
			if (w->HitBox(px - 1, py)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		if (heading == 1) {
			if (w->HitBox(px + 1, py)) {
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
			if (w->HitBox(px, py + 1)) {
				is_alive = false;
				w->SetIsAlive(false);
				return true;
			}
		}
		return false;
	}
	int Slime::FindPlayer(Player* player) {//根據玩家的座標尋找玩家的相對於史萊姆的方向，他只會往垂直方向和水平方向尋找，若不在直線上回傳-1，重疊回傳-2
		if (!is_alive) {
			return -1;
		}
		int nx = player->GetX();
		int ny = player->GetY();
		if (nx == px && ny == py) {
			player->SetIsAlive(false);
			return -2;
		}
		else if (ny == py) {
			if (px > nx) {
				return 0;
			}
			else
			{
				return 1;
			}
		}
		else if (nx == px) {
			if (py > ny) {
				return 2;
			}
			else {
				return 3;
			}
		}
		return -1;
	}
	bool Slime::IsAlive()//回傳史萊姆是否活著
	{
		return is_alive;
	}
	void Slime::SetPos(int nx, int ny) {//設定史萊姆的位置
		if (!is_alive) {
			return;
		}
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 195;
	}
	void Slime::LoadBitmap()//載入圖像資源
	{
		char* slimefiles[3] = { ".\\img\\slime1.bmp",".\\img\\slime2.bmp",".\\img\\slime3.bmp" };
		for (int i = 0; i < 3; i++)
			slime.AddBitmap(slimefiles[i], RGB(255, 255, 255));
		char* redslimefiles[3] = { ".\\img\\red1.bmp",".\\img\\red3.bmp",".\\img\\red2.bmp" };
		for (int i = 0; i < 3; i++)
			redslime.AddBitmap(redslimefiles[i], RGB(255, 255, 255));
		char* blueslimefiles[3] = { ".\\img\\blue1.bmp",".\\img\\blue2.bmp",".\\img\\blue3.bmp" };
		for (int i = 0; i < 3; i++)
			blueslime.AddBitmap(blueslimefiles[i], RGB(255, 255, 255));
		num_shock1.LoadBitmap(IDB_1);
		num_shock2.LoadBitmap(IDB_2);
		num_shock3.LoadBitmap(IDB_3);
	}
	void Slime::OnMove()//若有被暈眩，根據暈眩剩餘回合數顯示數字，若存活就根據其顏色撥放動畫
	{
		if (shock_count == 1) {
			num_shock1.SetTopLeft(x, y - 10);
			num_shock1.ShowBitmap();
		}
		if (shock_count == 2) {
			num_shock2.SetTopLeft(x, y - 10);
			num_shock2.ShowBitmap();
		}
		if (shock_count == 3) {
			num_shock3.SetTopLeft(x, y - 10);
			num_shock3.ShowBitmap();
		}
		if (is_alive && color == "green") {
			slime.SetTopLeft(x, y);
			slime.OnMove();
		}
		if (is_alive && color == "red") {
			redslime.SetTopLeft(x, y);
			redslime.OnMove();
		}
		if (is_alive && color == "blue") {
			blueslime.SetTopLeft(x, y);
			blueslime.OnMove();
		}
	}
	bool Slime::IsShock() {//回傳是否被暈眩
		return is_shock;
	}
	void Slime::SetIsAlive(bool alive)//設定他的死活
	{
		is_alive = alive;
	}
	void Slime::SetXY(int nx, int ny)//設定他的座標
	{
		x = nx; y = ny;
	}
	void Slime::OnShow()//若有被暈眩，根據暈眩剩餘回合數顯示數字，若存活就根據其顏色撥放動畫
	{
		if (is_alive && color == "green") {
			if (shock_count == 1) {
				num_shock1.SetTopLeft(x, y-10);
				num_shock1.ShowBitmap();
			}
			if (shock_count == 2) {
				num_shock2.SetTopLeft(x, y - 10);
				num_shock2.ShowBitmap();
			}
			if (shock_count == 3) {
				num_shock3.SetTopLeft(x, y - 10);
				num_shock3.ShowBitmap();
			}
			slime.SetTopLeft(x,y);
			slime.OnShow();
		}
		if (is_alive && color == "red") {
			redslime.SetTopLeft(x, y);
			redslime.OnShow();
		}
		if (is_alive && color == "blue") {
			blueslime.SetTopLeft(x, y);
			blueslime.OnShow();
		}
	}
}