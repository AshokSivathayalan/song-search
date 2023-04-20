#include "Songify.h"

//Constructor, destructor
Songify::Songify(){
}
Songify::~Songify(){
  //Getting each album in the array and deleting it
  for(int i=0;i<albums.getSize();i++){
    delete albums[i];
  }
}
//Adding, removing
bool Songify::addAlbum(const string& artist, const string& albumTitle){
  if(albums.isFull()) return false;
  else{
  //Creating a new album and trying to add it
    Album* a;
    if(factory.createAlbum(artist, albumTitle, &a)){
      albums += a;
      return true;
    }
  }
  return false;
}

bool Songify::removeAlbum(const string& artist, const string& albumTitle){
  for(int i=0;i<albums.getSize();i++){
    if(albums[i]->getArtist() == artist && albums[i]->getTitle() == albumTitle){
      Album* temp = albums[i];
      albums -= albums[i];
      delete temp;
      return true;
    }
  }
  return false;
}
bool Songify::addSong(const string& artist, const string& songTitle, const string& albumTitle){
  //Trying to find a matching album
  for(int i=0;i<albums.getSize();i++){
    cout<<albums[i]->getTitle()<<" "<<albumTitle<<endl;
    if(albums[i]->getTitle() == albumTitle && albums[i]->getArtist() == artist){
      //Creating a copy of the Song and trying to add it to the album
        Song* s;
        if(factory.createSong(artist, songTitle, &s)){
          albums[i]->addSong(s);
          return true;
        }
    }
  }
  //Returning false if no matching album title was found
  cout<<"No matching album was found"<<endl;
  return false;


}
bool Songify::removeSong(const string& artist, const string& songTitle, const string& albumTitle){
  for(int i=0;i<albums.getSize();i++){
    if(albums[i]->getTitle() == albumTitle && albums[i]->getArtist() == artist){
      Album* a = albums[i];
      Song* s;
      if(a->removeSong(songTitle, &s)){
        delete s;
        return true;
      }
      else return false;
    }
  }
  return false;
}

bool Songify::getAlbum(int index, Album** output) const{
  if(index < 0 || index > albums.getSize()) return false;
  else{
    *output = albums[index];
    return true;
  }
}

const Array<Album*>& Songify::getAlbums() const{
  return albums;
}

void Songify::getPlaylist(const string& artist, const string& category, Array<Song*>& playlist) const{
  Criteria* crit;
  if(!factory.createCriteria(artist, category, &crit)) return;
  for(int i=0;i<albums.getSize();i++){
    //For readability of code
    Album* currentAlb = albums[i];
    for(int j=0;j<currentAlb->getSize();j++){
      Song* curSong = (*currentAlb)[j];
      if(crit->matches(*curSong)){
        playlist += curSong;
      }
    }
  }
  delete crit;
}
