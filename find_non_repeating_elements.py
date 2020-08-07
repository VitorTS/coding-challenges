#Given an array arr[] consisting of integers and queries Q of the form (L, R),
#the task is to check whether any non-repeating element is present within indices [L, R] or not

#If there is at least one non-repeating element, then print “Yes”. Otherwise, print “No”.

def repeating_values_in_ranges(arr, queries):
	for query in queries:
		hasNonRepeating = False
		arr2 = []
		#get subarray from query [L, R]
		for i in range(query[0], query[-1] + 1):
			arr2.append(arr[i])
		
		#sort it 
		arr2.sort()
		
		#go to every second element comparing it to the previous one
		while i < len(arr2):
			if arr2[i] != arr2[i-1]:
				hasNonRepeating = True
				break
			
			#if second to last include last element
			if i == len(arr2) - 2:
				i += 2
			else:
				i += 1 
		
		print("Yes") if hasNonRepeating else print("No")
		
arr = [1, 2, 1, 2, 3, 4]
queries = [[0, 3], [0, 4]]

print("input: arr[] = {1, 2, 1, 2, 3, 4}, Queries[][] = {{1, 4}, {1, 5}}")
print("expected result: No Yes")
repeating_values_in_ranges(arr, queries)