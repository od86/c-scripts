#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};

// Frees allocated memory
void free_list(struct Node *node) {
  if (node != NULL)
  {
    printf(" Node %p - FREE\n", node);
    free_list(node->next);
    free(node);
  }
}

// // Prints every nodes value in the list
void print_list(struct Node *node) {
  if (node != NULL)
  {
    printf("( %i ) --> ", node->value);
    print_list(node->next);
  } else {
    printf("( NULL )\n");
  }
}

struct Node *append() {
  int value;

  printf(" Enter value for node: ");
  scanf("%i", &value);

  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->value = value;
  node->next = NULL;

  return node;
}

void main_loop(struct Node *head, struct Node *tail) {
  while (1)
  {
    int choice;
    printf("\n Choose option: ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
      print_list(head);
      break;
    case 2:
      // Sets tail->next to the new node
      // Sets tail the new node
      struct Node *node = append();
      tail->next = node;
      tail = node;
      break;
    case 3:
      // insert_at
      break;
    case 4:
      // remove_at
      break;
    case 5:
      free_list(head);
      printf("\n --- STOPPING PROGRAM ---\n\n");
      return;
    default:
      "Enter number between 1 and 5";
      break;
    }
  }
}

int main() {
  printf("\n --- STARTING PROGRAM ---\n\n");

  struct Node *head = (struct Node *)malloc(sizeof(struct Node));
  head = append();
  struct Node *tail = head;

  main_loop(head, tail);
  
  return 0;
}

