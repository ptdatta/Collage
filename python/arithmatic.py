def eval(postfix):
	stack = []
	for token in postfix:
		if token == '+':
			a = stack.pop()
			b = stack.pop()

			stack.append(a + b)
		elif token == '-':
			b = stack.pop()
			a = stack.pop()

			stack.append(a - b)
		elif token == '*':
			a = stack.pop()
			b = stack.pop()

			stack.append(a * b)
		elif token == '/':
			b = stack.pop()
			a = stack.pop()

			stack.append(a // b)
		elif token == '^':
			b = stack.pop()
			a = stack.pop()

			stack.append(pow(a,b))
		else:
			stack.append(token)

	return stack[-1]

def calculate( s: str) -> int:
	stack = []
	output = []

	rank = {
		'+': 1,
		'-': 1,
		'*': 2,
		'/': 2,
        '^': 3,
	}

	num = None

	for c in s:
		if c == ' ':
			continue

		if c in "0123456789":
			if num is None:
				num = 0
			num = num * 10 + int(c)
			continue

		if num is not None:
			output.append(num)
			num = None

		if c == '(':
			stack.append('(')
		elif c == ')':
			
			while stack[-1] != '(':
				output.append(stack.pop())

			
			stack.pop()
		else:
			
			while stack and stack[-1] != '(' and rank[stack[-1]] >= rank[c]:
				output.append(stack.pop())

			stack.append(c)

	
	if num != None:
		output.append(num)
	while stack:
		output.append(stack.pop())

	return output


if __name__ == "__main__":
    math=input("Enter the expression: ")
    print(eval(calculate(math)))

