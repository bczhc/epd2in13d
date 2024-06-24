#include <iostream>

extern "C" {
#include <EPD_2in13d.h>
}

int main() {
    if (DEV_Module_Init() != 0) {
        return -1;
    }

    printf("e-Paper Init and Clear...\n");
    EPD_2IN13D_Init();
    EPD_2IN13D_Clear();
    DEV_Delay_ms(500);

    size_t buffer_size = 2756;
    auto *image_buffer = (UBYTE *) malloc(buffer_size);
    size_t row_byte_len = 13;
    for (size_t col = 0; col < 212; ++col) {
        UBYTE filled_byte = col % 2 == 0 ? 0b01010101 : 0b10101010;
        memset(image_buffer + col * row_byte_len, filled_byte, row_byte_len);
    }
    printf("Display\n");
    EPD_2IN13D_Display(image_buffer);
    printf("Display done\n");
    printf("Sleep\n");
    EPD_2IN13D_Sleep();
    printf("Sleep done\n");
    return 0;
}
