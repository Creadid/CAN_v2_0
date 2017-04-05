#include "bus.h"

// Default Constructor
c_BUS::c_BUS()
{

}

void c_BUS::Tick( void )
{
    f_Update_Nodes ();
    f_Receive_Bit  ();
}

// Check if there were new nodes during the BUS Tick
void c_BUS::f_Update_Nodes( void )
{
    // Check for Nodes heartbeat
    int number_of_nodes_aux = c_BUS::f_Check_Nodes_Heatbeats();
    // Update the Nodes count
    f_Set_Number_Of_Nodes( number_of_nodes_aux );
}

// Check the number of nodes that are alive
int c_BUS::f_Check_Nodes_Heatbeats( void )
{
    // TO-DO
    return 0; // To Delete
}

// Receive the bits
void c_BUS::f_Receive_Bit( void)
{
    bool received_bit = c_CAN::RECESSIVE;
    bool node_bit     = c_CAN::RECESSIVE;

    // receive the bit of each note and see if it detects a dominant bit
    for (int i = 0; i < c_BUS::m_Number_Of_Nodes; i++)
    {
        node_bit = m_Nodes_Adress[i]->c_node::f_Get_Node_Bit();
        if ( node_bit == c_CAN::DOMINANT )
        {
            received_bit = c_CAN::DOMINANT ;
            break;
        }
    }
    f_Set_Current_Bit( received_bit );
}
