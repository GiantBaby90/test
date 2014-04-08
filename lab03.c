/* This program is made to solve the problem of the practice 1 in the textbook page 170.
    Sang Min Yoon
	The School of Computer Science, KOOKMIN UNIVERSITY
	2012.09.25
*/

/*
소프트웨어 공학 수업 관련 Git Test 중입니다. . .
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
	char string[30]; //저장할 문자열의 최대 크기 지정
	top=NULL;

	puts("문자열을 입력하시오 : ");
	fgets(string,sizeof(string),stdin); //stream으로부터 문자열을 받아 string에 저장

	for(i=0 ; i < (strlen(string)) ; i++)
    push(string[i]);//입력된 문자열을 한글자씩 스텍에 넘겨서 저장

 	for(i=0; i<(strlen(string)-1); i++) // 입력된 문자열과 스택에 있는 글자들을 한 글자씩 비교
	{
		pop(string[i],i);
	}
	printf("회문이 맞습니다.\n");
}


void push(char string)
{
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data=string;
	temp->link = top;
	top=temp;
}

void pop(char* string, int i) //string의 문자열과 i문자열의 길이를 pop에 받음
{
	stack *temp;

	temp = top;
	top = top->link;

	if(temp->link->data != string)
	{	
		printf("회문이 아닙니다\n");
		exit(1);
	}

	free(temp);
}

