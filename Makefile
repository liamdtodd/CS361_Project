CC = g++ -g -std=c++11
exe_file = run
$(exe_file): nutrition.o user.o driver.o
	$(CC) nutrition.o user.o driver.o -o $(exe_file)
nutrition.o: nutrition.cpp
	$(CC) -c nutrition.cpp
user.o: user.cpp
	$(CC) -c user.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
clean:
	rm -f *.out *.o $(exe_file)
