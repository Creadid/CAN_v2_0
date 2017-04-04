#ifndef MESSAGE_DATA_OR_REQUEST_H
#define MESSAGE_DATA_OR_REQUEST_H

struct m_Arbitration_Field
{
    int  Identifier     ; // Message ID (11 bits), most significant 7 bits (ID-10 to ID-4) must no all be recessive
    bool RTR_Bit        ; // Remote Transmission Request bit, Dominant for Data Frames, Recessive for Remote Frames
};

struct m_Control_Field
{
    int reserved        ; // Transmitters have to send 2 Dominant bits, Receivers can accept whatever
    int data_lengh_code ; // Number of bytes of the Data Field (4 bits, 0-8 bytes, not all bytes possibilities used), check Table page 12
};

struct m_CRC_Field
{
    int  CRC_Sequence   ; // ?
    bool CRC_Delimiter  ; // Recessive bit
};

struct m_ACK_Field
{
    bool ACK_Slot       ; // Transmitters send 1 Recessive bit
                          // Receivers matching the CRC Sequence report by superscribing 1 Dominat bit
    bool ACK_Delimiter  ; // Recessive bit
};

// Message Class, 7 Fields with a Total o 32 bits + 0-8 bytes (4-12 bytes)
class message_DATA_OR_REQUEST
{
public:
    message_DATA_OR_REQUEST();                             // Default  Constructor
    message_DATA_OR_REQUEST(x1, x2, x3, x4, x5, x6, x7);   // Full     Constructor
    message_DATA_OR_REQUEST(x1, x2, x3, x4, x5);           // Partial  Constructor without Start and End of Frame

private:
    int    m_Start_Of_Frame    ; // Dominant                                (1 bit)
    struct m_Arbitration_Field ; // Identifier + RTR bit                    (11 + 1 bits)
    struct m_Control_Field     ; // Reserved + Data lenght                  (2 + 4 bits)
    int    m_Data_Field        ; // Message Data                            (0-8 bytes)
    struct m_CRC_Field         ; // CRC sequence + CRC delimiter, Recessive (? + 1 bits)
    struct m_ACK_Field         ; // ACK Slot + ACK Delimiter                (1 + 1 bits)
    int    m_End_Of_Frame      ; // Recessive                               (7 bits)
};
#endif // MESSAGE_DATA_OR_REQUEST_H
