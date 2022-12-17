#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

// This implementation of hash table uses linear probing

static int hashtable_hash(const char *key, int size)
{
	int hash_code = 0;
	int n = strlen(key);

	for (int i = 0; i < n; i++) {
		hash_code = 31 * hash_code + key[i];
	}

	return hash_code % size;
}

hashtable_t *hashtable_init(int capacity)
{
	hashtable_t *ht = malloc(sizeof(hashtable_t));
	entry_t **entries = malloc(capacity * sizeof(entry_t));

	if (ht == NULL || entries == NULL) {
		printf("error: could not allocate the resources needed for the hashtable.\n");
		exit(EXIT_FAILURE);
	}

	ht->entries = entries;
	ht->size = 0;
	ht->capacity = capacity;

	for (int i = 0; i < capacity; i++) {
		ht->entries[i] = NULL;
	}

	return ht;
}

int hashtable_size(hashtable_t *ht)
{
	return ht->size;
}

int hashtable_is_empty(hashtable_t *ht)
{
	return ht->size == 0;
}

void hashtable_add(hashtable_t *ht, const char *key, int value)
{
	int i = hashtable_hash(key, ht->capacity);
	int starting_index = i;

	while (ht->entries[i] != NULL) {
		if (strcmp(ht->entries[i]->key, key) == 0) {
			ht->entries[i]->value = value;
			return;
		}

		i = (i + 1) % ht->capacity;

		if (i == starting_index) break;
	}

	// put after the loop to allow overriding existing keys
	if (ht->size == ht->capacity) {
		printf("error: hash table is full.\n");
		exit(EXIT_FAILURE);
	}

	if (ht->entries[i] == NULL) {
		entry_t *entry = malloc(sizeof(entry_t));
		entry->key = strdup(key);
		entry->value = value;

		ht->entries[i] = entry;
		ht->size++;
	}
}

int hashtable_exists(hashtable_t *ht, const char *key)
{
	int i = hashtable_hash(key, ht->capacity);
	int starting_index = i;

	while (ht->entries[i] != NULL) {
		if (strcmp(ht->entries[i]->key, key) == 0) {
			return 1;
		}

		i = (i + 1) % ht->capacity;

		if (i == starting_index) {
			return 0;
		}
	}
}

int hashtable_get(hashtable_t *ht, const char *key)
{
	int i = hashtable_hash(key, ht->capacity);
	int starting_index = i;

	while (ht->entries[i] != NULL) {
		if (strcmp(ht->entries[i]->key, key) == 0) {
			return ht->entries[i]->value;
		}

		i = (i + 1) % ht->capacity;

		if (i == starting_index) {
			printf("error: could not find a value with key %s\n", key);
			exit(EXIT_FAILURE);
		}
	}
}

void hashtable_remove(hashtable_t *ht, const char *key)
{
	int i = hashtable_hash(key, ht->capacity);
	int starting_index = i;

	while (1) {
		if (ht->entries[i] != NULL && strcmp(ht->entries[i]->key, key) == 0) {
			free(ht->entries[i]->key);
			free(ht->entries[i]);
			ht->entries[i] = NULL;
			ht->size--;
			break;
		}

		i = (i + 1) % ht->capacity;

		if (i == starting_index) {
			printf("error: could not find a value with key %s\n", key);
			exit(EXIT_FAILURE);
		}
	}
}

void hashtable_free(hashtable_t *ht)
{
	for (int i = 0; i < ht->capacity; i++) {
		if (ht->entries[i] != NULL) {
			free(ht->entries[i]->key);
			free(ht->entries[i]);
		}
	}
	free(ht->entries);
	free(ht);
}
