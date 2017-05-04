#include "node.h"

c_node::c_node()
{
    c_node::m_Node_Name = "Unamed" ;
}

c_node::c_node(std::string name_input)
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
        std::cout << "I'm node with name " << c_node::m_Node_Name << std::endl ;
        sleep(1);
    }

    return true;

}
