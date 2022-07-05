namespace game_framework {
	class Box
	{
	public:
		Box();
		bool IsAlive();											
		void LoadBitmap();										
		void OnMove();											
		void OnShow();											
		void SetXY(int nx, int ny);								
		void SetIsAlive(bool alive);							
		void SetPos(int nx, int ny);
		void GrabByPlayer();
		void ThrowByPlayer();
		bool NextToPlayer(int nx, int ny);
		bool hitplayer(int nx,int ny);
		bool HitWater(Water* w, int heading);
		bool ThrowOnWater(Water* w);
		bool IsGrabbed();
		int GetPx();
		int GetPy();
	protected:
		CMovingBitmap box;			
		int x, y;					
		int dx, dy;		
		bool is_alive;				
	private:
		bool Push(int map[6][8]);
		int px, py;
		bool HitSTH(int nx, int ny);
		bool isGrabbed;
	};
}