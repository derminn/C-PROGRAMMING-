#include <stdio.h>
#include <stdlib.h>

typedef struct
{
int *data;
int size;
int capacity;
} DynamicArray;
void init_array(DynamicArray *arr)
{
  arr -> capacity = 2 ;
  arr -> size = 0;
  arr -> data (int*)malloc(arr->capacity * sizeof(int));
}
void push_back(DynamicArray *arr ,int value)
{
  if(arr->size == arr->capacity)
  {
    arr->capacity = arr->capacity*2;
    printf("capacity doubled to %d\n",arr->capacity);
    arr->data = realloc(arr->data,arr->capacity * sizeof(int));
}
arr->data[arr->size] = value;
arr->size++;
}
int get(DynamicArray *arr, int index)
{
  if(index<0 ||)index >= arr->size)
    {
    printf("index out of bounds\n");
    return -1;
  }
  return arr->data[index];
}

void print_all(DynamicArray *arr)
{
  for(int i = 0;i<arr->size;i++)
  {
      printf("%d",arr->data[i]);
  }
  printf("\n");
}

void free_array(DynamicArray *arr)
{
  free(arr->data);
}
int main()
{
    DynamicArray arr;

    init_array(&arr);

  for(int i = 1; i <= 15; i++)
    {
        push_back(&arr, i);
    }
    printf("\nArray elements:\n");
    print_all(&arr);
    printf("\nElement at index 5: %d\n", get(&arr, 5));
    int memory = arr.capacity * sizeof(int);
    printf("\nTotal memory used: %d bytes\n", memory);
    free_array(&arr);
    return 0;
}
