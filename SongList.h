//
//  SongList.h
//
//  Created by Tara Kreft
//

#ifndef SongList_h
#define SongList_h

#include "Song.h"

const int maxList = 100;

//songlist Model
class SongList {
public:
    SongList();
    SongList(const char fileName[]);
    
    void readLibrary(char fileName[]);
    int  setSongListSize() const;
    void searchForArtist(const char searchTerm[], Song& matchingSong) const;
    void searchForAlbum(const char searchTerm[], Song& matchingSong) const;
    
    void addSong(song& addedSong, song songList[], int& songListSize);
    void displaySongs(song songList[], int& songListSize);
    void addNewSong(char fileName[], song songList[], int& songListSize);
    void removeSong(char fileName[], song songList[], int& songListSize);
    void saveLibrary(char fileName[], song songList[], int& songListSize);
    
private:
    Song listOfSongs[maxList];
    int  songListSize;
};

#endif /* SongList_h */
