RUNNER = platformio -f -c vim
PORT = /dev/cu.SLAB_USBtoUART
ENV = wemos_d1_mini32

all:
	$(RUNNER) test -e $(ENV) --upload-port $(PORT) --test-port $(PORT)

upload:
	$(RUNNER) run --target upload --upload-port $(PORT) -e $(ENV)

clean:
	$(RUNNER) run --target clean

program:
	$(RUNNER) run --target program

uploadfs:
	$(RUNNER) run --target uploadfs

update:
	$(RUNNER) update

serial:
	$(RUNNER) device monitor --port $(PORT)
