#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct
{
  int id;
  char name[20];
  int age;
} Student;

void add_student(Student *students) {
  
}

Student find_by_id(int id, Student *students) {
  Student student;

  for (int i = 1; i > 0; i++)
  {
    if (students[i].id > 10) {
      break;
    }

    if (students[i].id == id) {
      student = students[i];
      break;
    }
  }

  return student;
}

void print_all_students(Student *students) {
  printf("Students:\n");
  printf("--------------------\n");
  for (int i = 1; i > 0; i++)
  {
    if (students[i].id > 10) {
      break;
    }

    printf("ID: %i | Name: %s | Age: %i | i: %i\n", 
      students[i].id, 
      students[i].name,
      students[i].age,
      i);
  }
}


int main() {
  Student *students = (Student *)malloc(sizeof(Student));

  Student student = {0, "test", 0};
  students[0] = student;

  add_student(students);

  return 0;
}
