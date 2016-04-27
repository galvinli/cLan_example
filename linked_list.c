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

void insertNode( node* aNode, node* bNode, node* newNode){
	
	if(aNode)
		aNode->next=newNode;

	while(newNode->next != NULL){
		newNode=newNode->next;
	//	printf("newNode date:%d\n", newNode->date);
	}

	if(newNode->next == NULL){
		newNode->next=bNode;
	}else{
		printf("fail to insertNode\n");
	}	

}

void showNode(const node* p){
	printf("%d ", p->date);
}

int main(){
	node *pHead=NULL;
	node *pHead2=NULL;
	node *p=NULL;
	int i=0;

	/*Not only number. Add date list you want.*/
	for(i=4;i>0;i--){	
	pHead=createNode(i,pHead);
	}
	
	for(i=10;i>5;i--){
	pHead2=createNode(i,pHead2);
	}

	p=pHead->next;
	insertNode(p, p->next, pHead2);

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
	printf("pHead offest date be: %d\n", pHead->next->next->next->date);
	
	p=pHead;

	/*delete*/
	while(p != NULL){
		node *pTmp = p;
		p = p->next;
		free(pTmp);
	}

	
}
