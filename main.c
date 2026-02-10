/*
 * File:   main.c
 * Author: VINAYAK ACHARYA
 *
 * Created on 29 January, 2026, 8:56 AM
 */


#include <xc.h>
#include "ssds.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, BLANK, BLANK};

void init_config(void) {
    ADCON1 = 0x0F;
    init_ssd_control();
}

void main(void) {
    init_config();
    unsigned short i;
    unsigned char d0 = 0;
    unsigned char d1 = 1;
    unsigned char d2 = 2;
    unsigned char d3 = 3;

    unsigned int delay = 0;

    while (1) {
        ssd[0] = digit[d0];
        ssd[1] = digit[d1];
        ssd[2] = digit[d2];
        ssd[3] = digit[d3];

        display(ssd);

        if (++delay >= 100) {
            delay = 0;

            d0 = (d0 + 1) % 12;
            d1 = (d1 + 1) % 12;
            d2 = (d2 + 1) % 12;
            d3 = (d3 + 1) % 12;
        }
    }
}
