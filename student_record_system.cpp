#include <stdio.h>
#include <stdlib.h>

int main() {
	//structure to group student related information
	struct student {
	char name[100];
	int roll;
	float marks;
	};
	
	//Open the student.txt file
	FILE *fptr;
	fptr = fopen("student.txt", "a");
	
	//Generate an error message if file is not created
	if(fptr == NULL) {
		printf("Error in opening the File! \n");
		exit(1);
	}
	
	//Taking input from the user
	struct student s;
	printf("Enter your Name :");
	scanf("%s", s.name);
	printf("Enter your roll number :");
	scanf("%d", &s.roll);
	printf("Enter your marks :");
	scanf("%f", &s.marks);
	
	//Printing the information in the student file
	fprintf(fptr, "Name: %s \n", s.name);
	fprintf(fptr, "Roll Number: %d \n", s.roll);
	fprintf(fptr, "Marks obtained : %.2f \n", s.marks);
	fprintf(fptr, "----------------------------------- \n");
	
	//Closing the file
	fclose(fptr);
	
	//Opening the file again
	fptr = fopen("student.txt", "r");
	
	//Generate an error message if file cannot be opened for reading
	if(fptr == NULL) {
	    printf("Error in opening the File! \n");
	    exit(1);
	}
	
	//Declaring line as a string
	char line[200];
	
	//Print a header before storing data
	printf("\n--- Stored Student Records ---\n");

	//Starting a while-loop to print line
	while(fgets(line, sizeof(line), fptr)) {
		printf("%s", line);
	}
	
	//Closing the file
	fclose(fptr);
	
	return 0;
} 
