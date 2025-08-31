// custom version of vecf to hold floats
// offical repo : https://github.com/fif3x/vecf

#ifndef VECF_H
#define VECF_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int _capacity;
    int _size;
    float* _data;
} vecf;


static void vecf_init(vecf *v, int initial_capacity){  
    if(initial_capacity > 12000){
        printf("VECF ERROR: `initial_capacity` exceeds safety limit (12000)");
        return;
    }
    if(initial_capacity < 0){
        printf("VECF ERROR: `initial_capacity` is less than 0");
        return;
    }
    v->_data = (float*)calloc(initial_capacity, sizeof(int));
    v->_size = 0;
    v->_capacity = initial_capacity;
}

static void vecf_free(vecf *v){
    if(v->_data == NULL){
        printf("VECF ERROR: Vector is not initialized/has been freed");
        return;
    }
    for(int i = 0; i < v->_capacity; i++){
        v->_data[i] = 0;
    }
    free(v->_data);
    v->_data = NULL;
}

static void vecf_push_back(vecf *v, float elem){
    if(v->_data == NULL){
        printf("VECF ERROR: Vector is not initialized/has been freed");
        return;
    }
    if(v->_size >= v->_capacity){
        printf("VECF ERROR: Array size is equal or greater than array capacity");
        return;
    }
    v->_data[v->_size] = elem;
    v->_size++;
}

static void vecf_pop(vecf *v){
    if(v->_data == NULL){
        printf("VECF ERROR: Vector is not initialized/has been freed");
        return;
    }
    if(v->_size <= 0){
        printf("VECF ERROR: Array size is less than/equal to 0; Cannot remove elements");
        return;
    }
    v->_data[v->_size] = 0.0f;
    v->_size--;
}

static void vecf_resize(vecf *v, int new_size){
    if(v->_data == NULL){
        printf("VECF ERROR: Vector is not initialized/has been freed");
        return;
    }
    if(new_size < 0){
        printf("VECF ERROR: `new_size` is less than 0");
        return;
    }
    if(new_size > 12000){
        printf("VECF ERROR: `new_size` exceeds safety limit (12000)");
        return;
    }
    if(new_size < v->_capacity){
        printf("VECF ERROR: `new_size` is less than current capacity (%d->%d)", new_size, v->_capacity);
    }
    v->_data = (float*)realloc(v->_data, new_size * sizeof(int));
    v->_capacity = new_size;
}

static int vecf_at(vecf *v, int index){
    if(v->_data == NULL){
        printf("VECF ERROR: Vector is not initialized/has been freed");
        return 1;
    }
    if(index < 0 || index >= v->_capacity){
        printf("VECF ERROR: Index out of bounds");
        return 1;
    }
    return v->_data[index];
}

static int vecf_size(vecf *v){
    return v->_size;
}

static int vecf_capacity(vecf *v){
    return v->_capacity;
}

static void vecf_empty(vecf *v){
    if(v->_data == NULL){
        printf("VECF ERROR: Vector is not initialized/has been freed");
        return;
    }
    for(int i = 0; i < v->_size; i++){
        v->_data[i] = 0.0f;
    }
    v->_size = 0;
}

static bool vecf_isempty(vecf *v){
    if(v->_size == 0){
        return true;
    }else{
        return false;
    }
}

#endif