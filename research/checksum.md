# Trying to figuring out last 8 bytes in commands
The last 8 bytes in every command might be a checksum.
They are the same if the data payload is the same?



# Samples

### Version
Payload: 00 02 00 1e 00 34 73 80 5f 70 69 6e
Data: 00 02 00 1e
Checksum?: 00 34 73 80 5f 70 69 6e

### Edited same value on 2 cameras to maybe identify the last 8 bytes
04 01 0d 01 00 01 00 00  00 00 00 00 00 00 00 00  f8 bb 10 00 10 00 ff 2f  00 20 43 50 43 43 64 50
03 01 0d 01 00 01 00 00  00 00 00 00 00 00 00 00  f8 bb 10 00 10 00 ff 2f  00 20 43 50 43 43 64 50
