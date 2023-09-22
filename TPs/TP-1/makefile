cosinus: cosinus.o
	g++ -o cosinus cosinus.o -lm
cosinus.o: cosinus.cpp
	g++ -c cosinus.cpp -Wall
hello: hello.o
	g++ -o hello hello.o -lm
hello.o: hello.cpp
	g++ -c hello.cpp -Wall
clean:
	rm -rf *.o cosinus hello

# Question 4:
# • Why does the build starts with the second target of the makefile?
# • What is the purpose of the clean target ?
