/*
 * espi.h
 *
 *  Created on: Apr 16, 2022
 *      Author: Yarib Nevarez
 */

#ifndef SRC_ESPI_H_
#define SRC_ESPI_H_

#include "ILI9341_DISPLAY_YARIB.h"

void spi_initialize (int clk_polarity, int clk_phase, int data_len, int baud_rate_div);

void spi_data_command (int command);

void spi_reset (int reset);

void spi_cs_force (int cs_force);

unsigned int spi_transfer_data (unsigned int data);

#endif /* SRC_ESPI_H_ */
