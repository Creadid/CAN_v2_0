#include "node.h"

c_node::c_node()
{
    c_node::m_Node_Name = "Unamed" ;
}

c_node::c_node( std::string name_input )
{
    c_node::m_Node_Name = name_input;
}

bool c_node::f_Get_Node_Bit( void )
{
    return m_Current_Bit;
}

bool c_node::Tick( void )
{
    while ( true )
    {
        // Read from the BUS

        // Do my processing


        // Send the Message
        // 1st send it to the Buffer
        if ( c_node::f_Message_Send_to_Buffer( c_node::m_Message ) && !c_node::m_Message_Send_Thread_Working )
        {
            // 2nd: If the Buffer is not empty, then create a thread to send the message
            // The thread will work until every message in the Buffer is sent
            c_node::f_Message_Send_to_BUS( );
        }
        else
        {
            // I am not sending the message, so I am a receiver and I need to check the bus
        }


        n_CAN::Sleep_ns( n_CAN::p_TIME_TICK, 0  );
    }

    return true;

}

bool c_node::f_Message_Send_to_Buffer( c_message_DATA_OR_REQUEST const & message )
{
        // mutex
        m_Message_Buffer.push_back( message );
        // mutex

        return !m_Message_Buffer.empty() ;
}

void c_node::f_Message_Send_to_BUS( void )
{

    // Annunciate that I am sending Message
    m_Message_Send_Thread_Working = true;

    // Start the loop to send the Messages
    // Stop only when all messages are sent
    while( bool keep_on_looping = true )
    {
        //  Start the timer
        m_Time_Start = m_Clock.now();

        // Do the stuff

        // Encapsulate the Message

        // debug
        std::cout <<"int " << m_Time_Delta.count()*1e-6 << "milisegundos"  <<  std::endl;

        // Compute the time duration
        m_Time_Delta = m_Clock.now() - m_Time_Start;

        // Sleep the rest of the Time to make sure the correct ticking
        n_CAN::Sleep_ns( 0, n_CAN::p_NOMINAL_BIT_TIME_NS - m_Time_Delta.count() );
    }

    // Annunciate that I am not sending Messages anymore
    m_Message_Send_Thread_Working = false;

}
