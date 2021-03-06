#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int value;
} Node;

static void free_list(Node *list)
{
    Node *current;
    if (!list)
        return;
    while (list)
    {
        current = list;
        list = list->next;
        free(current);
    }
}

static Node *create_list(void)
{
    Node *result = 0, *current;
    for (int i = 0; i < 25; i++)
    {
        current = (Node *) malloc(sizeof(Node));
        if (!current)
        {
            free_list(result);
            return 0;
        }
        current->value = i;
        current->next = result;
        result = current;
    }
    return result;
}

static void print_list(Node *list)
{
    if (!list)
        return;
    while (list)
    {
        fprintf(stdout, "%d\n", list->value);
        list = list->next;
    }
}

static Node *invert_list(Node *in)
{
    Node *next = in, *last = 0, *temp = 0;
    while (next)
    {
        temp = next;
        next = next->next;
        temp->next = last;
        last = temp;
    }
    return last;
}

int main(int argc, char *argv[])
{
    Node *newlist = create_list();
    if (newlist)
    {
        fprintf(stdout, "%s", "------- Before ---------\n");
        print_list(newlist);
        newlist = invert_list(newlist);
        fprintf(stdout, "%s", "------- After ---------\n");
        print_list(newlist);
        free_list(newlist);
    }
    return 0;
}
