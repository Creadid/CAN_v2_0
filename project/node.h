#ifndef c_NODE_H
#define c_NODE_H

// My Includes
#include <message_DATA_OR_REQUEST.h>

// C++ Includes
#include <vector>
#include <mutex>
#include <string>
#include <iostream>

// C Includes
#include <unistd.h>


enum e_STATE             { idle, receiving, transmitting, error };
enum e_FAULT_CONFINEMENT { error_active, error_passive, bus_off }; // page 61

class c_node : public c_message_DATA_OR_REQUEST
{

public:

    // Constructors and Destructors
    c_node();
    c_node( std::string name_input );
    ~c_node(){}

    // Member Functions
    virtual void f_message_send(){}
    virtual void f_message_receive(){}
    virtual void f_message_request(){}
    virtual void f_sincronyze(){}
    virtual void f_detect_error(){}   // see page 59 for 5 different types of errors

    // Member Functions
    bool f_Get_Node_Bit( void );

    // Main Functions
    bool Tick( void );

private:
    // Member Variables
    char m_state                ;
    char m_fault_confinement    ;
    int  m_Error_Count_Transmit ; // page 61
    int  m_Error_Count_Receive  ; // page 61
    bool m_Current_Bit          ;

    // My variables
    std::string m_Node_Name     ;   // Name of the Node

};

#endif // c_NODE_H
