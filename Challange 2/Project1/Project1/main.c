#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct EncryptionStepDescriptor
{
	uint8_t operationCode;
	uint8_t operationParameter;
	uint32_t lengthToOperateOn;
}dec;

void get_dec(dec* keys, int i,uint8_t operationCode, uint8_t operationParameter, uint32_t lengthToOperateOn)
{
	
	keys[i].operationCode = operationCode;
	keys[i].operationParameter = operationParameter;
	keys[i].lengthToOperateOn = lengthToOperateOn;
}


 int* do_operation(dec* operation, char* message_now,char* message_start,  char* message_end, int* direction)
{
	int i;
	char* ptr = message_now;
	for (i = 0; i < operation->lengthToOperateOn; i++)
	{
		if (operation->operationCode == 0) // XOR
		{
			char value = ptr[0]^operation->operationParameter;
			ptr[0] = value;
		}
		else if (operation->operationCode == 1) // ADD
		{
			ptr[0] += operation->operationParameter;
		}
		else if (operation->operationCode == 2) // SUBSTRACT
		{
			ptr[0] -= operation->operationParameter;
		}
		else
		{
			fprintf(stderr, "ERROR! invalid operation code\n");
		}

		
		if (*direction == 1)
		{
			if (ptr == message_end)
				direction[0] = -1;
		}
		else if(*direction == -1)
		{
			if (ptr == message_start)
				direction[0] = 1;
		}
		else
		{
			fprintf(stderr, "ERROR! invalid direction\n");
		}
		ptr += direction[0];
	}
	return ptr;
}

int main()
{
	


	const int length = 8;
	

	
	char message[157];
	message[0] = 156;
	message[1] = 248;
	message[2] = 193;
	message[3] = 197;
	message[4] = 246;
	message[5] = 10;
	message[6] = 192;
	message[7] = 223;
	message[8] = 200;
	message[9] = 5;
	message[10] = 10;
	message[11] = 237;
	message[12] = 223;
	message[13] = 241;
	message[14] = 10;
	message[15] = 197;
	message[16] = 248;
	message[17] = 193;
	message[18] = 10;
	message[19] = 246;
	message[20] = 194;
	message[21] = 193;
	message[22] = 10;
	message[23] = 53;
	message[24] = 59;
	message[25] = 59;
	message[26] = 55;
	message[27] = 193;
	message[28] = 251;
	message[29] = 246;
	message[30] = 10;
	message[31] = 194;
	message[32] = 197;
	message[33] = 203;
	message[34] = 195;
	message[35] = 193;
	message[36] = 248;
	message[37] = 10;
	message[38] = 223;
	message[39] = 196;
	message[40] = 10;
	message[41] = 197;
	message[42] = 222;
	message[43] = 222;
	message[44] = 10;
	message[45] = 246;
	message[46] = 221;
	message[47] = 217;
	message[48] = 193;
	message[49] = 251;
	message[50] = 5;
	message[51] = 10;
	message[52] = 150;
	message[53] = 194;
	message[54] = 193;
	message[55] = 10;
	message[56] = 250;
	message[57] = 197;
	message[58] = 251;
	message[59] = 251;
	message[60] = 247;
	message[61] = 223;
	message[62] = 248;
	message[63] = 198;
	message[64] = 10;
	message[65] = 196;
	message[66] = 223;
	message[67] = 248;
	message[68] = 10;
	message[69] = 246;
	message[70] = 194;
	message[71] = 221;
	message[72] = 251;
	message[73] = 10;
	message[74] = 251;
	message[75] = 246;
	message[76] = 197;
	message[77] = 199;
	message[78] = 193;
	message[79] = 10;
	message[80] = 221;
	message[81] = 251;
	message[82] = 48;
	message[83] = 250;
	message[84] = 243;
	message[85] = 46;
	message[86] = 11;
	message[87] = 122;
	message[88] = 118;
	message[89] = 43;
	message[90] = 108;
	message[91] = 127;
	message[92] = 43;
	message[93] = 120;
	message[94] = 112;
	message[95] = 43;
	message[96] = 84;
	message[97] = 50;
	message[98] = 120;
	message[99] = 94;
	message[100] = 139;
	message[101] = 167;
	message[102] = 177;
	message[103] = 178;
	message[104] = 163;
	message[105] = 176;
	message[106] = 94;
	message[107] = 174;
	message[108] = 176;
	message[109] = 173;
	message[110] = 165;
	message[111] = 176;
	message[112] = 159;
	message[113] = 171;
	message[114] = 171;
	message[115] = 163;
	message[116] = 176;
	message[117] = 101;
	message[118] = 108;
	message[119] = 94;
	message[120] = 140;
	message[121] = 173;
	message[122] = 181;
	message[123] = 94;
	message[124] = 165;
	message[125] = 173;
	message[126] = 94;
	message[127] = 96;
	message[128] = 95;
	message[129] = 17;
	message[130] = 82;
	message[131] = 95;
	message[132] = 85;
	message[133] = 17;
	message[134] = 67;
	message[135] = 74;
	message[136] = 78;
	message[137] = 73;
	message[138] = 63;
	message[139] = 8;
	message[140] = 63;
	message[141] = 73;
	message[142] = 51;
	message[143] = 54;
	message[144] = 8;
	message[145] = 69;
	message[146] = 73;
	message[147] = 116;
	message[148] = 116;
	message[149] = 115;
	message[150] = 115;
	message[151] = 46;
	message[152] = 112;
	message[153] = 128;
	message[154] = 115;
	message[155] = 111;
	message[156] = 121;




	

	dec keys[8];
	

	const int message_length = 157;
	

	get_dec(keys,0,0, 45, 87); // code // parameter // how much
	get_dec(keys, 1,1, 172, 40);
	get_dec(keys, 2,2, 7, 40);
	get_dec(keys, 3,1, 24, 48);
	get_dec(keys,4,1, 75, 100);
	get_dec(keys, 5,0, 82, 82);
	get_dec(keys, 6,2, 2, 64);
	get_dec(keys, 7,0, 55, 33);


	int i;
	char* message_start = message;
	char* message_now = message;
	char* message_end = (message + (message_length-1));

	int direction = 1;
	for(i = 0; i < length; i++)
	{
		message_now = do_operation(keys + i, message_now, message_start, message_end, &direction);
	}

	for (i = 0; i < message_length; i++)
	{
		printf("%c", message[i]);
	}
	getchar();
}