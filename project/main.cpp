#include "main.h"

// Global Variables
c_BUS g_BUS;

void execute_BUS_Thread ( void )
{
    g_BUS.Init();
    while ( !g_BUS.f_Get_Exit_Condition() )
    {
        //BUS.Input();
        g_BUS.Tick();
        //BUS.Output();
    }
    g_BUS.Exit();
}

bool Wait_For_BUS_Initialization( void )
{
    int attempts = 1;
    while ( !g_BUS.f_Get_BUS_Initialized() )
    {
        std::cout << "Attempt #" << attempts << std::endl ;
        sleep(1);
        attempts++;
        if ( attempts > 5 )
        {
            std::cout << "Not able to initialize the BUS... Going to Exit" << std::endl ;
            return false;
        }
    }
    std::cout << "BUS initialized" << std::endl ;

    return true;
}

void Set_Priority_With_Errors( int niceness )
{

    if ( setpriority( PRIO_PROCESS, 0 , niceness ) == -1 ) // Needs sudo requests
    {
        switch errno
        {
            case EACCES:
                std::cout <<
                "The priority is being changed to a lower value\
                and the current process does not have the appropriate privilege."
                << std::endl;
                break;
            case EINVAL:
                std::cout <<
                "The symbol specified in the which argument was not recognized,\
                or the value of the who argument is not a valid process ID, process group ID or user ID."
                << std::endl;
                break;
            case ENOSYS:
                std::cout <<
                "The system does not support this function."
                << std::endl;
                break;
            case EPERM:
                std::cout <<
                "A process was located, but neither the real nor effective user ID of the executing process\
                match the effective user ID of the process whose priority is to be changed."
                << std::endl;
                break;
            case ESRCH:
                std::cout <<
                "No process could be located using the which and who argument values specified."
                << std::endl;
                break;
        }
        exit(0);
    }
}

int main( void )
{
    // Set the priorities of this process
   // Set_Priority_With_Errors( -20 );

    // Create BUS thread and execute it
    std::thread BUS_thread_id ( &execute_BUS_Thread );

    // Continue to execute the Main thread
    if ( std::this_thread::get_id() != BUS_thread_id.get_id() )
    {
        // Wait for BUS initialization
        bool init = Wait_For_BUS_Initialization(); // returns false on bad initialization
        if ( !init ) { exit(0); }

        // Ask for use Input
        std::string user_input ;
        bool ask_for_inputs = true;
        int input;
        do
        {
            std::cout << "Please state your command:" << std::endl ;
            std::cout << "1 - Create new node"        << std::endl ;
            std::cout << "2 - Close the BUS Thread"   << std::endl ;
            std::cin >> user_input ;
            try                              { input = std::stoi(user_input); }
            catch (std::invalid_argument &e) { std::cout << "Exception: Invalid argument..." << std::endl ; input = 0 ;}
            catch (std::out_of_range     &e) { std::cout << "Exception: Out of range..."     << std::endl ; input = 0 ;}
            switch (input)
            {
                case 1:
                    // Talk with user
                    std::cout << "You have selected 1" << std::endl ;
                    std::cout << "Please insert the node name (if nothing then press +):" << std::endl ;
                    std::cin >> user_input ;
                    // Use the input
                    if ( user_input == "+" ) { g_BUS.f_Add_Node( "Unamed"   ) ;}
                    else                     { g_BUS.f_Add_Node( user_input ) ;}
                    //
                    break;
                case 2:
                    // Talk with user
                    std::cout << "You have selected 2" << std::endl ;
                    // Use the input
                    g_BUS.f_Set_Exit_Condition();
                    ask_for_inputs = false;
                    //
                    break;
                default:
                    // Talk with User
                    std::cout << "This is not a valid input" << std::endl ;
                    //
                    break;
            }
            std::cout << "\n\n\n" << std::endl ;
        }
        while (ask_for_inputs);
    }

    // Making sure the BUS thread finished its execution
    BUS_thread_id.join();
    std::cout << "BUS Thread was terminated" << std::endl ;

    return 1;
}
