/**
 ******************************************************************************
 * @author: GaoDen
 * @date:   27/10/2025
 ******************************************************************************
**/

#ifndef __PCA9555_H__
#define __PCA9555_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef void (*pf_i2c_write_byte)(uint8_t dev_addr, uint8_t reg_addr, uint8_t data);
typedef uint8_t (*pf_i2c_read_byte)(uint8_t dev_addr, uint8_t reg_addr);

typedef enum {
    PCA9555_INPUT_0 = 0,
    PCA9555_INPUT_1,
    PCA9555_OUTPUT_0,
    PCA9555_OUTPUT_1,
    PCA9555_POLARITY_INV_0,
    PCA9555_POLARITY_INV_1,
    PCA9555_DIRECTION_0,
    PCA9555_DIRECTION_1,
} pca9555_register_t;

typedef enum {
    PCA9555_PORT_0 = 0,
    PCA9555_PORT_1,
} pca9555_port_t;

typedef enum {
    PCA9555_PIN_0 = 0,
    PCA9555_PIN_1,
    PCA9555_PIN_2,
    PCA9555_PIN_3,
    PCA9555_PIN_4,
    PCA9555_PIN_5,
    PCA9555_PIN_6,
    PCA9555_PIN_7,
} pca9555_pin_t;

typedef struct {
    uint8_t device_addr;
    pf_i2c_write_byte pf_write_byte;
    pf_i2c_read_byte pf_read_byte;
    uint8_t reg_output_port0;
    uint8_t reg_output_port1;
} pca9555_t;

extern void pca9555_init(pca9555_t* pca9555, uint8_t device_addr, pf_i2c_write_byte pf_write, pf_i2c_read_byte pf_read);
extern void pca9555_set_dir(pca9555_t* pca9555, pca9555_port_t port, uint8_t dir);
extern void pca9555_set_output(pca9555_t* pca9555, pca9555_port_t port, uint8_t value);
extern void pca9555_set_output_pin(pca9555_t* pca9555, pca9555_port_t port, pca9555_pin_t pin, bool level);
extern void pca9555_set_polarity(pca9555_t* pca9555, pca9555_port_t port, uint8_t polarity);
extern uint8_t pca9555_get_input(pca9555_t* pca9555, pca9555_port_t port);

#ifdef __cplusplus
}
#endif

#endif /* __PCA9555_H__ */
