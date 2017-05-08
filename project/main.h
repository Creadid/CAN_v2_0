#ifndef MAIN_H
#define MAIN_H

// C includes
#include <unistd.h>
#include <sys/resource.h>

// C++ includes
#include <thread>
#include <iostream>

// My includes
#include "bus.h"

// Functions Declarations
void execute_BUS_Thread ( void );
bool Wait_For_BUS_Initialization( void ) ;
void Set_Priority_With_Errors( int );
int  main( void );

#endif // MAIN_H

