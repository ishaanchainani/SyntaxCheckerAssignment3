HEADERS = GenStack.h
OBJS = main.o

all: assign3

assign3: $(OBJS)
	g++ -g -Wall -std=c++11 -o $@ $^

.cpp.o: $(HEADERS)
	g++ -g -Wall -std=c++11 -c $<

clean: FORCE
	/bin/rm -f *~ *.o assign3

FORCE:
