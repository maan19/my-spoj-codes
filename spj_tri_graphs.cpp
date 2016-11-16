#include<stdio.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int data[1000005][3];
int memo[1000005][3];
int rows;
 int f_min(int row,int col);
int main()
{
	
	scanf("%d",&rows);
	int k=1;

	while(rows!=0)
	{
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<3;j++)
				{
					scanf("%d",&data[i][j]);
					memo[i][j]=-1;
			}
		}

		printf("%d. %d\n",k++,f_min(0,1));
		scanf("%d",&rows);

	}
}

 int f_min(int row,int col)
{
	if(row==rows-1 && col == 1)
		return data[row][col];
	if(row==rows-1 && col == 0)
		return data[row][col] + data[row][1];
	if(row==rows-1&&col==2)
		return INT_MAX;

	if(memo[row][col]!=-1)
		return memo[row][col];
	 
	int x,y,z,t;
	x = y = z=t =INT_MAX;

	if(col==0)
	{
		
		x = f_min(row+1,col);y=f_min(row+1,col+1);z=f_min(row,col+1);
	}

	else if(col==1)
	{
		
		
			x = f_min(row+1,0);y=f_min(row+1,1);z=f_min(row+1,2);t=f_min(row,2);
	
	}
	else
	{
		    
				x= f_min(row+1,2); y = f_min(row + 1,1); 
			

			
	}
	
	


	return ((memo[row][col]=data[row][col]+ min(min(min(x,y),z),t)));
}
