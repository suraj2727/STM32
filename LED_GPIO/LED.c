void SystemClock_Config(void);
void GPIO_Init(void);
void Delay(void);

int main() {
    HAL_Init();
    SystemClock_Config();
    GPIO_Init();

    while (1) {
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_12); // Toggle LED
        Delay();  // Simple delay function
    }
}

void GPIO_Init(void) {
    __HAL_RCC_GPIOB_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Configure GPIOB12 as output
    GPIO_InitStruct.Pin = GPIO_PIN_12;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void Delay(void) {
    for (volatile int i = 0; i < 500000; i++);  // Simple delay
}

void SystemClock_Config(void) {
    // Keep default clock settings (for simplicity)
}

