tp2: tree.o main.o
	g++ -o tp2 main.o tree.o -lm
tree.o: tree.cpp
	g++ -c tree.cpp
main.o:
	g++ -c main.cpp 
clean:
	rm -rf *.o tree main tp2

# Question 4:
# • Why does the build starts with the second target of the makefile?
# • What is the purpose of the clean target ?
