#include"game.h"
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}


//打印棋盘
void printBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++) 
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
			}
			printf("\n");
			if (i < row - 1)
			{
				int j = 0;
				for (j = 0; j < col; j++) {
					printf("---");
					if (j < col - 1)
						printf("|");
				}
				printf("\n");
		}
	}
}

void playermove(char board[][COL], int row, int col) {
	int x = 0;
	int y = 0;
	printf("玩家走:>\n");
	while (1) {
		printf("请输入下棋的坐标(相邻坐标间用空格隔开):>");
		scanf("%d %d", &x, &y);
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//下棋
			//判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				printf("坐标被占用,请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
}


void computermove(char board[][COL], int row, int col){
	printf("电脑走:>\n");
	int x = rand()%row;
	int y = rand()%col;
	while (1) {
		int x = rand() % row;
		int y = rand() % col;
		//判断坐标是否被占用
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;
		}
	}
}


int Isfull(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		if (board[i][1] ==board[i][0] && board[i][1]==board[i][2] && board[i][0] != ' ') {
			return board[i][1];
		}
	}
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') {
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ') {
		return board[1][1];
	}
	int ret=Isfull(board, row, col);
	if (ret == 1) {
		return 'Q';
	}
	else {
		return 'C';
	}
}