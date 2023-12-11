/**
 ******************************************************************************
 * @file           : fsm.h
 * @brief          : Finite-state machine library
 *
 ******************************************************************************
 */

#ifndef __FSM_H__
#define __FSM_H__

/* Public includes -----------------------------------------------------------*/
#include "fsm_conf.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Public typedefs -----------------------------------------------------------*/
typedef enum {
    FSM_PRE,
    FSM_SOAK,
    FSM_REF,
    FSM_COOL,
    FSM_IDLE
} FSM_Device_State;

typedef struct {
    bool running;
    uint32_t duration;
    uint32_t profile_duration;
    float temperature;
    uint8_t target_temperature;
    float output;
    FSM_Device_State state;
    char *name;
    uint16_t *stages;
    uint8_t *profile;
} FSM_Handle_TypeDef;

/* Public defines ------------------------------------------------------------*/

/* Public macros -------------------------------------------------------------*/

/* Public variables ----------------------------------------------------------*/
extern FSM_Handle_TypeDef hfsm1;

/* Public function prototypes ------------------------------------------------*/
/**
 * @brief  Initialize the finite-state machine
 * @param  hfsm: Pointer to the finite-state machine handle
 * @param  name: Pointer to the profile name array
 * @param  stages: Pointer to the stages array
 * @param  profile_duration: The duration of the profile
 * @param  profile: Pointer to the profile array
 * @retval None
 */
void FSM_Init(FSM_Handle_TypeDef *hfsm, char *const name, uint16_t *const stages,
        const size_t profile_duration, uint8_t *const profile);

#endif /* __FSM_H__ */
