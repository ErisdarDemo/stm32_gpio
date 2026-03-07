# GPIO EXTI Example Details

This section provides technical details from the original `readme.txt` for the GPIO EXTI demonstration.

## Example Description

This example demonstrates how to configure external interrupt lines (EXTI) on the STM32H743. One EXTI line (EXTI15_10) is configured to generate an interrupt on each rising edge. In the interrupt routine, an LED connected to a specific GPIO pin is toggled.

- **EXTI15_10** is connected to PC.13 pin
  - When a rising edge is detected on EXTI15_10 (by pressing the User push-button), LED1 toggles once
- On NUCLEO-H743ZI: EXTI15_10 is connected to the User push-button

## Initialization and Clock Configuration

- At the beginning of the main program, `HAL_Init()` is called to reset all peripherals, initialize the Flash interface, and the SysTick.
- `SystemClock_Config()` configures the system clock for STM32H743xx Devices:
  - CPU at 400MHz
  - HCLK for D1 Domain AXI and AHB3 peripherals, D2 Domain AHB1/AHB2 peripherals, and D3 Domain AHB4 peripherals at 200MHz
  - APB clock dividers for D1 Domain APB3 peripherals, D2 Domain APB1 and APB2 peripherals, and D3 Domain APB4 peripherals to run at 100MHz

## Notes

- **HAL_Delay() Usage:**
  - `HAL_Delay()` provides accurate delay (in milliseconds) based on a variable incremented in the SysTick ISR. If called from a peripheral ISR, ensure the SysTick interrupt has higher priority (numerically lower) than the peripheral interrupt to avoid blocking.
  - To change the SysTick interrupt priority, use `HAL_NVIC_SetPriority()`.
- **SysTick Time Base:**
  - Ensure the SysTick time base is always set to 1 millisecond for correct HAL operation.
- **Memory and Cache Considerations:**
  - If using DTCM/ITCM memories (@0x20000000/0x0000000: not cacheable and only accessible by the Cortex M7 and the MDMA), no cache maintenance is needed for access by Cortex M7 and MDMA.
  - If using DMA or other masters, or requiring more RAM, use a non-TCM SRAM (e.g., D1 AXI-SRAM @ 0x24000000) and add cache maintenance mechanisms to ensure cache coherence between CPU and other masters (DMAs, DMA2D, LTDC, MDMA).
  - Cacheable buffers shared between CPU and other masters must be aligned to L1-CACHE line size (32 bytes).
  - It is recommended to enable the cache and maintain its coherence. Depending on the use case, it is also possible to configure the cache attributes using the MPU.
  - Refer to AN4838 "Managing memory protection unit (MPU) in STM32 MCUs" and AN4839 "Level 1 cache on STM32F7 Series" for more information.

## Keywords

GPIO, EXTI, LED, Button, Interrupt

## Directory Contents

- GPIO/GPIO_EXTI/Inc/stm32h7xx_hal_conf.h    HAL configuration file
- GPIO/GPIO_EXTI/Inc/stm32h7xx_it.h          Interrupt handlers header file
- GPIO/GPIO_EXTI/Inc/main.h                  Header for main.c module
- GPIO/GPIO_EXTI/Src/stm32h7xx_it.c          Interrupt handlers
- GPIO/GPIO_EXTI/Src/main.c                  Main program
- GPIO/GPIO_EXTI/Src/system_stm32h7xx.c      STM32H7xx system source file

## Hardware and Software Environment

- This example runs on STM32H743xx devices.
- Tested with NUCLEO-H743ZI board and can be easily tailored to other supported devices and development boards.

## How to Use

1. Open your preferred toolchain
2. Rebuild all files and load your image into target memory
3. Run the example