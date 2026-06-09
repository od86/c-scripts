#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>

int lines_to_clear = 1;

typedef struct
{
  int id;
  char name[20];
  int age;
} Student;

void show_menu() {
  printf("\n +----------------+-----+\n");
  printf(" | Function       | Num |\n");
  printf(" +----------------+-----+\n");
  printf(" | All students   |  0  |\n");
  printf(" | Create student |  1  |\n");
  printf(" | Find Student   |  2  |\n");
  printf(" | Delete Student |  3  |\n");
  printf(" | Exit program   | >=4 |\n");
  printf(" +----------------+-----+\n\n");
}

void delete_student(int num_of_students, Student *students) {

}

void find_by_id(int num_of_students, Student *students) {
  int id;
  bool student_exists = false;

  printf(" Stduent id: ");
  scanf("%i", &id);

  printf("\n Student:\n");

  for (int i = 0; i < num_of_students; i++)
  {
    if (students[i].id == id) 
    {
      printf(" Id: %i | Name: %s | Age: %i\n\n", 
        students[i].id, 
        students[i].name,
        students[i].age);
      student_exists = true;
      break;
    }
  }

  if(student_exists == false) {
    printf(" NO STUDENTS HAVE AN ID OF %i\n\n", id);
  }
}

void show_students(int num_of_students, Student *students) {
  printf(" STUDENTS:\n");

  for (int i = 0; i < num_of_students; i++)
  {
    printf(" Id: %i | Name: %s | Age: %i\n", 
      students[i].id, 
      students[i].name,
      students[i].age);
  }

  printf("\n");
}

Student create_student(int num_of_students) {
  char name[20];
  int age;

  printf(" Student name: ");
  scanf("%s", name);
  printf(" Student age: ");
  scanf("%i", &age);
  printf("\n");

  Student student;
  student.id = num_of_students + 1;
  strcpy(student.name, name);
  student.age = age;

  return student;
}

Student *add_student(int num_of_students, Student *students) {
  Student student = create_student(num_of_students);
  students = (Student *)realloc(students, (num_of_students + 1) * sizeof(Student));
  
  if (students == NULL) 
  {
    printf("Memory Reallocation Failed\n");
  }

  students[num_of_students] = student; 
  return students;
}

void main_loop(int num_of_students, Student *students) {
  int choice;

  printf(" Enter number of what you'd like to do: ");
  scanf("%i", &choice);

  printf("\e[%iA\e[J", lines_to_clear);
  lines_to_clear = 1;

  if (choice == 0) 
  {
    lines_to_clear = 3 + num_of_students;
    show_students(num_of_students, students);
    main_loop(num_of_students, students);
  } 
  else if (choice == 1)
  {
    lines_to_clear = 4;
    students = add_student(num_of_students, students);
    num_of_students++;
    main_loop(num_of_students, students);
  } 
  else if (choice == 2)
  {
    lines_to_clear = 6;
    find_by_id(num_of_students, students);
    main_loop(num_of_students, students);
  }
  else if (choice == 3)
  {
    lines_to_clear = 1;
    main_loop(num_of_students, students);
  }
  else 
  {
    printf(" --- EXITING PROGRAM ---\n\n");
  }
}

int main() {
  printf("\n --- STARTING PROGRAM ---\n\n");

  int num_of_students = 0;
  Student *students = (Student *)malloc(sizeof(Student));
  students = add_student(num_of_students, students);
  num_of_students++;

  printf("\e[4A\e[J");
  show_menu();
  main_loop(num_of_students, students);
  return 0;
}
