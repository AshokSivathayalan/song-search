#ifndef CRITERIA_H
#define CRITERIA_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Song.h"

class Criteria{
  friend ostream& operator<<(ostream& ost, const Criteria& c);
  public:
    virtual bool matches(const Song& s) const = 0;
    virtual void print(ostream& ost) const = 0;
};

class A_Criteria: virtual public Criteria{
  public:
    //Constructor
    A_Criteria(const string& artist);

    virtual bool matches(const Song& s) const;
    virtual void print(ostream& ost) const;

  private:
    const string artist;
};

class C_Criteria: virtual public Criteria{
  public:
    //Constructor
    C_Criteria(const string& artist);

    virtual bool matches(const Song& s) const;
    virtual void print(ostream& ost) const;

  private:
    const string category;
};

class AorC_Criteria: public A_Criteria, public C_Criteria{
  public:
    AorC_Criteria(const string& artist, const string& category);

    virtual bool matches(const Song& s) const;
    virtual void print(ostream& ost) const;
};

#endif
