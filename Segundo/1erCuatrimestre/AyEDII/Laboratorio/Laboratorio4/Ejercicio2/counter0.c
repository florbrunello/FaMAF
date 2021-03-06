#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
    counter c; 
    c = malloc(sizeof(struct _counter));
    return c; 
}

void counter_inc(counter c) {
    c->count = (c->count)+1; 
}

bool counter_is_init(counter c) {
    bool res = true; 
    res = (c->count == 0); 
    return res;  
}

void counter_dec(counter c) {
    assert(!counter_is_init(c));
    c->count = (c->count)-1; 

}

counter counter_copy(counter c) {
    counter copy; 
    copy = malloc(sizeof(struct _counter));
    copy = c;        //MAAAAAAAAAAAAAAALLLLLLLLLL
    return copy; 
}

void counter_destroy(counter c) {
    free(c); 
    c = NULL; 
}
