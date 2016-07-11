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

void pushBack( node* pre_Node, node* new_Node){

	while(pre_Node->next != NULL){
		pre_Node=pre_Node->next;
		DEBUG_PRINT("per_Node date:%d\n", pre_Node->date);
	}

	pre_Node->next=new_Node;
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
	}else
	    printf("fail to insertNode\n");
		

}

node* pushFront( node* pre_Node, node* newNode ){

	while(newNode->next != NULL){
		newNode=newNode->next;
		DEBUG_PRINT("newNode date:%d\n", newNode->date);
	}

	if(pre_Node != NULL){
	    if(newNode->next == NULL)
	        newNode->next = pre_Node;
	    else
	        printf("faile to insertNode\n");

	}
	else
		printf("Invalid Node %s\n", __func__);

        return newNode;
}

node* eraseFront(node* per_Node){
	node *p=NULL;

	if(per_Node != NULL){
	   p=per_Node->next;
	   free(per_Node);
	}
	else
	  printf("Invalid Node %s\n.", __func__);

	return p;
		
}

void eraseBack(node* pNode){
	node *pTmp=NULL;

	while(pNode->next != NULL){
		pTmp=pNode;
		pNode=pNode->next;
		DEBUG_PRINT("pTmp date:%d\n", pTmp->date);
		DEBUG_PRINT("per_Node date:%d\n", pNode->date);
	}

	pTmp->next=NULL;
	free(pNode);
	
}

int main(){
	node *pHead=NULL, *pHead2=NULL, *pHead3=NULL, \
		*pHead4=NULL;
	node *p=NULL;
	int i=0;

	/*Not only number. Add data as you wish .*/
/*pHead create*/	
	for(i=5;i>0;i--)	
	    pHead=createNode(i,pHead);
	DEBUG_PRINT("pHead: ");SHOW_NOTE(pHead);
	
	if(pHead == NULL)
	    printf("pHead linked fail\n");
/*pHead2 create*/	
	for(i=10;i>5;i--)
	    pHead2=createNode(i,pHead2);
	DEBUG_PRINT("pHead2: ");SHOW_NOTE(pHead2);
	
	if(pHead2 == NULL)
	    printf("pHead2 linked fail\n");
/*pHead3 create*/
	for(i=15;i>10;i--)
	    pHead3=createNode(i,pHead3);
	DEBUG_PRINT("pHead3: ");SHOW_NOTE(pHead3);
	
	if(pHead3 == NULL)
	    printf("linked fail\n");
/*pHead4 create*/
	    pHead4=createNode(16,pHead4);
	DEBUG_PRINT("pHead4: ");SHOW_NOTE(pHead4);
	
	if(pHead4 == NULL)
	    printf("linked fail\n");

/*Back Insertion*/
	pushBack(pHead, pHead2);

	printf("Node1 - Node2 - End\n");
	showNode(pHead);

/*Insert Node*/
	insertNode(pHead->next, pHead->next->next, pHead3);

	if(pHead == NULL)
	    printf("linked fail\n");

	printf("pre_Node1--Node3--end_Node1 - Node2 - End \n");	
	showNode(pHead);
	
	DEBUG_PRINT("pHead offest date be: %d\n", pHead->next->next->next->date);

/*Front Insertion*/
	pHead=pushFront(pHead, pHead4);
	printf("Hode4 - pre_Node1--Node3--end_Node1 - Node2 - End \n");	
	showNode(pHead);
	
/*Front Erase*/
	pHead=eraseFront(pHead);
	printf("pre_Node1--Node3--end_Node1 - Node2 - End \n");	
	showNode(pHead);

/*Back erasing*/
	eraseBack(pHead);
	printf("pre_Node1--Node3--end_Node1 - Node2..() - End \n");
	showNode(pHead);
	
	p=pHead;

	/*delete*/
	while(p != NULL){
		node *pTmp = p;
		p = p->next;
		free(pTmp);
	}

}
