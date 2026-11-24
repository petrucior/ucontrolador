# ucontrolador
Microcontrolador atmega328p

## Ubuntu

### Installing libraries
```
sudo apt update && sudo apt install gcc-avr binutils-avr avr-libc gdb-avr avrdude make
```
### Serial Port ID

/dev/ttyUSB0 or /dev/ttyACM0

```
ls /dev/tty*
```


## MacOS

### Installing libraries
- ![Homebrew](https://brew.sh/)
- ![avr-gcc](https://github.com/osx-cross/homebrew-avr)
```
brew top osx-cross/avr
brew install avr-gcc 
```
- ![avrdude](https://github.com/avrdudes/avrdude/)
```
brew install avrdude
```

### Serial Port ID
```
ls /dev/cu.*
```


