#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listint_s
{
  int n;
  struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint(listint_t **head, const int n);
void free_listint(listint_t *head);
int check_cycle(listint_t *list);

#endif /* LISTS_H */#include "lists.h"

/**
 * check_cycle - Checks if there is a loop in a linked list.
 * @list: A pointer to the head of the linked list.
 * Return: 0 if there is not a loop, 1 if there is a loop.
 */
int check_cycle(listint_t *list)
{
  listint_t *head;
  listint_t *tmp;

  head = list;
  tmp = list;

  while(tmp != NULL && head->next != NULL && head->next->next != NULL)
    {
      head = head->next->next;
      tmp = tmp->next;

      if (head == tmp)
	return (1);
    }

  return (0);
}
