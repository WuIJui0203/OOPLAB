namespace game_framework {
	class Water 
	{
	public:
		Water();
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetPos(int nx, int ny);							// 設定物件座標
		bool HitBox(int nx, int ny);							// 是否接觸箱子
		void SetIsAlive(bool alive);							// 是否存在地圖上
		int GetPx();											// 回傳x座標
		int GetPy();											// 回傳y座標
		bool HitPlayer(int nx, int ny);							// 是否接觸玩家
	protected:
		CMovingBitmap water;
		bool is_alive;
	private:
		int px;
		int py;
		int x;
		int y;
	};
}