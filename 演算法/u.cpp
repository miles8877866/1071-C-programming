#include <stdio.h>
#include <stdlib.h>


void Left(int start,int degree,int degree_total)
    {
        if(start<=degree)
        {
            degree_total=(degree-start)*9;
        }
        else
        {
            degree_total=360-((degree-start)*9);
        }
    }
    void Right(int start,int degree,int degree_total)
    {
        if(start<=degree)
        {
            degree_total=360-((degree-start)*9);
        }
        else
        {
            degree_total=(degree-start)*9;
        }

    }
int main()
{


    int start,d1,d2,d3;
    int degree=0;
        int degree_total=720;
    while(scanf("%d,%d,%d,%d",&start,&d1,&d2,&d3)!=EOF)
    {
        Right(start,d1,degree);
        degree_total=degree_total+degree;
        printf("%d\n",degree_total);
        degree_total=degree_total+180;
        printf("%d\n",degree_total);
        Left(d1,d2,degree);
        degree_total=degree_total+degree;
        Right(d2,d3,degree);
        degree_total=degree_total+degree;

        printf("%d\n",degree_total);
    }
}
