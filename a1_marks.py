marklist=[50,20,-1,30,50,-1,70,40,40,40,90,10]
total=0
absent=0
highest=0
lowest=100
freq={}

for mark in marklist:
    if mark==-1:
        absent+=1
    else:
        total=total+mark
        if mark<lowest:
            lowest=mark
        elif highest<mark: 
            highest=mark

        if freq.get(mark)==None:
            freq[mark]=1
        else:
            freq[mark]+=1

high_freq=0
high_freq_mark=0

for mark in freq:
    if freq[mark]>high_freq:
        high_freq_mark=mark;
        high_freq=freq[mark];

print(f"Total : {total}")
print(f"Average : {total/len(marklist)}")
print(f"Highest : {highest} and Lowest is {lowest}")
print(f"Absent Students : {absent}")
print(high_freq_mark)