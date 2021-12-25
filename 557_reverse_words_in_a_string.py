def reverseWords(s: str) -> str:
    new_list = s.split(" ")
    for i in range(len(new_list)):
        new_list[i] = new_list[i][::-1]

    return " ".join(new_list)


if __name__ == '__main__':
    s = "Let's take LeetCode contest"
    print(reverseWords(s))
