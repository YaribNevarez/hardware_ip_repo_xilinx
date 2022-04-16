/*
 * espi.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Yarib Nevarez
 */
#include "espi.h"

void spi_initialize (int clk_polarity, int clk_phase, int data_len, int baud_rate_div)
{
  SET_TFT_SPI_CLOCK_POLARITY (clk_polarity);
  SET_TFT_SPI_CLOCK_PHASE (clk_phase);
  SET_TFT_SPI_DATA_LENGTH (data_len);

  SET_TFT_SPI_BAUD_RATE_DIVIDER (baud_rate_div);
  SET_TFT_SPI_SETTLE_TIME (3);
}

void spi_data_command (int command)
{
  SET_TFT_DATA_COMMAND (command);
}

void spi_reset (int reset)
{
  SET_TFT_RESET (reset);
}

void spi_cs_force (int cs_force)
{
  SET_TFT_CS_FORCE (cs_force);
}

unsigned int spi_transfer_data (unsigned int word)
{
  while (!GET_TFT_TRANSMISSION_DONE);
  TFT_SPI_DATA = word;

  while (!GET_TFT_TRANSMISSION_DONE);
  return TFT_SPI_DATA;
}
