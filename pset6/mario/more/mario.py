from cs50 import get_int


def get_input():
    while True:
        size = get_int("Height: ")
        if size >= 1 and size <= 8:
            break

    return size


def make_pyramid(height):
    spaces = height - 1

    while spaces >= 0:
        print(" " * spaces, end="")
        print("#" * (height - spaces), end="")
        print("  ", end="")
        print("#" * (height - spaces), end="")
        print()

        spaces -= 1

size = get_input()
make_pyramid(size)
