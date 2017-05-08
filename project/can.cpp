#include "can.h"

namespace n_CAN {

    int Sleep_ns (time_t sleep_time_s, long sleep_time_ns )
    {
       // std::cout << "I have to sleep: " << sleep_time_ns << std::endl;
        struct timespec tv;
        /* Construct the timespec from the number of whole seconds... */
        tv.tv_sec  = sleep_time_s; //
        /* ... and the remainder in nanoseconds. */
        tv.tv_nsec =  sleep_time_ns;

        while ( true )
        {
            /* Sleep for the time specified in tv. If interrupted by a
            signal, place the remaining time left to sleep back into tv. */
            //int rval = clock_nanosleep (CLOCK_MONOTONIC, 0, &tv, &tv);
            int rval = nanosleep (&tv, &tv);

            if (rval == 0)
            {
                /* Completed the entire sleep time; all done. */
                return 0;
            }
            else if (errno == EFAULT)
            {
                std::cout <<
                "Request or remain specified an invalid address."
                << std::endl;
                continue;
            }
            else if (errno == EINTR)
            {
                std::cout <<
                "The sleep was interrupted by a signal handler."
                << std::endl;
                continue;
            }
            else if (errno == EINVAL)
            {
                std::cout <<
                "The value in the tv_nsec field was not in the range 0 to 999999999 or tv_sec was negative, or\
                clock_id was invalid.  (CLOCK_THREAD_CPUTIME_ID is not a permitted value for clock_id.)"
                << std::endl;
                continue;
            }
            else
            {
                std::cout << "Some other error with rval:" << rval << std::endl;
                return rval;
            }
        }
        return 0;
    }

}
