#include"game.c"
void main()
{
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle(TEXT("����˹����"));

	SMALL_RECT rc = { 0,0,UI_WIDTH * 2 + 15,UI_HEIGHT + 3 };  //���ô��ڴ�С����Ⱥ͸߶�
	SetConsoleWindowInfo(hOutput, TRUE, &rc);
	srand(time(NULL));
	initia();
	//���ػ������Ĺ��
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = 0;
	cci.dwSize = 1;
	SetConsoleCursorInfo(hOutput, &cci);

	produceBlock();
	moveBlock();
}