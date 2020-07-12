#ifndef _COMMANDS_H
#define _COMMANDS_H

 const char new_line= '\n';

//ADC FETCH COMMANDS
#define FETCH_ADC0 "CROSS+ADC0"
#define FETCH_ADC1 "CROSS+ADC1"
#define FETCH_ADC2 "CROSS+ADC2"
#define FETCH_ADC3 "CROSS+ADC3"
#define FETCH_ADC4 "CROSS+ADC4"
#define FETCH_ADC5 "CROSS+ADC5"
#define FETCH_ADC6 "CROSS+ADC6"
#define FETCH_ADC7 "CROSS+ADC7"

/********************************************
 * GPIO COMMANDS
 * ******************************************/
//INPUT COMMANDS
#define PINB0_INPUT "CROSS+INPUT_B0"
#define PINB1_INPUT "CROSS+INPUT_B1"
#define PINB2_INPUT "CROSS+INPUT_B2"
#define PINB3_INPUT "CROSS+INPUT_B3"
#define PINB4_INPUT "CROSS+INPUT_B4"
#define PINB5_INPUT "CROSS+INPUT_B5"
#define PINB6_INPUT "CROSS+INPUT_B6"
#define PINB7_INPUT "CROSS+INPUT_B7"

#define PINC0_INPUT "CROSS+INPUT_C0"
#define PINC1_INPUT "CROSS+INPUT_C1"
#define PINC2_INPUT "CROSS+INPUT_C2"
#define PINC3_INPUT "CROSS+INPUT_C3"
#define PINC4_INPUT "CROSS+INPUT_C4"
#define PINC5_INPUT "CROSS+INPUT_C5"
#define PINC6_INPUT "CROSS+INPUT_C6"
#define PINC7_INPUT "CROSS+INPUT_C7"

#define PIND0_INPUT "CROSS+INPUT_D0"
#define PIND1_INPUT "CROSS+INPUT_D1"
#define PIND2_INPUT "CROSS+INPUT_D2"
#define PIND3_INPUT "CROSS+INPUT_D3"
#define PIND4_INPUT "CROSS+INPUT_D4"
#define PIND5_INPUT "CROSS+INPUT_D5"
#define PIND6_INPUT "CROSS+INPUT_D6"
#define PIND7_INPUT "CROSS+INPUT_D7"

//INPUT STATUS COMMANDS
#define PINB0_INPUT_STATUS "CROSS+INPUT_STATUS_B0"
#define PINB1_INPUT_STATUS "CROSS+INPUT_STATUS_B1"
#define PINB2_INPUT_STATUS "CROSS+INPUT_STATUS_B2"
#define PINB3_INPUT_STATUS "CROSS+INPUT_STATUS_B3"
#define PINB4_INPUT_STATUS "CROSS+INPUT_STATUS_B4"
#define PINB5_INPUT_STATUS "CROSS+INPUT_STATUS_B5"
#define PINB6_INPUT_STATUS "CROSS+INPUT_STATUS_B6"
#define PINB7_INPUT_STATUS "CROSS+INPUT_STATUS_B7"

#define PINC0_INPUT_STATUS "CROSS+INPUT_STATUS_C0"
#define PINC1_INPUT_STATUS "CROSS+INPUT_STATUS_C1"
#define PINC2_INPUT_STATUS "CROSS+INPUT_STATUS_C2"
#define PINC3_INPUT_STATUS "CROSS+INPUT_STATUS_C3"
#define PINC4_INPUT_STATUS "CROSS+INPUT_STATUS_C4"
#define PINC5_INPUT_STATUS "CROSS+INPUT_STATUS_C5"
#define PINC6_INPUT_STATUS "CROSS+INPUT_STATUS_C6"
#define PINC7_INPUT_STATUS "CROSS+INPUT_STATUS_C7"

#define PIND0_INPUT_STATUS "CROSS+INPUT_STATUS_D0"
#define PIND1_INPUT_STATUS "CROSS+INPUT_STATUS_D1"
#define PIND2_INPUT_STATUS "CROSS+INPUT_STATUS_D2"
#define PIND3_INPUT_STATUS "CROSS+INPUT_STATUS_D3"
#define PIND4_INPUT_STATUS "CROSS+INPUT_STATUS_D4"
#define PIND5_INPUT_STATUS "CROSS+INPUT_STATUS_D5"
#define PIND6_INPUT_STATUS "CROSS+INPUT_STATUS_D6"
#define PIND7_INPUT_STATUS "CROSS+INPUT_STATUS_D7"

//OUTPUT COMMANDS
#define PINB0_OUTPUT "CROSS+OUTPUT_B0"
#define PINB1_OUTPUT "CROSS+OUTPUT_B1"
#define PINB2_OUTPUT "CROSS+OUTPUT_B2"
#define PINB3_OUTPUT "CROSS+OUTPUT_B3"
#define PINB4_OUTPUT "CROSS+OUTPUT_B4"
#define PINB5_OUTPUT "CROSS+OUTPUT_B5"
#define PINB6_OUTPUT "CROSS+OUTPUT_B6"
#define PINB7_OUTPUT "CROSS+OUTPUT_B7"

#define PINC0_OUTPUT "CROSS+OUTPUT_C0"
#define PINC1_OUTPUT "CROSS+OUTPUT_C1"
#define PINC2_OUTPUT "CROSS+OUTPUT_C2"
#define PINC3_OUTPUT "CROSS+OUTPUT_C3"
#define PINC4_OUTPUT "CROSS+OUTPUT_C4"
#define PINC5_OUTPUT "CROSS+OUTPUT_C5"
#define PINC6_OUTPUT "CROSS+OUTPUT_C6"
#define PINC7_OUTPUT "CROSS+OUTPUT_C7"

#define PIND0_OUTPUT "CROSS+OUTPUT_D0"
#define PIND1_OUTPUT "CROSS+OUTPUT_D1"
#define PIND2_OUTPUT "CROSS+OUTPUT_D2"
#define PIND3_OUTPUT "CROSS+OUTPUT_D3"
#define PIND4_OUTPUT "CROSS+OUTPUT_D4"
#define PIND5_OUTPUT "CROSS+OUTPUT_D5"
#define PIND6_OUTPUT "CROSS+OUTPUT_D6"
#define PIND7_OUTPUT "CROSS+OUTPUT_D7"

//OUTPUT COMMANDS HIGH
#define PINB0_HIGH "CROSS+HIGH_B0"
#define PINB1_HIGH "CROSS+HIGH_B1"
#define PINB2_HIGH "CROSS+HIGH_B2"
#define PINB3_HIGH "CROSS+HIGH_B3"
#define PINB4_HIGH "CROSS+HIGH_B4"
#define PINB5_HIGH "CROSS+HIGH_B5"
#define PINB6_HIGH "CROSS+HIGH_B6"
#define PINB7_HIGH "CROSS+HIGH_B7"

#define PINC0_HIGH "CROSS+HIGH_C0"
#define PINC1_HIGH "CROSS+HIGH_C1"
#define PINC2_HIGH "CROSS+HIGH_C2"
#define PINC3_HIGH "CROSS+HIGH_C3"
#define PINC4_HIGH "CROSS+HIGH_C4"
#define PINC5_HIGH "CROSS+HIGH_C5"
#define PINC6_HIGH "CROSS+HIGH_C6"
#define PINC7_HIGH "CROSS+HIGH_C7"

#define PIND0_HIGH "CROSS+HIGH_D0"
#define PIND1_HIGH "CROSS+HIGH_D1"
#define PIND2_HIGH "CROSS+HIGH_D2"
#define PIND3_HIGH "CROSS+HIGH_D3"
#define PIND4_HIGH "CROSS+HIGH_D4"
#define PIND5_HIGH "CROSS+HIGH_D5"
#define PIND6_HIGH "CROSS+HIGH_D6"
#define PIND7_HIGH "CROSS+HIGH_D7"

//OUTPUT COMMANDS LOW

#define PINB0_LOW "CROSS+LOW_B0"
#define PINB1_LOW "CROSS+LOW_B1"
#define PINB2_LOW "CROSS+LOW_B2"
#define PINB3_LOW "CROSS+LOW_B3"
#define PINB4_LOW "CROSS+LOW_B4"
#define PINB5_LOW "CROSS+LOW_B5"
#define PINB6_LOW "CROSS+LOW_B6"
#define PINB7_LOW "CROSS+LOW_B7"

#define PINC0_LOW "CROSS+LOW_C0"
#define PINC1_LOW "CROSS+LOW_C1"
#define PINC2_LOW "CROSS+LOW_C2"
#define PINC3_LOW "CROSS+LOW_C3"
#define PINC4_LOW "CROSS+LOW_C4"
#define PINC5_LOW "CROSS+LOW_C5"
#define PINC6_LOW "CROSS+LOW_C6"
#define PINC7_LOW "CROSS+LOW_C7"

#define PIND0_LOW "CROSS+LOW_D0"
#define PIND1_LOW "CROSS+LOW_D1"
#define PIND2_LOW "CROSS+LOW_D2"
#define PIND3_LOW "CROSS+LOW_D3"
#define PIND4_LOW "CROSS+LOW_D4"
#define PIND5_LOW "CROSS+LOW_D5"
#define PIND6_LOW "CROSS+LOW_D6"
#define PIND7_LOW "CROSS+LOW_D7"

#endif //_COMMANDS_H