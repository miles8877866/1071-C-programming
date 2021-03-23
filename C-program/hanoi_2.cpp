#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<stdio.h>
#include<string.h>

#define Width(N) 220-20*(N)		/*?��????N��?�l��?��*/
#define H 20					/* �C??�l������*/
#define LINE 180				/*?�l��?���W���?*/
#define MAX 9					/*?�l���̤j?�ءA�Ѥ_�t�mɬ���A?��?�j���৹��?��*/
#define DOWN 580				/*?�l�������?*/
/*-------����?�q-------------------------*/

int a[3]={0,0,0};				/*�s?A,B,C�W�l��?�e?�l?��*/

int findNum(char c)				
{
	switch(c)
	{
		case 'A':return 0;break;
		case 'B':return 1;break;
		case 'C':return 2;break;
	}
}

struct Rec						/*?�l���w?*/
{
	int number;
	int width;
	int left;
	int top;
	int right;
	int bottom;
};
struct Rec r[MAX];				/*?���ҳ̤j?�ت�?�l�A?�M�]�i�H??���t?�s�A?��?��?���A���O?�e?�����n,��?�쪺���i�H�ۤv��?*/
struct Area						/*�W�l���w?*/
{
	char name;					/*�W�l���W?*/
	int x;						/*???�쩳?��?��?��?*/
	int y;						/*???�쩳?��?��?��?*/
	struct Rec* recs[MAX];		/*�w?�̤j?�ت�?�l?��*/
	void Reduce()				/*�h���̤W��m��?�l*/
	{
		a[findNum(name)]--;
		recs[a[findNum(name)]]=NULL;
	}
	void Add(int n,int l,int t)	/*n??�l��??,l?��?left�At?��?top---???�l���K�[*/
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
struct Area A,B,C;				/*?���T?�W�l*/
void animation(int left,int top,int right,int bottom,int distance,char direction)/*???�l��?��??*/
/*left�Btop�Bright�Bbottom�O��?�Adistance�O��?�Z�á]�i�H??�^�Adirection?��V(X??�V�AY??�V)*/
{
	if(distance<=0)				/*�Ϥ�V??*/
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
			Sleep(5);	/*?��??�A�i�H�ק�*/
		}
	}
	else		/*����V��?*/
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
			Sleep(5);	/*?��??�A�i�H�ק�*/
		}
	}
}
void move(struct Area *c,struct Area *d)			/*???�l?c�W�l��d�W�l����?*/
{
	int number=a[findNum((*c).name)];
	int left=(*(*c).recs[number-1]).left;
	int top=(*(*c).recs[number-1]).top;
	int right=(*(*c).recs[number-1]).right;
	int bottom=(*(*c).recs[number-1]).bottom;
	int distance=LINE-top;
	animation(left,top,right,bottom,distance,'Y');	/*�V�W??��LINE?*/
	top=LINE;
	bottom=LINE+H;
	distance=(*d).x-(*c).x;
	animation(left,top,right,bottom,distance,'X');	/*?�V��?��d�W�l�����W��*/
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
	animation(left,top,right,bottom,distance,'Y');	/*��U?�l�bd�W�l�W*/
	(*d).Add((*(*c).recs[number-1]).number,left,top+distance);/*����??���Z�A?��d�W�l?�l���K�[�A�H��c�W�l�P�l���h��*/
	(*c).Reduce();
}
void hanoi(int n,struct Area *x,struct Area *y,struct Area *z) /*??��쫬��k*/
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
	printf("?�J?�r�]����j�_%d�^:",MAX);
	while(scanf("%d",&number))
	{
		if(number<MAX&&number>0)
		{
			break;
		}
		printf("?�A��?�J�ŦX�n�D��?�u:");
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
	/*�H�W��������?�q��?��*/
	for(int j=0;j<number;j++)
	{
		Rec r=(*A.recs)[j];
		setfillstyle(WHITE);
		bar(r.left,r.top,r.right,r.bottom);
	}
	/*�H�W?���???����?��*/
	hanoi(number,&A,&B,&C);
	getch();
	closegraph();
}
