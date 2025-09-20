#include <stdio.h>
#include "student.h"

int main()
{
    printf("Initial number of students: %d\n", get_student_count());

    student_t student_1 = create_student("Alice");
    student_t student_2 = create_student("Bob");

    printf("Student 1 Info: Name=%s, ID=%d\n", student_1.name, student_1.id);
    printf("Current number of students: %d\n", get_student_count());

    return 0;
}