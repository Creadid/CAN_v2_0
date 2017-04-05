#include "message_DATA_OR_REQUEST.h"

message_DATA_OR_REQUEST::message_DATA_OR_REQUEST()
:
m_Arbitration_Field { 0, 0                },
m_Control_Field     { 0, 0                },
m_Data_Field        { 0                   },
m_CRC_Field         { 0, 0                },
m_ACK_Field         { 0, 0                },
m_Start_Of_Frame    { POLARITY::RECESSIVE },
m_End_Of_Frame      { POLARITY::DOMINANT  }
{}

message_DATA_OR_REQUEST::message_DATA_OR_REQUEST(bool x1, Arbitration_Field x2, Control_Field x3, int x4, CRC_Field x5, ACK_Field x6, bool x7)
:
    m_Start_Of_Frame    ( x1 ),
    m_Arbitration_Field ( x2 ),
    m_Control_Field     ( x3 ),
    m_Data_Field        ( x4 ),
    m_CRC_Field         ( x5 ),
    m_ACK_Field         ( x6 ),
    m_End_Of_Frame      ( x7 )
{}

message_DATA_OR_REQUEST::message_DATA_OR_REQUEST(Arbitration_Field x2, Control_Field x3, int x4, CRC_Field x5, ACK_Field x6)
:
    m_Arbitration_Field ( x2 ),
    m_Control_Field     ( x3 ),
    m_Data_Field        ( x4 ),
    m_CRC_Field         ( x5 ),
    m_ACK_Field         ( x6 ),
    m_Start_Of_Frame    { POLARITY::RECESSIVE },
    m_End_Of_Frame      { POLARITY::DOMINANT  }
{}
