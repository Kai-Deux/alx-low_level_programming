#include "hash_tables.h"

/**
 * shash_table_create - create php hash table
 * @size: input size
 * Return: pointer to head, or NULL if malloc fails
 */
shash_table_t *shash_table_create(unsigned long int size)
{
    shash_table_t *ht;

    if (!size)
        return (NULL);
    ht = calloc(1, sizeof(shash_table_t));
    if (!ht)
        return (NULL);
    ht->size = size;
    ht->array = calloc(size, (sizeof(shash_node_t **)));
    if (!ht->array)
        return (NULL);
    ht->shead = NULL;
    ht->stail = NULL;
    return (ht);
}

/**
 * shash_table_set - set hash table with key and value
 * @ht: input hash table
 * @key: input key
 * @value: input value
 * Return: 1 on success, 0 on fail
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
    shash_node_t *new_node;

    if (!ht || !key || !value)
        return (0);
    if (search_and_replace(ht, key, value))
        return (1);
    new_node = create_node(ht, key, value);
    if (!ht->shead)
    {
        ht->shead = new_node;
        ht->stail = new_node;
        return (1);
    }
    strcmp(ht->shead->key, new_node->key) > 0
        ? insert_in_beginning(ht, new_node)
        : insert_in_middle_or_end(ht, new_node);
    return (1);
}

/**
 * insert_in_beginning - insert node to beginning of linked list
 * @ht: input hash table
 * @new_node: node to be inserted
 */
void insert_in_beginning(shash_table_t *ht, shash_node_t *new_node)
{
    new_node->snext = ht->shead;
    ht->shead->sprev = new_node;
    ht->shead = new_node;
}

/**
 * insert_in_middle_or_end - traverses pointers and inserts node in correct
 * position
 * @ht: input hash table
 * @new_node: node to be inserted
 */
void insert_in_middle_or_end(shash_table_t *ht, shash_node_t *new_node)
{
    shash_node_t *curr, *prev;

    curr = ht->shead;
    while (curr)
    {
        prev = curr->sprev;
        if (strcmp(curr->key, new_node->key) > 0)
        {
            prev->snext = new_node;
            curr->sprev = new_node;
            new_node->snext = curr;
            new_node->sprev = prev;
            return;
        }
        prev = curr;
        curr = curr->snext;
    }
    prev->snext = new_node;
    new_node->sprev = prev;
    ht->stail = new_node;
}

/**
 * search_and_replace - search chain for duplicate keys and replace values
 * @ht: input hash table
 * @key: input key
 * @value: input value
 * Return: 1 if duplicate found, 0 if not
 */
int search_and_replace(shash_table_t *ht, const char *key, const char *value)
{
    unsigned long int idx = key_index((const unsigned char *)key, ht->size);
    shash_node_t *curr = ht->array[idx];

    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
        {
            free(curr->value);
            curr->value = strdup(value);
            if (!curr->value)
                exit(1);
            return (1);
        }
        curr = curr->next;
    }
    return (0);
}

/**
 * create_node - create new node to insert into hash table
 * @ht: input hash table
 * @key: input key
 * @val: input value
 * Return: new shash_node_t
 */
shash_node_t *create_node(shash_table_t *ht, const char *key, const char *val)
{
    shash_node_t *new_node;
    unsigned long int idx = key_index((const unsigned char *)key, ht->size);

    new_node = malloc(sizeof(shash_node_t));
    if (!new_node)
        exit(1);
    new_node->key = strdup(key);
    if (!new_node->key)
        exit(1);
    new_node->value = strdup(val);
    if (!new_node->value)
        exit(1);
    new_node->next = ht->array[idx];
    new_node->sprev = NULL;
    new_node->snext = NULL;
    ht->array[idx] = new_node;
    return (new_node);
}

/**
 * shash_table_get - get value at key
 * @ht: input hash table
 * @key: input key
 * Return: string of value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
    unsigned long int idx;
    shash_node_t *curr = NULL;

    if (!ht || !key || !*key)
        return (NULL);
    idx = key_index((const unsigned char *)key, ht->size);
    curr = ht->array[idx];
    while (curr)
    {
        if (strcmp(curr->key, key) == 0)
            return (curr->value);
        curr = curr->next;
    }
    return (NULL);
}

/**
 * shash_table_print - print hash table
 * @ht: input hash table
 */
void shash_table_print(const shash_table_t *ht)
{
    if (!ht)
        return;
    print_in_order(ht, true);
}

/**
 * shash_table_print_rev - print hash table in reverse
 * @ht: input table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
    if (!ht)
        return;
    print_in_order(ht, false);
}

/**
 * print_in_order - print hash table according to user-defined order
 * @ht: input hash table
 * @in_order: flag to print in forward or reverse
 */
void print_in_order(const shash_table_t *ht, _Bool in_order)
{
    shash_node_t *start;
    _Bool first = true;

    start = in_order
                ? ht->shead
                : ht->stail;
    printf("{");
    while (start)
    {
        if (!first)
            printf(", ");
        printf("'%s': '%s'", start->key, start->value);
        first = false;
        start = in_order
                    ? start->snext
                    : start->sprev;
    }
    printf("}\n");
}

/**
 * shash_table_delete - delete and free hash table
 * @ht: input hash table
 */
void shash_table_delete(shash_table_t *ht)
{
    register unsigned int i = 0;
    shash_node_t *curr, *tmp;

    if (!ht)
        return;
    for (i = 0; i < ht->size; i++)
    {
        if (ht->array[i])
        {
            curr = ht->array[i];
            while (curr)
            {
                tmp = curr;
                free(curr->key);
                if (curr->value)
                    free(curr->value);
                curr = curr->next;
                free(tmp);
            }
        }
    }
    free(ht->array);
    free(ht);
}