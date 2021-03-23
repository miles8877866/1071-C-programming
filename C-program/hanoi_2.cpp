#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
#include<string.h>

#define Width(N) 220-20*(N)		/*?算????N的?子的?度*/
#define H 20					/* 每??子的高度*/
#define LINE 180				/*?子移?的上基准?*/
#define MAX 9					/*?子的最大?目，由于配置优先，?目?大不能完全?行*/
#define DOWN 580				/*?子底部基准?*/
/*-------全局?量-------------------------*/

int a[3]={0,0,0};				/*存?A,B,C柱子的?前?子?目*/

int findNum(char c)				
{
	switch(c)
	{
		case 'A':return 0;break;
		case 'B':return 1;break;
		case 'C':return 2;break;
	}
}

struct Rec						/*?子的定?*/
{
	int number;
	int width;
	int left;
	int top;
	int right;
	int bottom;
};
struct Rec r[MAX];				/*?明所最大?目的?子，?然也可以??分配?存，?而?省?源，但是?前?有必要,有?趣的的可以自己改?*/
struct Area						/*柱子的定?*/
{
	char name;					/*柱子的名?*/
	int x;						/*???域底?中?的?坐?*/
	int y;						/*???域底?中?的?坐?*/
	struct Rec* recs[MAX];		/*定?最大?目的?子?目*/
	void Reduce()				/*去除最上位置的?子*/
	{
		a[findNum(name)]--;
		recs[a[findNum(name)]]=NULL;
	}
	void Add(int n,int l,int t)	/*n??子的??,l?坐?left，t?坐?top---???子的添加*/
	{
		r[n-1].number=n;
		r[n-1].width=Width(n);
		r[n-1].left=l;
		r[n-1].top=t;
		r[n-1].right=r[n-1].left+r[n-1].width;
		r[n-1].bottom=r[n-1].top+H;
		a[findNum(name)]++;
		recs[a[findNum(name)]-1]=&r[n-1];
	}
};
struct Area A,B,C;				/*?明三?柱子*/
void animation(int left,int top,int right,int bottom,int distance,char direction)/*???子移?的??*/
/*left、top、right、bottom是坐?，distance是移?距离（可以??），direction?方向(X??向，Y??向)*/
{
	if(distance<=0)				/*反方向??*/
	{
		for(int i=0;i<abs(distance);i++)
		{
			switch(direction)
			{
				case 'X':
					{
						setfillstyle(BLACK);
						bar(left-i,top,right-i,bottom);
						setfillstyle(WHITE);
						bar(left-i-1,top,right-i-1,bottom);
						break;
					}
				case 'Y':
					{
						setfillstyle(BLACK);
						bar(left,top-i,right,bottom-i);
						setfillstyle(WHITE);
						bar(left,top-i-1,right,bottom-i-1);
						break;
					}
			}
			Sleep(5);	/*?停??，可以修改*/
		}
	}
	else		/*正方向移?*/
	{
		for(int i=0;i<distance;i++)
		{
			switch(direction)
			{
				case 'X':
					{
						setfillstyle(BLACK);
						bar(left+i,top,right+i,bottom);
						setfillstyle(WHITE);
						bar(left+i+1,top,right+i+1,bottom);
						break;
					}
				case 'Y':
					{
						setfillstyle(BLACK);
						bar(left,top+i,right,bottom+i);
						setfillstyle(WHITE);
						bar(left,top+i+1,right,bottom+i+1);
						break;
					}
			}
			Sleep(5);	/*?停??，可以修改*/
		}
	}
}
void move(struct Area *c,struct Area *d)			/*???子?c柱子到d柱子的移?*/
{
	int number=a[findNum((*c).name)];
	int left=(*(*c).recs[number-1]).left;
	int top=(*(*c).recs[number-1]).top;
	int right=(*(*c).recs[number-1]).right;
	int bottom=(*(*c).recs[number-1]).bottom;
	int distance=LINE-top;
	animation(left,top,right,bottom,distance,'Y');	/*向上??到LINE?*/
	top=LINE;
	bottom=LINE+H;
	distance=(*d).x-(*c).x;
	animation(left,top,right,bottom,distance,'X');	/*?向移?到d柱子的正上方*/
	left+=distance;
	right+=distance;
	if(a[findNum((*d).name)]==0)
	{
		distance=(*d).y-LINE-H;
	}
	else 
	{
		distance=(*(*d).recs[a[findNum((*d).name)]-1]).top-LINE-H;
	}
	animation(left,top,right,bottom,distance,'Y');	/*放下?子在d柱子上*/
	(*d).Add((*(*c).recs[number-1]).number,left,top+distance);/*完成??之后，?行d柱子?子的添加，以及c柱子牌子的去除*/
	(*c).Reduce();
}
void hanoi(int n,struct Area *x,struct Area *y,struct Area *z) /*??塔原型算法*/
{
    if(n==1)
    {
		Sleep(2);
		move(x,z);
    } 
	else
    {
        hanoi(n-1,x,z,y);
		Sleep(2);
		move(x,z);
        hanoi(n-1,y,x,z);
    }
}

void main()
{
	int number;
	printf("?入?字（不能大于%d）:",MAX);
	while(scanf("%d",&number))
	{
		if(number<MAX&&number>0)
		{
			break;
		}
		printf("?再次?入符合要求的?据:");
	}
	initgraph(800, 640);		
	A.name='A';
	A.x=140;
	A.y=DOWN;
	B.name='B';
	B.x=400;
	B.y=DOWN;
	C.name='C';
	C.x=660;
	C.y=DOWN;
	a[findNum(A.name)]=0;
	a[findNum(B.name)]=0;
	a[findNum(C.name)]=0;
	for(int i=1;i<=number;i++)
	{
		int x=Width(i);
		A.Add(i,A.x-x/2,A.y-i*H);
	}
	a[findNum(A.name)]=number;
	/*以上完成全局?量的?值*/
	for(int j=0;j<number;j++)
	{
		Rec r=(*A.recs)[j];
		setfillstyle(WHITE);
		bar(r.left,r.top,r.right,r.bottom);
	}
	/*以上?行初???面的?制*/
	hanoi(number,&A,&B,&C);
	getch();
	closegraph();
}
