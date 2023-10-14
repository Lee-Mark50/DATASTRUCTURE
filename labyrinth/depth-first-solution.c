#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// 算法不错，小改一波最短寻路、
// 由于深度优先搜索对于寻路而言要联通，此处需要重写graph，暂时为了可读性不用邻接表
/* 
 ————————————————————
| |
| |
| |
| |——————
|        |
|		 |
|        ————————————
|
|
|____________________

*/
#define rowSize 10
#define lineSize 10

int Map[10][10] =
{
	{ 0,0,0,0,0,0,0,0,0,0 }, //0行 
	{ 0,1,1,0,1,1,1,0,1,0 }, //1行
	{ 0,1,1,0,1,1,1,0,1,0 }, //2行
	{ 0,1,1,1,1,0,0,1,1,0 }, //3行  
	{ 0,1,0,0,0,1,1,1,1,0 }, //4行  
	{ 0,1,1,1,0,1,1,1,1,0 }, //5行
	{ 0,1,0,1,1,1,0,1,1,0 }, //6行
	{ 0,1,0,0,0,1,0,0,1,0 }, //7行
	{ 0,1,1,1,1,1,1,1,1,0 }, //8行
	{ 0,0,0,0,0,0,0,0,0,0 }  //9行
};

int distance(int x, int y){
	return sqrt(x)+sqrt(y);
}

int dfs(int i, int j,int visited[10][10],int EndX, int EndY)
{
	if (i == EndX && j == EndY)//首先判断给的起始点是否为终点
	{
		printf("(%d , %d)", i, j);
		return 0;
	}
	else
	{
	visited[i][j] = 1;
	for(int k=i+1;k<10;k++){
		if (!visited[k][j] && distance(k,j) < distance(i,j))
		{
		visited[k][j] = 1;
		printf("(%d,%d)", k , j );
		}
		else if(visited[k][j] || distance(k,j) > distance(k,j)){
			continue;
		}
	}
	}
	// if (!visited[i + 1][j] && Map[i + 1][j] == 1)
	// {
	// 	if (dfs(i + 1, j, visited))
	// 	{
	// 		printf(" <- (%d , %d)", i, j);
	// 		return 1;
	// 	}
	// }
	// if (!visited[i][j + 1] && Map[i][j + 1] == 1) 
	// {
	// 	if (dfs(i, j + 1, visited))
	// 	{
	// 		printf(" <- (%d , %d)", i, j);
	// 		return 1;
	// 	}
	// }
	// if (!visited[i - 1][j] && Map[i - 1][j] == 1)
	// {
	// 	if (dfs(i - 1, j, visited))
	// 	{
	// 		printf(" <- (%d , %d)", i, j);
	// 		return 1;
	// 	}
	// }
	// if (!visited[i][j - 1] && Map[i][j - 1] == 1) 
	// {
	// 	if (dfs(i, j - 1, visited))
	// 	{
	// 		printf(" <- (%d , %d)", i, j);
	// 		return 1;
	// 	}
	// }
	return 0;
}

int main(void)
{
	int visited[rowSize][lineSize] = { 0 };
	dfs(1, 1, visited, 9, 9);
	return 0;
}
