#include"game.c"
void main()
{
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(TEXT("俄罗斯方块"));

	SMALL_RECT rc = { 0,0,UI_WIDTH * 2 + 15,UI_HEIGHT + 3 };  //设置窗口大小，宽度和高度
	SetConsoleWindowInfo(hOutput, TRUE, &rc);
	srand(time(NULL));
	initia();
	//隐藏缓冲区的光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);

	produceBlock();
	moveBlock();
}