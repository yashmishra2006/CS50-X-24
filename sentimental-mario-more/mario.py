import cs50

while True:
    height = cs50.get_int("Height: ")
    if 1 <= height <= 8:
        break

for i in range(height):
    i += 1
    space = height - i
    print(" " * space, end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i)
