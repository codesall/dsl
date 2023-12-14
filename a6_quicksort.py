def quicksort(arr, lo, hi):
    if lo < hi:
        # Partition the array and get the index of the pivot element
        p = partition(arr, lo, hi)
        # Recursively sort the left and right partitions
        quicksort(arr, lo, p - 1)
        quicksort(arr, p + 1, hi)
def partition(arr, lo, hi):
    # Select the last element as the pivot
    pivot = arr[hi]
    i = lo - 1
    # Loop through the sub-array and partition it
    for j in range(lo, hi):
        if arr[j] <= pivot:
            # Move the element to the left partition
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
            # Move the pivot element to its final position in the array
    arr[i + 1], arr[hi] = arr[hi], arr[i + 1]
    # Return the index of the pivot element
    return i + 1
# Example usage
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quicksort(arr, 0, n - 1)
print("Sorted array:", arr)
