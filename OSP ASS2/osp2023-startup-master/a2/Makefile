
.default: all

all: sim

clean:
	rm -rf ppd *.o

sim: Driver.o Loader.o Simulator.o pcb.o 
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^	-lpthread

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

# %.o: %.cpp
# g++ -Wall -Werror -std=c++14 -g -O -c -o$^