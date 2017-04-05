#ifndef CAN_H
#define CAN_H


class CAN
{
public:
    // Constructors and Destructors
    CAN();
    ~CAN(){}
    // Definitions
    enum POLARITY { DOMINANT, RECESSIVE };
    const float NOMINAL_BIT_RATE = 10^6;                                 // [bit/s] [bit*H] -> 1Mbit/s
    const float NOMINAL_BIT_TIME = 1/NOMINAL_BIT_RATE;                   // [s/bit]
    const float NETWORK_LENGTH   = 100;                                  // [m]
    const float NETWORK_SPEED    = 3*10^8                                // [m/s]Light Speed
    const float SIGNAL_PROPRAGATION_TIME = NETWORK_LENGTH/NETWORK_SPEED; // [s]        -> 3.(3)*10^-7 Seconds
    const float OSCILLATIONS_RATE       = 1024                           // [oscillations/bit]
    const float MINIMUM_TIME_QUANTUM = NOMINAL_BIT_TIME / OSCILLATIONS_RATE // [s/oscillation]
};

#endif // CAN_H
