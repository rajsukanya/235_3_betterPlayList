/*
Name: Sukanya Raj
File name: PlayList.h
Date: 10/16/18
Assignment: Project 3
Description: interface of class PlayList
*/

#ifndef PLAY_LIST_
#define PLAY_LIST_

#include "LinkedSet.h"
#include "Song.h"

class PlayList : public LinkedSet<Song>
{
  public:
    PlayList(); //default constructor
    PlayList(const Song& a_song); //parameterized constructor
    PlayList(const PlayList& a_play_list); //copy constructor
    ~PlayList(); //Destructor
    //Adds a new song to PlayList
    bool add(const Song& new_song);
    //Removes a song from PlayList
    bool remove(const Song& a_song) override;
    void loop();
    void unloop();
    //Displays all entries from the PlayList
    void displayPlayList();

  private:
    Node<Song>* tail_ptr; //Pointer to last node
    Node<Song>* getPointerToLastNode() const;

    //post: previous_ptr is null if target is not in PlayList or if target is the
    //first node, otherwise it points to the node preceding target
    //return: either a pointer to the node containing target
    //or the null pointer if the target is not in the PlayList.
    Node<Song>* getPointerTo(const Song& target, Node<Song>*& previous_ptr) const;
};

#endif
