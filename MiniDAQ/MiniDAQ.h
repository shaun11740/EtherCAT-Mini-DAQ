#ifndef CUSTOM_PDO_NAME_H
#define CUSTOM_PDO_NAME_H
#define CUST_BYTE_NUM_OUT	0
#define CUST_BYTE_NUM_IN	44
#define TOT_BYTE_NUM_ROUND_OUT	0
#define TOT_BYTE_NUM_ROUND_IN	44

typedef union												//---- output buffer ----
{
	uint8_t  Byte [TOT_BYTE_NUM_ROUND_OUT];
	struct
	{
	}Cust;
} PROCBUFFER_OUT;


typedef union												//---- input buffer ----
{
	uint8_t  Byte [TOT_BYTE_NUM_ROUND_IN];
	struct
	{
		float       Analogue1;
		float       Analogue2;
		float       Analogue3;
		float       Analogue4;
		float       Analogue5;
		float       Analogue6;
		float       Analogue7;
		float       Analogue8;
    float       EulerX;
    float       EulerY;
    float       EulerZ;
	}Cust;
} PROCBUFFER_IN;

#endif