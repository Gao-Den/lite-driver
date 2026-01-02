/**
 ******************************************************************************
 * @author: GaoDen
 * @date:   27/10/2025
 ******************************************************************************
**/

#include "pca9555.h"

void pca9555_init(pca9555_t* pca9555, uint8_t device_addr, pf_i2c_write_byte pf_write, pf_i2c_read_byte pf_read) {
    pca9555->device_addr = device_addr;
    pca9555->pf_write_byte = pf_write;
    pca9555->pf_read_byte = pf_read;
    pca9555->reg_output_port0 = 0x00;
    pca9555->reg_output_port1 = 0x00;
}

void pca9555_set_dir(pca9555_t* pca9555, pca9555_port_t port, uint8_t dir) {
    switch (port) {
    case PCA9555_PORT_0: {
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_DIRECTION_0, dir);
    }
    break;

    case PCA9555_PORT_1: {
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_DIRECTION_1, dir);
    }
    break;

    default: {
    }
    break;
    }
}

void pca9555_set_output(pca9555_t* pca9555, pca9555_port_t port, uint8_t value) {
    switch (port) {
    case PCA9555_PORT_0: {
        pca9555->reg_output_port0 = value;
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_OUTPUT_0, pca9555->reg_output_port0);
    }
    break;

    case PCA9555_PORT_1: {
        pca9555->reg_output_port1 = value;
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_OUTPUT_1, pca9555->reg_output_port1);
    }
    break;

    default: {
    }
    break;
    }
}

void pca9555_set_output_pin(pca9555_t* pca9555, pca9555_port_t port, pca9555_pin_t pin, bool level) {
    switch (port) {
    case PCA9555_PORT_0: {
        if (level) {
            pca9555->reg_output_port0 |= (1 << pin);
        }
        else {
            pca9555->reg_output_port0 &= ~(1 << pin);
        }
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_OUTPUT_0, pca9555->reg_output_port0);
    }
        break;

    case PCA9555_PORT_1: {
        if (level) {
            pca9555->reg_output_port1 |= (1 << pin);
        }
        else {
            pca9555->reg_output_port1 &= ~(1 << pin);
        }
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_OUTPUT_1, pca9555->reg_output_port1);
    }
        break;

    default: {
    }
        break;
    }
}

void pca9555_set_polarity(pca9555_t* pca9555, pca9555_port_t port, uint8_t polarity) {
    switch (port) {
    case PCA9555_PORT_0: {
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_POLARITY_INV_0, polarity);
    }
    break;

    case PCA9555_PORT_1: {
        pca9555->pf_write_byte(pca9555->device_addr, PCA9555_POLARITY_INV_1, polarity);
    }
    break;

    default: {
    }
    break;
    }
}

uint8_t pca9555_get_input(pca9555_t* pca9555, pca9555_port_t port) {
    uint8_t input_value = 0x00;
    switch (port) {
    case PCA9555_PORT_0: {
        input_value = pca9555->pf_read_byte(pca9555->device_addr, PCA9555_INPUT_0);
    }
    break;

    case PCA9555_PORT_1: {
        input_value = pca9555->pf_read_byte(pca9555->device_addr, PCA9555_INPUT_1);
    }
    break;

    default: {
    }
    break;
    }

    return input_value;
}
