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
        
        addSong(fileName, addedSong);
        
        if(infile.peek() == EOF){
            return;
        }
    }
        
    infile.close();
}

//save song Library file
SongList::saveLibrary(const char fileName[]) const {
    
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
        listOfSongs[i].songMins(songMins);
        listOfSongs[i].getSecs(songSecs);
        listOfSongs[i].getAlbumTitle(albumTitle);
        listOfSongs[i].getIndex(index);
        
        outfile << songTitle << ';' << artistName << ';' << songMins << ';' << songSecs << ';' << albumTitle << ';' << index << endl;
    }
    
    outfile.close();
}

//set SongListSize
SongList::setSongListSize() const{
    return size;
}

//add a song
SongList::addSong(const char fileName[], const song& addedSong){
    song     addedSong;
    char     songTitle[maxChar];
    char     artistName[maxChar];
    int      songMins;
    int      songSecs;
    char     albumTitle[maxChar];
    int      index;
    
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
Songlist::removeSong(const char fileName[], song songList[]){
    int removeableIndex;
    song tempList[songListSize];
    bool indexFound = false;
    
    cout << "Please enter the index of the song that you would like to remove:" << endl;
    cin >> removeableIndex;
    
    while(!cin || removeableIndex >= songListSize){
        cin.clear();
        cin.ignore(100, '\n');
        cout << "That is not a valid index, please try again:" << endl;
        cin >> removeableIndex;
    }
    
    for(int i = 0; i < songListSize; i++){
        if(indexFound == true){
            tempList[i] = songList[i+1];
        } else if(i == removeableIndex){
            indexFound = true;
            tempList[i] = songList[i+1];
        } else {
            tempList[i] = songList[i];
        }
    }
    songListSize--;
    
    for(int j = 0; j < songListSize; j++){
        songList[j] = tempList[j];
    }
    
    cout << "the song with index " << removeableIndex << " has been removed." << endl;
    
}

//search by artist
//SongList::searchForArtist(const char searchTerm[], Song& matchingSong){
SongList::searchForArtist() const {
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
//SongList::searchForAlbum(const char searchTerm[], Song& matchingSong){
SongList::searchForAlbum() const {
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

//show all songs
SongList::displaySongs(){
    
    char   songTitle[maxChar];
    char   artistName[maxChar];
    int    songMins;
    int    songSecs;
    char   albumTitle[maxChar];
    int    index;
    
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    
    for(int i = 0; i < songListSize; i++){
        listOfSongs[i].getSongTitle(songTitle);
        listOfSongs[i].getArtistName(artistName);
        listOfSongs[i].songMins(songMins);
        listOfSongs[i].getSecs(songSecs);
        listOfSongs[i].getAlbumTitle(albumTitle);
        listOfSongs[i].getIndex(index);
        
        cout << left << setw(maxChar) << songTitle << setw(maxChar) << artistName << setw(7) << songMins << setw(1) << " " << setw(7) << songSecs << setw(maxChar) << albumTitle << setw(5) << index << endl;
        
    }
}











