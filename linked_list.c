#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define DEBUG
#ifdef DEBUG
#define DEBUG_PRINT(fmt, args...)    printf("[%s:] "fmt, __func__, ##args)
#define SHOW_NOTE(x)	showNode(x)
#else
#define DEBUG_PRINT(fmt, args...)    /* Don't do anything in release builds */
#define SHOW_NOTE(x)
#endif

typedef enum { FALSE=0, TRUE} boolean;

typedef struct Node{
	int data;
	struct Node *next;
}node;

node* createNode(int data, node* pNode){
	node *p = (node *)malloc(sizeof(node));

	if(p == NULL){
		printf("fail to allocate mrmory.\n");
	}

	p->data = data;
	p->next = pNode;
	return p;
}

void showNode(const node* p){
	while(p != NULL){
	    printf("%d ", p->data);
	    p=p->next;
	}
	printf("\n");
}

void pushBack( node* pre_Node, node* new_Node){

	while(pre_Node->next != NULL){
		pre_Node=pre_Node->next;
		DEBUG_PRINT("per_Node data:%d\n", pre_Node->data);
	}

	pre_Node->next=new_Node;
}

void insertNode( node* aNode, node* bNode, node* newNode){
	
	if(aNode)
		aNode->next=newNode;

	while(newNode->next != NULL){
		newNode=newNode->next;
		DEBUG_PRINT("newNode data:%d\n", newNode->data);
	}

	if(newNode->next == NULL){
		newNode->next=bNode;
	}else
	    printf("fail to insertNode\n");
		

}

node* pushFront( node* pre_Node, node* newNode ){

	while(newNode->next != NULL){
		newNode=newNode->next;
		DEBUG_PRINT("newNode data:%d\n", newNode->data);
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

node* searchPreNode(node* pNode, node* key){

	while(pNode != NULL){
	    if(pNode->next == key){
		DEBUG_PRINT("0x%x, 0x%x \n", (unsigned int)pNode->next,
			       	(unsigned int)key);	
	        return pNode;
	    }
	    pNode=pNode->next;
	}

	return NULL;
}

node* searchDate(node* pNode, int key){

	while( pNode != NULL){
	    if(pNode->data == key){
		DEBUG_PRINT("%d, %d \n", pNode->data, key);
	        return pNode;
	    }
	
	    pNode=pNode->next;
	}
	
	return NULL;	
}

void eraseBack(node* pNode){
	node *pErase=NULL;
	pErase=pNode;

	while(pErase->next != NULL){
		pErase=pErase->next;
		DEBUG_PRINT("pErase data:%d\n", pErase->data);
	}

	pNode=searchPreNode(pNode, pErase);


	pNode->next=NULL;
	free(pErase);
	
}

int eraseSpecficNode(node* pNode, int key){
	node *pErase=NULL;

	pErase=searchDate(pNode,key);
	if(pErase == NULL)
	    return FALSE;

	pNode=searchPreNode(pNode, pErase);

	pNode->next=NULL;
	free(pErase);	

	return TRUE;
}

int main(){
	node *pHead=NULL, *pHead2=NULL, *pHead3=NULL, \
		*pHead4=NULL;
	node *p=NULL;
	int i=0, key=11;

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
	
	DEBUG_PRINT("pHead offest data be: %d\n", pHead->next->next->next->data);

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
/*Remove the specifiec node*/

	if(eraseSpecficNode(pHead, key) == FALSE)
		printf("No such data is %d", key);
	else
		printf("data %d has been removed.", key);

	p=pHead;

	/*delete*/
	while(p != NULL){
		node *pTmp = p;
		p = p->next;
		free(pTmp);
	}

}
