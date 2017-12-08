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
    strcpy(songTitle, "no Title");
    strcpy(artistName, "no Artist");
    songMins = 0;
    songSecs = 0;
    strcpy(albumTitle, "no Album");
    index = 0;
}

//constructor
Song::Song(char songTitle[], char artistName[], int songMins, int songSecs, char albumTitle[], int index){
    strcpy(this->songTitle, songTitle);
    strcpy(this->artistName, artistName);
    this->songMins = songMins;
    this->songSecs = songSecs;
    strcpy(this->albumTitle, albumTitle);
    this->index = index;
}

//following functions will sets the internal value to the parameter
void Song::getSongTitle(char songTitle[]) const{
    strcpy(songTitle, this->songTitle);
}

void Song::getArtistName(char artistName[]) const{
    strcpy(artistName, this->artistName);
}

void Song::getSongMins(int& songMins) const{
    songMins = this->songMins;
}

void Song::getSongSecs(int& songSecs) const{
    songSecs = this->songSecs;
}

void Song::getAlbumTitle(char albumTitle[]) const{
    strcpy(albumTitle, this->albumTitle);
}

void Song::getIndex(int& index) const{
    index = this->index;
}

//print function
void Song::printSong() const{
    cout << left << setw(maxChar) << songTitle << setw(maxChar) << artistName << setw(7) << songMins << setw(7) << songSecs << setw(maxChar) << albumTitle << setw(5) << index << endl;
}

//following functions set the song values
void Song::setSongTitle(const char songTitle[]){
    strcpy(this->songTitle, songTitle);
}

void Song::setArtistName(const char artistName[]){
    strcpy(this->artistName, artistName);
}

void Song::setSongMins(const int songMins){
    this->songMins = songMins;
}

void Song::setSongSecs(const int songSecs){
    this->songSecs = songSecs;
}

void Song::setAlbumTitle(const char albumTitle[]){
    strcpy(this->albumTitle, albumTitle);
}

void Song::setIndex(const int index){
    this->index = index;
}

