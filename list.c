#include<stdio.h>
#include<stdlib.h>
#include "list.h"
#include<string.h>
#include <time.h>

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

song_node * insert_ordered(song_node * n, char * name, char * artist) { 
	song_node * insert = (song_node *) malloc(sizeof(song_node));
	strcpy(insert -> name, name);
	strcpy(insert -> artist, artist);

	while (strcmp(n->next-> name, name) < 0) {
		n = n -> next;
	}
	insert -> next = n -> next;
	n -> next = insert;
	return insert;
}

song_node * find_song(song_node * n, char * name, char * artist) {
	while (n && (strcmp(name, n->name) || strcmp(artist, n->artist))) {
		n = n -> next;
	}
	if (n == 0) printf("SONG NOT FOUND\n");
	return n; 
}

song_node * find_song_artist(song_node * n, char * artist) {
	while (strcmp(artist, n-> artist) && n) {
		n = n -> next;
	}
	return n;
}

song_node * rand_node(song_node * n) {
	srand(time(NULL));
	int len = 0; 
	song_node * temp = n;
	while (temp) {
		len++;  
		temp = temp -> next;
	}
	int rand_num = rand() % len;
	while (n && rand_num) {
		rand_num--;
		n = n -> next;
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

int remove_node(song_node * n, char * name, char * artist) {
	song_node * node = find_song(n, name, artist);
	while (n->next != node) {
		n = n -> next;
	}
	n -> next = node -> next;
	return 0;
}

int main(){
	song_node *head;
	song_node *next = 0;
	head = insert_front(next, "m", "b");
	head = insert_front(head, "b", "b");
	head = insert_front(head, "a", "d");
	//head = insert_ordered(head, "c", "b");
	printf("TESTING PRINT_LIST");
	print_list(head);
	br();
	printf("FINDING SONG BY NAME AND ARTIST\n");	
	print_list(find_song(head, "m", "b"));
	br();
	printf("FINDING SONG BY ARTIST\n");
	print_list(find_song_artist(head, "b"));
	br();
	printf("FINDING RANDOM NODE\n");
	print_list(rand_node(head));
	br();
	printf("REMOVING NODE\n");
	remove_node(head, "b", "b");
	print_list(head); 
	printf("INSERTING NODE IN ORDER\n");
	insert_ordered(head, "c", "d");
	print_list(head);
	//printf("%d\n", head->next->i);
	//print_list(head);
	free_list(head);
}
