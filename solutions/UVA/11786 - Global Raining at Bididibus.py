n = int(input())

for i in range(n):
    symbols = input()
    numbers = []
    current = 0
    minimum = 10005
    for symbol in symbols:
        if symbol == "/":
            current = current + 1
        elif symbol == "\\":
            current = current - 1
        minimum = min(minimum, current)
        numbers.append(current)
    numbers = list(map(lambda x: x - minimum, numbers))

    if symbols[0] == "/":
        numbers.insert(0, numbers[0] - 1)
    elif symbols[0] == "\\":
        numbers.insert(0, numbers[0] + 1)
    else:
        numbers.insert(0, numbers[0])

    equals = {}

    for i, number in enumerate(numbers):
        if number not in equals:
            equals[number] = []
        equals[number].append(i)

    numbers_copy = numbers.copy()

    keys = list(equals.keys())
    keys.sort()

    for key in keys:
        for k in range(len(equals[key]) - 1):
            i = equals[key][k]
            j = equals[key][k+1]

            error = False
            for l in range(i, j+1):
                if(numbers[l] > key):
                    error = True
                    break
            if not error:
                for l in range(i, j+1):
                    numbers[l] = key

    area1, area2 = 0, 0
    for i in range(len(numbers) - 1):
        if numbers[i] != numbers[i+1]:
            area1 = area1 + max(numbers[i], numbers[i+1]) - 0.5
        else:
            area1 = area1 + numbers[i]

        if numbers_copy[i] != numbers_copy[i+1]:
            area2 = area2 + max(numbers_copy[i], numbers_copy[i+1]) - 0.5
        else:
            area2 = area2 + numbers_copy[i]

    res = int(area1-area2)

    print(res)
