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
  } 
  else 
  {
    printf("( NULL )\n");
  }
}

int list_size(struct Node *node, int length) {
  if (node != NULL)
  {
    length++;
    list_size(node->next, length);
  } 
  else 
  {
    return length;
  }
}

void insert_at(struct Node *head) {
  struct Node *node = append();
  int index;

  printf("Enter index (0 based): ");
  scanf("%i", &index);

  int length = list_size(head, 0);

  if (index > 0 || index < length)
  {
    printf("Must enter a number between 0 and %i (inclusive)", length);
  }

  int tracker = 0;
}

struct Node *find_by_index(struct Node *node, int index, int tracker) {
  if (index == tracker)
  {
    return node;
  } 
  else if (node == NULL)
  {
    return NULL;
  } else {
    tracker++;
    find_by_index(node, index, tracker);
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
      break;
    case 4:
      // insert_at
      break;
    case 5:
      // remove_at
      break;
    case 6:
      printf("List size: %i\n", list_size(head, 0));
      break;
    case 7:
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

// To do
// create find by index so a user can enter a value between 0 and list_size()
// find the node at that index, head has an index of 0, head->next has an index of 2, etc
// use this to create insert_at
