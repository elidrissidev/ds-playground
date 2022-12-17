#ifndef HASHTABLE_H
#define HASHTABLE_H

typedef struct {
	char *key;
	int value;
} entry_t;

typedef struct {
	entry_t **entries;
	int size;
	int capacity;
} hashtable_t;

hashtable_t *hashtable_init(int size);

int hashtable_size(hashtable_t *ht);

int hashtable_is_empty(hashtable_t *ht);

void hashtable_add(hashtable_t *ht, const char *key, int value);

int hashtable_exists(hashtable_t *ht, const char *key);

int hashtable_get(hashtable_t *ht, const char *key);

void hashtable_remove(hashtable_t *ht, const char *key);

void hashtable_free(hashtable_t *ht);

#endif
