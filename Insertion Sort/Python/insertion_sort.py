list = [5,2,4,6,1,3]

def insertion_sort(sequence,steps=False):
    for j in range(1,len(sequence)):
        item = sequence[j]
        i = j - 1
        # Insert item (element j) in the sorted sequence sequence[0...j-1] 
        while i >= 0 and sequence[i] > item:
            sequence[i + 1] = sequence[i]
            i = i - 1
        sequence[i + 1] = item
        # sorting steps (optional parameter)
        if steps == True:
            print("step ",j,sequence)
    return sequence

print(insertion_sort(list,True))
