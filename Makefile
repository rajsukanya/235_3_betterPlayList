all: LinkedSet.h LinkedSet.cpp Node.h Node.cpp PlayList.h PlayList.cpp Song.h Song.cpp SetInterface.h project_tester.cpp 
	g++ -std=c++11 -o betterPlayList PlayList.cpp Song.cpp project_tester.cpp
