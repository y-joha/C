/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#include <stdio.h>/*fopen,fclose*/
#include<string.h>/*strlen*/
#include "WS9binary.h"


static int WriteFloat(float *num, FILE *file);
static int ReadFloat(float *num, FILE *file);
static int WriteString(const char *str, int str_len, FILE *file);
static int ReadString(char *str, FILE *file);


static int WriteGrades(student_t *student, FILE* file);
static int ReadGrades(student_t *student, FILE* file);
static int WriteHuminstic(grades_t *grades, FILE* file);
static int ReadHuminstic(grades_t *grades, FILE* file);
static int WriteReal(grades_t *grades, FILE* file);
static int ReadReal(grades_t *grades, FILE* file);
void PrintStructW(student_t *std);

/*static void PrintStructR(student_t *std2);*/



/****************************************************************/

static int WriteFloat(float *num, FILE *file)
{
    if(1 != fwrite(num,sizeof(float),1,file))
    {
        return 3;
    }
    return 0;
}

static int WriteString(const char *str, int str_len, FILE *file)
{
    if(1 != fwrite(&str_len,sizeof(int),1,file))
    {
        return 3;
    }

    if(1 != fwrite(str,str_len,1,file))
    {
        return 3;
    }
    return 0;
}

static int ReadFloat(float *num, FILE *file)
{
    if(1 != fread(num,sizeof(float),1,file))
    {
        return 4;
    }
    return 0;
}

static int ReadString(char *str, FILE *file)
{
    int tmp = 0;
    if(1 != fread(&tmp,sizeof(int),1,file))
    {
        return 3;
    }

    if(1 != fread(str,tmp,1,file))
    {
        return 4;
    }
    return 0;
}

static int WriteGrades(student_t *student, FILE* file)
{
    WriteHuminstic(&student->student_grades, file);
    WriteReal(&student->student_grades, file);
    WriteFloat(&student->student_grades.sports_grade, file);

    return(0);
}

static int WriteHuminstic(grades_t *grades, FILE* file)
{
    WriteFloat(&grades->humanistic_grades.sociology_grade, file);
    WriteFloat(&grades->humanistic_grades.psychology_grade, file);
    WriteFloat(&grades->humanistic_grades.literature_grade, file);

    return(0);
}

static int WriteReal(grades_t *grades, FILE* file)
{
    WriteFloat(&grades->real_grades.physics_grade, file);
    WriteFloat(&grades->real_grades.math_grade, file);

    return(0);
}

static int ReadGrades(student_t *student, FILE* file)
{
    ReadHuminstic(&student->student_grades, file);
    ReadReal(&student->student_grades, file);
    ReadFloat(&student->student_grades.sports_grade, file);

    return(0);
}

static int ReadHuminstic(grades_t *grades, FILE* file)
{
    ReadFloat(&grades->humanistic_grades.sociology_grade,file);
    ReadFloat(&grades->humanistic_grades.psychology_grade,file);
    ReadFloat(&grades->humanistic_grades.literature_grade,file);

    return(0);
}

static int ReadReal(grades_t *grades, FILE* file)
{
    ReadFloat(&grades->real_grades.physics_grade, file);
    ReadFloat(&grades->real_grades.math_grade, file);

    return(0);
}

void PrintStructW(student_t *std)
{
    printf("\n");
    printf("/**************/");
    printf("\n");
    printf("student first name: %s\n", std->first_name);
    printf("student last name: %s\n", std->last_name);
    printf("\n");
    printf("Humanitic Grades:\n");
    printf("\n");
    printf("Sociology Grade: %f\n", std->student_grades.humanistic_grades.sociology_grade);
    printf("Psychology Grade: %f\n", std->student_grades.humanistic_grades.psychology_grade);
    printf("Literature Grade: %f\n", std->student_grades.humanistic_grades.literature_grade);
    printf("\n");
    printf("Real grades:\n");
    printf("\n");
    printf("Math Grade: %f\n", std->student_grades.real_grades.math_grade);
    printf("Physics Grade: %f\n", std->student_grades.real_grades.physics_grade);
    printf("\n");
    printf("Other Grades:\n");  
    printf("\n");
    printf("sports:%f\n", std->student_grades.sports_grade);
}

int StudentWrite (student_t *student ,char *file_name)
{
    size_t first_name_size = strlen(student->first_name);
    size_t last_name_size = strlen(student->last_name);

    FILE *file;
    file = fopen(file_name, "wb");
    if(NULL == file)
    {
        return 1;
    }

    WriteString(student->first_name,first_name_size,file);
    WriteString(student->last_name,last_name_size,file);
    WriteGrades(student,file);

    if(fclose(file))
    {
        return (2);
    }
    return (0); 
}


int StudentRead (student_t *student, char *file_name)
{
    FILE *file;
    file = fopen(file_name, "rb");
    if(NULL == file)
    {
        return 1;
    }
     
    
    
    ReadString(student->first_name,file);
    ReadString(student->last_name,file);
    ReadGrades(student,file);

    if(fclose(file))
    {
        return (2);
    }
    return (0);
}
