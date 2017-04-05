#ifndef BUS_H
#define BUS_H

#include<can.h>

class BUS
    :
    public
     CAN
{
public:
    BUS();
    ~BUS(){};
private:
    const float
    int m_Time_QUANTUM  = 8 * CAN::MINIMUM_TIME_QUANTUM;
    // # Bits
    int m_Bits_PROP_SEG
    int m_Bits_SYNC_REG =1;
    int m_Bits_PHASE_SEG1;
    int m_Bits_PHASE_SEG2;
    // # Time
    float m_Time_PROP_SEG = 2*(CAN::SIGNAL_PROPRAGATION_TIME);    // TO-DO: add input comparator and output driver delays
    float m_Time_INFO_PROCE = 2*m_Time_QUANTUM;


    // wiki: Resynchronization occurs on every recessive to dominant transition during the frame(can spec shows more rules_

    // Setters
    virtual void BUS_Set(){};

};

#endif // BUS_H
