def intToRoman(num):
    values = [ 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 ]
    numerals = [ "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" ]
    res = ""
    for i, v in enumerate(values):
        res += (num//v) * numerals[i]
        num %= v
    return res

def romanToInt(s):
        p={'M':1000,'D':500,'C':100,'L':50,'X':10,'V':5,'I':1}
        ans=0;
        left=0
        for v in s:
            if left<p[v]:
                ans=ans-2*left
            ans=ans+p[v]
            left=p[v]
        return ans


if __name__ == "__main__":
    num=int(input("Enter number: "))
    print("Roman => ",intToRoman(num))
    roman=input("Enter roman value: ")
    print("Integer => ",romanToInt(roman))
