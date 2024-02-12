#include <stdio.h>

typedef struct s_list
{
    int        content;
    struct    s_list *next;
    struct    s_list *prev;
}t_list;

void    ft_lst_add_front(t_list **head, t_list *node)
{
    if (!node)
        return;
    if (*head)
    {
        node->prev = (*head)->prev;
        (*head)->prev->next = node;
        (*head)->prev = node;
        node->next = *head;
    }
    *head = node;
}

void    ft_lst_add_back(t_list **head, t_list *node)
{
    if (!node)
        return;
    if (*head)
    {
        node->next = *head;
        node->prev = (*head)->prev;
        (*head)->prev->next = node;
        (*head)->prev = node;
    }
    (*head) = node;
}

t_list    *ft_lst_new_node(int thing)
{
    t_list    *new;

    new = malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = thing;
    new->next = new;
    new->prev = new;
    return (new);
}

void    print_lst(t_list **head)
{
    t_list    *temp;
    size_t    i;

    i = 0;
    temp = *head;
    while (temp->next != *head)
    {
        printf("Elem n'%zu: %d\n", i, temp->content);
        temp = temp->next;
        i++;
    }
    printf("Elem n'%zu: %d\n", i, temp->content);
}

void    free_lst(t_list **head)
{
    t_list    *temp;

    (*head)->prev->next = NULL;
    while (*head)
    {
        temp = (*head)->next;
        (*head)->content = 0;
        free(*head);
        *head = temp;
    }
}

int main(void)
{
  int arc = 5;
  char argv[5][8] = {"lsdls", "7", "6", "602", "1"};
    if (arc < 2)
        return (0);
    t_list    *head;
    int    i;

    printf("Addfront:\n");
    i = arc - 1;
    head = NULL;
    while (i > 0)
    {
        ft_lst_add_front(&head, ft_lst_new_node(atoi(argv[i])));
        i--;
    }
    print_lst(&head);

    t_list *head2;
    t_list *temp;
    t_list *temp2;
    printf("\nAddback:\n");
    head2 = NULL;
    temp2 = head;
    temp = temp2;
    while (temp2->next != head)
    {
        temp2 = temp2->next;
        ft_lst_add_back(&head2, temp);
        temp = temp2;
        i++;
    }
    ft_lst_add_back(&head2, temp);
    ft_lst_add_back(&head2, head);
    print_lst(&head2);
    free_lst(&head2);
    return (0);
}
