#include"game.h"

void menu() {
	printf("**********************************\n");
	printf("********      1.play       *******\n");
	printf("********      0.exit       *******\n");
	printf("**********************************\n");
	printf("**********************************\n");
}




void game() {
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board,ROW,COL);
	//打印一下棋盘----打印数组的内容
	printBoard(board,ROW,COL);
	//玩家走
	char ret = 0;
	while (1) {
		playermove(board, ROW, COL);
		printBoard(board, ROW, COL);
		//判断输赢
	    ret=IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		computermove(board, ROW, COL);
		printBoard(board, ROW, COL);
		//判断输赢
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*') {
		printf("玩家赢了\n");
		printBoard(board, ROW, COL);

	}
	else if (ret == '#') {
		printf("电脑赢了\n");
		printBoard(board, ROW, COL);
	}
	else{
		printf("平局\n");
		printBoard(board, ROW, COL);
	}

}

int main() {
	int input = 0;
	srand((unsigned)time(NULL));
	do {
		menu();
		printf("请选择>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新输入数字\n");
			break;
		}
	} while (input);
	return 0;
}