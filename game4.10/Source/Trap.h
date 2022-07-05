namespace game_framework {
	class Trap
	{
	public:
		class Trap();
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY();											// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetDelay(int d);									// 設定延遲
		bool hit(int nx, int ny);								// 是否被接觸
		void Restart(int level);								// 重新設置
		void trigger(bool b);									// 設定觸發
		void SetPos(int nx, int ny);							// 設定物件座標
		bool GetTrigger();										// 是否觸發機關
	protected:
		CMovingBitmap trap[2];
		int x, y;												// 圖像位置
		bool triggered = false;									// 是否觸發
	private:
		int px, py;												// 物件座標
	};
}