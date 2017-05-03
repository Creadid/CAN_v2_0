#ifndef MAIN_H
#define MAIN_H

// C includes
#include <unistd.h>

// C++ includes
#include <iostream>
#include <vector>
#include <thread>

// My includes
#include "message_DATA_OR_REQUEST.h"
#include "bus.h"
#include "can.h"
#include "node.h"

// Functions Declarations
void execute_BUS_Thread ( void );
bool Wait_For_BUS_Initialization( void ) ;
int  main( void );

#endif // MAIN_H

