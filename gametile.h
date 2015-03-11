#ifndef GAMETILE
#define GAMETILE
class gametile {
	private:
		bool wall;
		bool way;
		bool hardware;
		int hardware_number;
	public:
		gametile();
		~gametile();
		void setWay(void);
		void setWall(void);
		void setHardware(int number);
		char getChar(void);
};
#endif
