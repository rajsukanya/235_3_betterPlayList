/*
Name: Sukanya Raj
File name: Song.cpp
Date: 9/25/18
Assignment: Project 2
Description: implementation of class Song
*/

#include <iostream>
#include "Song.h"

/*Initializes private member variables*/
Song::Song()
{
  title_ = "";
  author_ = "";
  album_ = "";
}

Song::Song(const std::string& title, const std::string& author, const std::string& album)
{
  title_ = title;
  author_ = author;
  album_ = album;    
}

/*Assigns the string 'title' to the member variable 'title_'*/
void Song::setTitle(std::string title)
{
  title_ = title;
}

/*Assigns the string 'author' to the member variable 'author_'*/
void Song::setAuthor(std::string author)
{
  author_ = author;
}

/*Assigns the string 'album' to the member variable 'album_'*/
void Song::setAlbum(std::string album)
{
  album_ = album;
}

/*@return Name of title*/
std::string Song::getTitle() const
{
  return title_;
}

/*@return Name of author*/
std::string Song::getAuthor() const
{
  return author_;
 }

/*@return Name of album*/
std::string Song::getAlbum() const
{
  return album_;
}

/*Overloads the equality operator to compare songs by title, author and album names*/
bool operator==(const Song& lhs, const Song& rhs)
{
  return(lhs.getTitle() == rhs.getTitle() && lhs.getAuthor() == rhs.getAuthor() && lhs.getAlbum() == rhs.getAlbum());
}

