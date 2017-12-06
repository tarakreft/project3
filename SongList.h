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
    
    void readLibrary(const char fileName[]);
    void saveLibrary(const char fileName[]) const;
    int  setSongListSize() const;
    void searchForArtist() const;
    void searchForAlbum() const;
    void displaySongs() const;
    void addSong(const char fileName[], const Song& addedSong);
//    void removeSong(const char fileName[], song songList[]);
    
private:
    Song listOfSongs[maxList];
    int  songListSize;
};

#endif /* SongList_h */
