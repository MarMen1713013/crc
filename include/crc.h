#ifndef __CRC_GEN__
#define __CRC_GEN__
#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

//8 bit declarations

/**
 * 8 bit bitwise CRC computation
 *
 * @param[in] data Pointer to input data for which the CRC is computed.
 * @param[in] data_size Size of data.
 * @param[in] poly 8 bit polynomial used for CRC computation.
 * @param[in] init Initialization value for CRC computation.
 * @param[in] refin Flag to specify whether the input data to the algorithm has to be reversed.
 * @param[in] refout Flag to specify whether the output CRC has to be reversed.
 * @param[in] xor_out Value to be xored to the CRC before returning its value.
 *
 * @return 8 bit CRC.
 */
uint8_t crc8(
        uint8_t * data, size_t data_size, uint8_t poly,
        uint8_t init, bool refin, bool refout, uint8_t xor_out);

/**
 * 8 bit table-based CRC computation 
 *
 * @param[in] table Pointer to CRC table.
 * @param[in] data Pointer to input data for which the CRC is computed.
 * @param[in] data_size Size of data.
 * @param[in] init Initialization value for CRC computation.
 * @param[in] refin Flag to specify whether the input data to the algorithm has to be reversed.
 * @param[in] refout Flag to specify whether the output CRC has to be reversed.
 * @param[in] xor_out Value to be xored to the CRC before returning its value.
 *
 * @return 8 bit CRC.
 */
uint8_t crc8_T(
        uint8_t *table, uint8_t * data, size_t data_size,
        uint8_t init, bool refin, bool refout, uint8_t xor_out);

/**
 * Utility function used to reverse bit order.
 *
 * @param[in] in Value to be reversed.
 *
 * @return Bitwise inversion of input data.
 */
uint8_t rev8(uint8_t in);

/**
 * Main routine used to compute polinomial division's remainder
 *
 * @param[in] val Polynomial used as the dividend.
 * @param[in] poly Polynomial used as the divisor.
 *
 * @return Reminder of polynomial division.
 */
uint8_t core8(uint8_t val, uint8_t poly);

/**
 * Function used to generate the lookup table for generic CRC configurations
 *
 * @param[in] dest Pointer to data location to be populated with lookup values.
 *                 Has to be at least 256*sizeof(uint8_t).
 * @param[in] poly 8 bit Polynomial of desired CRC configuration.
 * @param[in] refin Flag specifying data inversion of desired CRC configuration.
 */
void gen_lookup8(uint8_t *dest, uint8_t poly, bool refin);

//16 bit declarations

/**
 * 16 bit bitwise CRC computation
 *
 * @param[in] data Pointer to input data for which the CRC is computed.
 * @param[in] data_size Size of data.
 * @param[in] poly 16 bit polynomial used for CRC computation.
 * @param[in] init Initialization value for CRC computation.
 * @param[in] refin Flag to specify whether the input data to the algorithm has to be reversed.
 * @param[in] refout Flag to specify whether the output CRC has to be reversed.
 * @param[in] xor_out Value to be xored to the CRC before returning its value.
 *
 * @return 16 bit CRC.
 */
uint16_t crc16(
            uint8_t *data, uint16_t data_size, uint16_t poly,
            uint16_t init, bool refin, bool refout, uint16_t xor_out);

/**
 * 16 bit table-based CRC computation 
 *
 * @param[in] table Pointer to CRC table.
 * @param[in] data Pointer to input data for which the CRC is computed.
 * @param[in] data_size Size of data.
 * @param[in] init Initialization value for CRC computation.
 * @param[in] refin Flag to specify whether the input data to the algorithm has to be reversed.
 * @param[in] refout Flag to specify whether the output CRC has to be reversed.
 * @param[in] xor_out Value to be xored to the CRC before returning its value.
 *
 * @return 16 bit CRC.
 */
uint16_t crc16_T(
            uint16_t *table, uint8_t * data, size_t data_size,
            uint16_t init, bool refin, bool refout, uint16_t xor_out);

/**
 * Utility function used to reverse bit order.
 *
 * @param[in] in Value to be reversed.
 *
 * @return Bitwise inversion of input data.
 */
uint16_t rev16(uint16_t);

/**
 * Main routine used to compute polinomial division's remainder
 *
 * @param[in] val Polynomial used as the dividend.
 * @param[in] poly Polynomial used as the divisor.
 *
 * @return Reminder of polynomial division.
 */
uint16_t core16(uint16_t val, uint16_t poly);

/**
 * Function used to generate the lookup table for generic CRC configurations
 *
 * @param[in] dest Pointer to data location to be populated with lookup values.
 *                 Has to be at least 256*sizeof(uint16_t).
 * @param[in] poly 16 bit Polynomial of desired CRC configuration.
 * @param[in] refin Flag specifying data inversion of desired CRC configuration.
 */
void gen_lookup16(uint16_t *dest, uint16_t poly, bool refin);

//32 bit declarations

/**
 * 32 bit bitwise CRC computation
 *
 * @param[in] data Pointer to input data for which the CRC is computed.
 * @param[in] data_size Size of data.
 * @param[in] poly 32 bit polynomial used for CRC computation.
 * @param[in] init Initialization value for CRC computation.
 * @param[in] refin Flag to specify whether the input data to the algorithm has to be reversed.
 * @param[in] refout Flag to specify whether the output CRC has to be reversed.
 * @param[in] xor_out Value to be xored to the CRC before returning its value.
 *
 * @return 32 bit CRC.
 */
uint32_t crc32(
            uint8_t *data, uint16_t data_size, uint32_t poly,
            uint32_t init, bool refin, bool refout, uint32_t xor_out);

/**
 * 32 bit table-based CRC computation 
 *
 * @param[in] table Pointer to CRC table.
 * @param[in] data Pointer to input data for which the CRC is computed.
 * @param[in] data_size Size of data.
 * @param[in] init Initialization value for CRC computation.
 * @param[in] refin Flag to specify whether the input data to the algorithm has to be reversed.
 * @param[in] refout Flag to specify whether the output CRC has to be reversed.
 * @param[in] xor_out Value to be xored to the CRC before returning its value.
 *
 * @return 32 bit CRC.
 */
uint32_t crc32_T(
            uint32_t *table, uint8_t * data, size_t data_size,
            uint32_t init, bool refin, bool refout, uint32_t xor_out);

/**
 * Utility function used to reverse bit order.
 *
 * @param[in] in Value to be reversed.
 *
 * @return Bitwise inversion of input data.
 */
uint32_t rev32(uint32_t);

/**
 * Main routine used to compute polinomial division's remainder
 *
 * @param[in] val Polynomial used as the dividend.
 * @param[in] poly Polynomial used as the divisor.
 *
 * @return Reminder of polynomial division.
 */
uint32_t core32(uint32_t val, uint32_t poly);

/**
 * Function used to generate the lookup table for generic CRC configurations
 *
 * @param[in] dest Pointer to data location to be populated with lookup values.
 *                 Has to be at least 256*sizeof(uint32_t).
 * @param[in] poly 32 bit Polynomial of desired CRC configuration.
 * @param[in] refin Flag specifying data inversion of desired CRC configuration.
 */
void gen_lookup32(uint32_t *dest, uint32_t poly, bool refin);

#ifdef __cplusplus
}         
#endif
#endif

