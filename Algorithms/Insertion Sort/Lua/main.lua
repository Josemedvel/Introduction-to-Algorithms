local list = {5,10,4,8,1,5}

function InsertionSort(list)
    for j = 2,#list do
        local num = list[j]
        local i = j - 1
        while i > 0 and list[i] > num do
            list[i+1] = list[i]
            i = i - 1
        end
        list[i+1] = num
    end
    return list
end

local newList = InsertionSort(list)

for i = 1,#newList do
    print(newList[i])
end