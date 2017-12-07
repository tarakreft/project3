//
//  SongList.cpp
//
//  Created by Tara Kreft
//

#include "SongList.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

SongList::SongList(){
    songListSize = 0;
}

SongList::SongList(const char fileName[]){
    songListSize = 0;
    readLibrary(fileName);
}

//read the song library file
void SongList::readLibrary(const char fileName[]){
        
    ifstream infile;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    char     tempMins[4];
    int      songSecs;
    char     tempSecs[4];
    char     albumTitle[maxChar];
    int      index;
    char     tempIndex[4];
    Song     addedSong;
        
    infile.open(fileName);
        
    if(!infile){
        infile.clear();
        cout << "Could not open at this time." << endl;
        return;
    }

    while(infile.peek() != EOF){
        infile.get(songTitle, maxChar, ';');
        infile.get();
        infile.get(artistName, maxChar, ';');
        infile.get();
        infile.get(tempMins, 4, ';');
        infile.get();
        infile.get(tempSecs, 4, ';');
        infile.get();
        infile.get(albumTitle, maxChar, ';');
        infile.get();
        infile.get(tempIndex, 4, '\n');
        infile.ignore(100, '\n');
        
        songMins = atoi(tempMins);
        songSecs = atoi(tempSecs);
        index = atoi(tempIndex);
        
        addedSong.setSongTitle(songTitle);
        addedSong.setArtistName(artistName);
        addedSong.setSongMins(songMins);
        addedSong.setSongSecs(songSecs);
        addedSong.setAlbumTitle(albumTitle);
        addedSong.setIndex(index);
        
        addedSong.getSongTitle(songTitle);
        addedSong.getArtistName(artistName);
        addedSong.getSongMins(songMins);
        addedSong.getSongSecs(songSecs);
        addedSong.getAlbumTitle(albumTitle);
        addedSong.getIndex(index);
        
        listOfSongs[songListSize].setSongTitle(songTitle);
        listOfSongs[songListSize].setArtistName(artistName);
        listOfSongs[songListSize].setSongMins(songMins);
        listOfSongs[songListSize].setSongSecs(songSecs);
        listOfSongs[songListSize].setAlbumTitle(albumTitle);
        listOfSongs[songListSize].setIndex(index);
        
        addedSong.printSong();
        
        songListSize++;
        
        if(infile.peek() == EOF){
            return;
        }
    }
        
    infile.close();
}

//save song Library file
void SongList::saveLibrary(const char fileName[]) const {
    
    ofstream outfile;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    int      index;
    
    outfile.open(fileName);
    if(!outfile){
        outfile.clear();
        cout << "Could not open at this time." << endl;
        return;
    }
    
    for(int i = 0; i < songListSize; i++){
        listOfSongs[i].getSongTitle(songTitle);
        listOfSongs[i].getArtistName(artistName);
        listOfSongs[i].getSongMins(songMins);
        listOfSongs[i].getSongSecs(songSecs);
        listOfSongs[i].getAlbumTitle(albumTitle);
        listOfSongs[i].getIndex(index);
        
        outfile << songTitle << ';' << artistName << ';' << songMins << ';' << songSecs << ';' << albumTitle << ';' << index << endl;
    }
    
    outfile.close();
}

//get SongListSize
int SongList::getSongListSize() const {
    return songListSize;
}

//add a song
void SongList::addSong(const Song& addedSong){
    
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    int      index = getSongListSize();
    
    cout << "Please enter the title of the song you are add to the library:";
    cin.getline(songTitle, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the title:" << endl;
        cin.getline(songTitle, maxChar, '\n');
    }
    
    cout << "Please enter the artist's name of the song you are adding to the library:";
    cin.getline(artistName, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the artist's name:" << endl;
        cin.getline(artistName, maxChar, '\n');
    }
    
    cout << "Please enter the minutes of the song you are adding to the library:";
    cin >> songMins;
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Not Valid. Please re-enter the minutes:" << endl;
        cin >> songMins;
    }
    
    cout << "Please enter the seconds of the song you are adding to the library:";
    cin >> songSecs;
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Not Valid. Please re-enter the seconds:" << endl;
        cin >> songSecs;
    }
    
    cout << "Please enter the album title of the song you are adding to the library:";
    cin.getline(albumTitle, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the album title:" << endl;
        cin.getline(albumTitle, maxChar, '\n');
    }
    
    addedSong.getSongTitle(songTitle);
    addedSong.getArtistName(artistName);
    addedSong.getSongMins(songMins);
    addedSong.getSongSecs(songSecs);
    addedSong.getAlbumTitle(albumTitle);
    addedSong.getIndex(index);
    
    listOfSongs[songListSize].setSongTitle(songTitle);
    listOfSongs[songListSize].setArtistName(artistName);
    listOfSongs[songListSize].setSongMins(songMins);
    listOfSongs[songListSize].setSongSecs(songSecs);
    listOfSongs[songListSize].setAlbumTitle(albumTitle);
    listOfSongs[songListSize].setIndex(index);
    
    songListSize++;
}

//remove a song
//void Songlist::removeSong(const SongList& library){
//    
//    char     songTitle[maxChar];
//    char     artistName[maxChar];
//    int      songMins;
//    int      songSecs;
//    char     albumTitle[maxChar];
//    int      index;
//    
//    int removeableIndex;
//    int tempListSize = library.getSongListSize();
//    char tempList[tempListSize];
//    bool indexFound = false;
//    
//    cout << "Please enter the index of the song that you would like to remove:" << endl;
//    cin >> removeableIndex;
//    
//    while(!cin || removeableIndex >= songListSize){
//        cin.clear();
//        cin.ignore(100, '\n');
//        cout << "That is not a valid index, please try again:" << endl;
//        cin >> removeableIndex;
//    }
//    
//    for(int i = 0; i < tempListSize; i++){
//        if(indexFound == true){
//            tempList[i] = songList[i+1];
//        } else if(i == removeableIndex){
//            indexFound = true;
//            tempList[i] = songList[i+1];
//        } else {
//            tempList[i] = songList[i];
//        }
//    }
//    tempListSize--;
//    library.setSongListSize();
//    
//    for(int j = 0; j < songListSize; j++){
//        songList[j] = tempList[j];
//    }
//    
//    
//    
//    addedSong.getSongTitle(songTitle);
//    addedSong.getArtistName(artistName);
//    addedSong.getSongMins(songMins);
//    addedSong.getSongSecs(songSecs);
//    addedSong.getAlbumTitle(albumTitle);
//    addedSong.getIndex(index);
//    
//    listOfSongs[songListSize].setSongTitle(songTitle);
//    listOfSongs[songListSize].setArtistName(artistName);
//    listOfSongs[songListSize].setSongMins(songMins);
//    listOfSongs[songListSize].setSongSecs(songSecs);
//    listOfSongs[songListSize].setAlbumTitle(albumTitle);
//    listOfSongs[songListSize].setIndex(index);
//    
//    
//    cout << "the song with index " << removeableIndex << " has been removed." << endl;
//    
//}

//search by artist
//SongList::searchForArtist(const char searchTerm[], Song& matchingSong){
void SongList::searchForArtist() const {
    char searchTerm[maxChar];
    char currentArtist[maxChar];
//    char   songTitle[maxChar];
    char   artistName[maxChar];
//    int    songMins;
//    int    songSecs;
//    char   albumTitle[maxChar];
//    int    index;
    int matches = 0;
    
    cout << "enter the artist you would like to search for: " << endl;
    
    cin.getline(searchTerm, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the artist:" << endl;
        cin.getline(searchTerm, maxChar, '\n');
    }
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(int i=0; i < songListSize; i++){
        listOfSongs[i].getArtistName(artistName);
        if(strcmp(artistName, currentArtist) == 0){
            matches++;
            listOfSongs[i].printSong();
        }
    }
    
    if(matches == 0){
        cout << "I'm sorry, there are no matches for that artist" << endl;
    }
}

//search by album
//SongList::searchForAlbum(const char searchTerm[], Song& matchingSong){
void SongList::searchForAlbum() const {
    char searchTerm[maxChar];
    char currentAlbum[maxChar];
//    char   songTitle[maxChar];
//    char   artistName[maxChar];
//    int    songMins;
//    int    songSecs;
    char   albumTitle[maxChar];
//    int    index;
    int matches = 0;
    
    cout << "enter the album you would like to search for: " << endl;
    
    cin.getline(searchTerm, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the album:" << endl;
        cin.getline(searchTerm, maxChar, '\n');
    }
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(int i=0; i < songListSize; i++){
        listOfSongs[i].getAlbumTitle(albumTitle);
        if(strcmp(albumTitle, currentAlbum) == 0){
            matches++;
            listOfSongs[i].printSong();
        }
    }
    
    if(matches == 0){
        cout << "I'm sorry, there are no matches for that album" << endl;
    }
}

//show all songs
void SongList::displaySongs() const{
    
    char   songTitle[maxChar];
    char   artistName[maxChar];
    int    songMins;
    int    songSecs;
    char   albumTitle[maxChar];
    int    index;
    int    listSize = getSongListSize();
    cout << listSize << endl;
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(int i = 0; i < listSize; i++){
        listOfSongs[i].getSongTitle(songTitle);
        listOfSongs[i].getArtistName(artistName);
        listOfSongs[i].getSongMins(songMins);
        listOfSongs[i].getSongSecs(songSecs);
        listOfSongs[i].getAlbumTitle(albumTitle);
        listOfSongs[i].getIndex(index);
        
        listOfSongs[i].printSong();
        
    }
}











