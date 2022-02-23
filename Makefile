obj = main.o \
		src\program.o \
		src\mcmc.o \
		src\environment.o \
		src\instruction.o \
		src\operand.o \
		src\parsor.o \
		src\register.o \
		src\simos.o \


main : $(obj)
	g++ $(obj) -o $@

main.o : main.cpp
	g++ main.cpp -c

\src\%.o : \src\%.cpp
	g++ $< -c

\src\%.cpp : \src\%.h

clean:
	rm *.o *.exe src\\*.o