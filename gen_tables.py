#!/usr/bin/env python3
    
for code in ('cp1251', 'koi8-r', 'iso-8859-5'):
    print(f'\n--- {code} ---')
    for i in range(128, 256):
        byte = int.to_bytes(i, 1, 'big')
        utf8 = byte.decode(code, 'replace').encode('utf8')
        print('0x{:0>8}'.format(utf8.hex()), end=', ')
        if (i-127) % 8 == 0: print()
