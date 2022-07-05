namespace game_framework {
	class Potion
	{
	public:
		Potion();
		bool IsAlive();											// 是否存在地圖上
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);											// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetPos(int nx, int ny);							// 設定玩家座標
		bool hitplayer(int nx, int ny);							// 是否接觸玩家
		bool hitslime(int nx, int ny,Slime* s);					// 是否接觸史萊姆
		int GetPx();											// 回傳x座標
		int GetPy();											// 回傳y座標
		void Release();											// 釋放藥水
		bool isGrabbed();										// 是否被擁有
	protected:
		CMovingBitmap potion;			
		int x, y;				
		bool is_alive;											// 是否存在地圖上
		bool is_got;											// 是否被擁有
	private:
		int px, py;												// 物件座標
		Slime* slime_eaten;
	};
}