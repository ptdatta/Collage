import re


def freq(lines):
    counter = {}
    for line in lines:
        for char in line:
            if (char in counter):
                counter[char] = counter[char]+1
            else:
                counter[char] = 1
    print(counter)
    return


def freq_word(lines):
    counter = {"for": 0, "while": 0, "do": 0, "if": 0, "else": 0, "switch": 0, "int": 0,
               "float": 0, "char": 0, "printf": 0, "scanf": 0, "include": 0, "return": 0}
    for line in lines:
        line = re.split(r"[{(\s\d)}]", line)
        for word in line:
            if (word in counter):
                counter[word] = counter[word]+1
    print(counter)
    return


if __name__ == "__main__":
    main_file = open("sample.c", 'r+')
    main_file_lines = main_file.readlines()
    freq(main_file_lines)
    freq_word(main_file_lines)
