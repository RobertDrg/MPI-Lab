/*#include<iostream>
#include<mpi.h>


 using namespace std;

 int ciur[20];
 */
 /*int main() {

	 int rank, size;
	 int a = 0;
	 int v[20];
	 int total_sum = 0, s;
	 int N = 20;
	 MPI_Status status;

	 MPI_Init(NULL, NULL);

	 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	 MPI_Comm_size(MPI_COMM_WORLD, &size);*/


	 //Ex 1
	 /*ciur[1] = 1;
	 for (int i = 2; i <= N; i++) {
		 if (ciur[i] == 0) {
			 for (int j = 2 * i; j <= N; j = j + i) {
				 ciur[j] = 1;
			 }
		 }
	 }

	 if (rank == 0) {
		 int k = 1;
		 int limit = size - 1;
		 for (int i = 0; i <= N; i += limit) {
			 v[0] = i;
			 v[1] = i + limit - 1;
			 MPI_Send(&v, 2, MPI_INT, k, 1, MPI_COMM_WORLD);
			 k++;
		 }
	 }

	 if (rank != 0) {

		 MPI_Recv(&v, 2, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		 int a = v[0];
		 int b = v[1];


		 if (a < 20) {
			 for (a; a <= b; a++) {
				 if (ciur[a] == 0) {
					 cout << a << " is prime \n";
				 }
			 }
		 }

	 }
	 MPI_Finalize();
 }*/


	//Ex 2
	 /*for (int i = 0; i < 20; i++) {
		 v[i] = i;
	 }

	 if (rank == 0) {
		 int vector[3];

		 int findNumber = 6;
		 int limit = size - 1;
		 for (int i = 1; i < size; i++) {
			 vector[0] = (i - 1) * limit;
			 vector[1] = limit * i - 1;
			 vector[2] = findNumber;
			 MPI_Send(&vector, 3, MPI_INT, i, 1, MPI_COMM_WORLD);
		 }

		 int flag;
		 bool isFound = false;
		 for (int i = 1; i < size; i++) {
			 MPI_Recv(&flag, 1, MPI_INT, i, 1, MPI_COMM_WORLD, &status);
			 if (flag >= 0) {
				 isFound = true;
				 cout << "The number can be found at position:" << flag;
			 }
		 }

		 if (!isFound) {
			 cout << "Not found" << endl;
		 }
	 }

	 if (rank != 0) {
		 int vect[3];
		 MPI_Recv(&vect, 3, MPI_INT, 0, 1, MPI_COMM_WORLD, &status);
		 int a = vect[0];
		 int b = vect[1];
		 int num = vect[2];
		 bool flag = false;

		 for (a; a <= b; a++) {
			 if (v[a] == num) {
				 flag = true;
			 }
		 }

		 int trans;
		 if (flag) {
			 trans = a;
		 }
		 else {
			 trans = -1;
		 }
		 MPI_Send(&trans, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
	 }
	 MPI_Finalize();
}*/

 //Ex 3
 /*int main() {

	 int rank, size;
	 MPI_Status status;

	 MPI_Init(NULL, NULL);

	 MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	 MPI_Comm_size(MPI_COMM_WORLD, &size);

	 double start = MPI_Wtime();

	 int n = size;
	 int m = rand() % 901 + 100;

	 int sum = 0;

	 srand(time(NULL) + rank);

	 cout << "rank " << rank << ": ";
	 for (int j = 1; j <= m; j++) {
		 int number = rand() % 1000 + 1;
		 cout << number << " ";
		 sum += number;
	 }
	 cout << endl;

	 cout << "Sum for rank " << rank << " is " << sum << endl;

	 double end = MPI_Wtime();
	 cout << "The process " << rank << " took " << end - start << " seconds" << endl;

	 MPI_Finalize();
 }*/

//// LAB 2
//a
/*
#include "mpi.h"
#include <random>
#include <ctime>
#define SIZE 20
#define MASTER 0
#define NOT_FOUND -1

int rank, size;
int numbers[SIZE], result;
int numberToSearch;
int maxPosition = NOT_FOUND;

int main(int argc, char** argv) {

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == MASTER) {
		srand(time(NULL));
		numberToSearch = atoi(argv[1]);
		for (int i = 0; i < SIZE; i++) {
			numbers[i] = rand() % SIZE;
		}
		for (int i = 0; i < SIZE; i++) {
			printf("%d ", numbers[i]);
		}
		printf("\n");
	}

	MPI_Bcast(&numberToSearch, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
	MPI_Bcast(numbers, SIZE, MPI_INT, MASTER, MPI_COMM_WORLD);

	int distribution = SIZE / size;
	int last = SIZE % size;

	int lowBoundry = rank * distribution;
	int highBoundry = lowBoundry + distribution;

	if (rank == size - 1) {
		highBoundry += last;
	}

	for (int i = lowBoundry; i < highBoundry; i++) {

		if (numbers[i] == numberToSearch) {
			maxPosition = i;
		}
	}

	MPI_Reduce(&maxPosition, &result, 1, MPI_INT, MPI_MAX, MASTER, MPI_COMM_WORLD);

	if (rank == MASTER) {
		if (result == NOT_FOUND) {
			printf("Number not found");
		}
		else {
			printf("Maximum position is %d.\n", result);
		}
	}
	MPI_Finalize();
}
*/
//b
/*
#include "mpi.h"
#include <random>
#include <ctime>
#define SIZE 20
#define MASTER 0
#define NOT_FOUND -1

int main(int argc, char** argv) {
	int rank, size;
	int numbers[SIZE], result;
	int numberToSearch;
	int maxPosition = NOT_FOUND;

	MPI_Init(NULL, NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	int* receiveResult = new int[SIZE];

	if (rank == MASTER) {
		srand(time(NULL));
		numberToSearch = atoi(argv[1]);
		for (int i = 0; i < SIZE; i++) {
			numbers[i] = rand() % SIZE;
		}
		for (int i = 0; i < SIZE; i++) {
			printf("%d ", numbers[i]);
		}
		printf("\n");
	}

	int distribution = SIZE / size;
	int last = SIZE % size;
	int* numbersToSearch = new int[distribution];

	MPI_Bcast(&numberToSearch, 1, MPI_INT, MASTER, MPI_COMM_WORLD);
	MPI_Scatter(numbers, distribution, MPI_INT, numbersToSearch, distribution, MPI_INT, MASTER, MPI_COMM_WORLD);

	int* resultsOfProcess = new int[distribution];

	int top = -1;
	for (int i = 0; i < distribution; i++) {
		if (numbersToSearch[i] == numberToSearch) {
			resultsOfProcess[++top] = i + rank * distribution;
		}
	}

	for (int i = top + 1; i < distribution; i++) {
		resultsOfProcess[i] = NOT_FOUND;
	}

	MPI_Gather(resultsOfProcess, distribution, MPI_INT, receiveResult, distribution, MPI_INT, MASTER, MPI_COMM_WORLD);

	if (rank == MASTER) {
		for (int i = 0; i < SIZE; i++) {
			if (receiveResult[i] > NOT_FOUND) {
				printf("Number %d was found at %d.\n", numberToSearch, receiveResult[i]);
			}
		}
	}
	MPI_Finalize();
}
*/

//// LAB 3

#include <iostream>
#include <string.h>
#include <mpi.h>

#define idToSearch 6
#define noOfStudents 10
#define MASTER 0

typedef struct {

    char name[25];
    int studentId;

}student;

int main(int argc, char** argv)
{
    int rank;
    int size;

    student students[10];
    char name[10][25] = { "robert", "andrei", "anca", "mircea", "claudia", "mihai", "ionut", "ciprian", "maria", "iulia" };
    int ids[10] = { 1,7,5,8,2,10,4,3,6,9 };
    int blockcounts[2];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Status status;
    MPI_Aint offsets[2];
    /*derived data types*/
    MPI_Datatype dataTypes[2] = { MPI_CHAR, MPI_INT };

    /*define the struct student with name and id*/
    offsets[0] = offsetof(student, name); 
	blockcounts[0] = 1;
    offsets[1] = offsetof(student, studentId);
	blockcounts[1] = 1;

    MPI_Datatype studentType; 

    /*created structured type and commit it 
    can contain multiple data types*/
    MPI_Type_create_struct(2, blockcounts, offsets, dataTypes, &studentType);
    MPI_Type_commit(&studentType);

    for (int i = 0; i < noOfStudents; i++){
        strcpy_s(students[i].name, name[i]);
        students[i].studentId = ids[i];
    }

    int length = noOfStudents / size; // numbers per rank
    /* set the limit for rank */
    int start = rank * length;
    int stop = rank * length + length;

    /* sending the list of students*/
    MPI_Bcast(&students, noOfStudents, studentType, MASTER, MPI_COMM_WORLD);
    bool found = false;
    int index = 0;

    /*search the id*/
    for (int i = start; i <= stop; i++){
        if (students[i].studentId == idToSearch){
            found = true;
            index = i;
            break;
        }
    }

    /*print the id if it found, and the name of student*/
    if (found){
        std::cout << "The rank " << rank << " found the student with the id " << idToSearch << " and his/her name is \"" << students[index].name << "\" at position " << index << std::endl;
    }
    else{
        std::cout << "The rank " << rank << " not found the student with the id " << idToSearch << std::endl;
    }

    MPI_Finalize();
}

