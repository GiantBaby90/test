#include<conio.h>
#include<stdio.h>
#define N 6

int queue[N]={0};
int rear=0,front=0;

void insert(void);
void del(void);
void disp(void);
void cre(void);

void main()
{
    int user=0;

    clrscr();
    while(user!=4)
      {
        clrscr();
        printf("\n\n\n\t\t\t THE SIZE OF QUEUE IS %d",N);
        printf("\n\t 1.INSERT");
        printf("\n\t 2.DELETE");
        printf("\n\t 3.DISPLAY");
        printf("\n\t 4.EXIT");
        printf("\n\t 5.CREATE");
        scanf("%d",&user);
        switch(user)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                disp();
                break;
            case 4:
                printf("\n\t THANK U");
                break;
            case 5:
                cre();
                break;
        }
        getch();

      }
    getch();
}



/*********************insert********************/
void insert(void)
{
    int t;
    if(rear<N)
    {
        printf("\n\t ENTER A VALUE IN QUEUE");
        scanf("%d",&t);
        queue[rear]=t;
        rear++;
    }
    else
    {
        printf("\n\t Q OVERFLOW!!!!!!!!!!!!!!!");
    }
}
void del(void)
{
    int i;
	printf("\n\t %d gets deleted.........",queue[front]);
	queue[front]=0;
    front++;
}

void disp(void)
{
    int i;
    for(i=front;i<rear;i++)
    {
        printf("\n\t %d",queue[i]);
    }
}
void cre(void)
{

    int t;
    printf("\n\t ENTER A VALUE IN QUEUE");
    scanf("%d",&t);
    front=0;
    queue[front]=t;
    rear=front+1;
}
