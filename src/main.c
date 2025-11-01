#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_pm.h"
#include "esp_clk_tree.h"
#include <math.h>

void app_main(void)
{
    // Configure Power Management
    esp_pm_config_t pm_config = {
        .max_freq_mhz = 160,//* Set according to your chip's max frequency */
        .min_freq_mhz = 40,//* Set according to your chip's min frequency */
        .light_sleep_enable = true
    };
    ESP_ERROR_CHECK(esp_pm_configure(&pm_config));

    // Main task: control the workload
    while (true)
    {
        // Simulate a heavy computational load
        for (volatile int i = 0; i < 100000000; i++)
        {
            double result = sin(i) * cos(i);
        }
        // Delay to allow power management to adjust frequency and go into light sleep
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
}