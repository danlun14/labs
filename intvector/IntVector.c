#include "IntVector.h"

IntVector* int_vector_new(size_t initial_capacity)
{
    IntVector* arr = malloc(sizeof(IntVector));
    if (arr == NULL) {
        return NULL;
    }
    arr->data = malloc(sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

IntVector* int_vector_copy(const IntVector* v)
{
    IntVector* v2 = int_vector_new(v->capacity);
    if (v2 == NULL) {
        return NULL;
    }
    memcpy(v2, v, v->capacity);
    return v2;
}

void int_vector_free(IntVector* v)
{
    free(v->data);
    free(v);
}

int int_vector_get_item(const IntVector* v, size_t index)
{
    if (v->size <= index) {
        return -1;
    }
    return v->data[index];
}
int int_vector_set_item(IntVector* v, size_t index, int item)
{
    if (v->size <= index) {
        return -1;
    }
    v->data[index] = item;
    return 0;
}

size_t int_vector_get_size(const IntVector* v)
{
    return v->size;
}

size_t int_vector_get_capacity(const IntVector* v)
{
    return v->capacity;
}

int int_vector_push_back(IntVector* v, int item)
{
    if (v->size < v->capacity) {
        v->data[v->size] = item;
        v->size++;
    } else {
        int* v2 = realloc(v->data, 2 * v->capacity * sizeof(int));
        if (v2 == NULL) {
            return -1;
        }
        v->capacity *= 2;
        v->data = v2;
        free(v2);
        v->data[v->size] = item;
        v->size++;
    }
    return 0;
}

void int_vector_pop_back(IntVector* v)
{
    if (v->size - 1 < 0) {
        return;
    }
    v->size--;
    v->data[v->size] = 0;
    return;
}

int int_vector_shrink_to_fit(IntVector* v)
{
    if (v->size == 0) {
        v->data = NULL;
        v->capacity = 0;
        return 0;
    }
    if (v->capacity < v->size) {
        return -1;
    }
    int* v2 = realloc(v->data, v->size * sizeof(int));
    if (v2 == NULL) {
        return -1;
    }
    v->data = v2;
    free(v2);
    v->capacity = v->size;
    return 0;
}

int int_vector_resize(IntVector* v, size_t new_size)
{
    if (v->size < new_size) {
        int* v2 = realloc(v->data, new_size * sizeof(int));
        if (v2 == NULL) {
            return -1;
        }
        v->data = v2;
        free(v2);
        for (int i = v->size; i < new_size; i++) {
            v->data[i] = 0;
        }
    }
    v->size = new_size;
    return 0;
}

int int_vector_reserve(IntVector* v, size_t new_capacity)
{
    if (new_capacity <= v->capacity) {
        return 0;
    }
    int* v2 = realloc(v->data, new_capacity * sizeof(int));
    if (v2 == NULL) {
        return -1;
    }
    free(v2);
    v->data = v2;
    v->capacity = new_capacity;
    return 0;
}
