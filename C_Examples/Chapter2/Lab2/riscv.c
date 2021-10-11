#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // malloc & free
#include <stdint.h> // use guaranteed 64-bit integers
#include "tokenizer.h" // Create header file and reference that
#include "memory.h" // built-in functions to read and write to a specific file

int32_t* reg; // Array of 32 32-bit registers

void init_regs();
bool interpret(char* instr);
void write_read_demo();

/**
 * Initialize register array for usage.
 * Malloc space for each 32-bit register then initializes each register to 0.
 * Do not alter this function!
 */
void init_regs(){
	int reg_amount = 32;
	reg = malloc(reg_amount * sizeof(int32_t)); // 32 * 4 bytes
	for(int i = 0; i < 32; i++)
		reg[i] = i;
}



/**
 * Fill out this function and use it to read interpret user input to execute RV64 instructions.
 * You may expect that a single, properly formatted RISC-V instruction string will be passed
 * as a parameter to this function.
 */
bool interpret(char* instr){ 
    char **test = (char **)malloc(sizeof(char *) * (4));
    test = tokenize(instr, " ");
    char [] = sw; 
	//add function
    if (strcomp(test[0], "ADD") == 1) {
        char **inString = (char**)malloc(sizeof(char*) * (1));
	//get destination register
        inString = tokenize(test[1], "X");
        int dest_reg = atoi(inString[0]);
	//get register 1
	inString = tokenize(test[2], "X");
	int reg1 = atoi(inString[0]);
	//get register 2
	inString = tokenize(test[3], "X");
	int reg2 = atoi(inString[0]);
	//add values of 2 registers
	int sum = (long long int)reg[reg1] + (long long int)reg[reg2];
	reg[dest_reg] = sum; 
   
    	}else if(strcomp(test[0], "ADDI") == 1){
		char **inString =(char**)malloc(sizeof(char*) * (4));
		//get destination register
		inString = tokenize(test[1], "X");
		int dest_reg = atoi(inString[0]);
		//get register
		inString = tokenize(test[2], "X");
		int reg1 = atoi(inString[0]);
		//get constant value 
		int constant = atoi(test[3]);
		//add constant and value of register
		int sum = (long long int)reg[reg1] + constant;
		//store into destination register
		reg[dest_reg] = sum;	
		
	
	}else if (strcomp(test[0], "LW") == 1) {
		char **inString =(char**)malloc(sizeof(char*) * (4));
		//gets destination register
		inString = tokenize(test[1],"X");
		int dest_reg = atoi(inString[0]);
		//gets token for offset and register
		inString = tokenize(test[2], "(");
		int offset = atoi(inString[0]); 
		inString = tokenize(inString[1], ")");
		inString = tokenize(inString[0], "X");
		int regi = atoi(inString[0]);
		//add register value and offset to get address
		int32_t address = offset + regi; 
		//read address from memory and store into dest_reg
		int32_t read_value = read_address(address, "mem.txt");
		reg[dest_reg] = (long long int)read_value;
			
	}else if (strcomp(test[0], sw) == 1) {
		char **inString =(char**)malloc(sizeof(char*) * (4));
		//gets destination register
		inString = tokenize(test[1],"X");
		int dest_reg = atoi(inString[0]);
		//gets token for offset and register
		inString = tokenize(test[2], "(");
		int offset = atoi(inString[0]); 
		inString = tokenize(inString[1], ")");
		inString = tokenize(inString[0], "X");
		int regi = atoi(inString[0]);
		//add register value and offset to get address
		int32_t address = regi + offset; 
		//write data into address
		int data_to_write = reg[dest_reg];
		int32_t   write=write_address(data_to_write,address,"mem.txt");
		printf("HEYYYYYY");
		
	}
    return true;

}




//function to compare two given strings
int strcomp(char *str1, char *str2){
	int len1 =0; 
	int len2 = 0;

	for(int i =0; *(str1+i)!='\0';i++){
		len1++;
	}
	for(int i =0; *(str2+i)!='\0';i++){
		len2++;
	}
	
	if (len1 == len2){
		for(int i =0; i< len1; i++){
			if(*(str1+i) == *(str2+i)){
				return 1;
			}	
		}
	}return 0;
	
}


/**
 * Simple demo program to show the usage of read_address() and write_address() found in memory.c
 * Before and after running this program, look at mem.txt to see how the values change.
 * Feel free to change "data_to_write" and "address" variables to see how these affect mem.txt
 * Use 0x before an int in C to hardcode it as text, but you may enter base 10 as you see fit.
 */
void write_read_demo(){
	int32_t data_to_write = 0xFFF; // equal to 4095
	int32_t address = 0x98; // equal to 152
	char* mem_file = "mem.txt";

	// Write 4095 (or "0000000 00000FFF") in the 20th address (address 152 == 0x98)
	int32_t write = write_address(data_to_write, address, mem_file);
	if(write == (int32_t) NULL)
		printf("ERROR: Unsucessful write to address %0X\n", 0x40);
	int32_t read = read_address(address, mem_file);

	printf("Read address %lu (0x%lX): %lu (0x%lX)\n", address, address, read, read); // %lu -> format as an long-unsigned
}

void print_regs(){
	int col_size = 10;
	for(int i = 0; i < 8; i++){
		printf("X%02i:%.*lld", i, col_size, (long long int) reg[i]);
		printf(" X%02i:%.*lld", i+8, col_size, (long long int) reg[i+8]);
		printf(" X%02i:%.*lld", i+16, col_size, (long long int) reg[i+16]);
		printf(" X%02i:%.*lld\n", i+24, col_size, (long long int) reg[i+24]);
	}
}


/**
 * Your code goes in the main
 *
 */
int main(){
	// Do not write any code between init_regs
	init_regs(); // DO NOT REMOVE THIS LINE

	print_regs();

	// Below is a sample program to a write-read. Overwrite this with your own code.
	//write_read_demo();

	printf(" RV32 Interpreter.\nType RV32 instructions. Use upper-case letters and space as a delimiter.\nEnter 'EOF' character to end program\n");

	char* instruction = malloc(1000 * sizeof(char));
	bool is_null = false;
	// fgets() returns null if EOF is reached.
	is_null = fgets(instruction, 1000, stdin) == NULL;
	while(!is_null){
		interpret(instruction);
		printf("\n");
		print_regs();
		printf("\n");

		is_null = fgets(instruction, 1000, stdin) == NULL;
	}

	printf("Good bye!\n");

	return 0;
}

