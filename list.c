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

song_node * insert_front(song_node * n, int i){
	song_node *head = (song_node *)malloc(sizeof(song_node));
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
	return n;
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
