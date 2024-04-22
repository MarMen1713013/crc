#include "crc.h"

/**
 * Definitions
 */

uint8_t crc8(
        uint8_t *data, size_t data_size, uint8_t poly,
        uint8_t init, bool refin, bool refout, uint8_t xor_out) {
    //Sanity check
    if(data == NULL) return 0;
    uint8_t crc = init;
    for(size_t i = 0; i < data_size; i++) {
        crc ^= (refin ? rev8(data[i]) : data[i]);
        crc = core8(crc,poly);
    }
    return (refout ? rev8(crc) : crc) ^ xor_out;
}

uint8_t crc8_T(
        uint8_t *table, uint8_t * data, size_t data_size,
        uint8_t init, bool refin, bool refout, uint8_t xor_out) {
    //Sanity check
    if(data == NULL) return 0;
    uint8_t crc = init;
    for(size_t i = 0; i < data_size; ++i) {
        uint8_t in = data[i];
        uint8_t tmp = crc ^ in;
        crc = table[tmp];
    }
    return (refin^refout ? rev8(crc) : crc) ^ xor_out;
}

uint8_t rev8(uint8_t in) {
    uint8_t tmp=0;
    for(int i = 0; i<8;++i) tmp |= ((in >> i)&0x01)<<(7-i);
    return tmp;
}

uint8_t core8(uint8_t val, uint8_t poly) {
    for(size_t j = 0; j < 8; j++) {
        if (val & 0x80) val = (val << 1) ^ poly;
        else val <<= 1;
    }
    return val;
}

void gen_lookup8(uint8_t *dest, uint8_t poly, bool refin) {
    //iterate over all byte values 0 - 255
    for(size_t dividend = 0; dividend < 256; dividend++) {
        uint8_t crc = refin ? rev8(dividend) : dividend;
        //calculate the CRC-8 value for current byte
        crc = refin ? rev8(core8(crc,poly)) : core8(crc,poly);
        //store CRC value in lookup table
        dest[dividend] = crc;
    }
}

uint16_t crc16(
            uint8_t *data, uint16_t data_size, uint16_t poly,
            uint16_t init, bool refin, bool refout, uint16_t xor_out) {
    //Sanity check
    if(data == NULL) return 0;
    uint16_t crc = init;
    for (size_t i = 0; i < data_size; i++) {
        crc ^= (uint16_t)(refin ? rev8(data[i]) : data[i]) << 8;
        crc = core16(crc,poly);
    }
    return (refout ? rev16(crc) : crc) ^ xor_out;
}

uint16_t crc16_T(
            uint16_t *table, uint8_t *data, size_t data_size,
            uint16_t init, bool refin, bool refout, uint16_t xor_out) {
    //Sanity check
    if(data == NULL) return 0;
    uint16_t crc = init;
    for(size_t i = 0; i < data_size; ++i) {
        uint8_t in = data[i];
        uint8_t tmp = 0;
        if(refin) {
            crc ^= in;
            tmp = crc;
            crc >>= 8;
        } else {
            crc ^= (uint16_t)(in)<<8;
            tmp = crc>>8;
            crc <<= 8;
        }
        crc ^= table[tmp];
    }
    return (refin^refout ? rev16(crc) : crc) ^ xor_out;
}

uint16_t rev16(uint16_t in) {
    return (uint16_t)rev8((uint8_t)in) << 8 | rev8(in>>8); 
}

uint16_t core16(uint16_t val, uint16_t poly) {
    for(size_t j = 0; j < 8; j++) {
        if (val & 0x8000) val = (val << 1) ^ poly;
        else val <<= 1;
    }
    return val;
}

void gen_lookup16(uint16_t *dest, uint16_t poly, bool refin) {
    //iterate over all byte values 0 - 255
    for(size_t dividend = 0; dividend < 256; dividend++) {
        uint16_t crc = (uint16_t)(refin ? rev8(dividend) : dividend) << 8;
        //calculate the CRC-16 value for current byte
        crc = refin ? rev16(core16(crc,poly)) : core16(crc,poly);
        //store CRC value in lookup table
        dest[dividend] = crc;
    }
}

uint32_t crc32(
            uint8_t *data, uint16_t data_size, uint32_t poly,
            uint32_t init, bool refin, bool refout, uint32_t xor_out) {
    //Sanity check
    if(data == NULL) return 0;
    uint32_t crc = init;
    for(size_t i = 0; i < data_size; i++) {
        crc ^= (uint32_t)(refin ? rev8(data[i]) : data[i]) << 24;
        crc = core32(crc,poly);
    }
    return (refout ? rev32(crc) : crc) ^ xor_out;
}



uint32_t crc32_T(
            uint32_t *table, uint8_t *data, size_t data_size,
            uint32_t init, bool refin, bool refout, uint32_t xor_out) {
    //Sanity check
    if(data == NULL) return 0;
    uint32_t crc = init;
    for(size_t i = 0; i < data_size; ++i) {
        uint8_t in = data[i];
        uint8_t tmp = 0;
        if(refin) {
            crc ^= in;
            tmp = crc;
            crc >>= 8;
        } else {
            crc ^= (uint32_t)(in)<<24;
            tmp = crc>>24;
            crc <<= 8;
        }
        crc ^= table[tmp];
    }
    return (refin^refout ? rev32(crc) : crc) ^ xor_out;
}

uint32_t rev32(uint32_t in) {
    return (uint32_t)rev16((uint16_t)in) << 16 | rev16(in>>16); 
}

uint32_t core32(uint32_t val, uint32_t poly) {
    for (size_t j = 0; j < 8; j++) {
        if (val & 0x80000000) val = (val << 1) ^ poly;
        else val <<= 1;
    }
    return val;
}

void gen_lookup32(uint32_t *dest, uint32_t poly, bool refin) {
    //iterate over all byte values 0 - 255
    for(size_t dividend = 0; dividend < 256; dividend++) {
        uint32_t crc = (uint32_t)(refin ? rev8(dividend) : dividend) << 24;
        //calculate the CRC-32 value for current byte
        crc = refin ? rev32(core32(crc,poly)) : core32(crc,poly);
        //store CRC value in lookup table
        dest[dividend] = crc;
    }
}

