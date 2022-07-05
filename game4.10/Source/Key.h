namespace game_framework {
	class Key
	{
	public:
		class Key();
		void Link(Door* d);										// 連結機關門
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY();											// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetDelay(int d);									// 設定延遲
		bool WasGot();											// 是否被拾取
		void Restart(int level);								// 重新設置
		bool PlayerGet(int nx, int ny);							// 玩家擁有與否
		bool SlimeGet(int nx, int ny, Slime* s);				// 史萊姆吞噬與否
		void SetPos(int nx, int ny);							// 設定物件座標
		void Release();											// 釋放鑰匙
		int Getpx();											// 回傳x座標
		int Getpy();											// 回傳y座標
		void Eaten(Slime* s);									// 史萊姆吞噬
		bool WasGotByPlayer();                                  // 回傳是否被人拿到
		bool SlimeRelease(Slime* s);                            //史萊姆放掉
	protected:
		CMovingBitmap key;
		Door* linked_door;
		Slime* eaten_slime;
		bool got = false;										// 是否被拾取
		bool by_player = false;
		int x, y;												// 圖像位置
		bool is_eaten = false;									// 是否被吞噬
	private:
		int px, py;												// 物件座標
	};
}