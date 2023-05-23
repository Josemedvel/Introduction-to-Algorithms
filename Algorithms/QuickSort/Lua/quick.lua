function main()
    array = {4,10,1,3,9,7,4,6,5,5}
    quicksort(array, 1, #array)
    for i,num in ipairs(array) do
        io.write(num .."\t")
    end
    print()
end
function quicksort(arr, s, f)
    if s < f then
        q = partition(arr, s, f)
        quicksort(arr, s, q - 1)
        quicksort(arr, q + 1, f)
    end
end
function partition(arr, s, f)
    x = arr[f] -- pivot element (last one)
    i = s - 1 -- small or equal group final index
    for j = s, f - 1 do
        if arr[j] <= x then -- if less than pivot, expand small group
            i = i + 1
            arr[i], arr[j] = arr[j], arr[i]
        end
    end
    arr[i + 1], arr[f] = arr[f], arr[i + 1]
    return i + 1
end

main()