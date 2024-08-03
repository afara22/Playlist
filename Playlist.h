#ifndef Playlist_H
#define Playlist_H

using namespace std;

class PlaylistNode {
    private:
        string uniqueID;
        string songName;
        string artistName;
        int songLength;
        PlaylistNode* nextNodePtr;
    public:
        PlaylistNode() {                 //Default constructor w/ definition
            uniqueID = "none";
            songName = "none";
            artistName = "none";
            songLength = 0;
            nextNodePtr = 0;
        }
        PlaylistNode(string ID, string song, string artist, int length, PlaylistNode* next = nullptr) : uniqueID(ID), songName(song), artistName(artist), songLength(length), nextNodePtr(next) { }
        void InsertAfter(PlaylistNode* nodeLoc); 
        void SetNext(PlaylistNode* next); 
        string GetID();
        string GetSongName();
        string GetArtistName();
        int GetSongLength();
        PlaylistNode* GetNext();
        void PrintPlaylistNode();
    
};

class Playlist {
    public:
        Playlist() {
            head = nullptr;
            tail = nullptr;
        }
        void PrintFullPlaylist(string title);
        void RemoveSong();
        void AddSong();
        void SpecificArtist();
        void TotalTime();
        void ChangePos();
       /* ~Playlist(){
            PlaylistNode* tempHead;
            while (head != NULL) {
                tempHead = head->next;
                delete head;
                head = tempHead;
            }
        }*/
    
        PlaylistNode* head;
        PlaylistNode* tail;

};

#endif