//The idea is to begin from last element of ar2[] and search it in ar1[]. If there is a greater element in ar1[], then we move last element of ar1[] to ar2[]. 

// Code
void merge(int ar1[], int ar2[], int m, int n)
{
    // Iterate through all elements 
    // of ar2[] starting from the last element
    for (int i = n - 1; i >= 0; i--) 
    {
        /* Find the smallest element greater than ar2[i].
        Move all elements one position ahead till the
        smallest greater element is not found */
        int j, last = ar1[m - 1];
        for (j = m - 2; j >= 0 && ar1[j] > ar2[i]; j--)
            ar1[j + 1] = ar1[j];

        // If there was a greater element
        if (j != m - 2 || last > ar2[i]) 
        {
            ar1[j + 1] = ar2[i];
            ar2[i] = last;
        }
    }
}
