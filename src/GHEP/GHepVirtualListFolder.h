//____________________________________________________________________________
/*!

\class    genie::GHepVirtualListFolder

\brief    A singleton class to manage all named GHepVirtualLists

\author   Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
          CCLRC, Rutherford Appleton Laboratory

\created  July 16, 2005

\cpright  Copyright (c) 2003-2007, GENIE Neutrino MC Generator Collaboration
          All rights reserved.
          For the licensing terms see $GENIE/USER_LICENSE.
*/
//____________________________________________________________________________

#ifndef _GHEP_VIRTUAL_LIST_FOLDER_H_
#define _GHEP_VIRTUAL_LIST_FOLDER_H_

#include <map>
#include <string>

using std::map;
using std::string;

namespace genie {

class GHepParticle;
class GHepVirtualList;

class GHepVirtualListFolder
{
public:

  static GHepVirtualListFolder * Instance(void);

  void              AddToVirtualList  (string listname, GHepParticle * p);
  bool              VirtualListExists (string listname);
  void              RemoveList        (string listname);
  void              Clear             (void);
  GHepVirtualList * VirtualList       (string listname);

private:

  GHepVirtualListFolder();
  GHepVirtualListFolder(const GHepVirtualListFolder & config_pool);
  virtual ~GHepVirtualListFolder();

  static GHepVirtualListFolder * fInstance;

  map<string, GHepVirtualList *> fVirtualListMap;

  void AddVirtualList(string listname);

  struct Cleaner {
      void DummyMethodAndSilentCompiler() { }
      ~Cleaner() {
         if (GHepVirtualListFolder::fInstance !=0) {
            delete GHepVirtualListFolder::fInstance;
            GHepVirtualListFolder::fInstance = 0;
         }
      }
  };
  friend struct Cleaner;
};

}      // genie namespace

#endif // _GHEP_VIRTUAL_LIST_FOLDER_H_
