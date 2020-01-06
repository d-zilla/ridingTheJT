
output: main.o Game.o Space.o Interior.o Coastal.o Subtropical.o mainMenuSelection.o validInt.o yesOrNo.o compass.o
	g++ main.o Game.o Space.o Interior.o Coastal.o Subtropical.o mainMenuSelection.o validInt.o yesOrNo.o compass.o -o output

main.o: main.cpp Game.hpp mainMenuSelection.hpp
	g++ -c main.cpp Game.cpp mainMenuSelection.cpp

Game.o: Game.cpp Game.hpp Interior.hpp Coastal.hpp Subtropical.hpp
	g++ -c Game.cpp Interior.cpp Coastal.hpp Subtropical.hpp 

Space.o: Space.cpp Space.hpp validInt.hpp yesOrNo.hpp compass.hpp
	g++ -c Space.cpp validInt.cpp yesOrNo.cpp compass.cpp

Interior.o: Interior.cpp Interior.hpp Space.hpp
	g++ -c Interior.cpp Space.cpp

Coastal.o: Coastal.cpp Coastal.hpp Space.hpp
	g++ -c Coastal.cpp Space.cpp

Subtropical.o: Subtropical.cpp Subtropical.hpp Coastal.hpp
	g++ -c Subtropical.cpp Coastal.cpp

mainMenuSelection.o: mainMenuSelection.cpp mainMenuSelection.hpp validInt.hpp
	g++ -c mainMenuSelection.cpp validInt.cpp

yesOrNo.o: yesOrNo.cpp yesOrNo.hpp
	g++ -c yesOrNo.cpp

validInt.o: validInt.cpp validInt.hpp
	g++ -c validInt.cpp

compass.o: compass.cpp compass.hpp
	g++ -c compass.cpp

clean:
	rm *.o output
