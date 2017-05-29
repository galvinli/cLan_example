#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;

typedef enum psu_status Psu_status;

// PSU Model
//  A, Mask, each command clean
//  B, Mask, each command clean

typedef struct _PSU_SMBusInfo PSU_SMBusInfo;
typedef struct _PSU_CmdData PSU_CmdData;

struct _PSU_SMBusInfo
{
    char label;
    struct _PSU_CmdData *mask_info;
    struct _PSU_CmdData *cmd_code;
};

struct _PSU_CmdData
{
    uint8_t **cmdData;
    uint8_t count;
};

uint8_t PSU_A_MASK[] = { 0x1, 0x2};
uint8_t PSU_A_MASK_LEN = sizeof(PSU_A_MASK)/sizeof(uint8_t);

#define NORMAL_MASK_SIZE  7
uint8_t PSU_NORMAL_MASK[][NORMAL_MASK_SIZE] = {
    {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6},
//    {0x7, 0x7, 0x7, 0x7, 0x4, 0x5, 0x6},
};

uint8_t PSU_NORMAL_MASK_LEN = (sizeof(PSU_NORMAL_MASK)/NORMAL_MASK_SIZE)/sizeof(uint8_t);

uint8_t PSU_NORMAL_CODE[][3] = {
        { 0x1, 0x2, 0x3},
        { 0x4, 0x5, 0x6},
};

//uint8_t normal_code_len = sizeof(normal_code)/sizeof(uint8_t);

typedef enum psumask Psumask;

int main(){
    int i,j;
   PSU_CmdData normal_mask;
   PSU_CmdData normal_code;

   normal_mask.cmdData = malloc( PSU_NORMAL_MASK_LEN* NORMAL_MASK_SIZE * sizeof(uint8_t));
   normal_mask.count = PSU_NORMAL_MASK_LEN;
    for(i=0; i < PSU_NORMAL_MASK_LEN; i++)
    {
        normal_mask.cmdData[i] = &PSU_NORMAL_MASK[i][0];
    }

   normal_code.cmdData = malloc( 2* 3 * sizeof(uint8_t));
   normal_code.count = 2;
    for(i=0; i < 2; i++)
    {
        normal_code.cmdData[i] = &PSU_NORMAL_CODE[i][0];
    }

   PSU_SMBusInfo psu_a = {
                           .label='A',
                           .mask_info = &normal_mask,
                           .cmd_code = &normal_code,
   };
//switch case select PSU model;
   printf("label:%c, mask_count:%d \n",psu_a.label, normal_mask.count);

   printf(" psu_a mask: ");
   printf ( "\n" );
   for(i=0; i < 2; i++)
   {
        for(j=0; j < NORMAL_MASK_SIZE; j++)
        {
            printf(" 0x%x" ,psu_a.mask_info->cmdData[i][j]);
        }
        printf ( "\n" );
   }


   printf(" psu_a cmdCode: ");
   printf ( "\n" );
   for(i=0; i < 2; i++)
   {
        for(j=0; j < 3; j++)
        {
            printf(" 0x%x" ,psu_a.cmd_code->cmdData[i][j]);
        }
        printf ( "\n" );
   }
   printf ( "\n" );
}
