#pragma once

#include <string>

#include <Singular/libsingular.h>
#include <Singular/links/ssiLink.h> // for ssiInfo etc.
#include <Singular/newstruct.h>

// Singular defines this in ssiLink.cc
#define SSI_VERSION 13

// these are from ssiLink.cc
char* ssiReadString(const ssiInfo *d);

// these are from newstruct.cc
BOOLEAN newstruct_deserialize(blackbox **, void **d, si_link f);
BOOLEAN newstruct_serialize(blackbox *b, void *d, si_link f);

//structs
class ScopedLeftv
{
  public:
    ScopedLeftv (int c, void* data);
    ScopedLeftv (ScopedLeftv& parent, int c, void* data);
    ~ScopedLeftv();
    ScopedLeftv (ScopedLeftv const&) = delete;
    ScopedLeftv (ScopedLeftv&&) = delete;
    ScopedLeftv& operator= (ScopedLeftv const&) = delete;
    ScopedLeftv& operator= (ScopedLeftv&&) = delete;
    leftv leftV() const;
  private:
    leftv _;  
    bool chained = false;
};

void init_singular (std::string const&);
void call_singular ( std::string const&);
void call_singular_and_discard (std::string const&);
std::string filename_generator();
bool register_struct (std::string const&, std::string const&);
si_link ssi_open_for_read (std::string const&);
si_link ssi_open_for_write (std::string const&);
void ssi_close_and_remove (si_link);
void ssi_write_newstruct (si_link, std::string const&, lists);
void ssi_write_newstruct (si_link, int, lists);
std::string serialize (lists, std::string const&);
si_link ssi_open_for_read (std::string const& );
lists ssi_read_newstruct (si_link , std::string const& );
std::pair<int, lists> deserialize (std::string const&, std::string const&);
void load_singular_library (std::string const&);
std::pair<int, lists> call_user_proc (std::string const&,
                                      std::string const&,
                                      int,
                                      lists);

std::pair<int, lists> call_user_proc (std::string const&,
                                      std::string const&,
                                      ScopedLeftv&);
std::string worker();

