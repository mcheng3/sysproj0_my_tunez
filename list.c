#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include<string.h>



void print_list(song_node * n){
	int count = 0;
	while(n){
		printf("%d: %s by %s\n", count, n->name, n->artist);
		//printf("%p\n", n->next);
		n = n->next;
		count++;
	}
}

void br(){
	printf("============================\n");
}

song_node * insert_front(song_node * n, char * name, char * artist){
	song_node *head = (song_node *)malloc(sizeof(song_node));
	head->next = n;
	strcpy(head->name, name);
	strcpy(head->artist, artist);
	return head;
}

song_node * insert_ordered(song_node * n, char * name, char * artist){
	song_node *head = (song_node *)malloc(sizeof(song_node));
	
	while(n){
		if(strcmp(n->name, name) > 0){
			br();
			n->next = insert_front(n, name, artist);
	//		print_list(n);
			break;
		}
		n = n->next;	
	}
	return n;
}
song_node * free_list(song_node * n){
	while(n){
		song_node *hold = n;
		n = n->next;
		free(hold);
	}
	return n;
}

int main(){
	song_node *head;
	song_node *next = 0;
	head = insert_front(next, "c", "b");
	head = insert_front(head, "a", "b");
	head = insert_ordered(head, "b", "b");
	
	br();
	//printf("%d\n", head->next->i);
	print_list(head);
	free_list(head);
	//print_kist(head);
}
