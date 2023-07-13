#include "list.h"

/**
 * add_node_end - Add a new node at the beginning
 * of a double circular linked list
 * @list: Pointer to the list to modify
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    return (add_node_end(list, str) ? *list = (*list)->prev : NULL);
}

/**
 * add_node_end - Add a new node at the end of a double circular linked list
 * @list: Pointer to the list to modify
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *last, *new_node;

    if (!list || !str)
        return (NULL);

    new_node = malloc(sizeof(*new_node));
    if (!new_node)
        return (NULL);

    new_node->str = strdup(str);
    if (!new_node->str)
    {
        free(new_node);
        return (NULL);
    }
    if (!(*list))
    {
        *list = new_node;
        new_node->next = new_node->prev = new_node;
    }
    else
    {
        last = (*list)->prev;

        new_node->prev = last;
        new_node->next = (*list);
        last->next = (*list)->prev = new_node;
    }

    return (new_node);
}
