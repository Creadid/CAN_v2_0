#ifndef MESSAGE_DATA_OR_REQUEST_H
#define MESSAGE_DATA_OR_REQUEST_H

#include <can.h>

struct Arbitration_Field
{
    int  Identifier     ; // Message ID (11 bits), most significant 7 bits (ID-10 to ID-4) must no all be recessive
    bool RTR_Bit        ; // Remote Transmission Request bit, Dominant for Data Frames, Recessive for Remote Frames
};

struct Control_Field
{
    int reserved        ; // Transmitters have to send 2 Dominant bits, Receivers can accept whatever
    int data_lengh_code ; // Number of bytes of the Data Field (4 bits, 0-8 bytes, not all bytes possibilities used), check Table page 12
};

struct CRC_Field
{
    int  CRC_Sequence   ; // ?
    bool CRC_Delimiter  ; // Recessive bit
};

struct ACK_Field
{
    bool ACK_Slot       ; // Transmitters send 1 Recessive bit
                          // Receivers matching the CRC Sequence report by superscribing 1 Dominat bit
    bool ACK_Delimiter  ; // Recessive bit
};

//Message Class, 7 Fields with a Total of 32 bits + 0-8 bytes (4-12 bytes)
class message_DATA_OR_REQUEST
:
    public
        CAN
{
public:
    // Default Constructor
    message_DATA_OR_REQUEST();
    // Full Constructor
    message_DATA_OR_REQUEST(bool x1, Arbitration_Field x2, Control_Field x3, int x4, CRC_Field x5, ACK_Field x6, bool x7);
    // Partial Constructor without Start and End of Frame
    message_DATA_OR_REQUEST(Arbitration_Field x2, Control_Field x3, int x4, CRC_Field x5, ACK_Field x6);

private:
    bool              m_Start_Of_Frame    ; // Dominant                                (1 bit)
    Arbitration_Field m_Arbitration_Field ; // Identifier + RTR bit                    (11 + 1 bits)
    Control_Field     m_Control_Field     ; // Reserved + Data lenght                  (2 + 4 bits)
    int               m_Data_Field        ; // Message Data                            (0-8 bytes)
    CRC_Field         m_CRC_Field         ; // CRC sequence + CRC delimiter, Recessive (? + 1 bits)
    ACK_Field         m_ACK_Field         ; // ACK Slot + ACK Delimiter                (1 + 1 bits)
    bool              m_End_Of_Frame      ; // Recessive                               (7 bits)
};
#endif // MESSAGE_DATA_OR_REQUEST_H
