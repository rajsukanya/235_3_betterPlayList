/*
Name: Sukanya Raj
File name: Song.h
Date: 9/25/18
Assignment: Project 2
Description: interface of class Song
*/

#ifndef SONG_H_
#define SONG_H_

#include<string>

class Song
{
  public:
    Song();
    
    /*Adds a song to the set*/
    Song(const std::string& title, const std::string& author = "", const std::string& album = "");
    
    /*Assigns the string 'title' to the member variable 'title_'*/
    void setTitle(std::string title);
    
    /*Assigns the string 'author' to the member variable 'author_'*/
    void setAuthor(std::string author);
    
    /*Assigns the string 'album' to the member variable 'album_'*/
    void setAlbum(std::string album);
    
    /*@return Name of title*/
    std::string getTitle() const;
    
    /*@return Name of author*/
    std::string getAuthor() const;
    
    /*@return Name of album*/
    std::string getAlbum() const;
    
    /*Overloads the equality operator to compare songs by title, author and album names*/
    friend bool operator==(const Song& lhs, const Song& rhs);
  
  private:
    std::string title_;
    std::string author_;
    std::string album_;
};
#endif
