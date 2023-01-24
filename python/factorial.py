import sys
sys.setrecursionlimit(10000)

def fac(n):
    if(n<2):
        return "1"
    return multiply(str(n),fac(n-1))

def multiply(num1, num2):
        res = 0
        carry1 = 1
        for n1 in num1[::-1]:
            carry2 = 1
            for n2 in num2[::-1]:
                res += int(n1)*int(n2)*carry1*carry2
                carry2 *= 10
            carry1 *= 10
        return str(res)

if __name__ == "__main__":
    num=int(input("Enter number: ",))
    print("Factorial is: ",fac(num))
    