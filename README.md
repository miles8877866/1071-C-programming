# 1071-C-programming

w01

*welcome.cpp
*roots.cpp
*temp.cpp

w02

*year.cpp
*time.cpp
             
#include<stdio.h>


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
