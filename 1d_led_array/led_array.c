#include<stdio.h>
#include "pico/stdlib.h"

typedef unsigned int uint;

#define GPIO_ON 1
#define GPIO_OFF 0

uint LED_PIN[4] = {21,20,19,18};

int main(void)
{
  for(int i = 0; i < 4; i++)
  {
    gpio_init(LED_PIN[i]);
    gpio_set_dir(LED_PIN[i], GPIO_OUT);
  }

  while(1)
  {
    for(int i = 0; i < 4; i++)
    {
      gpio_put(LED_PIN[i], GPIO_ON);
      sleep_ms(500);
    }
    sleep_ms(500);
    for(int i = 4; i >= 0; i--)
    {
      gpio_put(LED_PIN[i], GPIO_OFF);
      sleep_ms(500);
    }
    for(int i = 0; i < 4; i++)
    {
      gpio_put(LED_PIN[i], GPIO_ON);
    }
    sleep_ms(200);
    for(int i = 4; i >= 0; i--)
    {
      gpio_put(LED_PIN[i], GPIO_OFF);
    }
    sleep_ms(500);
  }

  return 0;
}
