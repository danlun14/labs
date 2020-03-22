#include "IntVector.h"

void print(IntVector* v)
{
    printf("size: %ld\n", int_vector_get_size(v));
    printf("capacity: %ld\ndata:\n", int_vector_get_capacity(v));
    for (int i = 0; i < int_vector_get_size(v); i++) {
        printf("%d\t", v->data[i]);
    }
    printf("\n\n");
}
int main()
{
    int status;
    printf("started\n");
    IntVector* v;
    v = int_vector_new(6);
    for (int i = 0; i < int_vector_get_capacity(v); i++) {
        int_vector_push_back(v, i * 10);
    }
    printf("%ld\n", int_vector_get_size(v));
    for (int i = 0; i < int_vector_get_size(v); i++) {
        printf("%d\n", v->data[i]);
    }
    status = int_vector_reserve(v, 10);
    printf("%d status of int_vector_reserve\n", status);
    print(v);

    status = int_vector_push_back(v, 999);
    printf("%d status of int_vector_push_back\n", status);
    print(v);

    status = int_vector_push_back(v, 9999);
    printf("%d status of int_vector_push_back\n", status);
    print(v);

    status = int_vector_resize(v, 10);
    printf("%d status of int_vector_resize\n", status);
    print(v);

    status = int_vector_push_back(v, 999);
    printf("%d status of int_vector_push_back\n", status);
    print(v);

    status = int_vector_resize(v, 0);
    printf("%d status of int_vector_resize\n", status);
    print(v);

    status = int_vector_shrink_to_fit(v);
    printf("%d status of int_vector_shrink_to_fit\n", status);
    print(v);

    int_vector_free(v);
    printf("finished\n");
}