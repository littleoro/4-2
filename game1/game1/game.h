#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS 1
//���Ŷ���
#define ROW 3
#define COL 3

//��������
void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������
void printBoard(char board[ROW][COL],int row, int col);//��ӡһ������----��ӡ���������
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);