#ifndef EMPLOYEES_H
#define EMPLOYEES_H

int displayEmployees(int employeeID[], char employeeName[][50],
                     char department[][50], float basicSalary[],
                     float housingAllowance[], float transportAllowance[],
                     int employeeCount);

int searchEmployee(int employeeID[], char employeeName[][50],
                   char department[][50], float basicSalary[],
                   float housingAllowance[], float transportAllowance[],
                   int employeeCount);

float calculateSalary(int employeeID[], float basicSalary[],
                      float housingAllowance[], float transportAllowance[],
                      int employeeCount);

int displayEmployeeInformation(int employeeID[], char employeeName[][50],
                               char department[][50], float basicSalary[],
                               float housingAllowance[], float transportAllowance[],
                               int employeeCount);

int addEmployee(int employeeID[], char employeeName[][50],
                char department[][50], float basicSalary[],
                float housingAllowance[], float transportAllowance[],
                int employeeCount);

#endif