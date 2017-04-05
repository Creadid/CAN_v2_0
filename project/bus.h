#ifndef BUS_H
#define BUS_H


class BUS
{

private:
	
	void BUS::f_Check_Nodes_Heatbeats( void );
	void BUS::f_Update_Nodes( void );

	// Setters and Getters
	int  BUS::f_Get_Number_Of_Nodes(       ){ return m_Number_Of_Nodes ;}
	void BUS::f_Set_Number_Of_Nodes( int x ){ m_Number_Of_Nodes = x    ;}

public:

	// Constructors and Destructors
    BUS();

	// 5 Main Functions
	//Init   ();
	//Input  ();
	Tick   ();
	//Output ();
	//Exit   ();
};

#endif // BUS_H