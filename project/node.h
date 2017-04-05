#ifndef NODE_H
#define NODE_H

#include <message_DATA_OR_REQUEST.h>

enum STATE             { idle, receiving, transmitting, error };
enum FAULT_CONFINEMENT { error_active, error_passive, bus_off }; // page 61

class node
:
    public
        message_DATA_OR_REQUEST
{

public:

    // Constructors and Destructors
    node();
    ~node(){}

    // Member Functions
    virtual void message_send(){}
    virtual void message_receive(){}
    virtual void message_request(){}
    virtual void sincronyze(){};
    virtual void detect_error();    // see page 59 for 5 different types of errors

private:
    // Member Variables
    char m_state;
    char m_fault_confinement;
    int  m_Error_Count_Transmit; // page 61
    int  m_Error_Count_Receive;  // page 61
};

#endif // NODE_H
