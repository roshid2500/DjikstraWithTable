M=Matrix
D=driver
CFLAGS= -std=c++14

all: $(M).o $(D).o
	g++ $(CFLAGS) $(D).o $(M).o -o $(D)

$(M).o : $(M).cpp
	g++ $(CFLAGS) -c $(P).cpp -o $(P).o

$(D).o : $(D).h $(D).cpp
	g++ $(CFLAGS) -c $(D).cpp -o $(D).o


clean:
	rm $(D) *.o

run: all
	./$(D)
