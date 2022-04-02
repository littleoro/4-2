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
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡһ������----��ӡ���������
	printBoard(board,ROW,COL);
	//�����
	char ret = 0;
	while (1) {
		playermove(board, ROW, COL);
		printBoard(board, ROW, COL);
		//�ж���Ӯ
	    ret=IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		computermove(board, ROW, COL);
		printBoard(board, ROW, COL);
		//�ж���Ӯ
		ret=IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*') {
		printf("���Ӯ��\n");
		printBoard(board, ROW, COL);

	}
	else if (ret == '#') {
		printf("����Ӯ��\n");
		printBoard(board, ROW, COL);
	}
	else{
		printf("ƽ��\n");
		printBoard(board, ROW, COL);
	}

}

int main() {
	int input = 0;
	srand((unsigned)time(NULL));
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("��������Ϸ\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��������������\n");
			break;
		}
	} while (input);
	return 0;
}