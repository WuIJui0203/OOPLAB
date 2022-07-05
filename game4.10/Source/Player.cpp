#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include "Player.h"
#include <windows.h>
namespace game_framework {
	Player::Player()//初始化
	{
		is_alive = true;
		x = y = 0;
		heading = 0;
	}
	bool Player::IsAlive()//回傳玩家是否活著
	{
		return is_alive;
	}
	void Player::LoadBitmap()//載入圖片資源
	{
		char* leftfiles[4] = { ".\\img\\player_alive_left_1.bmp",".\\img\\player_alive_left_2.bmp",".\\img\\player_alive_left_3.bmp",".\\img\\player_alive_left_4.bmp" };
		char* rightfiles[4] = { ".\\img\\player_alive_right_1.bmp",".\\img\\player_alive_right_2.bmp",".\\img\\player_alive_right_3.bmp",".\\img\\player_alive_right_4.bmp" };
		char* upfiles[2] = { ".\\img\\player_alive_up_1.bmp",".\\img\\player_alive_up_2.bmp"};
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
			left.AddBitmap(leftfiles[i], RGB(255, 255, 255));
		for (int i = 0; i < 4; i++)	// 載入動畫(由4張圖形構成)
			right.AddBitmap(rightfiles[i], RGB(255, 255, 255));
		for (int i = 0; i < 2; i++)	// 載入動畫(由4張圖形構成)
			up.AddBitmap(upfiles[i], RGB(255, 255, 255));
		die.LoadBitmap(IDB_PLAYER_DEAD_LEFT, RGB(255, 255, 255));
	}
	void Player::SetHeading(int h) {//設定轉向
		heading = h;
	}
	bool Player::HitMonster(int nx,int ny) {//判斷玩家是否碰到怪物
		if (nx == px && ny == py) {
			is_alive = false;
			return true;
		}
		return false;
	}
	void Player::OnMove()//依照玩家的轉向撥放動畫
	{
		if (!is_alive) {
			die.SetTopLeft(x, y);
			die.ShowBitmap();
			return;
		}
		if (heading == 0) {
			left.SetTopLeft(x,y);
			left.OnMove();
		}
		else if (heading == 2) {
			up.SetTopLeft(x, y);
			up.OnMove();
		}
		else {
			right.SetTopLeft(x, y);
			right.OnMove();
		}
	}
	void Player::SetDelay(int d)//設定玩家動畫速度
	{
		delay = d;
	}
	int Player::GetX()//取得玩家的x值
	{
		return  px;
	}
	int Player::GetY()//取的玩家的y值
	{
		return  py;
	}
	void Player::SetIsAlive(bool alive)//設定玩家是否死亡
	{
		is_alive = alive;
	}
	void Player::SetXY()//設定玩家的xy座標
	{
		if (!is_alive) {
			return;
		}
		x = px * 70 + 315; 
		y = py * 70 + 175;
	}
	void Player::SetPos(int nx, int ny) {//設定玩家的座標
		if (!is_alive) {
			return;
		}
		px = nx ;
		py = ny ;
		x = px * 70 + 315;
		y = py * 70 + 175;
	}
	void Player::Restart(int level)//設定玩家起始位置
	{
		heading = 0;
		is_alive = true;
		if (level == 1) {
			px = 1;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level == 2) {
			px = 1;
			py = 3;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
		else if (level >= 3) {
			px = 5;
			py = 1;
			x = px * 70 + 315;
			y = py * 70 + 175;
		}
	}
	void Player::Reset()//設定玩家的初始值
	{
		is_alive = true;
		x = y = px = py = 0;
		heading = 0;
		left.SetDelayCount(5);
		right.SetDelayCount(5);
		up.SetDelayCount(5);
	}
	void Player::OnShow()//根據玩家轉向撥放不同動畫
	{
		if (!is_alive){
			die.SetTopLeft(x, y);
			die.ShowBitmap();
			return;
		}
		if(heading == 0) {
			left.SetTopLeft(x, y);
			left.OnShow();
		}
		else if (heading == 2) {
			up.SetTopLeft(x, y);
			up.OnShow();
		}
		else {
			right.SetTopLeft(x, y);
			right.OnShow();
		}
	}
}