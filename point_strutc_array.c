#include <stdio.h>
#include <stdlib.h>
//#define ARRAY_WAY

typedef unsigned char uint8_t;
typedef struct mux Mux;
struct mux {
    uint8_t slave;
    uint8_t addr;
};

void getMux(Mux **);

Mux g_mux[2] =
{
    { 0x30, 0x60},
    { 0x40, 0x80},
};


int main(){
#ifdef ARRAY_WAY
    struct mux *ppMux[2]={NULL};
#else
    struct mux **ppMux;
    ppMux = malloc( 2* sizeof(struct mux *));
#endif
    getMux(ppMux);
    printf("1.slave:0x%x , 1.addr: 0x%x \n", (*ppMux[0]).slave, (*ppMux[0]).addr);
    printf("2.slave:0x%x , 2.addr: 0x%x \n", ppMux[1]->slave, ppMux[1]->addr);
}

void getMux(Mux **ppMux)
{
#ifdef ARRAY_WAY
    printf ( "ARRAY_WAY\n" );
    ppMux[0] = &g_mux[0];
    ppMux[1] = &g_mux[1];
#else
    printf ( "POINT_WAY\n" );
    *ppMux = &g_mux[0];
    ppMux++;
    *ppMux = &g_mux[1];
#endif
}
