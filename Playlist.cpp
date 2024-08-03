#include <iostream>
#include "Playlist.h"
#include <limits>

using namespace std;

//Implementation of member functions for PLAYLISTNODE

void PlaylistNode::InsertAfter(PlaylistNode* nodeLoc) {
    PlaylistNode* tempNext = this->nextNodePtr;
    if (this->nextNodePtr != NULL){
        while (tempNext->nextNodePtr != NULL){
            tempNext = tempNext->nextNodePtr;
        }
        tempNext->nextNodePtr = nodeLoc;
    }
    else {
        this->nextNodePtr = nodeLoc;
    }
}

void PlaylistNode::SetNext(PlaylistNode* song) { 
   this->nextNodePtr = song;
}

string PlaylistNode::GetID() {
    return this->uniqueID;
}

string PlaylistNode::GetArtistName() {
    return this->artistName;
}

string PlaylistNode::GetSongName() {
    return this->songName;
}

int PlaylistNode::GetSongLength() {
    return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
    return this->nextNodePtr;
}
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}

//implementing Playlist member functions


void Playlist::PrintFullPlaylist(string playlistTitle) {
    
    cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            if (head == nullptr) {
                cout << "Playlist is empty" << endl << endl;
            }
            else {  
                PlaylistNode* curr = head;
                int number = 1;
                while (curr != nullptr) {
                    cout << number << "." << endl;
                    curr->PrintPlaylistNode();
                    cout << endl;
                    curr = curr->GetNext();
                    ++number;
                }
            }
}
 
void Playlist::AddSong() {
    string ID;
    string song;
    string artist;
    int length;

    cout << "ADD SONG" << endl;
    cout << "Enter song's unique ID:";
    cin >> ID;
    cout << endl << "Enter song's name:";
    getline(cin >> ws, song);      //numeric_limits<streamsize>::max(), '\n'
    cout << endl << "Enter artist's name:";
    getline(cin, artist);
    cout << endl << "Enter song's length (in seconds):";
    cin >> length;
    cout << endl << endl;
    
    PlaylistNode* addedNode = new PlaylistNode(ID,song,artist,length);

    if (head == nullptr) {
        head = addedNode;
        tail = addedNode;
    }
    
    else {
        tail->InsertAfter(addedNode);
        tail = addedNode;
    }
}

//Remove Song function

void Playlist::RemoveSong() {  //FIXME!!
    string uqID;
    cout << "REMOVE SONG" << endl;
    cout << "Enter song's unique ID:";
    cin >> uqID;
    

    PlaylistNode* temp = nullptr;

    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext()) {
        PlaylistNode* temp = i->GetNext();
        if (temp->GetID() == uqID) {
            i->SetNext(temp->GetNext());
            cout << endl << "\"" << temp->GetSongName() << "\"" << " removed." << endl << endl;
            delete temp;
            break;
        }
        if (head->GetID() == uqID) {
            PlaylistNode* temp2 = nullptr;
            temp2 = head;
            head = head->GetNext();
            delete temp2;
            break;
        }
    }    

}

void Playlist::SpecificArtist() {
    
    string name;
    
    cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    cout << "Enter artist's name:" << endl;
    cin >> name;
    cout << endl << endl;

    PlaylistNode* curr = head;

    while (curr != nullptr) {
        if (curr->GetArtistName() == name) {
            curr->PrintPlaylistNode();
            cout << endl;
        }
        curr = curr->GetNext();
    }
}

void Playlist::TotalTime() {
    int totTime = 0;

    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext()) {
        totTime = i->GetSongLength() + totTime;
    }
    
    cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
    cout << "Total time: " << totTime << " seconds" << endl;
}

void Playlist::ChangePos() {

    int currPos;
    int newPos;
    //PlaylistNode* currPrev = NULL;
   // PlaylistNode* newPrev = NULL;

    cout << "CHANGE POSITION OF SONG" << endl;
    cout << "Enter song's current position:" << endl;
    cin >> currPos;
    cout << endl << "Enter new position for song:" << endl;
    cin >> newPos;
    cout << endl;

    
    int cnt = 0;
    int cnt2 = 0;
   /* if (currPos < 1){
        currPos = 1;
    }
    if (newPos < 1){
        newPos = 1;
    }*/
    PlaylistNode* curr = head;
    while(curr != nullptr) {
        ++cnt;
        curr = curr->GetNext();
    }
   /* if (currPos >= cnt){
        currPos = cnt;
    }
    if (newPos >= cnt){
        newPos = cnt;
    }
    if (head == NULL || head == tail || currPos == newPos){
        return;
    }
    
    for (PlaylistNode* i = head; i != nullptr; i = i->GetNext()){
        ++cnt2;
        if (cnt2 == currPos - 1){
            currPrev = i;
        }
        else if (cnt2 == newPos - 1){
            newPrev = i;
        }
    }
    PlaylistNode* currNode;
    if (currPrev == NULL){
        currNode = head;
        head = head->GetNext();
        currNode->SetNext(newPrev->GetNext());
        newPrev->SetNext(currNode);
    }
    else if (newPrev == NULL){
        currPrev->SetNext(currPrev->GetNext()->GetNext());
        currNode->SetNext(head);
        head = currNode;
    }
    else {
        currPrev->SetNext(currPrev->GetNext()->GetNext());
        currNode->SetNext(newPrev->GetNext());
        newPrev->SetNext(currNode);
    }
    if (newPos == cnt){
        tail = currNode;
    }
    else if (currPos == cnt){
        tail = currPrev;
    }*/

    if (newPos < 1) {
        for(PlaylistNode* i = head; i != nullptr; i = i->GetNext()) {
            ++cnt2;
            if (cnt2 == currPos - 1) {
                PlaylistNode* temp = i->GetNext();
                i->SetNext(temp->GetNext());
                temp->SetNext(head);
                cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << newPos << endl;
                break;
            }
            //++cnt2;
        }
    }
    else if (newPos > cnt) {
        for(PlaylistNode* i = head; i != nullptr; i = i->GetNext()) {
            ++cnt2;
            if (cnt2 == currPos - 1) {
                PlaylistNode* temp = i->GetNext();
                i->SetNext(temp->GetNext());
                temp->SetNext(tail);
                cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << newPos << endl;
                break;
            }
            //++cnt2;
        }
    }
    else {
        for(PlaylistNode* i = head; i != nullptr; i = i->GetNext()) {
            ++cnt2;
            if (cnt2 == currPos - 1) {
                PlaylistNode* temp = i->GetNext();
                i->SetNext(temp->GetNext());
                cnt2 = 0;
                for (PlaylistNode* j = head; j != nullptr; j = j->GetNext()) {
                    ++cnt2;
                    if (cnt2 == newPos - 1) {
                        PlaylistNode* temp2 = j->GetNext();
                        j->SetNext(temp);
                        temp->SetNext(temp2);
                        cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << newPos << endl;
                        break;
                    }
                   // ++cnt2;
                }
                break;
            }
           // ++cnt2;
        }
    }
    


}