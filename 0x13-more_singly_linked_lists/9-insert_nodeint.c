#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node in a linked list at a given position.
 * @head: Pointer to the first node in the list.
 * @idx: Index where the new node is to be added.
 * @n: Data to insert in the new node.
 *
 * Return: Pointer to the new node, or NULL if the index is out of range or memory allocation fails.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i;
    listint_t *new_node, *current;

    new_node = malloc(sizeof(listint_t));
    if (!new_node || !head)
        return NULL;

    new_node->n = n;
    new_node->next = NULL;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return new_node;
    }

    current = *head;
    for (i = 0; current && i < idx; i++)
    {
        if (i == idx - 1)
        {
            new_node->next = current->next;
            current->next = new_node;
            return new_node;
        }
        else
            current = current->next;
    }

    free(new_node); // Cleanup if index is out of range
    return NULL;
}
