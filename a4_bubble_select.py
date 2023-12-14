def bubblesort(marks):
    n=len(marks)
    for i in range(n-1):
        for j in range(0,n-i-1):
            if marks[j]>marks[j+1]:
                marks[j],marks[j+1]=marks[j+1],marks[j]

    print(f"Bubble sorted list : {marks}")

def selectionsort(marks):
    n=len(marks)
    for i in range(n):
        min_index=i
        for j in range(i+1,n):
            if(marks[i]>marks[j]):
                min_index=j
        marks[i],marks[min_index]=marks[min_index],marks[i]
    print(f"Selection sorted list : {marks}")
    return marks

def top5(marks):
    marks=selectionsort(marks)
    marks.reverse()
    for i in range(5):
        print(marks[i])


marks=[4,2,3,5,1,7,6]
#bubblesort(marks)

selectionsort(marks)

top5(marks)