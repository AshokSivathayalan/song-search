#include "Album.h"

Album::Album(const string& artist, const string& title): artist(artist), title(title){
}

Album::~Album(){
  for(int i=0;i<songs.getSize();i++){
    //cout<<"deleting song"<<endl;
    delete songs[i];
  }
}

//Getters
const string& Album::getTitle() const{
  return title;
}
const string& Album::getArtist() const{
  return artist;
}
int Album::getSize() const{
  return songs.getSize();
}

Song* Album::operator[](int index){
  return songs[index];
}

ostream& operator<<(ostream& ost, Album& alb){
  alb.printShort(ost);
  return ost;
}

bool Album::lessThan(const Album& alb) const{
  if(this->artist.compare(alb.artist) < 0) return true;
  else if(this->artist.compare(alb.artist) == 0){
    if(this->title.compare(alb.title) < 0) return true;
    else return false;
  }
  else return false;
}

bool Album::addSong(Song* s){
  if(s->getArtist() == artist && !songs.isFull()){
    songs += s;
    return true;
  }
  //Returning false if the artist does not match
  else return false;
}

bool Album::getSong(const string& title, Song** output) const{
  for(int i=0;i<songs.getSize();i++){
    if(songs[i]->getTitle() == title){
      *output = songs[i];
      return true;
    }
  }
  return false;
}

bool Album::removeSong(const string& title, Song** output){
  for(int i=0;i<songs.getSize();i++){
    if(songs[i]->getTitle() == title){
      *output = songs[i];
      songs -= songs[i];
      return true;
    }
  }
  return false;
}
bool Album::removeSong(int index, Song** output){
  if(index >= songs.getSize() || index < 0) return false;
  else{
    *output = songs[index];
    songs -= songs[index];
    return true;
  }
}

void Album::print(ostream& ost) const{
  printShort(ost);
  for(int i=0;i<songs.getSize();i++){
    //Adding an indent so it is easier to read
    ost<<"\t";
    songs[i]->print(ost);
  }
}
void Album::printShort(ostream& ost) const{
  ost<<"Album: "<<artist<<" - "<<title<<endl;
}
