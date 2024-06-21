#include<stdio.h>
#include<stdlib.h>
#include "matrix.h"


//Function to validate and open a file in read mode
FILE* validate_input(int argc, char* argv[]){//takes in argument count and argument vector as parameters

	FILE* fp = NULL;

	if(argc < 2){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 2){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}
	
	fp = fopen(argv[1], "r");
	
	if(fp == NULL){
		printf("Unable to open file: %s\nEnding program.\n", argv[1]);
		exit(0);
	}
	
	return fp;//returns the file pointer

}

//main program
int main(int argc, char *argv[]) {
    // Check if the correct number of command-line arguments is provided
    FILE* fp = validate_input(argc, argv);

    matrix *m = ReadMatrix(fp);//read matrix from file

    double determinant = Determinant(*m);//find the determinant
    
    printf("The determinant is %.2lf.\n", determinant);
    // Closing the file
    fclose(fp);
    return 0;
}
