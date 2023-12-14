def insertionsort(arr):
    for i in range(1,len(arr)):
        j=i
        while arr[j]<arr[j-1] and j>0:
            arr[j],arr[j-1]=arr[j-1],arr[j]
            j-=1

    print(arr)


def shellsort(arr):
    n = len(arr)
    gap = n // 2

    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    print(arr)

arr=[3,2,4,8,5,1]
insertionsort(arr)
shellsort(arr)