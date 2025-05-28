/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: CC0-1.0
 */
#include "touch_element/touch_button.h"
#include "esp_log.h"
#include "esp_rom_sys.h"
#include "esp_task_wdt.h"

#define TOUCH_THRESHOLD 15000

static const char *TAG = "Touch Button Example";
#define TOUCH_BUTTON_NUM     14

static touch_button_handle_t button_handle[TOUCH_BUTTON_NUM];

static const touch_pad_t channel_array[TOUCH_BUTTON_NUM] = {
    TOUCH_PAD_NUM1,
    TOUCH_PAD_NUM2,
    TOUCH_PAD_NUM3,
    TOUCH_PAD_NUM4,
    TOUCH_PAD_NUM5,
    TOUCH_PAD_NUM6,
    TOUCH_PAD_NUM7,
    TOUCH_PAD_NUM8,
    TOUCH_PAD_NUM9,
    TOUCH_PAD_NUM10,
    TOUCH_PAD_NUM11,
    TOUCH_PAD_NUM12,
    TOUCH_PAD_NUM13,
    TOUCH_PAD_NUM14,
};

static const float channel_sens_array[TOUCH_BUTTON_NUM] = {
    0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
    0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F, 0.1F,
};

void app_main(void)
{
    touch_elem_global_config_t global_config = TOUCH_ELEM_GLOBAL_DEFAULT_CONFIG();
    ESP_ERROR_CHECK(touch_element_install(&global_config));
    ESP_LOGI(TAG, "Touch element library installed");

    touch_button_global_config_t button_global_config = TOUCH_BUTTON_GLOBAL_DEFAULT_CONFIG();
    ESP_ERROR_CHECK(touch_button_install(&button_global_config));
    ESP_LOGI(TAG, "Touch button installed");

    for (int i = 0; i < TOUCH_BUTTON_NUM; i++) {
        touch_button_config_t button_config = {
            .channel_num = channel_array[i],
            .channel_sens = channel_sens_array[i]
        };
        ESP_ERROR_CHECK(touch_button_create(&button_config, &button_handle[i]));
        ESP_ERROR_CHECK(touch_button_set_longpress(button_handle[i], 2000));
    }
    ESP_LOGI(TAG, "Touch buttons created");

    touch_element_start();
    ESP_LOGI(TAG, "Touch element library start");

    esp_task_wdt_deinit(); // Desactiva el watchdog de tareas

    // Polling loop (sin FreeRTOS)
    uint32_t last_value[TOUCH_BUTTON_NUM] = {0};
    while (1) {
        for (int i = 0; i < TOUCH_BUTTON_NUM; i++) {
            uint32_t value = 0;
            touch_pad_read_raw_data(channel_array[i], &value);
            if (value < TOUCH_THRESHOLD && last_value[i] >= TOUCH_THRESHOLD) {
                ESP_LOGI(TAG, "Tocaste el botón %d", i + 1);
            }
            last_value[i] = value;
        }
        esp_rom_delay_us(50000); // 50 ms
    }
}