testmap: testmap.o
	g++ -g -Wall $^ -o $@

testmap.o: testmap.cpp map_template.h employee.h library.h
	g++ -g -c -Wall -pedantic $< -o $@

.PHONY: clean

clean:
	-rm testmap.o testmap
