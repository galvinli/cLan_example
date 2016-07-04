#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(fmt, args...)    printf(fmt, ##args)
#define SHOW_NOTE(x)	showNode(x)
#else
#define DEBUG_PRINT(fmt, args...)    /* Don't do anything in release builds */
#define SHOW_NOTE(x)
#endif
typedef struct Node{
	int date;
	struct Node *next;
}node;

node* createNode(int date, node* pNode){
	node *p = (node *)malloc(sizeof(node));

	if(p == NULL){
		printf("fail to allocate mrmory.\n");
	}

	p->date = date;
	p->next = pNode;
	return p;
}

void showNode(const node* p){
	while(p != NULL){
	    printf("%d ", p->date);
	    p=p->next;
	}
	printf("\n");
}

void addNode( node* pre_Node, node* new_Node){
	node *p=NULL;
	p=pre_Node;

	while(p->next != NULL){
		p=p->next;
	}	

	if(p->next == NULL)
	    p->next=new_Node;
}

void insertNode( node* aNode, node* bNode, node* newNode){
	
	if(aNode)
		aNode->next=newNode;

	while(newNode->next != NULL){
		newNode=newNode->next;
		DEBUG_PRINT("newNode date:%d\n", newNode->date);
	}

	if(newNode->next == NULL){
		newNode->next=bNode;
	}else{
		printf("fail to insertNode\n");
	}	

}

int main(){
	node *pHead=NULL;
	node *pHead2=NULL;
	node *pHead3=NULL;
	node *p=NULL;
	int i=0;

	/*Not only number. Add date list you want.*/
	for(i=5;i>0;i--)	
	    pHead=createNode(i,pHead);
	DEBUG_PRINT("pHead: ");SHOW_NOTE(pHead);
	
	if(pHead == NULL)
	    printf("pHead linked fail\n");

	for(i=10;i>5;i--)
	    pHead2=createNode(i,pHead2);
	DEBUG_PRINT("pHead2: ");SHOW_NOTE(pHead2);
	
	if(pHead2 == NULL)
	    printf("pHead2 linked fail\n");

/*Add Node*/
	addNode(pHead, pHead2);

	printf("Node1 - Node2 - End\n");
	showNode(pHead);

	for(i=15;i>10;i--)
	    pHead3=createNode(i,pHead3);
	DEBUG_PRINT("pHead3: ");SHOW_NOTE(pHead3);
	
	if(pHead3 == NULL)
	    printf("linked fail\n");

/*Insert Node*/
	insertNode(pHead->next, pHead->next->next, pHead3);

	if(pHead == NULL)
	    printf("linked fail\n");

	printf("pre_Node1--Node3--end_Node1 - Node2 - End \n");	
	showNode(pHead);
	
	DEBUG_PRINT("pHead offest date be: %d\n", pHead->next->next->next->date);
	
	p=pHead;

	/*delete*/
	while(p != NULL){
		node *pTmp = p;
		p = p->next;
		free(pTmp);
	}

}
