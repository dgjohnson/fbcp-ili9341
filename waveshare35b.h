#pragma once

// Data specific to the Waveshare35b display
#ifdef WAVESHARE35B_ILI9486

// SPI_BUS_CLOCK_DIVISOR specifies how fast to communicate the SPI bus at. Possible values
// are 4, 6, 8, 10, 12, ... Smaller values are faster. On my Waveshare35b display, the
// following values were observed to work (on a Pi 3B):

// core_freq=400: CDIV=14, results in 28.57MHz
// core_freq=250: CDIV=8, results in 31.25MHz
// core_freq=256: CDIV=8, results in 32.00MHz

// While the following values were seen to not work:

// core_freq=400: CDIV=12, would result in 33.33MHz, but this was too fast for the display
// core_freq=258: CDIV=8, would result in 32.25MHz, this would work 99% of the time, but full screen fade-ins and fade-outs would start to exhibit occasional incorrect pixel noise

#if !defined(SPI_BUS_CLOCK_DIVISOR)
#error Please define -DSPI_BUS_CLOCK_DIVISOR=<some even number> on the CMake command line! (see file waveshare35b.h for details). This parameter along with core_freq=xxx in /boot/config.txt defines the SPI display speed.
#endif

#if !defined(GPIO_TFT_DATA_CONTROL)
#define GPIO_TFT_DATA_CONTROL 24
#endif

#if !defined(GPIO_TFT_RESET_PIN)
#define GPIO_TFT_RESET_PIN 25
#endif

#define DISPLAY_WIDTH 480
#define DISPLAY_HEIGHT 320

#define DISPLAY_COVERED_LEFT_SIDE 0
#define DISPLAY_COVERED_TOP_SIDE 0
#define DISPLAY_COVERED_BOTTOM_SIDE 0

#define DISPLAY_DRAWABLE_WIDTH (DISPLAY_WIDTH-DISPLAY_COVERED_LEFT_SIDE)
#define DISPLAY_DRAWABLE_HEIGHT (DISPLAY_HEIGHT-DISPLAY_COVERED_TOP_SIDE-DISPLAY_COVERED_BOTTOM_SIDE)

#define InitSPIDisplay InitILI9486

#endif
