/*
Name: Sukanya Raj
File name: PlayList.cpp
Date: 10/16/18
Assignment: Project 3
Description: implementation of class PlayList
*/

#include "PlayList.h"
#include<iostream>
using namespace std;

PlayList::PlayList()
{
  tail_ptr = nullptr;
}

//Parameterized constructor
PlayList::PlayList(const Song& a_song)
{
  add(a_song);
}

//Copy constructor
PlayList::PlayList(const PlayList& a_play_list) : LinkedSet(a_play_list)
{
  tail_ptr = getPointerToLastNode();
}

//Destructor
PlayList::~PlayList()
{
  tail_ptr = nullptr;
}

//Adds a new song to the PlayList
bool PlayList::add(const Song& new_song)
{
  if(contains(new_song))
    return false;

  if(item_count_ == 0)
  {
    Node<Song>* new_song_ptr = new Node<Song>(new_song, nullptr);
    head_ptr_ = new_song_ptr;
    tail_ptr = new_song_ptr;
    item_count_++;
    return true;
  }
  else
  {
    Node<Song>* new_song_ptr = new Node<Song>(new_song, nullptr);
    tail_ptr->setNext(new_song_ptr);
    tail_ptr = tail_ptr->getNext();
    item_count_++;
    return true;
  }
}

//Removes a song from the PlayList
bool PlayList::remove(const Song& a_song) 
{
  Node<Song>* previous_ptr = nullptr;
  if(item_count_ != 0)
  {
    Node<Song>* ptr_to_delete = getPointerTo(a_song, previous_ptr);
    if(head_ptr_ == ptr_to_delete)
    {
      head_ptr_ = ptr_to_delete->getNext();
      delete ptr_to_delete;
      ptr_to_delete->setNext(nullptr);
      item_count_--;
      return true;
    }
    else
    {
      previous_ptr->setNext(ptr_to_delete->getNext());
      delete ptr_to_delete;
      ptr_to_delete->setNext(nullptr);
      tail_ptr = ptr_to_delete;
      item_count_--;
      return true;
    }
  }
  else 
    return false;
}

void PlayList::loop()
{
  tail_ptr->setNext(head_ptr_->getNext());
}

void PlayList::unloop()
{
  tail_ptr = nullptr;
}

//Displays all entries from the PlayList
void PlayList::displayPlayList()
{
  vector<Song> v = toVector();

  for(size_t i = 0; i < v.size(); i++)
  {
    cout << " * " << "Title: " << v[i].getTitle() << " * " << "Author: " << v[i].getAuthor() << " * " << "Album: " << v[i].getAlbum() << " * " <<endl;
  }
  cout << "End of playlist" <<endl;
}

//private member function
Node<Song>* PlayList::getPointerToLastNode() const
{
  bool found = false;
  Node<Song>* last_ptr = head_ptr_;

  while(!found && last_ptr->getNext() != nullptr)
  {
    last_ptr = last_ptr->getNext();
    found = true;
  }
  return last_ptr;
}

//private member function
/*returns either a pointer to the node containing target or
the null pointer if the target is not in the PlayList. */
Node<Song>* PlayList::getPointerTo(const Song& target, Node<Song>*& previous_ptr) const
{
  previous_ptr = nullptr;
  Node<Song>* current_ptr = head_ptr_;
  
  while((current_ptr != nullptr))
  {
    if (current_ptr->getItem() == target)
    {
      return current_ptr;
    }
    else
    {
      previous_ptr = current_ptr;
      current_ptr = current_ptr->getNext();
   }
  }
  return current_ptr;
}
