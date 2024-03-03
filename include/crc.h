#ifndef __CRC_GEN__
#define __CRC_GEN__
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 *  Declarations
 */
uint8_t crc8(uint8_t * data, size_t data_size, uint8_t poly,
            uint8_t init, bool refin, bool refout, uint8_t xor_out);
uint8_t crc8_T(uint8_t *table, uint8_t * data, size_t data_size, uint8_t init, bool refin, bool refout, uint8_t xor_out);
uint8_t rev8(uint8_t);
uint8_t core8(uint8_t val, uint8_t poly);
void gen_lookup8(uint8_t *dest, uint8_t poly, bool refin);

uint16_t crc16(uint8_t *data, uint16_t data_size, uint16_t poly,
                uint16_t init, bool refin, bool refout, uint16_t xor_out);
uint16_t crc16_T(uint16_t *table, uint8_t * data, size_t data_size, uint16_t init, bool refin, bool refout, uint16_t xor_out);
uint16_t rev16(uint16_t);
uint16_t core16(uint16_t val, uint16_t poly);
void gen_lookup16(uint16_t *dest, uint16_t poly, bool refin);

uint32_t crc32(uint8_t *data, uint16_t data_size, uint32_t poly,
                uint32_t init, bool refin, bool refout, uint32_t xor_out);
uint32_t crc32_T(uint32_t *table, uint8_t * data, size_t data_size, uint32_t init, bool refin, bool refout, uint32_t xor_out);
uint32_t rev32(uint32_t);
uint32_t core32(uint32_t val, uint32_t poly);
void gen_lookup32(uint32_t *dest, uint32_t poly, bool refin);
            
#endif
