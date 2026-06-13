#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  struct Node *next;
};

// Case 7 - Frees all linked list memory
void free_list(struct Node *node) {
  if (node != NULL)
  {
    free_list(node->next);
    printf("Freed node %p\n", node);
    free(node);
  }
}

// Case 6 - Gets the length of the list
int list_length(struct Node *node) {
  int length = 0;

  while (node != NULL)
  {
    length++;
    node = node->next;
  }

  return length;
}

// Case 6 - Prints the size of list
void size_of_list(struct Node *head) {
  int length = list_length(head);
  printf("List length = %i\n", length);
}

// Helper that gets a index for a node
int get_index() {
  int index;
  printf("Enter node index (0 based): ");
  scanf("%i", &index);
  return index;
}

// Helper that gets a value for a node
int get_value() {
  int value;
  printf("Enter node value: ");
  scanf("%i", &value);
  return value;
}

// Helper that creates a new node
struct Node *create_node(int value) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->value = value;
  node->next = NULL;

  return node;
}

// Case 5 - Finds node at specific index
struct Node *find_by_index(struct Node *node, int index) {
  int tracker = 0;

  while (node != NULL)
  {
    if (tracker == index) {
      return node;
    }

    tracker++;
    node = node->next;
  }
}

// Case 5 - Prints node user wants
void find_node(struct Node *head) {
  int index = get_index();
  struct Node *node = find_by_index(head, index);

  printf("Index %i found node %p with value %i\n", index, node, node->value);
}

// Case 4 - Getting the node before tail
struct Node *node_before_tail(struct Node *node, struct Node *tail) {
  while (1)
  {
    if (node->next == tail)
    {
      return node;
    }

    node = node->next;
  }
}

// Case 4 - Removes a node at a specific index
void remove_at(struct Node **head, struct Node **tail) {
  int index = get_index();
  struct Node *node = find_by_index(*head, index);

  if (index == 0)
  {
    struct Node *prev_head = *head;
    struct Node *new_head = prev_head->next;
    *head = new_head;
  }
  else if (index < (list_length(*head) - 1))
  {
    struct Node *prev_node = find_by_index(*head, index - 1);
    struct Node *next_node = find_by_index(*head, index + 1);
    prev_node->next = next_node;
  }
  else
  {
    struct Node *new_tail = node_before_tail(*head, *tail);
    new_tail->next = NULL;
    *tail = new_tail;
  }

  printf("Removed node %p with value %i at %i\n", node, node->value, index);
  free(node);
}

// Case 3 - Creates a new node and inserts it a specific index
void insert_at(struct Node **head, struct Node **tail) {
  int index = get_index();
  int value = get_value();
  struct Node *new_node = create_node(value);

  if (index == 0)
  {
    new_node->next = *head;
    *head = new_node;
  }
  else if (index < (list_length(*head) - 1))
  {
    struct Node *prev_node = find_by_index(*head, index - 1);
    struct Node *next_node = find_by_index(*head, index);
    prev_node->next = new_node;
    new_node->next = next_node;
  }
  else
  {
    struct Node *prev_tail = *tail;
    prev_tail->next = new_node;
    *tail = new_node;
  }
  
  printf("Inserted node %p with value %i at %i\n", new_node, new_node->value, index);
}

// Case 2 - Adds node to the linked list
void append_node(struct Node **head, struct Node **tail) {
  int value;

  printf("Enter node value: ");
  scanf("%i", &value);

  // Create the new node
  struct Node *new_node = create_node(value);
  printf("Created Node %p with value %i\n", new_node, new_node->value);

  // For when no nodes exist
  if (*head == NULL) {
    *tail = new_node;
    *head = *tail;
    return;
  }

  struct Node *prev_tail = *tail;
  prev_tail->next = new_node;
  *tail = new_node;
}

// Case 1 - Prints all node values in the list
void print_list(struct Node *node) {
  while (node != NULL)
  {
    printf("( %i ) -> ", node->value);
    node = node->next;
  }
  
  printf("( NULL )\n");
}

void main_loop(struct Node *head, struct Node *tail) {
  while (1)
  {
    int choice;
    printf("\nChoose option: ");
    scanf("%i", &choice);

    switch (choice)
    {
    case 1:
      print_list(head);
      break;
    case 2:
      append_node(&head, &tail);
      break;
    case 3:
      insert_at(&head, &tail);
      break;
    case 4:
      remove_at(&head, &tail);
      break;
    case 5:
      find_node(head);
      break;
    case 6:
      size_of_list(head);
      break;
    case 7:
      free_list(head);
      return;
    default:
      printf("Enter a number between 1 and 7");
      break;
    }
  }
}

int main() {
  struct Node *head;
  struct Node *tail;
  append_node(&head, &tail);
  main_loop(head, tail);
  
  return 0;
}

// Case 1 = print all nodes
// Case 2 = create node
// Case 3 = insert at index
// Case 4 = remove at index 
// Case 5 = find by index 
// Case 6 = list size
// Case 7 = free list and end program