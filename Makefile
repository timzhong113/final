CXX = g++-4.9						# compiler
CXXFLAGS = -g -Wall -Werror -std=c++11 -MMD		# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}		# makefile name

# object files forming executable
OBJECTS = watcola.o student.o watcardoffice.o vendingmachine.o nameserver.o bottlingplant.o truck.o
EXEC = soda						# executable name

DEPENDS = ${OBJECTS:.o=.d}				# substitute ".o" with ".d"

${EXEC} : ${OBJECTS} printer.o				#link step
	${CXX} ${OBJECTS} printer.o -o ${EXEC}

-include ${DEPENDS}					# include *.d files containing program dependences

.PHONY : clean
# remove files that can be regenerated
clean :
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
