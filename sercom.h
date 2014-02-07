/*
 * sercom.c - USB serial communication support
 *
 * Defines several functions for communication over USB serial.
 *
 */

#ifndef _SERCOM_H_
#define _SERCOM_H_

#include <stdbool.h>
#include "packets.h"

// little-endian "MBED"
#define PACKET_IDENT (('D' << 24) | ('E' << 16) | ('B' << 8) | 'M')

#pragma pack(push, 1)
typedef struct
{
	uint32_t ident;
	uint8_t type;
	uint8_t size;
} PacketHeader_t;
#pragma pack(pop)

void sercom_init(void);
void sercom_send(PacketType_e packet_type, const uint8_t *pBuf, uint8_t size);
bool sercom_receive(PacketHeader_t *pHdr, uint8_t **pPayload);

#endif
