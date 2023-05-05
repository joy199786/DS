# include <stdio.h>
# include "node.h"
# include <stdlib.h>

//typedef struct _node{
//	int value;
//	struct _node *next;
//}Node;
typedef struct _list{
	Node *head;
	Node *tail;
}List;

Node *findNode(List *list, int num){
	Node *index = list->head;
	while(index != NULL){
		//printf("%d\t", index->value);
		if(index->value == num){
			return index;
		}
		index = index->next;
	} 
	printf("Not Found\n");
	return NULL;
}

int  deleteNode(List *list, int num){
	//find node
	//free node
	Node *p = list->head;
	Node *q = NULL;

	while(p != NULL){
		//printf("%d\t", index->value);
		if(p->value == num){
			if(q){
				q->next = p->next;
				free(p);
				return 1;
			}
			else{
				list->head = p->next;
				free(q);
				return 1;
			}
		}
		q = p;
		p = p->next;
	} 
	return -1;
}


void printList(List *list){
	if(!list){
		printf("Not exist\n");
		return;
	}
	
	Node *index = list->head;
	while(index != NULL){
		printf("%d\t", index->value);
		index = index->next;
	} 
//	for(index= list->head; NULL; index=index->next){
//		printf("%d\t", index->value);
//		index = index->next;
//	}
//	printf("\n");
}

void addNode(List *plist, int num){
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = num;
	p->next = NULL;
	if(plist->head == NULL){
		plist->head = p;
		plist->tail = p;
	} else{
		plist->tail->next = p;
		plist->tail = p;
	}
} 

void FreeList(List *list){
	Node *p;// = list->head;
	Node *q;
	for(p=list->head; p; p=q){
		q = p->next;
		free(p);
	}
	list->head = list->tail = NULL;  // the head and tail pointers to NULL

}

int main(){
	List list;
	list.head = list.tail = NULL;
	// if input == -1, then stop the loop
	int num = 0;
	scanf("%d", &num);
	while(num != -1){
		addNode(&list, num);
		scanf("%d", &num);
	}
//	do{
//		scanf("%d", &num);
//		addNode(&list, num);
//	}while(num != -1);
	printList(&list);
	
	//Find Node
	Node *f = findNode(&list, 10);
	printf("Find: %d", f->value);
	
	//Delete Node 
	printf("Delete Num: ");
	scanf("%d", &num);
	deleteNode(&list, num);
	printList(&list);
	
	// Free the whole list 
	FreeList(&list);
	printList(&list);
	
	return 0;
} 
