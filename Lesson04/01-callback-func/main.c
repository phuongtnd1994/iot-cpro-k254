#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef void (*PizzaDeliveryCallback)(const char *pizza_type);
static PizzaDeliveryCallback s_customer_callback = NULL;

static char s_pizza_in_over[100];
static int s_baking_time_left = 0;

void on_pizza_delivered(const char *pizza_type)
{
    printf("\n!!! DING DONG !!!\n");
    printf("    Yay, the '%s' pizza is here!\n\n", pizza_type);
}

void place_pizza_order(const char *pizza_type, PizzaDeliveryCallback handler)
{
    if (s_baking_time_left > 0)
    {
        printf("[Store] Oven is busy, please wait!\n");
        return;
    }

    printf("[Store] Order received for '%s'. It will be ready in 5 seconds.\n", pizza_type);

    s_customer_callback = handler;
    strncpy(s_pizza_in_over, pizza_type, sizeof(s_pizza_in_over) - 1);

    s_baking_time_left = 5;
}

void pizzastore_process_orders()
{
    if (s_baking_time_left > 0)
    {
        s_baking_time_left--;

        printf("[Store] Baking... %d seconds left.\n", s_baking_time_left);

        if (s_baking_time_left == 0)
        {
            printf("[Store] Pizza is ready! Out for delivery...\n");

            if (s_customer_callback != NULL)
            {
                s_customer_callback(s_pizza_in_over);
            }

            s_customer_callback = NULL;
        }
    }
}

int main()
{
    printf("[DevLinux] Feeling hungry, let's order a pizza.\n");

    place_pizza_order("Pepperoni & Mushroom", on_pizza_delivered);

    printf("[DevLinux] Order placed. Now I'll just watch some TV while I wait.\n\n");

    for (int i = 0; i < 7; i++)
    {
        printf("[DevLinux] Watching TV, not worried about the pizza...\n");

        pizzastore_process_orders();
        sleep(1);
    }

    printf("\n[DevLinux] That was a great meal!\n");

    return 0;
}