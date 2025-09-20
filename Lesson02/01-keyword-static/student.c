#include "student.h"
#include <string.h>

static int s_student_count = 0;

static int s_next_id = 1;

student_t create_student(const char *name)
{
    student_t new_student;
    strcpy(new_student.name, name);
    new_student.id = s_next_id;

    s_student_count++;
    s_next_id++;

    return new_student;
}

int get_student_count()
{
    return s_student_count;
}