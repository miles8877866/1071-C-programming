#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
srand( time(NULL) );
int a=1,b=0,d,e;
int c[10] = {0};
for(a=0;a<=9;a++)
{


        b=(rand()%31)+20;
        while(b%3==0||b%4==0)
        {
        b=( rand( )%31)+20;
        }
        for(e=0;e<=a;e++)
        if(c[e]==b)
        {
            while(c[e]==b)
            {
                b=(rand()%31)+20;
                while(b%3==0||b%4==0)
                {
                    b=( rand( )%31)+20;
                }
            }
            c[a]==b;
        }
        else
        c[a]=b;






    printf("%d " ,c[a]);
}
return 0;
}
