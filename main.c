#include <stdio.h>
#include <math.h>
#include <time.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"


int main() {
  stdio_init_all();

  adc_init();
  adc_gpio_init(28);
  adc_select_input(2);

  float adcread = 0;
  float VD = 3.3 / 4095;
  float beta = 3977;
  float t0 = 298;
  float rt0 = 10000;

  while(1){

    adcread = adc_read();
    float adcval = adcread * VD;
    float Rt = 10000 / ((3.3 / adcval) - 1);
    float temperatura = beta / (log(Rt/rt0)+(beta/t0));
    float tempcelsius = temperatura - 273;
    printf("La temperatura es : %.2f grados celsius\n", tempcelsius);
    sleep_ms(50000);

  }

  
}