# 1071-C-programming

w01

*welcome.cpp
*roots.cpp
*temp.cpp

w02

*year.cpp
*time.cpp
             
#include<stdio.h>#include<stdio.h>


void prchar(char c,int n)
{
    for(int i=1; i<=n; i++)
        printf("%c",c);
}

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
void drawVer(int height, int type, int filled)
{
    switch(type)
    {
    case 1:
        if(filled)
        {
            for(int i=1; i<=height ; i++)
            {
                prchar('*',i);
                printf("\n");
            }
        }
        else
        {
            for(int i=1; i<=height; i++)
            {
                if(i==1 || i == height)
                {
                    prchar('*',i);
                }
                else
                {
                    printf("*");
                    prchar(' ',i-2);
                    printf("*");
                }
                printf("\n");
            }
        }break;
    case 2:
    	if(filled)
        {
            for(int i=1; i<=height ; i++)
            {
                prchar('*',height-i+1);
                printf("\n");
            }
        }
        else
        {
            for(int i=1; i<=height; i++)
            {
                if(i==1 || i == height)
                {
                    prchar('*',height-i+1);
                }
                else
                {
                    printf("*");
                    prchar(' ',height-i-1);
                    printf("*");
                }
                printf("\n");
            }
        }break;
    }
}

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
        		printf("Enter height, type, filled: ");
                scanf("%d %d %d", &height, &type, &filled);
        	switch(type)
            {
            case 1: 
				drawVer(height,type,filled);
				break;
			case 2:
				drawVer(height,type,filled);
				break;
            }

        }
    }


    return 0;
}
int main() {
	int choice;
	int height;
	int width;
	int type;

	while(1) {
		printf("Main menu\n");
		printf("1. Rectangle\n");
		printf("2. Vertical triangle\n");
		printf("3. Exits\n");
		printf("=> ");
		scanf("%d", &choice);
		if(choice==3)
			break;
		switch(choice) {
			case 1:
				printf("Enter height and width: ");
				scanf("%d %d", &height, &width);
				for(int i=1; i<=height; i++) {
					for(int j=1; j<=j; j++) {
						if(i==1 || i==height || j==1 || j==width)
							printf("*");
						else
							printf(" ");
					}
					printf("\n");
				}

				break;
			case 2:
				printf("Enter height and type: ");
				scanf("%d %d", &height, &type);
				if(type==1)
					for(int i=1; i<=height; i++)
				    {
						for(int j=1; j<=i; j++)
						{
							if(i==j || j==1 || i==height)
								printf("*");
							else
								printf(" ");
						}
						printf("\n");
					}
				break;
		}
	}


	return 0;
}
