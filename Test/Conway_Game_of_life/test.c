#include <stdio.h>
#define Total_Generations 12
#define DEAD 0
#define ALIVE 1
#define MAXROW 20
#define MAXCOL 20
#define ORIGINAL_LIVES 10//初始化的生命数

char newMap[MAXROW][MAXCOL];

void main()
{
	int row, col;
	initEnv();//初始化环境
	int i = 0;
	while(i < Total_Generations)
	{
		printf("\nGeneration %d\n", i+1);
		i++;
		outputMap();
		for(row = 0; row < MAXROW; row++)//计算下一代
		{
			for(col = 0; col < MAXCOL; col++)
			{
				switch(neighbors(row,col))
				{
					//周围有0，1，4，5，6，7，8个细胞时 该细胞都会死亡
					case 0:newMap[row][col] = DEAD;break;
					case 1:newMap[row][col] = DEAD;break;
					case 4:newMap[row][col] = DEAD;break;
					case 5:newMap[row][col] = DEAD;break; 
					case 6:newMap[row][col] = DEAD;break;
					case 7:newMap[row][col] = DEAD;break; 
					case 8:newMap[row][col] = DEAD;break;

					//周围有两个细胞 保持不变
					case 2:newMap[row][col] = newMap[row][col];break;

					//周围有3个细胞 变为存活
					case 3:newMap[row][col] = ALIVE;break;



				}
			}
		}

	}
}

void initEnv(void)//环境初始化
{
	int row,col;

	for(row = 0; row < MAXROW; row++)
		for(col = 0; col < MAXCOL; col++)
		{
			newMap[row][col] = DEAD;//一开始都处于死亡状态
		}

	puts("Game of Life Simulation");//使用puts可以自动换行

	int j = 0;
	while(j < ORIGINAL_LIVES)
	{
		row = arc4random()%MAXROW;//随机产生一个0 到 MAXROW-1 之间的数
		col = arc4random()%MAXCOL;
		if( (row >= 0) && (row < MAXROW) && (col >= 0) && (col < MAXCOL) )
		{
			newMap[row][col] = ALIVE;
		}
		else if( (row < 0) | (col < 0))
			break;
		else
			printf("(x,y) exceeds map range");

		j++;

	}

}

int neighbors(int row, int col)//判断邻居生存数目
{
	int count = 0;
	int c,r;

	for(r = row-1; r < row+1; r++)
		for(c = col -1; c < col+1; c++)
		{
			if( (r < 0) | (r >= MAXROW) | (c < 0) | (c >= MAXCOL) )
				continue;//对于边缘的元素 可能出现负值或者超过最大范围 继续就可以
			if(newMap[r][c] == ALIVE)
				count++;
		}

	if(newMap[row][col] == ALIVE)//如果要检测的元素本身是ALIVE，最后的结果应该减去
		count--;
	return count;
}

void outputMap()
{
	int row,col;
	printf("Game of Life Status");
	for(row = 0; row < MAXROW; row++)
	{
		printf("\n%20c",' ');
		for(col = 0; col < MAXCOL; col++)
		{
			if(newMap[row][col] == ALIVE)
				putchar('0');
			else	putchar('-');
		}
	}
}



