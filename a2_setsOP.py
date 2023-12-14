res=[]
def intersection(l1,l2):
    res=[]
    for i in l1:
        if i in l2:
            res.append(i)
    return res

def union(l1,l2):
    res=l2.copy()
    for i in l1:
        if not i in res:
            res.append(i)
    return res

def diff(l1,l2):
    res=[]
    for i in l1:
        if not i in l2:
            res.append(i)
    return res

cricket=[1,2,4,5,6,9]
badminton=[2,3,5,7]
football=[1,2,3,8,7]

print(f"a. play both cricket and badminton {intersection(cricket,badminton)}")
print(f"b. play either cricket or badminton not both {diff(union(cricket,badminton),intersection(cricket,badminton))}")
print(f"play nor cricket nor badminton {diff(diff(football,cricket),badminton)}")
print(f"play cricket and football but no badmintion {diff(intersection(cricket,football),badminton)}")