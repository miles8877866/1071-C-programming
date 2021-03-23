#include <stdio.h>
#include <stdlib.h>
#define num 8
#define start 4
void print(int d[],int pre[],int S[]);
int findMin(int d[],int S[]);

int main ()
{

    int A[num][num]=
    {
            0,99999,99999,99999,99999,99999,99999,99999,
          300,    0,99999,99999,99999,99999,99999,99999,
         1000,  800,    0,99999,99999,99999,99999,99999,
        99999,99999, 1200,    0,99999,99999,99999,99999,
        99999,99999,99999, 1500,    0,  250,99999,99999,
        99999,99999,99999, 1000,99999,    0,  900, 1400,
        99999,99999,99999,99999,99999,99999,    0, 1000,
         1700,99999,99999,99999,99999,99999,99999,    0,
    };
    int d[num],pre[num],T[num],S[num];
    for(int i=0; i<num; i++)
    {
        d[i]=99999;
        pre[i]=-1;
        T[i]=0;
        S[i]=-1;
    }
    d[start]=0;
    pre[start]=-1;


    print(d,pre,S);
    for(int k=0; k<num; k++)
    {
        int j=findMin(d,T);
        for(int i=0; i<num; i++)
        {
            if(A[j][i]!=99999)
            {
                if(d[i]>(d[j]+A[j][i]))
                {
                    d[i]=d[j]+A[j][i];
                    pre[i]=j;
                }
            }
            T[j]=1;
            S[k]=j;
        }
        print(d,pre,S);
    }
}


int findMin(int d[],int T[])
{
    int min=99999;
    int minnum;
    for(int i=0; i<num; i++)
    {
        if(d[i]<min&&T[i]!=1)
        {
            min=d[i];
            minnum=i;
        }
    }
    return minnum;
}

void print(int d[],int pre[],int S[])
{
    printf("d[v]    = ");
    for(int i=0; i<num; i++)
    {
        printf(" %5d ",d[i]);
    }
    printf("\n");

    printf("prev[v] = ");
    for(int i=0; i<num; i++)
    {
        if(pre[i]==-1)
            printf("     x ");
        else if(pre[i]==-1)
            printf("     u ");
        else
            printf(" %5d ",pre[i]);
    }
    printf("\n");

    printf("S       = ");
    for(int i=0; i<num; i++)
    {
        if(S[i]==-1)
            break;
        printf(" %5d ",S[i]);
    }

    printf("\n");
    printf("\n");

}


