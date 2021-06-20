#include <iostream>
#include <vector>

using namespace std;
vector<string> answer;		


const int MazeHeight = 8;
const int MazeWidth = 9;

char Maze[MazeHeight][MazeWidth + 1] =
{
	"#########",
	"#+++++++#",
	"#+###+#+#",
	"++#+++#+#",
	"###+#####",
	"###+#####",
	"###++++0#",
	"#########",
};                                                            


const char Wall = '#';
const char Free = '+';
const char Path = '|';
const char Start = '0';                                       


void printMaze();

void findStartingPoint(int& x, int& y);

bool Solve(int X, int Y);


int main()
{
	answer.clear();
	
	int startingX = 0, startingY = 0;
	
	findStartingPoint(startingX, startingY);

	if (Solve(startingX, startingY))
	{
		Maze[startingY][startingX] = Start;
		printMaze();

		for (int i = answer.size() - 1; i > 0; i--) 
		{
			cout << answer[i] << ' ';
		}
		cout << answer[0] << ' ';
		cout << endl;
	}
	else
	{
		cout << "not successful" << endl;
	}
	system("pause");
	return 0;
}


void printMaze()
{
	for (int Y = 0; Y < MazeHeight; Y++)
	{
		cout << Maze[Y] << endl;
	}
	cout << endl;
}

void findStartingPoint(int& x, int& y)
{
	for (int Y = 0; Y < MazeHeight; Y++)
	{
		for (int X = 0; X < MazeWidth; X++)
		{
			if (Maze[Y][X] == Start)
			{
				x = X;
				y = Y;
				return;
			}
		}
	}
}

bool Solve(int X, int Y)                                    
{
	Maze[Y][X] = Path;                                                         
	
	if (X == 0 || Y == 0 || X == MazeWidth - 1 || Y == MazeHeight - 1)              
	{
		return true;
	}

	if (X > 0 && Maze[Y][X - 1] == Free && Solve(X - 1, Y))                   
	{
		answer.push_back("left");
		return true;
	}

	if (X < MazeWidth - 1 && Maze[Y][X + 1] == Free && Solve(X + 1, Y))         
	{
		answer.push_back("right");
		return true;
	}

	if (Y > 0 && Maze[Y - 1][X] == Free && Solve(X, Y - 1))
	{
		answer.push_back("up");
		return true;
	}

	if (Y < MazeHeight - 1 && Maze[Y + 1][X] == Free && Solve(X, Y + 1))
	{
		answer.push_back("down");
		return true;
	}
	Maze[Y][X] = Free;         
                                             
	return false;
}