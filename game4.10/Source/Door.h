namespace game_framework {
	class Door
	{
	public:
		class Door();
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY();											// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetDelay(int d);									// 設定延遲
		void Restart(int level);								// 重新設置
		bool hit(int nx, int ny);								// 是否被接觸
		void Open(bool b);										// 將門開啟
		void SetPos(int nx, int ny);							// 設定物件座標
		bool GetOpen();											// 門是否開啟
	protected:
		CMovingBitmap door;
		int x, y;												// 圖像位置	
		bool open = false;										// 開啟與否
	private:
		int px, py;												// 物件座標
	};
}