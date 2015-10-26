# edit this makefile so that running make compiles your enigma program

enigma: Main.o Enigma.o Plugboard.o Rotor.o RotorConnector.o Reflector.o Utils.o
	g++ -o enigma Main.o Enigma.o Plugboard.o Rotor.o RotorConnector.o Reflector.o Utils.o

Main.o: Main.cpp
	g++ -c Main.cpp

Enigma.o: classes/Enigma.cpp classes/Enigma.hpp
	g++ -c classes/Enigma.cpp

Plugboard.o: classes/Plugboard.cpp classes/Plugboard.hpp
	g++ -c classes/Plugboard.cpp

Rotor.o: classes/Rotor.cpp classes/Rotor.hpp
	g++ -c classes/Rotor.cpp

RotorConnector.o: classes/RotorConnector.cpp classes/RotorConnector.hpp
	g++ -c classes/RotorConnector.cpp


Reflector.o: classes/Reflector.cpp classes/Reflector.hpp
	g++ -c classes/Reflector.cpp

Utils.o: Utils.cpp Utils.hpp
	g++ -c Utils.cpp

all: enigma

clean:
	rm -rf enigma *.o

.PHONY: clean all
