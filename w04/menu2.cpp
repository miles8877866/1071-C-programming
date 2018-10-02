#include<stdio.h>

void prchar(char c,int n){
for(int i=1;i<=n;i++)
printf("%c",c);}

void drowrect(int height, int width, int filled)
{
    if(filled)
    {
        for(int i=1; i<=height; i++)
        {
            for(int j=1; j<=width; j++)

            {
                printf("*",i,j);
            }
            printf("\n");

        }
    }

    else
    {
        for(int i=1; i<=height; i++)
        {
            for(int j=1; j<=width; j++)
            {
                if(i==1 || i==height || j==1 || j==width)
                    printf("*");
                else
                    printf(" ");
            }
            printf("\n");
        }
    }

}
void drowvert


int main()
{
    int choice;
    int height;
    int width;
    int type;
    int filled;

    while(1)
    {
        printf("Main menu\n");
        printf("1. Rectangle\n");
        printf("2. Vertical triangle\n");
        printf("3. Exits\n");
        printf("=> ");
        scanf("%d", &choice);
        if(choice==3)
            break;
        switch(choice)
        {
        case 1:
            printf("Enter height,width,filled: ");
            scanf("%d %d %d", &height, &width, &filled);
            drowrect(height, width, filled);
            break;
        case 2:
            switch(type)
            {
            case 1:
                printf("Enter height and type,filled: ");
                scanf("%d %d", &height, &type, &filled);
                drowvert(height, type, filled);
                break;
            case 2:

                break;
            case 3:

                break;
            case 4:

                break;
            }

        }
    }


    return 0;
}
