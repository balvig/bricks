# Running Node-RED and an MQTT broker locally

This Docker setup allows anyone to run a [Node-RED](https://nodered.org/) server and an MQTT broker ([Eclipse Mosquitto](https://mosquitto.org/)) – both vital parts of the Bricks ecosystem – on your personal computer (or on a server, or in the cloud, provided some tweaks).

## Requirements

You'll need to have [Docker](https://www.docker.com/) on your computer, and that's about it.

## Starting/stopping

You can start the Node-RED server and the MQTT broker by running `docker-compose up` in this directory. This command will keep running and display both applications's logs. You can use the `--detach` option if you want it to run in the background (you won't be able to read the logs though).

:memo: _The first time you run `docker-compose up`, it will take longer, as it needs to download and build Docker images._

To stop the Docker containers, just run `docker-compose down`.

## Details

### Access to the MQTT broker

The two Docker containers defined in `docker-compose.yml` are on the same network, and the MQTT broker is visible from Node-RED under the alias `mqtt`. Just use the server name `mqtt` when declaring an MQTT broker in Node-RED. (_**TODO**: figure out a way to add a default MQTT broker into Node-RED's configuration._)

### Data

Node-RED's data (stored in the `/data` directory of the Docker container) is synced to the `data/` directory, so that flows and configuration are persisted when the Docker containers are shut down. After running once, you will find the following files:

- `data/flows.json`
- `data/flows_cred.json`

### SQLite

The `node-red-node-sqlite` module is already installed, and provides access to SQLite databases. To ensure that your SQLite data is persisted when the Docker container is shut down, make sure you set your database's path inside `/data/`.

### Node modules

Node-RED's UI provides a way to install new modules ("Manage Palette" in the top menu, then "Install" tab). Installing new modules will update the `data/package.json` and `data/package-lock.json` files.
