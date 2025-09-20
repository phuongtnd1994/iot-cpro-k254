#ifndef STUDENT_H
#define STUDENT_H

typedef struct
{
    char name[50];
    int id;
} student_t;

student_t create_student(const char *name);

int get_student_count();

#endif