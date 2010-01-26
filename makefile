
testcase:TinyDNSResolver.h
	g++ -o test.o -g -Wall TinyDNSResolver.h TinyDNSResolver.cpp test.cpp -lpthread
clean:
	rm *.o 
