# Running Node-RED and an MQTT broker locally

This Docker setup allows anyone to run a [Node-RED](https://nodered.org/) server and an MQTT broker ([Eclipse Mosquitto](https://mosquitto.org/)) – both vital parts of the Bricks ecosystem – on your personal computer (or on a server, or in the cloud, provided some tweaks).

## Requirements

You'll need to have [Docker](https://www.docker.com/) on your computer, and that's about it.

## Starting/stopping

You can start the Node-RED server and the MQTT broker by running `docker compose up` in this directory. This command will keep running and display both applications' logs. You can use the `--detach` option if you want it to run in the background (you won't be able to read the logs though).

:memo: _The first time you run `docker compose up`, it will take longer, as it needs to download and build Docker images._

To stop the Docker containers, just run `docker compose down`.

## Details

### Access to the MQTT broker

The two Docker containers defined in `docker compose.yml` are on the same network, and the MQTT broker is visible from Node-RED under the alias `mqtt`.

- Use the server name `mqtt` when declaring an MQTT broker in Node-RED.
- Use the host's ip address when configuring `BRICKS_MQTT_HOST` on the gateway brick.

### Data

Node-RED's data is bind mounted to the `data/` local directory, so that flows and configuration are persisted when the Docker containers are shut down.
After running once, you will find the following files:

-  `data/settings.js`: Node-RED's settings file, that could be checked in if there are settings changes that need to be persisted
- `data/flows.json`: an export of all the flows defined in Node-RED
- `data/flows_cred.json`

### SQLite

The `node-red-node-sqlite` module is already installed, and provides access to SQLite databases.
