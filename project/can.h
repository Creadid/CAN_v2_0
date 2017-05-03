#ifndef c_CAN_H
#define c_CAN_H


class c_CAN
{
public:
    // Constructors and Destructors
    c_CAN();
    ~c_CAN(){}
    // Definitions
    //// Others
    enum  e_POLARITY { DOMINANT, RECESSIVE };
    const int   p_MAX_NODES                = 40                                       ;
    //// Times/Oscillations
    const float p_NOMINAL_BIT_RATE         = 10^6                                     ; // [bit/s] [bit*H] -> 1Mbit/s
    const float p_NOMINAL_BIT_TIME         = 1/p_NOMINAL_BIT_RATE                     ; // [s/bit]
    const float p_NETWORK_LENGTH           = 100                                      ; // [m]
    const float p_NETWORK_SPEED            = 3*10^8                                   ; // [m/s]Light Speed
    const float p_SIGNAL_PROPRAGATION_TIME = p_NETWORK_LENGTH/p_NETWORK_SPEED         ; // [s] -> 3.(3)*10^-7 Seconds
    const float p_OSCILLATIONS_RATE        = 1024                                     ; // [oscillations/bit]
    const float p_MINIMUM_TIME_QUANTUM     = p_NOMINAL_BIT_TIME / p_OSCILLATIONS_RATE ; // [s/oscillation]
};

#endif // c_CAN_H
