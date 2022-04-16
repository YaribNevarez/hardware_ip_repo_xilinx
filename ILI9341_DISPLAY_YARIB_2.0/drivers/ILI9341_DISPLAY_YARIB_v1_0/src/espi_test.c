/*
 * espi.c
 *
 *  Created on: Apr 16, 2022
 *      Author: Yarib Nevarez
 */
/***************************** Include Files *******************************/
#include "espi.h"
#include "stdio.h"
#include "stdlib.h"
/***************************** Test function *******************************/
void spi_test (void)
{
//  TFT_SPI_DATA_LENGTH_8_BITS
//  TFT_SPI_DATA_LENGTH_16_BITS
//  TFT_SPI_DATA_LENGTH_24_BITS
//  TFT_SPI_DATA_LENGTH_32_BITS

  int clk_polarity;
  int clk_phase;
  int data_len;
  int baud_rate_div;

  int error_count = 0;
  int spi_value = 0;
  printf ("SPI Feedback Loop Test.\n\n");

  /////////////////////////////////////////////////////////////////////////////
  printf ("8-bit test [CP = 0, CPH = 0] ...\n");

  clk_polarity = 0;
  clk_phase = 0;
  data_len = TFT_SPI_DATA_LENGTH_8_BITS;
  baud_rate_div = 32;

  spi_initialize (clk_polarity, clk_phase, data_len, baud_rate_div);

  error_count = 0;
  for (int i = 0; i < 30000; i++)
    {
      spi_value = spi_transfer_data (i);
      if (spi_value != (i & 0xFF)) // 8-bit mask
	{
	  error_count++;
	  printf ("Error 0x%X != 0x%X (%d)\n", spi_value, i, error_count);
	}
    }
  printf ("8-bit test DONE... ");
  if (error_count == 0)
    {
      printf ("SUCCESS\n\n");
    }
  else
    {
      printf ("FAIL\n\n");
    }
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  printf ("16-bit test  [CP = 0, CPH = 1] ...\n");
  clk_polarity = 0;
  clk_phase = 1;
  data_len = TFT_SPI_DATA_LENGTH_16_BITS;
  baud_rate_div = 64;

  spi_initialize (clk_polarity, clk_phase, data_len, baud_rate_div);

  error_count = 0;
  for (int i = 0; i < 30000; i++)
    {
      spi_value = spi_transfer_data (i);
      if (spi_value != (i & 0xFFFF)) // 16-bit mask
	{
	  error_count++;
	  printf ("Error 0x%X != 0x%X (%d)\n", spi_value, i, error_count);
	}
    }
  printf ("16-bit test DONE... ");
  if (error_count == 0)
    {
      printf ("SUCCESS\n\n");
    }
  else
    {
      printf ("FAIL\n\n");
    }
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  printf ("24-bit test  [CP = 1, CPH = 0] ...\n");
  clk_polarity = 1;
  clk_phase = 0;
  data_len = TFT_SPI_DATA_LENGTH_24_BITS;
  baud_rate_div = 128;

  spi_initialize (clk_polarity, clk_phase, data_len, baud_rate_div);

  error_count = 0;
  for (int i = 0; i < 30000; i++)
    {
      int data = rand();
      spi_value = spi_transfer_data (data);
      if (spi_value != (data & 0xFFFFFF)) // 24-bit mask
	{
	  error_count++;
	  printf ("Error 0x%X != 0x%X (%d)\n", spi_value, i, error_count);
	}
    }
  printf ("24-bit test DONE... ");
  if (error_count == 0)
    {
      printf ("SUCCESS\n\n");
    }
  else
    {
      printf ("FAIL\n\n");
    }
  /////////////////////////////////////////////////////////////////////////////

  /////////////////////////////////////////////////////////////////////////////
  printf ("32-bit test  [CP = 1, CPH = 1] ...\n");
  clk_polarity = 1;
  clk_phase = 1;
  data_len = TFT_SPI_DATA_LENGTH_32_BITS;
  baud_rate_div = 255;

  spi_initialize (clk_polarity, clk_phase, data_len, baud_rate_div);

  error_count = 0;
  for (int i = 0; i < 30000; i++)
    {
      int data = rand();
      spi_value = spi_transfer_data (data);
      if (spi_value != data)
	{
	  error_count++;
	  printf ("Error 0x%X != 0x%X (%d)\n", spi_value, i, error_count);
	}
    }
  printf ("32-bit test DONE... ");
  if (error_count == 0)
    {
      printf ("SUCCESS\n\n");
    }
  else
    {
      printf ("FAIL\n\n");
    }
  /////////////////////////////////////////////////////////////////////////////

  printf ("End SPI Test.\n");
}

//int main (void)
//{
//  spi_test ();
//  return 0;
//}
