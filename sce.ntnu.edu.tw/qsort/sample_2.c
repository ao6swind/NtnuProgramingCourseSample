#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
typedef struct student
{
    int id;
    int age;
    char name[20];
} Student;

int compareFun(const void *a, const void *b)
{
    return (*(Student *)a).age - (*(Student *)b).age;
}

int main()
{
    Student students[10];
    for (int i = 0; i < 10; i++)
    {
        students[i].id = i + 1;
        students[i].age = 10 + (rand() % 10); // 10~19歲
        strcpy(students[i].name, "student_");
        students[i].name[8] = i + '0';
    }
    printf("Before sort by age:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\t%2d %s %d\n", students[i].id, students[i].name, students[i].age);
    }
    printf("\n");

    qsort(students, 10, sizeof(Student), compareFun);
    printf("After sort by age:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("\t%2d %s %d\n", students[i].id, students[i].name, students[i].age);
    }
    printf("\n");

    return 0;
}