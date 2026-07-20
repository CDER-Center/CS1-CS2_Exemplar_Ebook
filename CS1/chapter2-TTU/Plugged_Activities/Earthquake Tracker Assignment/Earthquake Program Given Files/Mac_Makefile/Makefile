# MAC VERSION Makefile

# Use this Makefile to compile and run your code.
#
# 		STEP ONE:   Update the TWO places YOUR/PATH/HERE appears 
#                   to the location where your lab files are located. 
#				    On my computer, the file path was "C:/CSC 1300/PROGRAMS/Program 3"
#                   but your program files may be in a different location.
#
# 		STEP TWO:   In the command prompt in the same directory with this Makefile
# 				    Type "make" to build the executable (named earthquake)
#
#
# 		STEP THREE: Type "make run" to run the executable
#
#       Note: you can type "make clean" to delete the executable file
#
# Review presentation slides & example on Makefiles to understand how they work

#remember - do not use spaces - TABS only!

#start here
all:		Earthquake

# Compile the program with required libraries and create executable named earthquake
# You need to update YOUR/PATH/HERE with your actual file path!
Earthquake:	Prog3.cpp
			g++ -Wall -std=c++17 Prog3.cpp -I "YOUR/PATH/HERE/curl-8.6.0_3-win64-mingw/include" -I "YOUR/PATH/HERE/json/include" -lcurl -o earthquake
# Run
run: 
			./earthquake

# Clean
clean:
			rm -f earthquake