//____________________________________________________________________________
/*!

\class   genie::InteractionGeneratorMap

\brief   An Interaction -> EventGeneratorI associative container. 
         The container is being built for the loaded EventGeneratorList and for 
         the input InitialState object and is being used to locate the generator
         that can generate aany given interaction.

\author  Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
         CCLRC, Rutherford Appleton Laboratory

\created January 23, 2006

\cpright Copyright (c) 2003-2007, GENIE Neutrino MC Generator Collaboration
         All rights reserved.
         For the licensing terms see $GENIE/USER_LICENSE.
*/
//____________________________________________________________________________

#ifndef _INTERACTION_GENERATOR_MAP_H_
#define _INTERACTION_GENERATOR_MAP_H_

#include <map>
#include <string>
#include <ostream>

using std::map;
using std::string;
using std::ostream;

namespace genie {

class EventGeneratorI;
class InteractionList;
class InitialState;
class EventGeneratorList;

class InteractionGeneratorMap : public map<string, const EventGeneratorI *> {

public :
  InteractionGeneratorMap();
  InteractionGeneratorMap(const InteractionGeneratorMap & igmap);
  ~InteractionGeneratorMap();

  void UseGeneratorList (const EventGeneratorList * list);
  void BuildMap         (const InitialState & init_state);

  const EventGeneratorI * FindGenerator      (const Interaction * in) const;
  const InteractionList & GetInteractionList (void) const;

  void Reset (void);
  void Copy  (const InteractionGeneratorMap & xsmap);
  void Print (ostream & stream) const;

  InteractionGeneratorMap & operator =  (const InteractionGeneratorMap & xsmap);
  friend ostream & operator << (ostream & stream, const InteractionGeneratorMap & xsmap);

private:

  void Init    (void);
  void CleanUp (void);

  const EventGeneratorList * fEventGeneratorList;

  InitialState *    fInitState;
  InteractionList * fInteractionList;
};

}      // genie namespace

#endif // _INTERACTION_GENERATOR_MAP_H_
