typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;
void print_list(song_node *);
song_node * insert_front(song_node *, char*, char*);
song_node * free_list(song_node *);
int comp_song(song_node *, char *, char *);
song_node * insert_ordered(song_node *, char*, char*);
song_node * find_song(song_node *, char*, char*);
song_node * find_song_artist(song_node *, char*);
song_node * rand_node(song_node *);
song_node * remove_node(song_node *, char *, char *);
// table functions
void add_song(song_node * ary[], char *, char *);
song_node * search_song(song_node * ary[], char *, char *);
song_node * search_artist(song_node * ary[], char *);
void print_letter_list(song_node * ary[], char);
  
  