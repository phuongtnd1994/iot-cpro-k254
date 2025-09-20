#include <stdio.h>
#include <stdint.h>

void ADC_update_temperature();
void LCD_display_temperature();

int main()
{

    printf("Embedded System starting ... \n");

    for (int i = 0; i < 5; i++)
    {
        printf("\n--- System Tick %d ---\n", i + 1);

        ADC_update_temperature();
        LCD_display_temperature();
    }
}