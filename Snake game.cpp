#include<bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100];
int nTail;
enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;
void Setup()
{
    gameOver = true;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{

    system("cls"); //system("clear");
    for (int i = 0; i < width+2; ++i)
        printf(".");
    puts("");

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            if (j == 0)
                printf(".");
            if (i == y && j == x)
                printf("O");
            else if (i == fruitY && j == fruitX)
                printf("F");
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; ++k)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        printf("o");
                        print = true;
                    }
                }
                if (!print)
                    printf(" ");
            }


            if (j == width - 1)
                printf(".");
        }
        puts("");

    }

    for (int i = 0; i < width+2; i++)
        printf(".");
    puts("");
    printf("Score: %d\n",score);
    printf("\n\nPress x for stop the game\n");
}
void Input()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'l':
            dir = LEFT;
            break;
        case 'r':
            dir = RIGHT;
            break;
        case 'u':
            dir = UP;
            break;
        case 'd':
            dir = DOWN;
            break;
        case 'x':
            gameOver = false;
            puts("\n\nGame is over\n");
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    //if (x > width || x < 0 || y > height || y < 0)
    //	gameOver = true;
    if (x >= width) x = 0;
    else if (x < 0) x = width - 1;
    if (y >= height) y = 0;
    else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
}
int main()
{
    Setup();
    while (gameOver)
    {
        Draw();
        Input();
        Logic();
        Sleep(300);
    }

    return 0;
    getch();
}

