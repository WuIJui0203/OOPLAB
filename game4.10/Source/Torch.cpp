#include "stdafx.h"
#include "Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include "audio.h"
#include "gamelib.h"
#include <windows.h>
#include "Torch.h"
namespace game_framework {
	Torch::Torch()//初始化
	{
		x = y = px = py = 0;
		torch.SetDelayCount(5);
	}
	void Torch::LoadBitmap()//載入圖片資源
	{
		char* torchfiles[3] = { ".\\img\\torch1.bmp",".\\img\\torch2.bmp",".\\img\\torch3.bmp" };
		for (int i = 0; i < 3; i++)	// 載入動畫(由3張圖形構成)
			torch.AddBitmap(torchfiles[i], RGB(255, 255, 255));
	}
	void Torch::OnMove()//撥放動畫
	{
		torch.SetTopLeft(x, y);
		torch.OnMove();
	}
	void Torch::SetPos(int nx, int ny) {//設定座標
		px = nx;
		py = ny;
		x = px * 70 + 315;
		y = py * 70 + 190;
	}
	void Torch::OnShow()//根據玩家轉向撥放不同動畫
	{
		torch.SetTopLeft(x, y);
		torch.OnShow();
	}
}