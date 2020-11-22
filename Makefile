M=Matrix
D=Driver
CFLAGS= -std=c++14

all: $(M).o $(D).o
	g++ $(CFLAGS) $(D).o $(M).o -o $(D)

$(M).o : $(M).cpp $(M).h
	g++ $(CFLAGS) -c $(M).cpp -o $(M).o

$(D).o : $(D).cpp
	g++ $(CFLAGS) -c $(D).cpp -o $(D).o


clean:
	rm $(D) *.o

run: all
	./$(D)
