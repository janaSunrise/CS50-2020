from cs50 import get_int
import sys


def luhn_check(card_number):
    def digits_of(n):
        return [int(d) for d in str(n)]

    digits = digits_of(card_number)

    odd_digits = digits[-1::-2]
    even_digits = digits[-2::-2]

    checksum = 0
    checksum += sum(odd_digits)

    for d in even_digits:
        checksum += sum(digits_of(d * 2))

    return (checksum % 10) == 0


def main():
    card_number = get_int("Number: ")

    # check is in invalid types
    if len(str(card_number)) not in [13, 15, 16]:
        print("INVALID 1")
        sys.exit(1)

    if not luhn_check(card_number):
        print("INVALID 2")
        sys.exit(1)
    # or some of the possible cards!
    else:
        first_number = int(str(card_number)[0])
        second_number = int(str(card_number)[1])

        if first_number == 4:
            print("VISA")
        elif first_number == 3 and second_number in [4, 7]:
            print("AMEX")
        elif first_number == 5 and second_number in [1, 2, 3, 4, 5]:
            print("MASTERCARD")


main()
