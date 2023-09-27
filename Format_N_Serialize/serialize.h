/*********************************
 * Reviewer: Avigail				
 * Author: Yohai Azoulai			
 * File: WS9binary.c					
 * ******************************/

#ifndef __SERIALIZE_H__
#define __SERIALIZE_H__
#define ASRT(A) ({((NULL == A)?(printf("your assertion failed buddy")&& return 0;):(NULL))\})
#include <stdio.h>
#include <stddef.h>
/*#define ENUM TERMINATE {E_GO, E_ERROR, E_CLOSE = 3}
*/

typedef struct
{
    float sociology_grade;
    float psychology_grade;
    float literature_grade;
} humanistic_grades_t;

typedef struct
{
    float physics_grade;
    float math_grade;
} real_grades_t;

typedef struct
{
    humanistic_grades_t humanistic_grades;
    real_grades_t real_grades;
    float sports_grade;
} grades_t;

typedef struct
{
    char first_name[20];
    char last_name[20];
    grades_t student_grades;
} student_t;


/* "yohai"(5 characters),"azoulai"(7 characters),socio - 85,psycho - 82,lit - 70,phys - 80,math - 97,phys ad - 100*/



int StudentRead (student_t *student, char *file_name);
/*StudentRead is a function to read from a binary file named file_name, and deserialize to a student struct*/
/*Return Value: 0 upon success, or error_number if failed*/

int StudentWrite (student_t *student, char *file_name);
/*StudentWrite is a function that serialize a student struct into a binray file named file_name*/
/*Return Value: 0 upon success, or error_number if failed*/


#endif 
