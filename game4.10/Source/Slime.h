namespace game_framework {
	class Slime 
	{
	public:
		Slime();
		bool HitWater(Water* w,int heading);					// 是否掉入水裡
		void LoadBitmap();										// 載入圖形
		void OnMove();											// 移動
		void OnShow();											// 將圖形貼到畫面
		void SetXY(int nx, int ny);								// 設定圖像位置
		void SetIsAlive(bool alive);							// 設定是否活著		
		int FindPlayer(Player* player);							// 尋找玩家方向
		void SetPos(int nx, int ny);							// 設定物件座標
		void Move(int dir);										// 移動
		int GetX();												// 回傳x座標
		int GetY();												// 回傳y座標
		void Change_Color(string c);							// 變換顏色
		bool HitPlayer(Player* player);							// 是否接觸玩家
		bool IsGreen();											// 是否為綠色
		void Shock();											// 暈眩史萊姆
		bool IsShock();											// 是否為暈眩狀態
		bool IsAlive();											// 是否存活
	protected:
		CAnimation slime,redslime,blueslime ;
		CMovingBitmap num_shock1, num_shock2, num_shock3;
		int x, y;						
		bool is_alive;				
	private:
		int shock_count = 0;									// 暈眩倒計時
		bool is_shock = false;
		int px, py;
		string color = "green";
	};
}