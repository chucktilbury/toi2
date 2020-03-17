#ifndef _PARSER_DEFS_H_
#define _PARSER_DEFS_H_

/*
 *  This header contains various definitions that the parser support routines
 *  use to function.
 */
#  include <stdint.h>

typedef struct literal_num {
    int vtype;
    union {
        uint64_t unum;
        int64_t inum;
        double fnum;
    } value;
} literal_num_t;

#endif /* _PARSER_DEFS_H_ */
