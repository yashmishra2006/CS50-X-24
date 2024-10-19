import cs50

card_number = cs50.get_string("Number: ")


def luhn(card_number):
    sum = 0
    length = len(card_number)
    for i in range(length-2, -1, -2):
        num = int(card_number[i])*2
        if num//10 == 0:
            sum = sum + num
        else:
            sum = sum + num % 10
            sum = sum + 1
    for i in range(length-1, -1, -2):
        sum = sum + int(card_number[i])

    if sum % 10 == 0:
        if length == 13:
            print("VISA")
        elif length == 15:
            if int(int(card_number)/10000000000000) in [34, 37]:
                print("AMEX")
            else:
                print("INVALID")
        elif length == 16:
            if int(int(card_number)/1000000000000000) == 4:
                print("VISA")
            elif int(int(card_number)/100000000000000) in [51, 52, 53, 54, 55]:
                print("MASTERCARD")
            else:
                print("INVALID")
        else:
            print("INVALID")

    else:
        print("INVALID")


luhn(card_number)
