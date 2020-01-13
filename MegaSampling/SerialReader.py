import serial
import csv
import sys
import glob
import time
import struct

def serial_ports():
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except serial.SerialException:
            continue
    return result

ports = serial_ports()
print('Choose your port: ')
print(ports)
port = ''
while port not in ports:
    port = input()

print('Enter file name:')
name = input()
name += '.csv'

baudRate = 115200

try:
    ser = serial.Serial(port, baudRate, timeout=1)
    print('Start communication: ')
    msg = input()
    ser.write(struct.pack('>B', ord(msg)))
    while True:
        try:
            ser_bytes = ser.readline()
            try:
                decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
                print(decoded_bytes)
                with open(name,"a") as f:
                    writer = csv.writer(f,delimiter=",")
                    writer.writerow([time.time(),decoded_bytes])
            except:
                continue
        except:
            print("Keyboard Interrupt")
            break

except serial.SerialException:
    print('Error')
