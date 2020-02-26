#ifndef _PARSER_STATES_H_
#define _PARSER_STATES_H_

typedef enum parser_states_t {
    PSTATE_DATA_DEFINITION = 0x01 << 0,
    PSTATE_METHOD_DEFINITION = 0x01 << 1,
    PSTATE_CLASS_DEFINITION = 0x01 << 2,
    PSTATE_FLAGS_DEFINITION = 0x01 << 3,
} parser_states_t;

extern unsigned int global_pstate;

#define SET_PSTATE(s)    (global_pstate |= (s))
#define CLEAR_PSTATE(s)  (global_pstate &= ~(s))
#define TOGGLE_PSTATE(s) (global_pstate ^= (s))
#define CHECK_PSTATE(s)  (global_pstate & (s))
#define CLEAR_ALL_PSTATE() (global_pstate = 0)

#endif /* _PARSER_STATES_H_ */