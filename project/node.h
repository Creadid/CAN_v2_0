#ifndef c_NODE_H
#define c_NODE_H

// My Includes
#include <message_DATA_OR_REQUEST.h>

// C++ Includes
#include <string>
#include <iostream>
#include <chrono>
#include <vector>

// C Includes

enum e_STATE             { idle, receiving, transmitting, error };
enum e_FAULT_CONFINEMENT { error_active, error_passive, bus_off }; // page 61

class c_node : public c_message_DATA_OR_REQUEST
{

public:

    // Constructors and Destructors
    c_node();
    c_node( std::string );
    ~c_node(){}

    // Member Functions
    virtual void f_message_receive(){}
    virtual void f_message_request(){}
    virtual void f_sincronyze(){}
    virtual void f_detect_error(){}   // see page 59 for 5 different types of errors

    // Member Functions
    bool f_Get_Node_Bit( void );
    void f_Message_Send_to_BUS( void );
    bool f_Message_Send_to_Buffer( c_message_DATA_OR_REQUEST const & message );

    // Main Functions
    bool Tick( void );

private:
    // Member Variables
    char m_state                ;
    char m_fault_confinement    ;
    int  m_Error_Count_Transmit ; // page 61
    int  m_Error_Count_Receive  ; // page 61
    bool m_Current_Bit          ;
    c_message_DATA_OR_REQUEST   m_Message;

    // My variables
    std::string m_Node_Name     ;   // Name of the
    bool m_Message_Send_Thread_Working = false;
    std::vector< c_message_DATA_OR_REQUEST > m_Message_Buffer;

    // Clock Variables
    std::chrono::steady_clock                                                                    m_Clock     ; // Precise Clock
    std::chrono::time_point< std::chrono::steady_clock, std::chrono::duration<long,std::nano>  > m_Time_Start; // Init of time
    std::chrono::duration< long , std::nano>                                                     m_Time_Delta; // End of time - Init of time

};

#endif // c_NODE_H
