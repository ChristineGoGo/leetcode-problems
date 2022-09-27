"""
    Given a string s, reverse only all the vowels in the string and return it.

    The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both cases.
"""
def reverseVowels(self, s: str) -> str:
    vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}
    l = list(s)
    start, end = 0, len(s) - 1

    while start < end:
        # print(f"l[start]: {l[start]} , l[end]: {l[end]}")
        if l[start] in vowels and l[end] in vowels:
            temp = l[start]
            l[start] = l[end]
            l[end] = temp
            start += 1
            end -= 1
        elif s[start] not in vowels:
            start += 1
        else:
            end -= 1
    return "".join(l)
