#include <stdio.h>
#include <stdlib.h>

// Functions:
// view all students
// create a student
// view a student
// edit a student
// delete a student

// maybe use a global variable to remember how many lines need to be cleared
// printf("\e[2A\e[J");

typedef struct
{
  int id;
  char name[6];
  int age;
} Student;

void view_all_students(Student *students) {
  printf("\e[2A\e[J");
  printf("\nStudents:\n");
  printf("--------------------\n");

  for (int i = 0; i > -1; i++)
  {
    if (students[i].id == 0) {
      break;
    }

    printf("ID: %i | Name: %s | Age: %i\n", 
      students[i].id, 
      students[i].name,
      students[i].age);
  }

  printf("\n");
}

void determine_choice(Student *students) {
  int choice;

  printf("Enter number of what you'd like to do: ");
  scanf("%i", &choice);

  if (choice == 1) {
    view_all_students(students);
    determine_choice(students);
  }
  else {
    printf("\n\nAhhhh thats not an option im gonna... \n");
    printf("\n--- PROGRAM DIED ---\n\n");
  }
}

// Displays options and asks for input
void print_options() {
  printf("\n+----------------+-----+\n");
  printf("| Function       | Num |\n");
  printf("+----------------+-----+\n");
  printf("| All students   |  1  |\n");
  printf("| Create student |  2  |\n");
  printf("| View student   |  3  |\n");
  printf("| Edit student   |  4  |\n");
  printf("| Delete Student |  5  |\n");
  printf("+----------------+-----+\n\n");
}

int main() {
  Student *students = (Student *)malloc(sizeof(Student) * 2);

  Student student1 = {1, "Jeff", 20};
  Student student2 = {2, "Bob", 30};

  students[0] = student1;
  students[1] = student2;

  print_options();
  determine_choice(students);

  return 0;
}
