#!/usr/bin/python3
"""
Write in the heap
"""
import sys


def write_heap():
    """
    script to re write the heap
    """
    if len(sys.argv) != 4:
        print("Usage: read_write_heap.py pid search_string replace_string")
        exit(1)
    try:
        mMap = open('/proc/{}/maps'.format(sys.argv[1]), 'r')
    except Exception as e:
        print(e)
        exit(1)

    try:
        mFile = open("/proc/{}/mem".format(sys.argv[1]), 'rb+')
    except Exception as e:
        print(e)
        mMap.close()
        exit(1)

    for line in mMap.readlines():
        info = line.split()
        if "[heap]" in info:
            addr = info[0].split("-")
            start = int(addr[0], 16)
            end = int(addr[1], 16)
            mFile.seek(start)
            heap = mFile.read(end - start)
            i = heap.find(str.encode(sys.argv[2]))
            if i == -1:
                break
            mem_file.seek(start + i)
            mem_file.write(str.encode(sys.argv[3]) + b'\x00')
            break

    mMap.close()
    mem_file.close()


if __name__ == '__main__':
    write_heap()
