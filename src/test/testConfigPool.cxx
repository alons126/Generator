//____________________________________________________________________________
/*!

\program gtestConfigPool

\brief   Program used for testing / debugging GENIE's AlgConfigPool

\author  Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
         STFC, Rutherford Appleton Laboratory

\created May 4, 2004

\cpright Copyright (c) 2003-2009, GENIE Neutrino MC Generator Collaboration
         For the full text of the license visit http://copyright.genie-mc.org
         or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#include "Algorithm/Algorithm.h"
#include "Algorithm/AlgFactory.h"
#include "Algorithm/AlgConfigPool.h"
#include "Base/QELFormFactorsModelI.h"
#include "ElFF/ELFormFactorsModelI.h"
#include "Messenger/Messenger.h"

using namespace genie;

int main(int /*argc*/, char ** /*argv*/)
{
  // Get an instance of the ConfigPool
  LOG("Main", pINFO) << "Get config pool instance";
  AlgConfigPool * pool = AlgConfigPool::Instance();

  // Print the ConfigPool ( => print all its configuration registries )
  LOG("Main", pINFO) << "Printing the config pool\n" << *pool;

  // Get the algorithm factory
  AlgFactory * algf = AlgFactory::Instance();

  // Instantiate an algorithm
  LOG("Main", pINFO) << "Instantiate a concrete algorithm";
  const Algorithm * alg0 = 
       algf->GetAlgorithm("genie::LlewellynSmithModelCC","Default");
  const QELFormFactorsModelI * llewellyn_smith =
                  dynamic_cast<const QELFormFactorsModelI *> (alg0);
  LOG("Main", pINFO) << *alg0;

  LOG("Main", pINFO) << "Instantiate another concrete algorithm";
  const Algorithm * alg1 = 
     algf->GetAlgorithm("genie::DipoleELFormFactorsModel","Default");
  const ELFormFactorsModelI * dipole_elff =
                   dynamic_cast<const ELFormFactorsModelI *> (alg1);
  LOG("Main", pINFO) << *alg1;

  // Ask the ConfigPool for this algorithm's config registry and print it

  LOG("Main", pINFO) << "Find the configuration for both algorithms";

  Registry * config1 = pool->FindRegistry( llewellyn_smith );
  Registry * config2 = pool->FindRegistry( dipole_elff     );

  if(config1) LOG("Main", pINFO) << "1st algorithm config: \n" << *config1;
  if(config2) LOG("Main", pINFO) << "2nd algorithm config: \n" << *config2;

  return 0;
}

