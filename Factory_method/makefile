all: main.o pizza.o kitchen.o
	g++ -o main $^ -Wall



%.o: %.cpp
	g++ -c $^

clean:
	rm *.o main