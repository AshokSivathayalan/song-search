#include "Criteria.h"

//Criteria Class Code

ostream& operator<<(ostream& ost, const Criteria& c){
  c.print(ost);
  return ost;
}

//A_Criteria Code
A_Criteria::A_Criteria(const string& artist): artist(artist){}

bool A_Criteria::matches(const Song& s) const{
  return s.getArtist() == artist;
}
void A_Criteria::print(ostream& ost) const{
  ost<<"Matches with songs by "<<artist<<endl;
}

//C_Criteria Code
C_Criteria::C_Criteria(const string& category): category(category){}

bool C_Criteria::matches(const Song& s) const{
  return s.getCategory() == category;
}
void C_Criteria::print(ostream& ost) const{
  ost<<"Matches with "<<category<<" songs."<<endl;
}

//AorC_Criteria Code
AorC_Criteria::AorC_Criteria(const string& artist, const string& category): A_Criteria(artist), C_Criteria(category){}

bool AorC_Criteria::matches(const Song& s) const{
  return this->A_Criteria::matches(s) || this->C_Criteria::matches(s);
}
void AorC_Criteria::print(ostream& ost) const{
  //ost<<"Matches songs by "<<this->A_Criteria::artist<<" or "<<this->C_Criteria::category<<" songs."<<endl;
  this->A_Criteria::print(ost);
  ost<<" or ";
  this->C_Criteria::print(ost);
}
