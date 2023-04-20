#ifndef SONGIFY_H
#define SONGIFY_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Song.h"
#include "defs.h"
#include "MediaFactory.h"

using namespace std;

class Songify {

	public:
		//constructors
		Songify();

		//destructor
		~Songify();

		//add and remove Songs and Albums
		bool addAlbum(const string& artist, const string& albumTitle);
		bool addSong(const string& artist, const string& songTitle, const string& albumTitle);

		bool getAlbum(int index, Album** output) const;
		// bool addSong(const Song& song);
		bool removeSong(const string& artist, const string& songTitle, const string& albumTitle);
		bool removeAlbum(const string& artist, const string& albumTitle);

		const Array<Album*>& getAlbums() const;
		void getPlaylist(const string& artist, const string& category, Array<Song*>& playlist) const;

	private:
		Array<Album*> albums;
		MediaFactory factory;

};
#endif
