obj = main.o ..\VirtualOS\src\environment.o \
	..\VirtualOS\src\instruction.o\
	 ..\VirtualOS\src\operand.o\
	  ..\VirtualOS\src\parsor.o\
	   ..\VirtualOS\src\register.o\
	    ..\VirtualOS\src\simos.o\
		 src\program.o \


main : $(obj)
	g++ $(obj) -o $@

main.o : main.cpp
	g++ main.cpp -c

\src\%.o : \src\%.cpp
	g++ $< -c

..\VirtualOS\src\%.o : ..\VirtualOS\src\%.cpp
	g++ $< -c -o $@

clean:
	rm ..\\VirtualOS\\src\\*.o *.o *.exe src\\*.o