#my own implementation of mergeSort based only on the conceptual definition of the algorithm

def merge_sort(arr):
	if len(arr) <= 1:
		return arr;
		
	#break down array on the middle again and again
	mid = round(len(arr) / 2)
	
	left = arr[mid:len(arr)]
	right = arr[0:mid]

	sLeft = merge_sort(left)
	sRight = merge_sort(right)
	
	sortedResult = []
	
	#merge those arrays by comparing the first element of each
	i = j = 0 
	
	while len(sortedResult) < len(sLeft) + len(sRight):
		#if one of the arrays 'ran dry' shove the values on the other
		if i >= len(sLeft):
			sortedResult.append(sRight[j])
			j += 1
		elif j >= len(sRight):
			sortedResult.append(sLeft[i])
			i += 1
			#choose the smallest one
		elif sLeft[i] <= sRight[j]: 
			sortedResult.append(sLeft[i])
			#in the chosen array, go for the next element
			i += 1
		else:
			sortedResult.append(sRight[j])
			j += 1
			
	return sortedResult

randomList = [68,100,88,51,15,92,38,9,6,78,80,25,42,50,63,36,76,5,56,41,83,21,89,72,8,87,31,7,44,94,18,43,64,13,98,12,61,24,3,46,71,39,27,11,10,70,86,77,60,40,32,54,82,66,26,35,22,23,95,75,48,59,52,97,33,74,65,62,81,16,90,69,47,91,85,73,67,57,17,55,99,45,49,4,93,14,58,84,34,37,28,53,20,1,96,2,30,19,29,79]

print("input: " + str(randomList))
result = merge_sort(randomList)
print("result: " + str(result))