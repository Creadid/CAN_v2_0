#ifndef c_BUS_H
#define c_BUS_H

// My Includes
#include <can.h>
#include <node.h>

// Other Includes
#include <vector>

class c_BUS
    :
    public
     c_CAN
{
private:
    // Member Variables
    //// # Bits
    int m_Bits_SYNC_REG =1 ;
    int m_Bits_PROP_SEG    ;
    int m_Bits_PHASE_SEG1  ;
    int m_Bits_PHASE_SEG2  ;
    //// # Time
    float m_Time_INFO_PROC = 2*m_Time_QUANTUM                  ;
    float m_Time_PROP_SEG  = 2*(c_CAN::p_SIGNAL_PROPRAGATION_TIME) ; // TO-DO: add input comparator and output driver delays
    float m_Time_QUANTUM  = 8 * c_CAN::p_MINIMUM_TIME_QUANTUM      ;
    //// # Nodes
    int m_Number_Of_Nodes;
    //// Others
    bool m_Current_Bit;
    // Member Functions
    int  f_Check_Nodes_Heatbeats( void );
    void f_Update_Nodes( void );
    void f_Receive_Bit ( void );

public:
    // Constructors and Destructors
    c_BUS();
    ~c_BUS(){}
    // 5 Main Functions
    //Init   ();
    //Input  ();
    void Tick (void);
    //Output ();
    //Exit   ();

    // TODO REMOVE (put private)
    std::vector < c_node * > m_Nodes_Adress;

    // Setters and Getters
    int  f_Get_Number_Of_Nodes(       ){ return m_Number_Of_Nodes ;}
    void f_Set_Number_Of_Nodes( int x ){ m_Number_Of_Nodes = x    ;}
    void f_Set_Current_Bit    ( int x ){ m_Current_Bit = x        ;}
};

#endif // c_BUS_H
