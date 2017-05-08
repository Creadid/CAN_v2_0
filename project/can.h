#ifndef c_CAN_H
#define c_CAN_H

// C Includes
#include <errno.h>
#include <time.h>

// C++ Includes
#include <iostream>

namespace n_CAN {

    enum  e_POLARITY { DOMINANT, RECESSIVE };
    const int   p_MAX_NODES                = 40                                       ;
    //// Times/Oscillations
    const float p_NOMINAL_BIT_RATE         = 1                                      ; // [bit/s] [bit*H] -> 1kbit/s
    const float p_NOMINAL_BIT_TIME         = 1/p_NOMINAL_BIT_RATE                     ; // [s/bit]
    const long  p_NOMINAL_BIT_TIME_NS      = (long) p_NOMINAL_BIT_TIME*1e9                   ; // [ns/bit]
    const float p_NETWORK_LENGTH           = 100                                      ; // [m]
    const float p_NETWORK_SPEED            = 3*1e8                                    ; // [m/s]Light Speed
    const float p_SIGNAL_PROPRAGATION_TIME = p_NETWORK_LENGTH/p_NETWORK_SPEED         ; // [s] -> 3.(3)*10^-7 Seconds
    const float p_OSCILLATIONS_RATE        = 1024                                     ; // [oscillations/bit]
    const float p_MINIMUM_TIME_QUANTUM     = p_NOMINAL_BIT_TIME / p_OSCILLATIONS_RATE ; // [s/oscillation]
    //
    const float  p_FREQ_TICK = 60;
    const time_t p_TIME_TICK = 1/p_FREQ_TICK;

    // Ref: Advanced Linux Programming
     int Sleep_ns ( time_t, long );

}

#endif // c_CAN_H
