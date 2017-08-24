/*	fread(model.fire_model_2.sq1_1, sizeof(float),insideDim*inputDim,fp);			\
	fread(model.fire_model_2.sq1_1_bias, sizeof(float),insideDim,fp);				\
	fread(model.fire_model_2.ex1_1, sizeof(float),insideDim*halfOutputDim,fp);		\
	fread(model.fire_model_2.ex1_1_bias, sizeof(float),halfOutputDim,fp);			\
	fread(model.fire_model_2.ex3_3, sizeof(float),insideDim*halfOutputDim*3*3,fp);	\
	fread(model.fire_model_2.ex3_3_bias, sizeof(float),halfOutputDim,fp);			\
	}*/

#include <stdlib.h>
#include <stdio.h>

#include "load_model.h"

char model_path[] = "squeezeDet_quant_8bit.bin";
FILE *fp;


int load_model(net_model * model){

	fp = fopen(model_path,"r"); // read mode
	if( fp == NULL )
	{
	   perror("Error while opening the file.\n");
	   return -1;
	}


	//ConvLayer 1
	fread((model_t *)(*model).conv1, sizeof(model_t),3*3*3*64,fp);
	fread((model_t *)(*model).conv1_bias, sizeof(model_t),64,fp);
	//FireUnit 2
	fread((model_t *)(*model).fire2.sq1_1, sizeof(model_t),16*64,fp);
	fread((model_t *)(*model).fire2.sq1_1_bias, sizeof(model_t),16,fp);
	fread((model_t *)(*model).fire2.ex1_1, sizeof(model_t),16*64,fp);
	fread((model_t *)(*model).fire2.ex1_1_bias, sizeof(model_t),64,fp);
	fread((model_t *)(*model).fire2.ex3_3, sizeof(model_t),16*64*3*3,fp);
	fread((model_t *)(*model).fire2.ex3_3_bias, sizeof(model_t),64,fp);
	//FireUnit 3
	fread((model_t *)(*model).fire3.sq1_1, sizeof(model_t),16*128,fp);
	fread((model_t *)(*model).fire3.sq1_1_bias, sizeof(model_t),16,fp);
	fread((model_t *)(*model).fire3.ex1_1, sizeof(model_t),16*64,fp);
	fread((model_t *)(*model).fire3.ex1_1_bias, sizeof(model_t),64,fp);
	fread((model_t *)(*model).fire3.ex3_3, sizeof(model_t),16*64*3*3,fp);
	fread((model_t *)(*model).fire3.ex3_3_bias, sizeof(model_t),64,fp);

	//FireUnit 4
	fread((model_t *)(*model).fire4.sq1_1, sizeof(model_t),32*128,fp);
	fread((model_t *)(*model).fire4.sq1_1_bias, sizeof(model_t),32,fp);
	fread((model_t *)(*model).fire4.ex1_1, sizeof(model_t),32*128,fp);
	fread((model_t *)(*model).fire4.ex1_1_bias, sizeof(model_t),128,fp);
	fread((model_t *)(*model).fire4.ex3_3, sizeof(model_t),32*128*3*3,fp);
	fread((model_t *)(*model).fire4.ex3_3_bias, sizeof(model_t),128,fp);

	//FireUnit 5
	fread((model_t *)(*model).fire5.sq1_1, sizeof(model_t),32*256,fp);
	fread((model_t *)(*model).fire5.sq1_1_bias, sizeof(model_t),32,fp);
	fread((model_t *)(*model).fire5.ex1_1, sizeof(model_t),32*128,fp);
	fread((model_t *)(*model).fire5.ex1_1_bias, sizeof(model_t),128,fp);
	fread((model_t *)(*model).fire5.ex3_3, sizeof(model_t),32*128*3*3,fp);
	fread((model_t *)(*model).fire5.ex3_3_bias, sizeof(model_t),128,fp);
	//FireUnit 6
	fread((model_t *)(*model).fire6.sq1_1, sizeof(model_t),48*256,fp);
	fread((model_t *)(*model).fire6.sq1_1_bias, sizeof(model_t),48,fp);
	fread((model_t *)(*model).fire6.ex1_1, sizeof(model_t),48*192,fp);
	fread((model_t *)(*model).fire6.ex1_1_bias, sizeof(model_t),192,fp);
	fread((model_t *)(*model).fire6.ex3_3, sizeof(model_t),48*192*3*3,fp);
	fread((model_t *)(*model).fire6.ex3_3_bias, sizeof(model_t),192,fp);
	//FireUnit 7
	fread((model_t *)(*model).fire7.sq1_1, sizeof(model_t),48*384,fp);
	fread((model_t *)(*model).fire7.sq1_1_bias, sizeof(model_t),48,fp);
	fread((model_t *)(*model).fire7.ex1_1, sizeof(model_t),48*192,fp);
	fread((model_t *)(*model).fire7.ex1_1_bias, sizeof(model_t),192,fp);
	fread((model_t *)(*model).fire7.ex3_3, sizeof(model_t),48*192*3*3,fp);
	fread((model_t *)(*model).fire7.ex3_3_bias, sizeof(model_t),192,fp);
	//FireUnit 8
	fread((model_t *)(*model).fire8.sq1_1, sizeof(model_t),64*384,fp);
	fread((model_t *)(*model).fire8.sq1_1_bias, sizeof(model_t),64,fp);
	fread((model_t *)(*model).fire8.ex1_1, sizeof(model_t),64*256,fp);
	fread((model_t *)(*model).fire8.ex1_1_bias, sizeof(model_t),256,fp);
	fread((model_t *)(*model).fire8.ex3_3, sizeof(model_t),64*256*3*3,fp);
	fread((model_t *)(*model).fire8.ex3_3_bias, sizeof(model_t),256,fp);
	//FireUnit 9
	fread((model_t *)(*model).fire9.sq1_1, sizeof(model_t),64*512,fp);
	fread((model_t *)(*model).fire9.sq1_1_bias, sizeof(model_t),64,fp);
	fread((model_t *)(*model).fire9.ex1_1, sizeof(model_t),64*256,fp);
	fread((model_t *)(*model).fire9.ex1_1_bias, sizeof(model_t),256,fp);
	fread((model_t *)(*model).fire9.ex3_3, sizeof(model_t),64*256*3*3,fp);
	fread((model_t *)(*model).fire9.ex3_3_bias, sizeof(model_t),256,fp);
	//FireUnit 10
	fread((model_t *)(*model).fire10.sq1_1, sizeof(model_t),96*512,fp);
	fread((model_t *)(*model).fire10.sq1_1_bias, sizeof(model_t),96,fp);
	fread((model_t *)(*model).fire10.ex1_1, sizeof(model_t),96*384,fp);
	fread((model_t *)(*model).fire10.ex1_1_bias, sizeof(model_t),384,fp);
	fread((model_t *)(*model).fire10.ex3_3, sizeof(model_t),96*384*3*3,fp);
	fread((model_t *)(*model).fire10.ex3_3_bias, sizeof(model_t),384,fp);
	//FireUnit 11
	fread((model_t *)(*model).fire11.sq1_1, sizeof(model_t),96*768,fp);
	fread((model_t *)(*model).fire11.sq1_1_bias, sizeof(model_t),96,fp);
	fread((model_t *)(*model).fire11.ex1_1, sizeof(model_t),96*384,fp);
	fread((model_t *)(*model).fire11.ex1_1_bias, sizeof(model_t),384,fp);
	fread((model_t *)(*model).fire11.ex3_3, sizeof(model_t),96*384*3*3,fp);
	fread((model_t *)(*model).fire11.ex3_3_bias, sizeof(model_t),384,fp);
	//ConvDet
	fread((model_t *)(*model).convDet, sizeof(model_t),CONVDET_CHANNELS*768*3*3,fp);
	fread((model_t *)(*model).convDet_bias, sizeof(model_t),CONVDET_CHANNELS,fp);


	//printf(" fire 3 ex3_3 val 1_1_1_2 : %d\n", (*model).fire3.ex3_3[1][1][1][2]);
	//printf(" conv1 val 0_0_0_0 : %d\n", (*model).conv1[0][0][0][0]);


	fclose(fp);
	return 0;
}
