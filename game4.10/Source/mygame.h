#include "Water.h"
#include "Box.h"
#include "Player.h"
#include "Coin.h"
#include "Slime.h"
#include "Trap.h"
#include "Button.h"
#include "Door.h"
#include "Key.h"
#include "Potion.h"
#include "Pipe.h"
#include "Torch.h"
namespace game_framework {
	/////////////////////////////////////////////////////////////////////////////
	// Constants
	/////////////////////////////////////////////////////////////////////////////
	enum AUDIO_ID {				// 定義各種音效的編號
		AUDIO_BGM,				// 0
		AUDIO_DING,				// 1
		AUDIO_WATER,			// 2
		AUDIO_BOX,				// 3
		AUDIO_EAT,
		AUDIO_COIN,
		AUDIO_PASS,
		AUDIO_FAIL,
		AUDIO_TRAP_OPEN,
		AUDIO_TRAP_CLOSE,
		AUDIO_DOOR,
		AUDIO_THROW
	};
	struct position 
	{
		int x;
		int y;
	};
	static bool sound = false;
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲開頭畫面物件
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////
	class CGameMap {
	public:
		CGameMap();
		void SetLevel(int level);						// 設定當前關卡等級
		void LoadBitmap();								// 載入圖形
		void LoadMap();									// 載入地圖
		void OnShow();									// 顯示圖形
		int GetMap(int x, int y);						// 讀取地圖內容
		int map[6][8];									// 設定地圖
		int GetLv();									// 讀取當前關卡等級
	protected:
		CMovingBitmap floor1, floor2, water, wall1, wall2, wall3, wall4, wall5, wall6, wall7, \
			wall8, wall9, wall10, wall11, wall12, wall13, wall14, corner1, corner2, corner3, corner4, black;
		int Level1_Map[6][8] = { {20,8,8,8,13,8,8,18},{5,2,1,1,17,1,2,6},{17,1,1,1,10,1,1,17},{6,1,4,1,1,1,1,17},{17,2,6,1,1,1,2,6},{19,7,14,8,9,8,8,21} };
		int Level2_Map[6][8] = { {20,9,8,13,9,8,9,18},{17,2,1,17,1,1,2,17},{17,1,1,10,1,1,1,5},{5,1,1,1,1,1,1,17},{17,2,1,2,1,1,2,5},{19,8,9,8,8,8,7,21} };
		int Level3_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level4_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level5_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level6_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level7_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level8_Map[6][8] = { {20,9,8,13,8,9,8,18},{17,1,1,6,2,1,1,17},{17,1,8, 21,1,1,1,17},{5,1,1,1,2,1,1,5},{17,1,1,4,1,2,1,17},{19,8,9,14,8,8,8,21} };
		int Level = 1;
		const int X, Y;
		const int MW, MH;
	};
	class CGameStateInit : public CGameState {
	public:
		CGameStateInit(CGame *g);
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnKeyUp(UINT, UINT, UINT); 				// 處理鍵盤Up的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
	protected:
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		CMovingBitmap logo;								
		CMovingBitmap mainmenu, sound_off, about;
		CMovingBitmap levels, l2, l3, l4, l5, l6, l7, l8;
		CMovingBitmap intro;
		CMovingBitmap btn_play;
		CMovingBitmap btn_levels;
		CMovingBitmap btn_credits;
		CAnimation	  charactor;
		CAnimation	  slime;
		CGameMap gamemap = CGameMap();
		bool		in_intro, in_about;					// 是否在intro/about介面內
	};
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的遊戲執行物件，主要的遊戲程式都在這裡
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateRun : public CGameState {
	public:
		CGameStateRun(CGame *g);
		~CGameStateRun();
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();  								// 遊戲的初值及圖形設定
		void OnKeyDown(UINT, UINT, UINT);				// 處理鍵盤的動作
		void OnKeyUp(UINT, UINT, UINT);					// 處理鍵盤的動作
		void OnLButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnLButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void OnMouseMove(UINT nFlags, CPoint point);	// 處理滑鼠的動作 
		void OnRButtonDown(UINT nFlags, CPoint point);  // 處理滑鼠的動作
		void OnRButtonUp(UINT nFlags, CPoint point);	// 處理滑鼠的動作
		void Reset(int level);							// 重設關卡
		void OnCharacterMove(int dir);					// 玩家移動
		bool MapCheck(int dir, int x, int y, Slime* s); // 史萊姆移動
		void ButtonCheck();								// 按鈕互動
		void TrapCheck();								// 陷阱互動
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		bool pflag = false;
		bool fflag = false;
		int countdown = 0;
		int Boxesnum[8] =	{ 0,1,1,2,0,2,2,3 };		// 設置每關箱子數量
		int Waternum[8] =	{ 0,3,4,0,0,1,1,3 };		// 設置每關水坑數量
		int Slimenum[8] =	{ 0,0,1,1,0,1,2,2 };		// 設置每關史萊姆數量
		int Trapnum[8] =	{ 0,0,0,1,0,1,0,0 };		// 設置每關陷阱數量
		int Doornum[8] =	{ 0,0,0,0,2,1,1,2 };		// 設置每關機關門數量
		int Buttonnum[8] =	{ 0,0,0,1,0,1,0,0 };		// 設置每關按鈕數量
		int Potionnum[8] =	{ 0,0,0,0,0,1,1,2 };		// 設置每關藥水數量
		int Torchnum =   0;
		int Pipenum =    0;
		int LV1BoxPos[1][2] = { {-999,-999} };			// 設置關卡箱子座標
		int LV2BoxPos[1][2] = { {2,2} };
		int LV3BoxPos[1][2] = { {5,2} };
		int LV4BoxPos[2][2] = { {5,2},{5,3} };
		int LV5BoxPos[2][2] = { {5,2},{5,3} };
		int LV6BoxPos[2][2] = { {5,2},{5,3} };
		int LV7BoxPos[2][2] = { {5,2},{4,2} };
		int LV8BoxPos[3][2] = { {5,2},{4,2},{6,2} };
		int LV1WaterPos[1][2] = { {-999,-999} };		// 設置關卡水坑座標
		int LV2WaterPos[3][2] = { {4,2} ,{5,2} ,{6,2} };
		int LV3WaterPos[4][2] = { {1,3},{1,4},{2,3},{2,4} };
		int LV6WaterPos[1][2] = { {1,3} };
		int LV7WaterPos[1][2] = { {5,4} };
		int LV8WaterPos[3][2] = { {4,4},{5,3},{6,4} };
		int LV3SlimePos[1][2] = { {3,3} };				// 設置關卡史萊姆座標
		int LV4SlimePos[1][2] = { {2,3} };
		int LV5SlimePos[1][2] = { {2,3} };
		int LV6SlimePos[1][2] = { {2,3}  };
		int LV7SlimePos[2][2] = { {2,3} ,{1,3} };
		int LV8SlimePos[2][2] = { {1,3},{3,3}};
		int LV6PotionPos[1][2] = { {6,2} };				// 設置關卡藥水座標
		int LV7PotionPos[1][2] = { {4,1} };
		int LV8PotionPos[2][2] = { {6,1},{4,1} };
		int LV5KeyPos[2][2] = { {5,2},{5,3} };			// 設置關卡鑰匙座標
		int LV6KeyPos[1][2] = { {4,3} };
		int LV7KeyPos[1][2] = { {3,3} };
		int LV8KeyPos[2][2] = { {2,3},{5,4} };
		int LV5DoorPos[2][2] = { {1,2},{3,3} };			// 設置關卡機關門座標
		int LV6DoorPos[1][2] = { {1,2} };
		int LV7DoorPos[1][2] = { {1,2} };
		int LV8DoorPos[2][2] = { {1,2}, {1,1} };
		int coinpos[8][2] = { {5,1},{5,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1} };	// 設置關卡金幣座標
		Box* box;
		Water* water;
		Coin coin;
		Player player = Player();
		Slime* slime;
		CMovingBitmap logo, hint[8], banner, sound_on, sound_off, fail_logo, pass_logo, potion_num, key_num;
		CMovingBitmap levels, l2, l3, l4, l5, l6, l7, l8;
		CGameMap gamemap = CGameMap();
		Trap* trap;
		Button* button;
		Door* door;
		Key* key;
		Key* key_logo;
		Potion* potion;
		Torch* torch;
		Pipe* pipe;
		int nums[3] = { IDB_num0 , IDB_num1 ,IDB_num2};
		int key_get = 0;								// 擁有鑰匙數量
		int potion_get = 0;								// 擁有藥水數量
	};
	/////////////////////////////////////////////////////////////////////////////
	// 這個class為遊戲的結束狀態(Game Over)
	// 每個Member function的Implementation都要弄懂
	/////////////////////////////////////////////////////////////////////////////
	class CGameStateOver : public CGameState {
	public:
		CGameStateOver(CGame *g);
		void OnBeginState();							// 設定每次重玩所需的變數
		void OnInit();
	protected:
		void OnMove();									// 移動遊戲元素
		void OnShow();									// 顯示這個狀態的遊戲畫面
	private:
		int counter;	// 倒數之計數器
		CMovingBitmap ending;
	};
}