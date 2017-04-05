#include "bus.h"

// Default Constructor
BUS::BUS()
{

}

BUS::Tick()
{	
	f_Update_Nodes ();
	f_Receive_Bit  ();
}

// Check if there were new nodes during the BUS Tick
void BUS::f_Update_Nodes( void )
{
	// Check for Nodes heartbeat
	int number_of_nodes_aux = BUS::f_Check_Nodes_Heatbeats();
	// Update the Nodes count
	f_Set_Number_Of_Nodes( number_of_nodes_aux );		
}

// Check the number of nodes that are alive
void BUS::f_Check_Nodes_Heatbeats( void )
{
	// TO-DO	
}

// Receive the bits
void BUS::Recieve_Bit( void)
{
	bool received_bit = CAN::RECESSIVE;
	bool node_bit     = CAN::RECESSIVE;

	// receive the bit of each note and see if it detects a dominant bit
	for (int i = 0; i < BUS::m_Number_Of_Nodes; i++)
	{		
		node_bit = m_Node_Adress[i]->node::f_Get_Node_Bit();
		if ( note bit == CAN::DOMINANT )
		{ 
			received_bit = CAN::DOMINANT ;
			break;
		}
	}
}