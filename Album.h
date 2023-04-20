#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Song.h"

using namespace std;

class Album {

	friend ostream& operator<<(ostream& ost, Album& alb);

	public:
		//constructors
		Album(const string& artist, const string& albumTitle);

		//destructor
		~Album();

		Song* operator[](int index);

		//getters
		const string& getTitle() const;
		const string& getArtist() const;
		int getSize() const;

		//comparison
		bool matches(const string& artist, const string& albumTitle) const;
		bool lessThan(const Album&) const;

		//add and remove
		bool addSong(Song*);

		bool getSong(const string& songTitle, Song**) const;
		bool removeSong(const string& songTitle, Song**);
		bool removeSong(int, Song**);

		void printShort(ostream& ost) const;
		void print(ostream& ost) const;

	private:
		string title;
		string artist;
		Array<Song*> songs;

};
#endif
