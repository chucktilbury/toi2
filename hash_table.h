#ifndef _HASH_TABLE_H_
#  define _HASH_TABLE_H_

#  include <stdint.h>
#  include <stdlib.h>

typedef void *hash_tab_t;

hash_tab_t create_hash_table(int slots);
void destroy_hash_table(hash_tab_t ht);
int hash_save(hash_tab_t ht, const char *key, void *data, size_t size);
void *hash_find(hash_tab_t ht, const char *key);
uint32_t make_hash(const char *str);

#endif /* _HASH_TABLE_H_ */
