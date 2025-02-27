8-bit-processor-cpp2asm
#Fetarue
1) Variable Declarations: 
						Supports declaring integer variables.
2) Assignment Operations: 
					   Can handle basic assignments (a = 10 or a = b + c).
3) Print Statements: 	
				   Converts print statements into assembly commands for output.
4) Error Handling:
			    Checks for undefined variables and reports errors.
5) Assembly Code Generation:
							Generates assembly code for each statement in the input

#Input(Simple Language Code):-
1) int a ;
2) int b ;
3) int c ;
4) a = 10 ;
5) b = 20 ;
6) c = a + b ;

#Output:-
1) MOV A, # 10
2) STD 0
3) MOV A, # 20
4) STD 0
5) LDA 0 STD 0


# How the Code Works
1) Tokenization (Token1 function): The input Simple Language code is split into tokens (keywords, variables, operators) for easier processing.

2) Logic Processing (check_logic_code function): Each token is analyzed to identify whether it is a variable declaration, an assignment, or a print statement.

3) Assembly Code Generation (Assembly_Text_Converter function): Based on the identified statements, assembly code is generated. Variables are tracked in a map, and assembly commands are constructed to represent each operation.

# File Output
1) The generated assembly code will be saved into a file named OutPut.asm in the same directory as the program.


