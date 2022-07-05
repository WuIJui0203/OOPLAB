namespace game_framework {
	class Coin
	{
	public:
		Coin();
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY();											// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著
		void Restart(int level);								// 重新設置
		bool hitplayer(int nx, int ny);							// 是否接觸玩家
		void SetPos(int nx, int ny);							// 設定物件座標
		bool hit(int nx, int ny);								// 是否被接觸
	protected:
		CAnimation coin;			
		int x, y;												// 圖像位置	
	private:
		int px, py;												// 物件座標
	};
}