def counting_sort(array):
    i = 1

    c  = [0 for i in range(max(array)+ 1)]
    for item in array:
        c[ item ] +=1
    for item in c:
        if i>= len(c):
            break
        c[i] += c[i-1]
        i+=1
    answer = [0 for x in range(0,len(array))]
    print(len(answer))
    j = len(array) - 1;
    for item in range(j-1,-2, -1):
        answer[ c[ array[j] ] - 1 ] = array[j]
        c[array[j]]-=1
        j-= 1
    return answer

