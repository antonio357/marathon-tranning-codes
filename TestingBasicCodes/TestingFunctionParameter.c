#include <stdio.h>
void myfuncn( int var1[], int var2)
{
    /* The pointer var1 is pointing to the first element of
     * the array and the var2 is the size of the array. In the
     * loop we are incrementing pointer so that it points to
     * the next element of the array on each increment.
     *
     */
    for(int x=0; x<var2; x++)
    {
        printf("Value of var_arr[%d] is: %d \n", x, var1[x]);
        /*increment pointer for next element fetch*/
    }
}

int main()
{
    int var_arr[] = {11, 22, 33, 44, 55, 66, 77};
    myfuncn(var_arr, 7);
    return 0;
}