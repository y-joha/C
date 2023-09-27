/*********************************
 * Reviewer: Avigail				
 * Author: Yohai Azoulai			
 * File: WS9binary_test.c				
 * ******************************/

#include "serialize.h" 
void PrintStructW(student_t *std);


int main()
{
    student_t stud = {"yohai","azoulai",{{75.2,80.4,99.1},{85.2,64.3},88.2}};
    student_t stud1= {"","",{{0,0,0},{0,0},0}};
    StudentWrite(&stud,"studentbin.bin");
    PrintStructW(&stud);

    StudentRead(&stud1,"studentbin.bin");
    PrintStructW(&stud1);



    return 0;
}
