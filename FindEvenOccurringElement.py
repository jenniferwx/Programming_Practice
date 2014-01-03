def getEven1(arr): counts=collections.defaultdict(int) for num in arr: counts[num]+=1 for num, count in counts.items(): if count%2==0: return num
