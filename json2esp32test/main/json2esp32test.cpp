#include <math.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

#include "drivers/uda1334a/uda1334a.h"

static UDA1334A dac;
static uint32_t sample_rate = 48000;
static float phase = 0.0f;
static float lfo_phase = 0.0f;

static float nextSample()
{
    const float base_frequency = 220.0f;
    const float lfo = sinf(lfo_phase * 2.0f * (float)M_PI) * 0.5f + 0.5f;
    const float frequency = base_frequency + (lfo * 880.0f);

    phase += frequency / static_cast<float>(sample_rate);
    if (phase >= 1.0f) {
        phase -= 1.0f;
    }

    lfo_phase += 0.5f / static_cast<float>(sample_rate);
    if (lfo_phase >= 1.0f) {
        lfo_phase -= 1.0f;
    }

    return sinf(phase * 2.0f * (float)M_PI) * 0.35f;
}

extern "C" void app_main(void)
{
    esp_err_t ret = dac.begin(sample_rate, GPIO_NUM_27, GPIO_NUM_26, GPIO_NUM_25);
    if (ret != ESP_OK) {
        ESP_LOGE("APP", "Failed to initialize UDA1334A: %d", static_cast<int>(ret));
        return;
    }

    while (true) {
        const float sample = nextSample();
        ret = dac.write(sample, sample);
        if (ret != ESP_OK) {
            ESP_LOGE("APP", "Audio write failed: %d", static_cast<int>(ret));
            vTaskDelay(pdMS_TO_TICKS(10));
        }
    }
}
