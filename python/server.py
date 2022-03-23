import serial

ser = serial.Serial('COM1',9600)
ser.open()
while True:
    new_data = ser.read()
    if new_data:
        # flush serial
        ser.flushInput()
        print("new data:", new_data)
        ser.write(b"ACK\r")