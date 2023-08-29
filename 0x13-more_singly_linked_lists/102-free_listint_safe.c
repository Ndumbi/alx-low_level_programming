#include "lists.h"

/**
 * free_listint_safe - Frees a linked list safely.
 * @h: Pointer to the pointer of the first node in the linked list.
 *
 * Return: Number of elements in the freed list.
 */
size_t free_listint_safe(listint_t **h)
{
    size_t len = 0;
    listint_t *current, *next_node;

    if (!h || !*h)
        return 0;

    current = *h;
    while (current)
    {
        if (current <= current->next)  // Compare memory addresses
        {
            next_node = current->next;
            free(current);
            current = next_node;
            len++;
        }
        else
        {
            free(current);
            current = NULL;
            len++;
            break;
        }
    }

    *h = NULL;

    return len;
}
