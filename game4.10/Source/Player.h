namespace game_framework {
	class Player
	{
	public:
		Player();
		bool IsAlive();											// 是否存活
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY();											// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetDelay(int d);									// 設定延遲
		void Reset();											// 回到預設狀態
		void SetHeading(int h);									// 設定前進方向
		void Restart(int level);								// 重新設置
		int GetX();												// 回傳x座標
		int GetY();												// 回傳y座標
		void SetPos(int nx, int ny);							// 設定玩家座標
		bool HitMonster(int nx,int ny);							// 是否接觸史萊姆
	protected:
		CAnimation left;
		CAnimation right;
		CAnimation up;
		CAnimation down;
		CMovingBitmap die;
		int x, y;												// 圖像位置
		int delay;												// 設定延遲
		bool is_alive;											// 是否存活
		int heading; //面向 0:left 1:right 2:up 3:down
	private:
		int px, py;												// 物件座標
	};
}