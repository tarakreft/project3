//  project3.cpp
//
//  Created by Tara Kreft
//

#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


//set the array size in songList
void songList::setSongListSize(int maxList){
    if(maxList >= 0){
        songListSize = maxList;
    } else {
        maxList = 100;
    }
}

//add a song to the library
void addSong(song& addedSong, song songList[], int& songListSize){
    int tempIndex = songListSize;
    strncpy(songList[songListSize].songTitle, addedSong.songTitle, maxChar);
    strncpy(songList[songListSize].artistName, addedSong.artistName, maxChar);
    strncpy(songList[songListSize].songMins, addedSong.songMins, 4);
    strncpy(songList[songListSize].songSecs, addedSong.songSecs, 4);
    strncpy(songList[songListSize].albumTitle, addedSong.albumTitle, maxChar);
    addedSong.index = tempIndex;
    ++songListSize;
}

void saveLibrary(char fileName[], song songList[], int& songListSize){
    
    ofstream outfile;
    
    outfile.open(fileName);
    if(!outfile){
        outfile.clear();
        cout << "Could not open at this time." << endl;
        return;
    }
    
    for(int i = 0; i < songListSize; i++){
        outfile << songList[i].songTitle << ';' << songList[i].artistName << ';' << songList[i].songMins << ';' << songList[i].songSecs << ';' << songList[i].albumTitle << ';' << songList[i].index << endl;
    }
    
    outfile.close();
}

//display all songs
void displaySongs(song songList[], int& songListSize){
    cout << left << setw(maxChar) << "Song Title" << setw(maxChar) << "Artist Name" << setw(7) << "Mins" << setw(1) << " " << setw(7) << "Secs" << setw(maxChar) << "Album Title" << setw(5) << "index" << endl;
    for(int i = 0; i < songListSize; i++){
        cout << left << setw(maxChar) << songList[i].songTitle << setw(maxChar) << songList[i].artistName << setw(7) << songList[i].songMins << setw(1) << " " << setw(7) << songList[i].songSecs << setw(maxChar) << songList[i].albumTitle << setw(5) << i << endl;
    }
}

// add songs
void addNewSong(char fileName[], song songList[], int& songListSize){
    
    song addedSong;
    char     tempSongTitle[maxChar];
    char     tempArtistName[maxChar];
    char     tempSongMins[4];
    char     tempSongSecs[4];
    char     tempAlbumTitle[maxChar];
    
    cout << "Please enter the title of the song you are add to the library:";
    cin.getline(tempSongTitle, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the title:" << endl;
        cin.getline(tempSongTitle, maxChar, '\n');
    }
    
    cout << tempSongTitle << endl;
    cout << "Please enter the artist's name of the song you are adding to the library:";
    cin.getline(tempArtistName, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the artist's name:" << endl;
        cin.getline(tempArtistName, maxChar, '\n');
    }
    
    cout << "Please enter the minutes of the song you are adding to the library:";
    cin.getline(tempSongMins, 4, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the minutes:" << endl;
        cin.getline(tempSongMins, 4, '\n');
    }
    
    cout << "Please enter the seconds of the song you are adding to the library:";
    cin.getline(tempSongSecs, 4, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the seconds:" << endl;
        cin.getline(tempSongMins, 4, '\n');
    }
    
    cout << "Please enter the album title of the song you are adding to the library:";
    cin.getline(tempAlbumTitle, maxChar, '\n');
    while(!cin){
        cin.clear();
        cin.ignore(maxChar, '\n');
        cout << "Too Long. Please re-enter the album title:" << endl;
        cin.getline(tempAlbumTitle, maxChar, '\n');
    }
    
    strncpy(addedSong.songTitle, tempSongTitle, maxChar);
    strncpy(addedSong.artistName, tempArtistName, maxChar);
    strncpy(addedSong.songMins, tempSongMins, 4);
    strncpy(addedSong.songSecs, tempSongSecs, 4);
    strncpy(addedSong.albumTitle, tempAlbumTitle, maxChar);
    addedSong.index = songListSize;
    
    addSong(addedSong, songList, songListSize);
    saveLibrary(fileName, songList, songListSize);
    
}

// remove songs by index
void removeSong(char fileName[], song songList[], int& songListSize){
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
    saveLibrary(fileName, songList, songListSize);
}



//search for songs by album
void searchForAlbum(song songList[], int& songListSize){
    
}

int displayChoices(){
    int usersChoice;
    cout << "\n" << "\n" << "What would you like to do? Please enter a number from the following key:" << endl;
    cout << "1 - view library" << endl;
    cout << "2 - remove song by index" << endl;
    cout << "3 - search for a song by artist" << endl;
    cout << "4 - search for a song by album" << endl;
    cout << "5 - enter a new song to the library" << endl;
    cout << "6 - quit this program" << endl;
    
    cin >> usersChoice;
    cin.clear();
    cin.ignore(100, '\n');
    
    return usersChoice;
}

void runUserChoice(int programChoice, char fileName[], song songList[100], int& songListSize){
    switch(programChoice){
        case 1:
            cout << "you have chosen option 1:" << endl;
            displaySongs(songList, songListSize);
            break;
        case 2:
            cout << "you have chosen option 2:" << endl;
            removeSong(fileName, songList, songListSize);
            break;
        case 3:
            cout << "you have chosen option 3:" << endl;
            searchForArtist(songList, songListSize);
            break;
        case 4:
            cout << "you have chosen option 4:" << endl;
            searchForAlbum(songList, songListSize);
            break;
        case 5:
            cout << "you have chosen option 5:" << endl;
            addNewSong(fileName, songList, songListSize);
            break;
        case 6:
            cout << endl;
            break;
        default:
            cout <<programChoice << " is an Invalid entry! Try again" << endl;
    }
}

int main()
{
    int  programChoice;
    char fileName[] = "songs.txt";
    song songList[100];
    int  songListSize = 0;
    
    readLibrary(fileName, songList, songListSize);
    
    cout << "Welcome to the music library interface!" << endl;
    
    programChoice = displayChoices();
    
    while(programChoice != 6){
        runUserChoice(programChoice, fileName, songList, songListSize);
        programChoice = displayChoices();
    }
    
    cout << "Thank you for using the music library. Your changes have been saved." << endl;
    
    return 0;
}










