#ifndef BUS_H
#define BUS_H

#include<can.h>

class BUS
    :
    public
     CAN
{
private:
    const float
    int m_Time_QUANTUM  = 8 * CAN::MINIMUM_TIME_QUANTUM;
    // # Bits
    int m_Bits_SYNC_REG =1;
    int m_Bits_PROP_SEG
    int m_Bits_PHASE_SEG1;
    int m_Bits_PHASE_SEG2;
    float m_Time_PROP_SEG = 2*(CAN::SIGNAL_PROPRAGATION_TIME);    // TO-DO: add input comparator and output driver delays
    // # Time
    float m_Time_INFO_PROCE = 2*m_Time_QUANTUM;
	void BUS::f_Check_Nodes_Heatbeats( void );
	void BUS::f_Update_Nodes( void );

	// Setters and Getters
	int  BUS::f_Get_Number_Of_Nodes(       ){ return m_Number_Of_Nodes ;}
	void BUS::f_Set_Number_Of_Nodes( int x ){ m_Number_Of_Nodes = x    ;}

public:

	// Constructors and Destructors
    BUS();
    ~BUS(){};

	// 5 Main Functions
	//Init   ();
	//Input  ();
	Tick   ();
	//Output ();
	//Exit   ();
};

#endif // BUS_H