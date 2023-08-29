#include "lists.h"

/**
 * free_listint - Frees a linked list.
 * @head: Pointer to the listint_t list to be freed.
 */
void free_listint(listint_t *head)
{
    listint_t *current, *next_node;

    current = head;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
