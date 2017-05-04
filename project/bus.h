#ifndef c_BUS_H
#define c_BUS_H

// My Includes
#include "can.h"
#include "node.h"
#include "main.h"

// C++ Includes
#include <vector>
#include <mutex>
#include <string>

// C Includes

class c_BUS : public c_CAN
{
private:
    // Definitions
    enum e_THREAD_TYPE { BUS, NEW_NODES };

    // Member Variables
    //// # Bits
    int m_Bits_SYNC_REG =1 ;
    int m_Bits_PROP_SEG    ;
    int m_Bits_PHASE_SEG1  ;
    int m_Bits_PHASE_SEG2  ;
    //// # Time
    float m_Time_INFO_PROC = 2*m_Time_QUANTUM                    ;
    float m_Time_PROP_SEG  = 2*c_CAN::p_SIGNAL_PROPRAGATION_TIME ; // TO-DO: add input comparator and output driver delays
    float m_Time_QUANTUM   = 8*c_CAN::p_MINIMUM_TIME_QUANTUM     ;
    //// # Nodes
    int  m_Number_Of_Nodes;
    //// Others
                           bool m_Current_Bit              ;
                           bool m_BUS_Initialized  = false ;
                           bool m_Exit_Condition   = false ;
    std::vector < std::string > m_New_Node_Name            ;
    std::mutex                  s_Nodes_Mutex              ;

    // Member Functions
    void f_Check_Nodes_Heatbeats ( void );
    void f_Update_Nodes          ( void );
    void f_Receive_Bit           ( void );

public:
    // Constructors and Destructors
    c_BUS();
    ~c_BUS(){}

    // 5 Main Member Functions
    void Init ( void );
    //Input  ();
    void Tick ( void );
    //Output ();
    void Exit ( void );

    // Other Member Functions
    void f_Init_Socket             ( void             ) const ;
    void f_Create_New_Nodes_Thread ( void             )       ;
    void f_Add_Node                ( std::string name ) { m_New_Node_Name.push_back( name ) ; }

    // Setters and Getters
    bool f_Get_BUS_Initialized( void  ) const { return m_BUS_Initialized ;}
    int  f_Get_Exit_Condition ( void  ) const { return m_Exit_Condition  ;}
    void f_Set_BUS_Initialized( void  )       { m_BUS_Initialized = true ;}
    void f_Set_Current_Bit    ( int x )       { m_Current_Bit     = x    ;}
    void f_Set_Exit_Condition ( void  )       { m_Exit_Condition  = true ;}

    // TODO REMOVE (put private)
    std::vector < c_node * > m_Nodes_Adress;

};

#endif // c_BUS_H
