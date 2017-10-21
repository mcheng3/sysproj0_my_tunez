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

int songcmp(song_node * a, song_node * b){
	int artist_cmp = strcmp(a->artist, b->artist);
	if(artist_cmp){
		return artist_cmp;
	}
	else{
		return strcmp(a->name, b->name);
	}
}

song_node * insert_ordered(song_node * n, char * name, char * artist) { 
	song_node * insert = (song_node *) malloc(sizeof(song_node));
	strcpy(insert -> name, name);
	strcpy(insert -> artist, artist);
	song_node * x = n;
	printf("Comparing [%s: %s] to [%s: %s]\n %d\n", x->artist, x->name, insert->artist, insert->name, songcmp(x, insert));
	if(songcmp(x, insert) > 0){
		insert->next = x;
		return insert;
	}
	else{
		while (x->next){
			printf("Comparing [%s: %s] to [%s: %s]\n %d\n", x->artist, x->name, insert->artist, insert->name, songcmp(x, insert));
			if(songcmp(x, insert) > 0){
				insert->next = x->next;
				x->next = insert;
			return n;
			}
			x = x->next;
		}
		x->next = insert;
		return n;
	}
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

song_node * remove_node(song_node * n, char * name, char * artist) {
	song_node * node = find_song(n, name, artist);
	if(node == n){
		song_node * hold = n->next;  
		free(n);
		return hold;
	}
	while (n->next != node) {
		n = n -> next;
	}
	n -> next = node -> next;
	return n;
}

void add_song(song_node * ary[], char * name, char * artist){
	char letter = artist[0];
	printf("%c aka %d\n", letter, letter);
	if(!ary[letter-97]){
		printf("ok\n");
		ary[letter-97] = (song_node *) malloc(sizeof(song_node));
		ary[letter-97] = insert_front(0, name, artist);
		
	}
	else{
		ary[letter-97] = insert_ordered(ary[letter-97], name, artist);
	}
	print_list(ary[letter-97]);
	br();
} 

void print_letter_list(song_node * ary[], char letter){
	print_list(ary[letter-97]);
}

int main(){
	song_node * table[27];
	int i = 0;
	for(;i<27;i++){
		table[i] = 0;
	}
	song_node *head;
	song_node *next = 0;
	head = insert_front(next, "m", "b");
	head = insert_ordered(head, "b", "b");
	head = insert_ordered(head, "a", "d");
	//head = insert_ordered(head, "c", "b");
	printf("TESTING PRINT_LIST\n");
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
	head = remove_node(head, "b", "b");
	print_list(head);
	song_node  * test0 = (song_node *)malloc(sizeof(song_node)); 
	song_node * test1 = (song_node *)malloc(sizeof(song_node));
	strcpy(test0->name, "look what you made me do");
	strcpy(test0->artist, "taylor swift");
	strcpy(test1->name, "bad blood");
	strcpy(test1->artist, "taylor swift");
	br();
	printf("TESTING songcmp()\n");
	printf("Comparing [taylor swift: look what you made me do] to [taylor swift: bad blood]\n %d\n", songcmp(test0, test1)); 
	br();
	printf("INSERTING NODE IN ORDER\n");
	head = insert_ordered(head, "c", "d");
	print_list(head);
	add_song(table, "abc", "potato");
	add_song(table, "def", "potato");

	add_song(table, "look what you made me do", "taylor swift");
	add_song(table, "bad blood", "taylor swift");
	add_song(table, "closer", "the chainsmokers");
	add_song(table, "paris", "the chainsmokers");
	//printf("%d\n", head->next->i);
	printf("PRINT p list\n");
	print_letter_list(table, 'p');
	printf("PRINT t list\n");
	print_letter_list(table, 't');
	free_list(head);
}
