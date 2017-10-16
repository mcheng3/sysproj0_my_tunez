typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;
song_node *table[26];
struct node{
	int i;
	node * next;
};
void print_list(struct node *);
struct node * insert_front(struct node *, int);
struct node * free_list(struct node *);
