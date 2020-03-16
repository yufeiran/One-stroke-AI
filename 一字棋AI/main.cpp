#include <iostream>

using namespace std;

struct ChessMap
{
	int DATA[3][3] = { 0 };
};
ChessMap NowMap;

void DrawMap()
{
	cout <<" ----------- " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "|";
		for (int j = 0; j < 3; j++)
		{
			
			if (NowMap.DATA[i][j] != 0)
			{
				cout <<" "<< ((NowMap.DATA[i][j] == 1) ? 'O' : 'X') << " |";

			}
			else
			{
				cout << "   |";
			}
		}
		cout <<endl;
		cout << " ----------- " << endl;
	}

}

bool PutChess(int x, int y, int type,ChessMap &map)
{
	if (x < 0 || x>2 || y < 0 || y>2)
	{
		cout << "Wrong place!" << endl;
		return false;
	}
	if (map.DATA[y][x] == 0)
	{
		map.DATA[y][x] = type;
		return true;
	}
	cout << "This place already have chess!" << endl;
	return false;
}

void CleanMap()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			NowMap.DATA[i][j] = 0;
		}
	}
}

bool IsTypeWin(ChessMap& map,int type)
{
	for (int i = 0; i < 3; i++)
	{
		if (map.DATA[i][0] != 0 && (map.DATA[i][0] == map.DATA[i][1]) && (map.DATA[i][1] == map.DATA[i][2]))
		{
			if (map.DATA[i][0] == type)
			{
				return true;
			}
		}
		else if (map.DATA[0][i] != 0 && (map.DATA[0][i] == map.DATA[1][i]) && (map.DATA[1][i] == map.DATA[2][i]))
		{
			if (map.DATA[0][i] == type)
			{
				return true;
			}
		}
	}
	if (map.DATA[0][0] != 0 && (map.DATA[0][0] == map.DATA[1][1]) && (map.DATA[1][1] == map.DATA[2][2]))
	{
		if (map.DATA[0][0] == type)
		{
			return true;
		}
	
	}
	if (map.DATA[0][2] != 0 && (map.DATA[0][2] == map.DATA[1][1]) && (map.DATA[1][1] == map.DATA[2][0]))
	{
		if (map.DATA[0][2] == type)
		{
			return true;
		}
	}

	//

	return false;
}

bool IsGameOver(ChessMap& map)
{
	for (int i = 0; i < 3; i++)
	{
		if (map.DATA[i][0]!=0&&(map.DATA[i][0] == map.DATA[i][1])&&(map.DATA[i][1]== map.DATA[i][2]))
		{
			if (map.DATA[i][0] == 1)
			{
				cout << "O WIN!" << endl;
				return true;
			}
			else {
				cout << "X WIN!" << endl;
				return true;
			}
		}
		else if (map.DATA[0][i]!=0&& (map.DATA[0][i] == map.DATA[1][i]) && (map.DATA[1][i] == map.DATA[2][i]))
		{
			if (map.DATA[0][i] == 1)
			{
				cout << "O WIN!" << endl;
				return true;
			}
			else {
				cout << "X WIN!" << endl;
				return true;
			}
		}
	}
	if (map.DATA[0][0] != 0 && (map.DATA[0][0] == map.DATA[1][1])&&(map.DATA[1][1] == map.DATA[2][2]))
	{
		if (map.DATA[0][0] == 1)
		{
			cout << "O WIN!" << endl;
			return true;
		}
		else {
			cout << "X WIN!" << endl;
			return true;
		}
	}
	if (map.DATA[0][2] != 0 && (map.DATA[0][2] == map.DATA[1][1])&&(map.DATA[1][1] == map.DATA[2][0]))
	{
		if (map.DATA[0][2] == 1)
		{
			cout << "O WIN!" << endl;
			return true;
		}
		else {
			cout << "X WIN!" << endl;
			return true;
		}
	}
	
	//

	int chessCount = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (map.DATA[i][j] != 0)
			{
				chessCount++;
			}
		}
	}
	if (chessCount == 9)
	{
		cout << "DRAW!" << endl;
		return true;
	}
	return false;
}


int N(int type,ChessMap &map)
{
	int count = 0;
	bool haveOurChessFlag;
	bool haceEnemyChessFlag;
	for (int i = 0; i < 3; i++)
	{
		//行扫描，至少有一个自己的棋子，不可以有对方棋子，则满足条件
		haveOurChessFlag = false;
		haceEnemyChessFlag = false;
		for (int j = 0; j < 3; j++)
		{
			if (map.DATA[i][j] == type)
			{
				haveOurChessFlag = true;
			}
			else if (map.DATA[i][j] != 0)
			{
				haceEnemyChessFlag = true;
			}
		}
		if (haceEnemyChessFlag == false && haveOurChessFlag == true)
		{
			count++;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		//对角线扫描，至少有一个自己的棋子，不可以有对方棋子，则满足条件
		haveOurChessFlag = false;
		haceEnemyChessFlag = false;
		for (int j = 0; j < 3; j++)
		{
			if (map.DATA[j][i] == type)
			{
				haveOurChessFlag = true;
			}
			else if (map.DATA[j][i] != 0)
			{
				haceEnemyChessFlag = true;
			}
		}
		if (haceEnemyChessFlag == false && haveOurChessFlag == true)
		{
			count++;
		}
	}
	
	haveOurChessFlag = false;
	haceEnemyChessFlag = false;
	for (int j = 0; j < 3; j++)
	{
		if (map.DATA[j][j] == type)
		{
			haveOurChessFlag = true;
		}
		else if (map.DATA[j][j] != 0)
		{
			haceEnemyChessFlag = true;
		}
	}
	if (haceEnemyChessFlag == false && haveOurChessFlag == true)
	{
		count++;
	}

	haveOurChessFlag = false;
	haceEnemyChessFlag = false;
	for (int j = 0; j < 3; j++)
	{
		if (map.DATA[j][2-j] == type)
		{
			haveOurChessFlag = true;
		}
		else if (map.DATA[j][2-j] != 0)
		{
			haceEnemyChessFlag = true;
		}
	}
	if (haceEnemyChessFlag == false && haveOurChessFlag == true)
	{
		count++;
	}
	//cout << ((type == 1) ?  'O' : 'X') << "value is " << count << endl;
	//对于赢局面加权
	if (IsTypeWin(map,type))
		count += 10;
	return count;
}
int E(int type, ChessMap& map)
{
	int value = N(type, map) - N(type * -1, map);
	//cout << ((type == 1) ? 'O' : 'X') << "E value is " << value << endl;
	return value;
}


void AI(int type, ChessMap& map)
{
	int max = -999;
	int choiceX;
	int choiceY;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ChessMap NewMap = map;
			if (NewMap.DATA[i][j] == 0)
			{

				//cout << "Step 1 X" << j << " Y " << i << endl;
				int min = 999;
				
				PutChess(j, i, type, NewMap);

				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						if (NewMap.DATA[k][l] == 0)
						{
							//cout << "Step 2 X" << l << " Y " << k << endl;
							ChessMap New2Map = NewMap;
							int nowValue;
							PutChess(l, k, type * -1, New2Map);
							nowValue = E(type, New2Map);
							if (nowValue < min)
							{
								min = nowValue;
							}
						}
					}
				}
				if (min > max)
				{
					max = min;
					choiceX = j;
					choiceY = i;
				}
			}
		}

	}

	cout << "[AI] (x,y) " << choiceX+1 <<" "<<3-choiceY << endl;
	PutChess(choiceX, choiceY, type, NowMap);
}

void main()
{
	int nowTurn = -1;
	int x, y;
	int temp;
	while (1)
	{
		DrawMap();
		if (nowTurn == -1)
		{
			AI(-1, NowMap);
			//cout << "N " << N(-1, NowMap) << endl;
		}
		else
		{
			do
			{
				cout << "[" << ((nowTurn == 1) ? 'O' : 'X') << "]" << " (x,y) <<";
				cin >> temp;
				if (temp >= 10)
				{
					y = temp % 10;
					x = temp / 10;
				}
				else
				{
					x = temp;
					cin >> y;
				}
				x -= 1;
				y -= 1;
				y = 2 - y;

			} while (!PutChess(x, y, nowTurn, NowMap));
		}
		
		nowTurn *= -1;
		
		if (IsGameOver(NowMap))
		{
			DrawMap();
			CleanMap();
		}
		
	}
}