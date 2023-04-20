#include "Song.h"

Song::Song(const string& artist, const string&  title, const string& category, const string& content): artist(artist), title(title), category(category), content(content){

}

//getters
const string& Song::getTitle() const{
  return title;
}
const string& Song::getArtist() const{
  return artist;
}
const string& Song::getCategory() const{
  return category;
}

ostream& operator<<(ostream& ost, const Song& s){
  ost<<s.artist<< " - " <<s.title<<endl
  <<"\tCategory: "<<s.category<<endl;
  return ost;
}

bool Song::matches(const string& artist, const string& title) const{
  return(this->artist == artist && this->title == title);
}

void Song::print(ostream& ost) const{
  ost<<(*this);
}
void Song::play(ostream& ost) const{
  ost<<*this
  <<"\t"<<this->content<<endl;
}
