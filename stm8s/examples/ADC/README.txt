This example measures the voltage on ADC channel 4 (PD3) and sends the result over UART.


 --------------------             [VCC]
|                    |              |
|                    |              \
|                PD3 |------------->/  (10k pot)
|                    |              \
|                PD5 |-> TX         |
|       <STM8>       |             _|_
|                PD6 |-> RX       [GND]
|                    |
|                    |
|                    |
|                    |
 --------------------
