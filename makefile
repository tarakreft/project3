CC = g++
CPPFLAGS = -Wall -g -std=c++11

app: project3.cpp song.o songlist.o

song.o: Song.h Song.cpp

songlist.o: SongList.h SongList.cpp

.PHONY: clean
clean:
	$(info -- cleaning the directory -- )
	rm -f *.o
	rm -f app
