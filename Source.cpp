#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
const int width = 30, height = 20;
int snakex = width/2, snakey = height/2, foodx = rand()%28, foody = rand()%18,score=0;
int tailx[27], taily[18], ntail = 0;
char direction = NULL;
bool gameover = 0;
void design()
{
	system("cls");
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == 0 || i == height - 1||j == 0 || j == width - 1)
			{
				cout << "=";
			}
			else if (snakex == j && snakey == i)
			{
				cout << "O";
			}
			else if (foodx == j && foody == i)
			{
				cout << "o";
			}
			else
			{
				bool check = 0;
				for (int k=0; k < ntail; k++)
				{
					if (tailx[k] == j && taily[k] == i)
					{
						cout << "o";
						check = 1;
					}
				}
				if (check == 0)
				{
					cout << " ";
				}
			}
		}cout << endl;
	}cout << "Score: " << score;
}
void input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			direction = 'l';
			break;
		case 'w':
			direction = 'u';
			break;
		case 's':
			direction = 'd';
			break;
		case 'd':
			direction = 'r';
			break;
		default:
			break;
		}
	}
	
}
void logic()
{
	int prevx = tailx[0], prevy = taily[0], prev2x= snakex, prev2y= snakey;
	switch (direction)
	{
	case 'l':
		snakex--;
		break;
	case 'u':
		snakey--;
		break;
	case 'd':
		snakey++;
		break;
	case 'r':
		snakex++;
		break;
	default:
		break;
	}
	if (ntail > 0)
	{
		if (snakex == tailx[0] && snakey == taily[0])
		{
			switch (direction)
			{
			case 'l':
				snakex+=2;
				direction = 'r';
				break;
			case 'u':
				snakey+=2;
				direction = 'd';
				break;
			case 'd':
				snakey-=2;
				direction = 'u';
				break;
			case 'r':
				snakex-=2;
				direction = 'l';
				break;
			default:
				break;
			}
		}
	}
	tailx[0] = prev2x;
	taily[0] = prev2y;
	for (int i = 1; i < ntail+1; i++)
	{
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;
	}
	if (snakex == foodx && snakey == foody)
	{
		ntail++;
		score += 5;
		foodx = rand() % 28+1;
		foody = rand() % 18+1;
		
	}
	if (snakex <= 0)
		snakex = width - 1;
	else if (snakex >= width - 1)
		snakex = 1;

	if (snakey <= 0)
		snakey = height - 1;
	else if (snakey >= height - 1)
		snakey = 1;
}
void main()
{
	while (!gameover)
	{
		design();
		input();
		logic();
	}_getch();
}