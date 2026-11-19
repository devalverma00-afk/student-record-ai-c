# AI-Assisted Student Record and Result Management System

## Project Information

- Course: Programming in C
- Course Code: PRC1001
- SAP ID: 590034319
- Language: C

## Project Description

This project is a console-based, menu-driven Student Record and Result Management System developed using C programming.

The system allows users to add, search, display, delete, and sort student records. It also calculates student CGPA and average CGPA by year.

The project includes an AI-Assisted Academic Advisor that provides academic recommendations based on the student's CGPA.

## Features

1. Add Student Record
2. Search Student by SAP ID
3. Calculate Student CGPA
4. Calculate Average CGPA by Year
5. Display All Student Records
6. Delete Student Record
7. Sort Students by SAP ID
8. Sort Students by Name
9. AI-Assisted Academic Advisor
10. Exit

## Student Information Stored

The program stores:

- SAP ID
- Roll Number
- Name
- Phone Number
- Email ID
- Year
- Current Semester
- SGPA for up to 8 semesters

## AI-Assisted Academic Advisor

The academic advisor uses the student's CGPA to provide simple academic recommendations using if-else statements.

- CGPA >= 9.0: Excellent Performance
- CGPA >= 7.5: Good Performance
- CGPA >= 6.0: Needs Improvement
- CGPA < 6.0: Requires Immediate Attention

No external AI API is used in the C program.

## How to Compile

Using GCC:

gcc 590034319.c -o student_record

## How to Run

On Windows:

student_record.exe

## AI Assistance

ChatGPT was used as a learning assistant for understanding C programming concepts, designing the CGPA-based academic advisor, generating test cases, debugging, and improving project documentation.