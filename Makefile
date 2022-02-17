obj = main.o src\\environment.o src\\instruction.o src\\operand.o src\\parsor.o src\\register.o src\\simos.o

main : $(obj)
	g++ $(obj) -o $@

main.o : main.cpp
	g++ main.cpp -c

src\\environment.o : src\\environment.cpp
	g++ $< -c -o $@

src\\instruction.o : src\\instruction.cpp
	g++ $< -c -o $@

src\\operand.o : src\\operand.cpp
	g++ $< -c -o $@

src\\parsor.o : src\\parsor.cpp
	g++ $< -c -o $@

src\\register.o : src\\register.cpp
	g++ $< -c -o $@

src\\simos.o : src\\simos.cpp
	g++ $< -c -o $@

clean:
	rm src\\*.o *.o