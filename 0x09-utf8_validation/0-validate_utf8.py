#!/usr/bin/python3
"""
method that determines if a given data set represents a valid UTF-8 encoding.

"""


def validUTF8(data):
    count = 0

    for byte in data:
        if count == 0:
            # check if this byte starts with binary 110 (0b110)
            if (byte >> 5) == 0b110:

                count = 1
            # check if this byte starts with binary 1110 (0b1110)
            elif (byte >> 4) == 0b1110:

                count = 2
            # check if this byte starts with binary 11110 (0b11110)
            elif (byte >> 3) == 0b11110:

                count = 3
            # check if this byte starts with binary 0 (byte >> 7)
            elif (byte >> 7):

                # if so, the encoding is not valid, so return False
                return False
        # if we are currently expecting more bytes (count > 0)
        else:
            # check if this byte starts with binary 10 (0b10)
            if (byte >> 6) != 0b10:
                # if not, the encoding is not valid, so return False
                return False
            # decrement count by 1
            count -= 1
    # if count is not 0, it means we have not received all the bytes
    # so the encoding is not valid
    return count == 0
