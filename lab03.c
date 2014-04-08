/* This program is made to solve the problem of the practice 1 in the textbook page 170.
    Sang Min Yoon
	The School of Computer Science, KOOKMIN UNIVERSITY
	2012.09.25
*/

/*
����Ʈ���� ���� ���� ���� Git Test ���Դϴ�. . .
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 101

typedef struct stack{
 char data;
 struct stack *link;
}stack;

stack *top;

void push(char string);
void pop(char string, int i);

int main(void)
{
	int i;
	char string[30]; //������ ���ڿ��� �ִ� ũ�� ����
	top=NULL;

	puts("���ڿ��� �Է��Ͻÿ� : ");
	fgets(string,sizeof(string),stdin); //stream���κ��� ���ڿ��� �޾� string�� ����

	for(i=0 ; i < (strlen(string)) ; i++)
    push(string[i]);//�Էµ� ���ڿ��� �ѱ��ھ� ���ؿ� �Ѱܼ� ����

 	for(i=0; i<(strlen(string)-1); i++) // �Էµ� ���ڿ��� ���ÿ� �ִ� ���ڵ��� �� ���ھ� ��
	{
		pop(string[i],i);
	}
	printf("ȸ���� �½��ϴ�.\n");
}


void push(char string)
{
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data=string;
	temp->link = top;
	top=temp;
}

void pop(char* string, int i) //string�� ���ڿ��� i���ڿ��� ���̸� pop�� ����
{
	stack *temp;

	temp = top;
	top = top->link;

	if(temp->link->data != string)
	{	
		printf("ȸ���� �ƴմϴ�\n");
		exit(1);
	}

	free(temp);
}

