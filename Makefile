CXX = g++-4.9									# compiler
CXXFLAGS = -g -Wall -Werror -std=c++11 -MMD				# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}			# makefile name

OBJECTS = student.o watcardoffice.o vendingmachine.o nameserver.o bottlingplant.o truck.o printer.o  # object files forming executable
EXEC = soda										# executable name

DEPENDS = ${OBJECTS:.o=.d}						# substitute ".o" with ".d"

${EXEC} : ${OBJECTS}							#link step
	${CXX} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}								# include *.d files containing program dependences

.PHONY : clean
clean :											# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}

