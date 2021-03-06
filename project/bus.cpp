#include "bus.h"

// Default Constructor
c_BUS::c_BUS()
{

}

void c_BUS::Init( void )
{
    // Init the Socket for accepting new nodes
    c_BUS::f_Init_Socket ();
    // Acknowledge that the BUS was initialized
    c_BUS::f_Set_BUS_Initialized();
}

void c_BUS::Tick( void )
{
    c_BUS::f_Update_Nodes ();    
    c_BUS::f_Receive_Bit  ();

   // std::cout << "#nodes:" <<  (int)c_BUS::m_Nodes_Adress.size() <<std::endl;

    sleep(1);

}

void c_BUS::Exit ( void )
{
    // Clean up all the stuff
}

// Check if there were new nodes during the BUS Tick
void c_BUS::f_Update_Nodes( void )
{
    // If there are still new Node request, create the node
    if (c_BUS::m_New_Node_Name.size() > 0 )
    {
        // Create a thread to handle the new node and detach it (it is necessary to detach, DON'T KNOW YET WHY :/ )
        std::thread Node_thread_id( &c_BUS::f_Create_New_Nodes_Thread, this );
        Node_thread_id.detach();
    }

    // Check for Nodes heartbeat
    //c_BUS::f_Check_Nodes_Heatbeats();
}

// Receive the bits
void c_BUS::f_Receive_Bit ( void )
{
    bool received_bit = n_CAN::RECESSIVE;
    bool node_bit     = n_CAN::RECESSIVE;

    // receive the bit of each note and see if it detects a dominant bit
    for (int i = 0 ; i < (int)c_BUS::m_Nodes_Adress.size() ; i++)
    {
        node_bit = m_Nodes_Adress[i]->c_node::f_Get_Node_Bit();
        if ( node_bit == n_CAN::DOMINANT )
        {
            received_bit = n_CAN::DOMINANT ;
            break;
        }
    }
    c_BUS::f_Set_Current_Bit( received_bit );
}

// Initialize the BUS Server Socket
void c_BUS::f_Init_Socket (void ) const
{
    int                socket_server_fd     { 0               } ;
    char               socket_name[]        { "Socket_Server" } ;
    struct sockaddr_un struct_socket_adress                     ;

    // Create the socket and save in the file descritor
    socket_server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    // Prevent from errors
    if (socket_server_fd == -1) {exit(0);}

    // Definition of the socket's address structure
    struct_socket_adress.sun_family = AF_UNIX;
    strncpy(struct_socket_adress.sun_path, socket_name, sizeof(struct_socket_adress.sun_path) - 1);

    // Binding - Assigning a name to a socket - NON BLOCKING
    bind(socket_server_fd, (const sockaddr * ) &struct_socket_adress, sizeof(struct_socket_adress));

    // Listening - Making the socket as a passive socket that will receive message of #clients - NON BLOCKING
    listen( socket_server_fd, n_CAN::p_MAX_NODES ); // Set 40 maximum nodes
}


void c_BUS::f_Create_New_Nodes_Thread( void )
{

    std::cout << "I'll try to create a node" << std::endl;

    // Create new node with the given name
    c_node * new_node_adress = new c_node( c_BUS::m_New_Node_Name.at( 0 ) ); // name of the Node is at the first positon

    // Lock Thread to prevent for multi-node creation
    c_BUS::m_Nodes_Mutex.lock();

    // Add new node to the list
    c_BUS::m_Nodes_Adress.push_back( new_node_adress );

    // Clean the request
    c_BUS::m_New_Node_Name.erase( c_BUS::m_New_Node_Name.begin() ); // remove the node as it is in the first position

    // Unlock Thread
    c_BUS::m_Nodes_Mutex.unlock();

    std::cout << "I was able to create a node" << std::endl;

    // Start the node execution by ticking it
    new_node_adress->Tick();
}

//void b (void)
//{
//    // Accepting - ???-> BLOCKING CALL
//    struct sockaddr client_name     ;
//    socklen_t       client_name_len ;
//    int             client_socket_fd;
//    std::cout << "xx" << std::endl ;
//    //accept(socket_server_fd, NULL, NULL);
//    client_socket_fd = accept (socket_server_fd, &client_name, &client_name_len);
//    std::cout << "lol" << std::endl ;
//}
