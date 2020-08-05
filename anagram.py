#checks if two strings are anagrams

def is_anagram(str1, str2):
	if len(str1) != len(str2):
		return False
	
	for c in str1:
		if c not in str2:
			return False
		return True

print("are 'cinema' and 'iceman' anagrams?")	
print(is_anagram("cinema", "iceman"))

print("are 'apples' and 'oranges' anagrams?")	
print(is_anagram("apples", "oranges"))