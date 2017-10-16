#include<stdio.h>
#include<stdlib.h>
#include "list.h"

void print_list(struct node * n){
	int count = 0;
	while(n){
		printf("%d: %d\n", count, n->i);
		//printf("%p\n", n->next);
		n = n->next;
		count++;
	}
}

struct node * insert_front(struct node * n, int i){
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->next = n;
	head->i = i;
	return head;
}

struct node * free_list(struct node * n){
	while(n){
		struct node *hold = n;
		n = n->next;
		free(hold);
	}
}

int main(){
	struct node *head;
	struct node *foo = 0;
	head = insert_front(foo, 0);
	head = insert_front(head, 1);
	head = insert_front(head, 2);
	head = insert_front(head, 3);
	head = insert_front(head, 4);
	//printf("%d\n", head->next->i);
	print_list(head);
	free_list(head);
	//print_list(head);
}