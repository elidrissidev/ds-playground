#include <assert.h>
#include <stdio.h>
#include "hashtable.h"

int main()
{
	int capacity = 8;
	hashtable_t *ht = hashtable_init(capacity);

	assert(hashtable_size(ht) == 0);
	assert(hashtable_is_empty(ht) == 1);

	hashtable_add(ht, "mark", 21);
	hashtable_add(ht, "bob", 64);
	hashtable_add(ht, "alice", 43);
	hashtable_add(ht, "chloe", 18);

	assert(hashtable_size(ht) == 4);
	assert(hashtable_is_empty(ht) == 0);	

	assert(hashtable_exists(ht, "alice") == 1);
	assert(hashtable_exists(ht, "john") == 0);
	assert(hashtable_exists(ht, "bob") == 1);

	assert(hashtable_get(ht, "alice") == 43);
	assert(hashtable_get(ht, "mark") == 21);
	assert(hashtable_get(ht, "chloe") == 18);
	assert(hashtable_get(ht, "bob") == 64);

	hashtable_remove(ht, "mark");
	hashtable_remove(ht, "chloe");

	assert(hashtable_size(ht) == 2);

	hashtable_free(ht);
	return 0;
}
