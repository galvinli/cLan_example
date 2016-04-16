#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node{
	int date;
	struct Node *next;
}node;

node* createNode(int date, node* pNode){
	//node x = {date, pNode};
	printf("date:%d \n", date);
	node *p = (node *)malloc(sizeof(node));

	if(p == NULL){
		printf("fail to allocate mrmory.\n");
	}

	p->date = date;
	p->next = pNode;
	return p;
}

void showNode(const node* p){
	printf("%d ", p->date);
}

int main(){
	node *pHead=NULL;
	node *p=NULL;
	int i=0;

	for(i=4;i>0;i--){
	pHead=createNode(i,pHead);
	}

	/*
	pHead=createNode(4, pHead);
	printf("pHead->Date: %d\n", pHead->date);
	pHead=(node *)createNode(3, pHead);
	printf("pHead->Date: %d\n", pHead->date);
	*/

	if(pHead == NULL)
		printf("linked fail\n");
	
	p=pHead;
	printf("start linked list\n");	
	while(p != NULL){
		showNode(p);
		p=p->next;
	}
	printf("\n");
	
	p=pHead;
	while(p != NULL){
		node *pTmp = p;
		p = p->next;
		free(pTmp);
	}

	
}
