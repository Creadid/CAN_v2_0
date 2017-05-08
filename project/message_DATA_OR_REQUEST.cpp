#include "message_DATA_OR_REQUEST.h"

c_message_DATA_OR_REQUEST::c_message_DATA_OR_REQUEST()
:
m_Arbit_Field    { 0, 0                         },
m_Ctr_Field      { 0, 0                         },
m_Data_Field     { 0                            },
m_CRC_Field      { 0, 0                         },
m_ACK_Field      { 0, 0                         },
m_Start_Of_Frame { n_CAN::e_POLARITY::RECESSIVE },
m_End_Of_Frame   { n_CAN::e_POLARITY::DOMINANT  }
{}

c_message_DATA_OR_REQUEST::c_message_DATA_OR_REQUEST(bool x1, Arbit_Field x2, Ctr_Field x3, int x4, CRC_Field x5, ACK_Field x6, bool x7)
:
    m_Start_Of_Frame ( x1 ),
    m_Arbit_Field    ( x2 ),
    m_Ctr_Field      ( x3 ),
    m_Data_Field     ( x4 ),
    m_CRC_Field      ( x5 ),
    m_ACK_Field      ( x6 ),
    m_End_Of_Frame   ( x7 )
{}

c_message_DATA_OR_REQUEST::c_message_DATA_OR_REQUEST(Arbit_Field x2, Ctr_Field x3, int x4, CRC_Field x5, ACK_Field x6)
:
    m_Arbit_Field    ( x2 ),
    m_Ctr_Field      ( x3 ),
    m_Data_Field     ( x4 ),
    m_CRC_Field      ( x5 ),
    m_ACK_Field      ( x6 ),
    m_Start_Of_Frame { n_CAN::e_POLARITY::RECESSIVE },
    m_End_Of_Frame   { n_CAN::e_POLARITY::DOMINANT  }
{}
