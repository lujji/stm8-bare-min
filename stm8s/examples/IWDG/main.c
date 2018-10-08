#include <stm8s.h>

static void iwdg_enable() {
    /* enable IWDG */
    IWDG_KR = IWDG_KEY_ENABLE;

    /* enable write access */
    IWDG_KR = IWDG_KEY_ACCESS;

    /* prescaler = 64 */
    IWDG_PR |= 4;

    /* timeout = 250ms */
    IWDG_RLR = 0xFA;

    /* reload watchdog counter */
    IWDG_KR = IWDG_KEY_REFRESH;
}

inline void iwdg_refresh() {
    IWDG_KR = IWDG_KEY_REFRESH;
}

void main() {
    iwdg_enable();

    while (1) {
        /* kick the dog */
        iwdg_refresh();
    }
}
