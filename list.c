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

/* song_node * insert_ordered(song_node * n, char * name, char * artist){
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
} */

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

int main(){
	song_node *head;
	song_node *next = 0;
	head = insert_front(next, "m", "b");
	head = insert_front(head, "b", "b");
	head = insert_front(head, "a", "d");
	//head = insert_ordered(head, "c", "b");
	printf("FINDING SONG BY NAME AND ARTIST\n");	
	print_list(find_song(head, "m", "b"));
	br();
	printf("FINDING SONG BY ARTIST\n");
	print_list(find_song_artist(head, "b"));
	br();
	printf("FINDING RANDOM NODE\n");
	print_list(rand_node(head));
	//printf("%d\n", head->next->i);
	//print_list(head);
	free_list(head);
}
