#include "prot.h"

int draw_line_wrapper(void *ptr)
{
    if (ptr == NULL)
        return (ERR_NULL_VALUE_DETECTED);
    t_structs *val = (t_structs *)ptr;
    draw_line(val);
    return (0);
}
