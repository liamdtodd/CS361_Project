CC = g++ -g -std=c++11
exe_file = run
$(exe_file): nutrition.o fitness.o user.o driver.o main.o
	$(CC) nutrition.o fitness.o user.o driver.o main.o -o $(exe_file)
nutrition.o: nutrition.cpp
	$(CC) -c nutrition.cpp
fitness.o: fitness.cpp
	$(CC) -c fitness.cpp
user.o: user.cpp
	$(CC) -c user.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
main.o: main.cpp
	$(CC) -c main.cpp
clean:
	rm -f *.out *.o $(exe_file)
