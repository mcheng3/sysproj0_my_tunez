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
	//printf("%s\n", name);
	return head;
}

song_node * insert_ordered(song_node * n, char * name, char * artist){
	song_node * temp = n;
	song_node * tmp2 = n -> next;
	song_node * head = n; 	
	while(temp && (strcmp(temp->name, name) < 0)){
		temp = temp->next;	
	}
	head = insert_front(temp, name, artist);
//	print_list(n);
	br();
	while (strcmp(n->name, name) < 0 && n) {
		printf("%d\n", strcmp(n->name, name));		
		n = n-> next;
	}   
	print_list(n);
	br();
	print_list(head);
	n -> next = head;
	head->next = tmp2;
	br();
	//print_list(n);
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
	head = insert_front(next, "m", "b");
	head = insert_front(head, "b", "b");
	head = insert_front(head, "a", "d");
	head = insert_ordered(head, "c", "b");	
	br();
	//printf("%d\n", head->next->i);
	print_list(head);
	free_list(head);
}
