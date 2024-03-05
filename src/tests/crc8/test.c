#include <stdint.h>
#include <stdbool.h>
#include <crc.h>
#include <stdio.h>

#define crc_red(x,y) crc8(x,y,0x31,0x00,true,true,0x00)

int main( int argc, char *argv[] ) {
    uint8_t data[] = "Hello, I'm a test string!";
    printf("Input data: %s\n",data);
    size_t len = sizeof(data)/sizeof(char) - 1; //ignore terminating \0

    uint8_t crc = crc_red(data,len); 
    printf("Result: 0x%02X\n",crc);
    bool res = (crc == 0xA6);
    return !res;
}
