fqbn = arduino:avr:mega
port = /dev/cu.usbserial-14330

compile:
	arduino-cli compile --fqbn ${fqbn} .

upload:
	arduino-cli upload -p ${port} --fqbn ${fqbn} .

monitor:
	arduino-cli monitor -p ${port}

all: compile upload monitor

tutorial:
	open https://arduino.github.io/arduino-cli/0.20/getting-started/

lib:
	arduino-cli lib install $(name)

