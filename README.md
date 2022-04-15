# MPI-Lab

LABORATORY 1 TASKS:
1. Write a program that prints all the prime numbers less than N using M processes.
2. Write a program that searches an element inside an array and prints its position in case the array
contains that element, otherwise it prints 'Not found.'
3. Let there be n processes. Each process generates m (m>=100) random numbers ( <=1000 ), prints
them to the console, computes their sum and prints it to the console. Determine the time it takes for
each process to complete the job.

LABORATORY 2 TASKS:
1. Write a program that searches an element inside an array.
a. Use MPI_Broadcast for sending the array. If the element is found, print the maximum
position index. For computing the maximum position, you need to use MPI_Reduce.
b. Use scatter for sending the array. If the element is found many times, print all its positions.
Use MPI_Gather for sending back the positions.

LABORATORY 3 TASKS:
1. Define a type called Student that stores information about students. Create a list of students, and
then using n processors, search for one specific student.
