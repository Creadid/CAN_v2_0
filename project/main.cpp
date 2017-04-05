#include <iostream>
#include <vector>

#include <bus.h>
#include <can.h>
#include <message_DATA_OR_REQUEST.h>
#include <node.h>

int main( void )
{

    c_BUS  busA;
    c_node nodeA;
    c_node nodeB;

    busA.m_Nodes_Adress.push_back(&nodeA);
    busA.m_Nodes_Adress.push_back(&nodeB);

    busA.f_Set_Number_Of_Nodes( 2 );
    for (int i=1; i<3; i++)
    {
        busA.Tick();
        std::cout << busA.f_Get_Number_Of_Nodes() << std::endl;
    }

return true;
}
