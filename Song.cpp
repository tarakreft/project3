//
//  Song.cpp
//
//  Created by Tara Kreft
//

#include "Song.h"
#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

//default constructor
Song::Song(){
    strncpy(songTitle, "no Title");
    strncpy(artistName, "no Artist");
    songMins = 0;
    songSecs = 0;
    strncpy(albumTitle, "no Album");
    index = 0;
}

//constructor
Song::Song(char songTitle[], char artistName[], int songMins, int songSecs, char albumTitle[], int index){
    strncpy(this->songTitle, songTitle);
    strncpy(this->artistName, artistName);
    this->songMins = songMins;
    this->songSecs = songSecs;
    strncpy(this->albumTitle, albumTitle);
    this->index = index;
}

//following functions will returns each parameter
void Song::getSongTitle(char songTitle[]) const{
    strncpy(songTitle, this->songTitle);
}

void Song::getArtistName(char artistName[]) const{
    strncpy(artistName, this->artistName);
}

void Song::getSongMins(int songMins) const{
    songMins = this->songMins;
}

void Song::getSongSecs(int songSecs) const{
    songSecs = this->songSecs;
}

void Song::getAlbumTitle(char albumtTitle[]) const{
    strncpy(albumTitle, this->albumTitle);
}
void Song::getIndex(int index) const{
    index = this->index;
}

//print function
void Song::printSong() const{
    cout << left << setw(maxChar) << songTitle << setw(maxChar) << artistName << setw(7) << songMins << setw(1) << " " << setw(7) << songSecs << setw(maxChar) << albumTitle << setw(5) << index << endl;
}

//following functions set the song values
void Song::setSongTitle(const char songTitle[]){
    strncpy(this->songTitle, songTitle);
}

void Song::setArtistName(const char artistName[]){
    strncpy(this->artistName, artistName);
}

void Song::setSongMins(const int songMins){
    this->songMins = songMins;
}

void Song::setSongSecs(const int songSecs){
    this->songSecs = songSecs;
}

void Song::setAlbumTitle(const char albumtTitle[]){
    strncpy(this->albumTitle, albumTitle);
}

void Song::setIndex(const int index){
    this->index = index;
}
