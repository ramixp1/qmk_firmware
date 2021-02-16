void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    oled_write_P(PSTR(command_id), false);
}