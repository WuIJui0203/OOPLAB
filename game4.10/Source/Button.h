namespace game_framework {
	class Button
	{
	public:
		class Button();
		bool GetTrapT();										// 是否對應陷阱
		void Link(Trap* t);										// 對應陷阱
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY();											// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著
		void SetDelay(int d);									// 設定延遲
		void Restart(int level);								// 重新設置
		bool trigger(int nx, int ny);							// 切換開關
		void SetPos(int nx, int ny);							// 設定物件座標
	protected:
		CMovingBitmap button;
		Trap* linked_trap;
		bool triggered = false;									// 是否觸發
		int x, y;												// 圖像位置
	private:
		int px, py;												// 物件座標
	};
}