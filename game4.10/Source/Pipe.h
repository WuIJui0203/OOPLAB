namespace game_framework {
	class Pipe
	{
	public:
		Pipe();
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetPos(int nx, int ny);							// 設定玩家座標
	protected:
		CAnimation pipe;
		int x, y;												// 圖像位置
	private:
		int px, py;												// 物件座標
	};
}