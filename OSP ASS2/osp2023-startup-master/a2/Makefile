
.default: all

all: fifo sjf rr

clean: clean_fifo clean_sjf clean_rr

clean_fifo:
	rm -rf ppd *.o

clean_sjf:
	rm -rf ppd *.o

clean_rr:
	rm -rf ppd *.o

fifo: Driver.o Loader.o Simulator.o pcb.o Schedule.o fifo.o sjf.o rr.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^	

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

sjf: Driver.o Loader.o Simulator.o pcb.o Schedule.o sjf.o rr.o fifo.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

rr: Driver.o Loader.o Simulator.o pcb.o Schedule.o rr.o fifo.o sjf.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@ $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^

# %.o: %.cpp
# g++ -Wall -Werror -std=c++14 -g -O -c -o$^