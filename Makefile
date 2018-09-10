test: main.c conversionFunctions.c encodingFunctions.c menuCommands.c 
	gcc main.c conversionFunctions.c encodingFunctions.c menuCommands.c -o test -lm -I .

