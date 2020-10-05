def find_min(seq):
    "返回当前序列的最小值和其索引"
    i = 0
    while i < len(seq):
        if i == 0:
            Min = seq[i]
        if Min > seq[i]:
            Min = seq[i]
            index = i
        i += 1
    return Min, index