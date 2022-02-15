headers = ./include/*.h
srcs = ./src/*.cpp

main : main.cpp
	cls && g++ -O2 main.cpp $(srcs) -o main

clean :
	rm -rf main.exe