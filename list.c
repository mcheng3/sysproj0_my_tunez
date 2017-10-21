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

int comp_song(song_node * n, char * name, char * artist) {
	if (!strcmp(artist, n -> artist)) return strcmp(name, n -> name);
	return strcmp(artist, n -> artist);
}

song_node * insert_ordered(song_node * n, char * name, char * artist) { 
	song_node * temp = n;
	song_node * end = n;
	if(!n || comp_song(n, name, artist) < 0) return insert_front(n, name, artist);
	while (n) {
	    if (comp_song(n, name, artist) > 0) {
			end = n;
			n = n->next;
		}
		else {
			end -> next = insert_front(n, name, artist);
			return temp;
		}
	}
	end -> next = insert_front(n, name, artist);
	return temp;
}

song_node * find_song(song_node * n, char * name, char * artist) {
	while (n && (strcmp(name, n->name) || strcmp(artist, n->artist))) {
		n = n -> next;
	}
	if (n == 0) printf("SONG NOT FOUND\n");
	return n; 
}

song_node * find_song_artist(song_node * n, char * artist) {
	while (n && strcmp(artist, n-> artist)) {
		n = n -> next;
	}
	if (!n) 
		printf("ARTIST NOT FOUND\n");
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
	ary[letter-97] = insert_ordered(ary[letter-97], name, artist);
} 

void print_letter_list(song_node * ary[], char letter){
	print_list(ary[letter-97]);
}

song_node * search_song(song_node * ary[], char * name, char * artist) {
	char letter = artist[0];
	song_node * search = ary[letter-97];
	return find_song(search, name, artist);
}

song_node * search_artist(song_node * ary[], char * artist) {
	char letter = artist[0];
	song_node * search = ary[letter-97];
	return find_song_artist(search, artist);
}
void print_table(song_node * ary[]) {
	int i = 0;
	int j = 0;
	for (; i < 27; i++) {
		song_node * temp = ary[i];
		while (temp) {
			printf("%d: %s by %s\n", j, temp -> name, temp -> artist);
			temp = temp -> next;
			j++;
		}
	}
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
	head = insert_front(head, "b", "b");
	head = insert_front(head, "a", "a");
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
	head = remove_node(head, "a", "a");
	head = remove_node(head, "b", "b");
	print_list(head); 
	printf("INSERTING NODE IN ORDER\n");
	head = insert_ordered(head, "c", "d");
	head = insert_ordered(head, "a", "e");
	print_list(head);
	br();
	printf("TESTING TABLE ADD SONG\n");
	add_song(table, "look what you made me do", "taylor swift");
	add_song(table, "bad blood", "taylor swift");
	add_song(table, "closer", "the chainsmokers");
	add_song(table, "paris", "the chainsmokers");
	add_song(table, "honest", "the chainsmokers");
	add_song(table, "hello", "adele");
	print_table(table);
	br();
	printf("TESTING SEARCH BY SONG\n");
	print_list(search_song(table, "hello", "adele"));
	br();
	printf("TESTING SEARCH BY ARTIST\n");
	print_list(search_artist(table, "the chainsmokers"));
	br();
	printf("TESTING PRINT LETTER LIST\n");
	print_letter_list(table, 't');
	free_list(head);
}
