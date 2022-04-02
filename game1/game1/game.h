#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS 1
//符号定义
#define ROW 3
#define COL 3

//函数声明
void InitBoard(char board[ROW][COL], int row, int col);//初始化棋盘
void printBoard(char board[ROW][COL],int row, int col);//打印一下棋盘----打印数组的内容
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);