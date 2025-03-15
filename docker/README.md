# How to work with Docker?

## First Steps (docker CLI commands)

After installation (for Mint you can use [Ubuntu guidelines](https://docs.docker.com/engine/install/ubuntu/))
you can start with `docker run image_name` command that will create a **container** based on selected **image**

Following commands:

- `docker run -it image_name command`:
  `-it`: `-i` will provide console till force exit, `-t` create virtual TTY
  `--rm`: deletes container on exit
  `-d`: **detached** mode - opportunity to exit inner console without exiting the container
  `-P`: publish all exposed (открытые) ports to random ports
  `-p`: set port for running
- `docker images`: shows all available images in local system
- `docker ps`: shows currently running containers (`-a` will show previously running as well)
- `docker rm contanier_id`: deletes container by its ID from `docker ps -a`
- `docker rm(docker ps -a -q -f(ilter) condition)`: deletes all containers with corresponding status
  `-q`: returns numeric container ID
  `-f`: (filter) based on condition
  `docker container prune` is analogue in supported versions
- `docker stop container_id/container_name`: exits running container in case of **detached** mode
- `docker build path_to_Dockerfile`: creates an **image** from _Dockerfile_
  `-t`: specify name for image

## Dockerfile (how to describe an image?)

- `FROM base_image:version`: specifies base images to pull from docker hub
- `WORKDIR path/dir/dir`: specifies working directory inside base image
- `COPY path path`: copies from current directory into working directory
  `ADD`: copy application into the **new volume**
- `EXPOSE PORT`: открыть port
- `CMD ["part", "of", "command", "by", "words"]`: initial command on creating

### Docker Network (how to connect containers?)

- `docker network ls`: shows list of available **Docker Networks** (`bridge`, `host` and `none` are
  created automatically)
- `docker network inspect network_name`
