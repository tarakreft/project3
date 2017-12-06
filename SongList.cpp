//
//  SongList.cpp
//
//  Created by Tara Kreft
//

#include "Song.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

SongList::SongList(){
    songListSize = 0;
}

SongList::SongList(const char fileName[]){
    size = 0;
    readLibrary(fileName);
}

//read the song library file
SongList::readLibrary(const char fileName[]){
        
    ifstream infile;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    int      index;
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
        infile.get(songMins, ';');
        infile.get();
        infile.get(songSecs, ';');
        infile.get();
        infile.get(albumTitle, maxChar, ';');
        infile.get(index, ';');
        infile.ignore(100, '\n');
        
        addedSong.setSongTitle(songTitle);
        addedSong.setArtistName(artistName);
        addedSong.setSongMins(songMins);
        addedSong.setSongSecs(songSecs);
        addedSong.setAlbumTitle(albumTitle);
        addedSong.setIndex(songListSize);
        
        addSong(addedSong);
        
        if(infile.peek() == EOF){
            return;
        }
    }
        
    infile.close();
}

//set SongListSize
SongList::setSongListSize() const{
    return size;
}

//search by artist
//SongList::searchForArtist(const char searchTerm[], Song& matchingSong){
SongList::searchForArtist(const char searchTerm[]){
    char searchTerm[maxChar];
    char currentArtist[maxChar];
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
        listOfSongs[i].getArtistName(currentArtist);
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
//void searchForAlbum(const char searchTerm[], Song& matchingSong){
    void searchForAlbum(const char searchTerm[]){
    char searchTerm[maxChar];
    char currentAlbum[maxChar];
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
        listOfSongs[i].getAlbumTitle(currentAlbum);
        if(strcmp(albumTitle, currentAlbum) == 0){
            matches++;
            listOfSongs[i].printSong();
        }
    }
    
    if(matches == 0){
        cout << "I'm sorry, there are no matches for that album" << endl;
    }
}














