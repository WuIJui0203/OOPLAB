#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Pipe.h"
namespace game_framework {
	Pipe::Pipe()//初始化
	{
		x = y = px = py =  0;
		pipe.SetDelayCount(4);
	}
	void Pipe::LoadBitmap()//載入圖片資源
	{
		char* pipefiles[5] = { ".\\img\\pipe1.bmp",".\\img\\pipe2.bmp",".\\img\\pipe3.bmp",".\\img\\pipe4.bmp",".\\img\\pipe5.bmp" };
		for (int i = 0; i < 5; i++)	// 載入動畫(由5張圖形構成)
			pipe.AddBitmap(pipefiles[i], RGB(255, 255, 255));
	}
	void Pipe::OnMove()//撥放動畫
	{
		pipe.SetTopLeft(x, y);
		pipe.OnMove();
	}
	void Pipe::SetPos(int nx, int ny) {//設定座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 240;
	}
	void Pipe::OnShow()//根據玩家轉向撥放不同動畫
	{
		pipe.SetTopLeft(x, y);
		pipe.OnShow();
	}
}