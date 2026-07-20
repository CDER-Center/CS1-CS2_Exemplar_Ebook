# *****************************MAC VERSION of Makefile
# This is a comment

# The Makefile is named Makefile with no extension and should be in the SAME folder as your source files.
# Then, open your terminal in this folder.

# Type "make" (without the double quotes) in terminal to compile (build) your program
# Type "make run" (without the double quotes) in terminal to run your program
# Type "make clean" (without the double quotes) in terminal to delete the executable file

#remember - do not use spaces in the rules - TABS only!

#Default rule - the first rule listed in the Makefile. It's the entry point for the build process. 
#It's the rule that "make" will execute when you just type make with no arguments.
all:		Turtleprog


# The rule below will compile the program if driver.cpp and functions.cpp exists.
Turtleprog: driver.cpp functions.cpp
			g++ -Wall -o turtleprog driver.cpp functions.cpp

# Execute the rule below with "make run" (without the double quotes), which will run the program if the turtleprog executable exists.
run:		turtleprog
			./turtleprog

# Execute the rule below with "make clean" (without the double quotes), which will delete the executable file turtleprog if it exists.	
clean:		turtleprog		
			rm -f turtleprog
	