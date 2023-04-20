#ifndef SONG_H
#define SONG_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Song{

	friend ostream& operator<<(ostream& ost, const Song& s);
	public:
		//constructors
		Song(const string& artist, const string&  title, const string& category, const string& content);

		//getters
		const string& getTitle() const;
		const string& getArtist() const;
		const string& getCategory() const;

		bool matches(const string& artist, const string& title) const;

		void print(ostream& ost) const;
		void play(ostream& ost) const;

	private:
		string title;
		string artist;
		string content;
		string category;

};
#endif
